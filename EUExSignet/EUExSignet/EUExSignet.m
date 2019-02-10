//
//  EUExSignet.m
//  EUExSignet
//
//  Created by 张一鹏 on 2019/2/1.
//  Copyright © 2019 张一鹏. All rights reserved.
//

#import "EUExSignet.h"
#import "SignetSDK/Header/SignetManager.h"

@implementation EUExSignet

SignetManager *mySignet;

- (instancetype)initWithWebViewEngine:(id<AppCanWebViewEngineObject>)engine{
    self = [super initWithWebViewEngine:engine];
    if (self) {
        //初始化工作
    }
    mySignet =  [ SignetManager initManager:self delegate:self];
    return self;
}

#pragma mark - AppDelegate by EngineControl

+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions{
    //TODO App初始化代理通知
    return NO;
}

#pragma mark - 插件方法定义

- (void)findBackUser:(NSMutableArray *)inArguments{
//    mySignet findbackUser:<#(NSString *)#> UserName:<#(NSString *)#> UserCardID:<#(NSString *)#> IDType:<#(NSString *)#>
}

- (void)userLogin:(NSMutableArray *)inArguments{
//    mySignet userLogin:<#(NSString *)#> MSSPID:<#(NSString *)#> LogInJobID:<#(NSString *)#>
}

- (void)getUserList:(NSMutableArray *)inArguments{
    [SignetManager getUserList];
}

- (void)clearCert:(NSMutableArray *)inArguments{
//    mySignet clearCert:<#(NSString *)#> MSSPID:<#(NSString *)#>
}

- (void)clean{
    //NSLog(@"网页即将被销毁");
}

@end
