//
//  Signet_SDK.h
//  Signet-SDK
//
//  Created by BJCA on 16/2/16.
//  Copyright © 2016年 bjca. All rights reserved.
//

#import <UIKit/UIKit.h>
#pragma mark 数据类型

typedef NS_ENUM(NSUInteger, SignetUserCertType) {
    RSA_LOGIN_CERT,
    SM2_LOGIN_CERT,
    RSA_SIGN_CERT,
    SM2_SIGN_CERT,
    USER_LOGIN,
    USER_SIGN,
    USER_RSA,
    USER_SM2,
    ALL_CERT,
};


typedef NS_ENUM(NSUInteger, SignetUserType) {
    PERSON,
    ENTERPRISE,
};

typedef NS_ENUM(NSUInteger, SignetDataType) {
    CLEAR_DATA,
    HASH_DATA,
};
@interface SignetManager : NSObject
//回调协议
@property (assign) id delegate;
#pragma mark    对象初始化函数
/**
 *  @breif      对象初始化接口
 *                 调用者使用当前UIViewController初始化
 *
 *  @param    parentContorller      当前活跃的UIViewController
 *
 *  @return    SignetManager对象，以下对象接口函数需使用该对象调用
 *  @note      调用者为单UIViewController应用时，该初始化函数只需调用一次
 *                 调用者为多UIViewController应用时，应在切换到新的UIViewController时重新调用该函数
 */
+(instancetype)initManager:(UIViewController*)parentContorller delegate:(id)delegateObject;
#pragma mark    业务接口函数
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 如果用户已注册，则发起找回老用户流程
 *
 *  @param   appID          调用者的应用编号
 *  @param   activeCode   用户注册码
 *
 *
 *  @return   error            同步返回错误码
 
 *  @note
 */
-(NSError*)userRegister:(NSString *)appID ActiveCode:(NSString*)activeCode;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口,通过扫码进行注册
 *                 如果用户已注册，则发起找回老用户流程
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error            同步返回错误码
 
 *  @note
 */
-(NSError*)qrRegister:(NSString *)appID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 开启用户自助注册流程
 *
 *  @param   appID          调用者的应用编号
*
 *
 *  @return   error            同步返回错误码
 
 *  @note
 */
-(NSError*)selfRegister:(NSString *)appID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 用户自注册返回用户信息
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error            同步返回错误码
 
 *  @note
 */
-(NSError*)selfRegisterandBackUserInfo:(NSString *)appID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 开启匿名用户注册流程
 *
 *  @param   appID          调用者的应用编号
 *  @param   userType       用户类型
 *
 *
 *  @return   error            同步返回错误码
 
 *  @note
 */
-(NSError*)anonymousRegister:(NSString *)appID UserType:(NSString*)userType RegInfo:(NSString*)userRegInfo;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 用户登录接口，发起用户登录流程
 *
 *  @param   msspID        用户唯一身份标识
 *  @param   appID          调用者的应用编号
 *  @param   loginJobID    登录业务流水号
 *
 *
 *  @return   error            同步返回错误码
 *
 *  @note
 */
-(NSError*)userLogin:(NSString*)appID MSSPID:(NSString*)msspID LogInJobID:(NSString*)loginJobID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 扫描二维码，发起用户登录流程
 *
 *  @param   msspID        用户唯一身份标识
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error            同步返回错误码
 *
 *  @note
 */
-(NSError*)qrLogin:(NSString*)appID MSSPID:(NSString*)msspID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 信步云企业帐户找回老用户接口，发起找回老用户流程
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)findbackEnterPriseBySignet:(NSString*)appID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 找回老用户接口，发起找回老用户流程
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)findbackUserBySignet:(NSString*)appID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 找回老用户接口，发起找回老用户流程
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)findbackUser:(NSString*)appID UserName:(NSString*)userName UserCardID:(NSString*)cardID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 找回老用户接口，发起找回老用户流程
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)findbackUser:(NSString*)appID UserName:(NSString*)userName UserCardID:(NSString*)cardID IDType:(NSString*)IDTypeString;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 找回企业老用户接口，发起找回企业老用户流程
 *
 *  @param   appID          调用者的应用编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)findbackEnterPrise:(NSString*)appID UserName:(NSString*)userName UserCardID:(NSString*)cardID IDType:(NSString*)IDTypeString EnterPriseID:(NSString*)enterPriseIdStr EnterPriseIDType:(NSString*)enterPriseIDTypeString;
#pragma 签名
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 设置用户手写签名接口，发起手写签名设定流程
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)setUserHandWriting:(NSString*)appID MSSPID:(NSString*)msspID;

