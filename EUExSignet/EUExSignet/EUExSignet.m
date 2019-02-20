//
//  EUExSignet.m
//  EUExSignet
//
//  Created by 张一鹏 on 2019/2/1.
//  Copyright © 2019 张一鹏. All rights reserved.
//

#import "EUExSignet.h"
#import "SignetSDK/Header/SignetManager.h"

//调用者的应用编号
#define APP_ID                     @"APP_DD4E6AC3F72342D49880F7D4074340A6"

@interface EUExSignet()<SignetManagerDelegate>

@property (nonatomic,retain)SignetManager *mySignet;

@property (nonatomic,retain)ACJSFunctionRef *findBackUserCallbackFunc;
@property (nonatomic,retain)ACJSFunctionRef *userLoginCallbackFunc;


@end

@implementation EUExSignet


- (instancetype)initWithWebViewEngine:(id<AppCanWebViewEngineObject>)engine{
    self = [super initWithWebViewEngine:engine];
    if (self) {
        //初始化工作
         _mySignet =  [SignetManager initManager:self.webViewEngine.viewController delegate:self];
    }
    return self;
}

#pragma mark - AppDelegate by EngineControl

+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions{
    //TODO App初始化代理通知
    return NO;
}

#pragma mark - 插件方法定义

- (void)findBackUser:(NSMutableArray *)inArguments{
    if (inArguments.count == 0) {
        return;
    }
    ACArgsUnpack(NSDictionary *info,ACJSFunctionRef *callback) = inArguments;
    _findBackUserCallbackFunc = callback;
    NSString *userName = stringArg(info[@"userName"]);
    NSString *idCardNumber = stringArg(info[@"idCardNumber"]);
    NSString *idCardType = stringArg(info[@"idCardType"]);
    __block   NSError *error;
    if (userName.length>0) {
        //不带界面找回用户
        error =  [_mySignet findbackUser:APP_ID UserName:userName UserCardID:idCardNumber IDType:idCardType];
    }else {
        //带界面找回用户
        dispatch_async(dispatch_get_main_queue(), ^{
            error =  [self->_mySignet findbackUserBySignet:APP_ID];
        });
        
    }
    ACLogDebug(@"->uexSignet ---> findBackUser error %@ \n",error);
    
    if ( error != nil ) {
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"提示" message:[error localizedDescription]preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:nil];
        [alertController addAction:okAction];
        [self.webViewEngine.viewController presentViewController:alertController animated:YES completion:nil];
    }

}
#pragma mark --- SignetManagerDelegate
-(void)isProcessFinished:(NSDictionary*)backParam{
    NSLog(@"backParam=======%@",backParam);
    NSMutableDictionary *resultDict = [NSMutableDictionary dictionary];
    NSString *businessType = [backParam objectForKey:@"businessType"];
    
    if ([businessType isEqualToString:@"1"]) {
        // userLogin 回调
        [resultDict setValue:[backParam objectForKey:@"errorCode"] forKey:@"errCode"];
        [resultDict setValue:[backParam objectForKey:@"errorDescript"] forKey:@"errMsg"];
        if (_userLoginCallbackFunc) {
            if (![backParam[@"errorCode"] isEqualToString:@"0x00000000"]) {
                [_userLoginCallbackFunc executeWithArguments:@[[resultDict ac_JSONFragment]]];
            }else {
                
                NSDictionary *msspInfo = (NSDictionary*)backParam[@"backData"];
                NSLog(@"backParam==========%@",backParam);
                NSArray *array = [msspInfo objectForKey:@"signDataInfos"];
                NSLog(@"array========%@",array);
                NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:0];
                NSString *key;
                for (int i = 0; i<array.count; i++) {
                    key = [NSString stringWithFormat:@"%d",i];
                    [dict setObject:[array objectAtIndex:i] forKey:key];
                }
                NSLog(@"dict%@",dict);
                NSLog(@"the sign Cert:%@", [msspInfo objectForKey:@"SignCert"] );
                [resultDict setValue:[msspInfo objectForKey:@"SignJobID"] forKey:@"SignDataJobID"];
                [resultDict setValue:[msspInfo objectForKey:@"SignCert"] forKey:@"cert"];
                [_userLoginCallbackFunc executeWithArguments:@[[resultDict ac_JSONFragment]]];
            }
        }
    }else if([businessType isEqualToString:@"2"]){
        // findbackuser 回调
        [resultDict setValue:[backParam objectForKey:@"errorCode"] forKey:@"errCode"];
        [resultDict setValue:[backParam objectForKey:@"errorDescript"] forKey:@"errMsg"];
        if (_findBackUserCallbackFunc) {
            if (![backParam[@"errorCode"] isEqualToString:@"0x00000000"]) {
                [_findBackUserCallbackFunc executeWithArguments:@[[resultDict ac_JSONFragment]]];
            }else {
                NSString *msspID = (NSString*)backParam[@"backData"];
                [resultDict setValue:msspID forKey:@"msspId"];
                
                [_findBackUserCallbackFunc executeWithArguments:@[[resultDict ac_JSONFragment]]];
            }
        }
    }else {
        return ;
    }
    [self.webViewEngine.viewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)userLogin:(NSMutableArray *)inArguments{
    if (inArguments.count == 0) {
        return;
    }
    ACArgsUnpack(NSDictionary *info,ACJSFunctionRef *callback) = inArguments;
    _userLoginCallbackFunc = callback;
    NSString *msspId = stringArg(info[@"msspId"]);
    NSString *signId = stringArg(info[@"signId"]);
    NSError *error =  [_mySignet userLogin:APP_ID MSSPID:msspId LogInJobID:signId];
    ACLogDebug(@"->uexSignet ---> findBackUser error %@ \n",error);
    if ( error != nil ) {
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"提示" message:[error localizedDescription]preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:nil];
        [alertController addAction:okAction];
        [self.webViewEngine.viewController presentViewController:alertController animated:YES completion:nil];
    }
    
}

- (NSString *)getUserList:(NSMutableArray *)inArguments{
    NSDictionary *myuserListInfo = [SignetManager getUserList];
    return [myuserListInfo ac_JSONFragment];
}

- (NSString *)clearCert:(NSMutableArray *)inArguments{
    ACArgsUnpack(NSDictionary *info) = inArguments;
    NSString *msspId = stringArg(info[@"msspId"]);
    NSString *certType = stringArg(info[@"certType"]);
    
    [ _mySignet clearCert:msspId MSSPID:certType];
    return @"清除成功";
}

- (void)clean{

    //NSLog(@"网页即将被销毁");
}


@end