/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 拍摄用户手写签名接口，发起手写签名设定流程
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)pictureHandWriting:(NSString *)appID MSSPID:(NSString*)msspID;
/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 同步调用接口
 *                 获取用户手写签名笔迹
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *
 *  @return   NSString*           同步返回用户的手写签名笔迹
 *
 *  @note
 */
-(NSString*)getUserHandWriting:(NSString*)appID MSSPID:(NSString*)msspID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 设置用户指纹签名接口，发起指纹签名设定流程
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */

-(NSError*)enableFingerSign:(NSString*)appID MSSPID:(NSString*)msspID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 设置用户指纹签名接口，发起指纹签名设定流程
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)disableFingerSign:(NSString*)appID MSSPID:(NSString*)msspID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 数据签名接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识 
 *  @param   signJobID     签名业务编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */

-(NSError*)signData:(NSString*)appID MSSPID:(NSString*)msspID SignJobID:(NSString*)signJobID;

/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 数据签名，传入PIN口令接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *  @param   signJobID      签名业务编号
 *  @param   pin            用户口令
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)signDataWithPin:(NSString*)appID MSSPID:(NSString*)msspID SignJobID:(NSString*)signJobID UserPin:(NSString*)pin;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 数据签名，传入PIN口令接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *  @param   signJobID      签名业务编号
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)signDataAndReturnPin:(NSString*)appID MSSPID:(NSString*)msspID SignJobID:(NSString*)signJobID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 数据签名接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *  @param   data           待签数据、数组类型(支持批量数据签名)
 *  @param   type           待签数据需要的签名算法、数据类型和签名类型共三个参数的字典,具体的key与对应的value如下
                            签名算法：key:algoPolicy    value:SHA1WITHRSA/SHA256WITHRSA/SM3WITHSM2
                            数据类型：key:dataType      value:CLEAR_DATA/HASH_DATA
                            签名类型：key:signType      value:AUTH/SIGN
 
 *
 *  @return   error         同步返回错误码
 *
 *  @note
 */
-(NSError*)signDataFromClient:(NSString*)appID MSSPID:(NSString*)msspID Data:(NSArray*)data PolicyWithType:(NSDictionary*)type;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 数据签名接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识
 *  @param   signJobID     签名业务编号
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)qrSign:(NSString*)appID MSSPID:(NSString*)msspID;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 数据签名接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID        用户唯一身份标识
 *  @param   signDocID    待签文档标识
 *
 *
 *  @return   error           同步返回错误码
 *
 *  @note
 */
-(NSError*)signDoc:(NSString*)appID MSSPID:(NSString*)msspID SignDocID:(NSString*)signDocID;
#pragma 工具接口
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *              异步调用接口
 *              通过OCR获取用户信息
 *
 *  @param appID        调用者的应用编号
 *
 *  @return
 */
-(NSError*)getUserInfoFromIDOCR:(NSString *)appID ImageSymbol:(BOOL)bNeedIDImage;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *              异步调用接口
 *              活体检测-成功返回照片
 *
 *  @param appID        调用者的应用编号
 *
 *  @return
 */
-(NSError*)startLiveCheckAppID:(NSString *)appID liveNumber:(int)liveNumber;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 同步调用接口
 *                 清除本地用户证书接口
 *
 *  @param appID        调用者的应用编号
 *  @param msspID      用户的唯一编号
 *                               @note对于单用户版本忽略该参数
 */
-(void)clearCert:(NSString *)appID MSSPID:(NSString*)msspID;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 证书解析接口，对证书字符串进行分析，返回证书的C，CN，UID信息
 *
 *  @param certString        Base64的DER证书字符串
 *  @param   error           返回错误信息
 *
 *  @return  证书信息的Dictionary，其中C的key为字符串“C”，CN的key为字符串“CN”，UID的key为字符串“UID”
 */
+(NSDictionary*)analyzeCert:(NSString*)certString Error:(NSError**)error;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 证书获取接口，根据证书类型和用户标识返回证书列表
 *
 *  @param msspID        用户唯一标识
 *  @param certType       需要的证书类型，SignetUserCertType的enum
                                    USER_LOGIN_RSA    －－ 只返回用户登录的RSA证书
                                    USER_LOGIN_SM2    －－ 只返回用户登录的SM2证书
                                    USER_SIGN_RSA,      －－  只返回用户签名的RSA证书
                                    USER_SIGN_SM2,      －－  只返回用户签名的RSA证书
                                    USER_LOGIN,           －－  返回用户登录的RSA证书和SM2证书
                                    USER_SIGN,             －－  返回用户签名的RSA证书和SM2证书
                                    USER_RSA,              －－  返回用户登录的RSA证书和签名的RSA证书
                                    USER_SM2,              －－  返回用户登录的SM2证书和签名的SM2证书
                                    USER_ALL,              －－  只返回用户所有证书
 *  @param   error           返回错误信息
 *
 *  @return  证书的Array，Array内对象为NSDictionary，该Dictionary含两项元素
                                                                              key：“Type” Value：证书类型
                                                                                                    @“USER_LOGIN_RSA” －－ 用户登录的RSA证书
                                                                                                    @“USER_LOGIN_SM2” －－ 用户登录的SM2证书
                                                                                                    @“USER_SIGN_RSA” －－ 用户签名的RSA证书
                                                                                                    @“USER_SIGN_SM2” －－ 用户签名的SM2证书
                                                                              Key：“Cert”  Value：Base64编码的Der证书字符串
 */
+(NSArray*)getUserCert:(NSString*)msspID Type:(SignetUserCertType)certType Error:(NSError**)error;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 本地用户列表获取接口，取得本地存储的所有用户的用户名和对应的MSSPID
 *
 *  @param    无
 *
 *  @return   用户名和MSSPID的Dictionary，key值为MSSPID，value为用户名
 *  @note      单用户版本此接口返回空
 */

+(NSDictionary*)getUserList;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 根据用户类型获取本地用户列表接口，取得本地存储的对应用户类型的用户名和对应的MSSPID
 *
 *  @param   SignetUserType 用户类型 PERSON为个人用户  ENTERPRISE为企业用户
 *
 *  @return   用户名和MSSPID的Dictionary，key值为MSSPID，value为用户名
 *  @note      单用户版本此接口返回空
 */

+(NSDictionary*)getUserListWithUserType:(SignetUserType)userType;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 获取当前设备标识号
 *
 *  @param   无
 *
 *  @return   设备标识号字符串
 *  @note      由于苹果限制，该ID再删除重装后会变化
 */
+(NSString*)getDeviceID;

/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 获取当前设备信息
 *
 *  @param   无
 *
 *  @return   当前设备信息字典
 *  @note     无
 */
+(NSDictionary*)getDeviceInfor;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 获取当前SDK版本号
 *
 *  @param   无
 *
 *  @return    SDK版本号字符串
 *  @note      无
 */
+(NSString*)getVersionInfo;
/**
 *  @breif      类接口函数，无需初始化对象，可直接调用
 *                 同步调用接口
 *                 加密用户登录信息
 *
 *  @param   userName     用户姓名
 *  @param   userIDCardNumber   用户证件号码
 *  @param   userPassString     用户登录口令
 *  @param   msspID        用户唯一身份标识
 *
 *  @return   加密的用户信息，该信息用于加密登录接口
 *  @note      单用户版本此接口返回空
 */
+(NSData*)encryptUserInfo:(NSString*)userName IDNumber:(NSString*)userIDCardNumber UserPass:(NSString*)userPassString MSSPID:(NSString*)msspID;


/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 同步调用接口
 *                 获取用户所有企业签章图片
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *
 *  @return  NSDictionary*      同步返回当前企业的签章图片
 *
 *  @note
 */
-(NSDictionary*)getAllEnterpriseSealImage:(NSString*)appID MSSPID:(NSString*)msspID;

/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 查询当前企业的签章图片信息(主要信息是imageID（印章ID）和name（印章名称）)
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *  @return  NSDictionary*      同步返回当前企业的印章信息(包括enterpriseName（企业名称）、imageID和name)
 *
 *  @note
 */
-(NSDictionary*)getEnterpriseseal:(NSString*)appID MSSPID:(NSString*)msspID;

/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 查询当前企业的签章图片（可以查询某一张或几张印章图片）
 *
 *  @param   appID              调用者的应用编号
 *  @param   msspID             用户唯一身份标识
 *  @param   infor              当前企业的印章信息,为数组字典格式，每组信息包括： imageID和name
 *  @return  NSArray*           同步返回当前企业的印章图片
 *
 *  @note
 */
-(NSArray*)getEnterpriseSealImage:(NSString*)appID MSSPID:(NSString*)msspID withEnterprisesealInfor:(NSArray*)infor;
/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 离线签名接口
 *
 *  @param   appID              调用者的应用编号
 *  @param   msspID             用户唯一身份标识
 *  @param   policy           签名算法，暂用固定值：SM3withSM2（以后要兼容RSA）
 *  @param   type             签名类型，取值范围：AUTH/SIGN
 *  @return  error            同步返回错误码
 *
 *  @note
 */
-(NSError*)getUserLocalCert:(NSString*)appID MSSPID:(NSString*)msspID AlgoPolicy:(NSString*)policy SignType:(NSString*)type;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 异步调用接口
 *                 离线签名接口，用户完成数据签名
 *
 *  @param   appID          调用者的应用编号
 *  @param   msspID         用户唯一身份标识
 *  @param   signData       待签数据
 *  @param   dataType       数据类型  CLEAR_DATA或HASH_DATA
 *  @param   algoPolicy     暂用固定值:SM3WITHSM2（以后要兼容RSA）

 *
 *  @return   error         同步返回错误码
 *
 *  @note
 */
-(NSError*)offlineSign:(NSString*)appID MSSPID:(NSString*)msspID SignData:(NSString*)signData SignAlgoPolicy:(NSString*)algoPolicy DataType:(NSString*)dataType;
/**
 *  @breif      对象接口函数， 需调用initManager初始化SignetManager对象
 *                 同步调用接口
 *                 清除本地用户证书接口
 *
 *  @param appID        调用者的应用编号
 *  @param msspID      用户的唯一编号
 *                               @note对于单用户版本忽略该参数
 */
-(void)clearOfflineCert:(NSString *)appID MSSPID:(NSString*)msspID;
/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 手写签署预览接口
 *
 *  @param   appID              调用者的应用编号
 *  @param   msspID             用户唯一身份标识
 *  @param   signDocID          文档签名业务ID
 *  @param   signImage          用户手写签名图片
 *  @return                     返回与文档签名相同
 *
 *  @note
 */
-(NSError*)signDocWithHandWriting:(NSString*)appID MSSPID:(NSString*)msspID SignDocID:(NSString*)signDocID SignImage:(NSString*)signImage;

/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 手写签署预览接口
 *
 *  @param   appID              调用者的应用编号
 *  @param   msspID             用户唯一身份标识
 *  @param   error              异常返回
 *  @return                     用户绑定设备列表
 *
 *  @note
 */
- (NSError *)getBindedDeviceList:(NSString *)appID MSSPID:(NSString *)msspID;

/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 手写签署预览接口
 *
 *  @param   devID              设备ID
 *  @param   msspID             用户唯一身份标识
 *  @param   error              异常返回
 *  @return                     删除用户绑定设备
 *
 *  @note
 */
- (NSError *)deleteUserDevice:(NSString *)devID MSSPID:(NSString *)msspID;
//隐藏
+ (NSDictionary*)setHudStatus:(BOOL)isHidden;


/**
 *  @breif         对象接口函数， 需调用initManager初始化SignetManager对象
 *                 检测本机密钥状态的接口
 *
 *  @param   appID              调用者的应用编号
 *  @param   msspID             用户唯一身份标识
 *  @return  error              异常返回
 *
 *  @note
 */
- (NSError *)detectionUserKeyState:(NSString *)appID MSSPID:(NSString *)msspID;

@end

@protocol SignetManagerDelegate
/**
 *  @breif      回调接口
 *                 调用者通过该接口获得异步调用结果
 *
 *  @param    NSDictionary类型
                    该dictionary由四对键值对组成：
                    key：“errorCode”       value：错误值字符串，当为字符串“0”时成功
                    key：“errorDescript”    value：错误描述字符串，成功时为“”空内容的字符串
                    key：“businessType”    value：业务类型值字符串，具体描述如下：
                                            "0"  表示注册业务              对应接口 userRegister
                                            “1”  表示登录业务          对应接口 userLogin
                                            “2”  表示找回业务          对应接口 findbackUser
                                            “3”  表示签名业务          对应接口 userSign
                                            “4”  表示笔迹业务          对应接口 HandWriting
                                            “5”  表示指纹业务          对应接口 fingerPrint
                                            “6”  表示OCR业务          对应接口 OCRUserInfo
                                            “7”  表示离线证书业务       对应接口 SoftCert
                                            “8”  表示离线签名业务       对应接口 SoftSign
                                            “9”  表示获取用户设备列表    对应接口 GetUserDeviceList
                                            “10” 表示用户设备删除业务    对应接口 UserDeviceDelete
                                            “11” 表示活体识别业务       对应接口 LiveCheck
                                            “12” 表示检测本机密钥状态   对应接口 CheckKeyState
 
                   key：“backData”         value：返回数据对象，当出现错误时为“”空内容字符串
                                                                   对应接口 userRegister 为NSString＊
                                                                   对应接口 userLogin     为NSDictionar＊
                                                                   对应接口 findbackUser 为NSString＊
 *          OCRUserInfo 数组，第一项为用户信息的NSDictionary，第二项和第三项为ID的拍摄图片，如果bNeedIDImage为YES
 *                      则为用户身份证，正，反两面的拍摄图片NSData，如果为NO，则无数据
 *                      用户信息包括：用户姓名、身份证号码
 *
 *  @return   无
 *  @note      该接口为delegate，由调用者实现
 */

-(void)isProcessFinished:(NSDictionary*)backParam;

@end
