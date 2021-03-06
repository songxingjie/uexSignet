[TOC]

Ca云签名-登录插件
## 1.1、说明 
 Ca云签名-登录插件,是用来实现登录认证，找回用户等功能.

## 1.2、开源源码
   无
## 1.3、平台版本支持

本插件的所有API默认支持**Android4.0+**和**iOS9.0+**操作系统.

有特殊版本要求的API会在文档中额外说明.

## 1.4、接口有效性

本插件所有API默认在插件版本**4.0.0+**可用.
# 2、API概览

## 2.1、方法

### 🍭 findBackUser 找回用户（通过输入证件信息等，找回用户CA认证所需的个人证书。找回证书后，证书实体本身不需要前端维护，也不需要插件维护，是由插件内封装的SDK内部维护的）

`uexSignet.findBackUser(JSON.stringify(jsonData), function(result){
                alert(JSON.stringify("findBackUser: " + result));
                console.log(JSON.stringify("findBackUser: " + result));
            });`

**说明:**

找回用户功能,该方法分为两种情况，分别为：手动修改测试代码(参数不为空时，调用SDK方法找回) 和 自带界面的找回证书（当参数传空，会调用SDK的方法用于启动界面）
1.1  当参数不为空时：
**参数:**

| 参数名称    | 参数类型   | 是否必选 | 说明                                       |
| ------- | ------ | ---- | ---------------------------------------- |
| userName    | String    | 是        | 用户姓名|
| idCardNumber| String    | 是        | 证件号码|
| idCardType  | String    | 是        | 证件类型|
| result      | Function  | 是        | 用于调用SDK找回用户API找回用户返回信息,将调用此回调函数|

**示例:**

```javascript
function findBackUser() {
    var jsonData = {
        userName:"测试用户",
        idCardNumber:"210624200001017496",
        idCardType:1,
    }
    // idCardType取值：
    //0 HK,
    //1 HZ,
    //2 JG,
    //3 JI,
    //4 JL,
    //5 SB,
    //6 SF,
    //7 SG,
    //8 WZ,
    //9 XJ,
    //10 GA;
    uexSignet.findBackUser(JSON.stringify(jsonData), function(result){
        alert(JSON.stringify("findBackUser: " + result));
        console.log(JSON.stringify("findBackUser: " + result));
    });
}
```
1.2  当参数为空时：       
**参数:**
        
| 参数名称    | 参数类型   | 是否必选 | 说明                                       |
| ------- | ------ | ---- | ---------------------------------------- |
| result    | Function    |   是      |  用于调用SDK找回用户API找回用户返回信息,将调用此回调函数  |


**示例:**

```javascript
function findBackUserWithInputUI() {
var jsonData = {}
uexSignet.findBackUser(JSON.stringify(jsonData), function(result){
alert(JSON.stringify("findBackUser: " + result));
console.log(JSON.stringify("findBackUser: " + result));
});
}
```      
        
### 🍭 userLogin 用户登录：通过EMM登录后，后端返回的msspId和signId等信息
` uexSignet.userLogin(JSON.stringify(jsonData), function(result){
                alert(JSON.stringify("userLogin: " + result));
                console.log(JSON.stringify("userLogin: " + result));
            });`

**说明:**

用户登录功能

**参数:**

| 参数名称    | 参数类型   | 是否必选 | 说明                                       |
| ------- | ------ | ---- | ---------------------------------------- |
| appID            | String    |   是      |  业务应用ID |
| msspID           | String    |   是      |  用户在云签名系统中的唯一标识，与实名身份相绑定。|
| signJobID        | String    |   是      |  本次登录业务的唯一标识，从服务端获取并传参。|
| result           | Function  |   是      |  用于调用SDK登录API使用当前用户对应的证书对随机数做电子 签名，进行身份认证，从而实现App的登录,将调用此回调函数 |



**示例:**

```javascript
function userLogin() {
    var jsonData = {
        msspId:"123456",
        signId:"123456",
    }
    uexSignet.userLogin(JSON.stringify(jsonData), function(result){
        alert(JSON.stringify("userLogin: " + result));
        console.log(JSON.stringify("userLogin: " + result));
    });
}
```


### 🍭 getUserList 获取本地所有已经存储好了的证书（可用证书），用于检查本地是否存在证书，是否还需要调用findBackUser接口
`  var result = uexSignet.getUserList();
            alert(JSON.stringify("getUserList: " + result));
            console.log(JSON.stringify("getUserList: " + result));`

**说明:**

获取当前用户列表功能

**参数:**

| 参数名称    | 参数类型   | 是否必选 | 说明                                       |
| ------- | ------ | ---- | ---------------------------------------- |
| result           | Function  |   是      |  用于调用SDK用户列表API获取设备中当前所有证书用户的列表，以Dictionary的形式返回，KEY与
VALUE分别为msspID与其对应的用户名。应用情景为登录App时选择特定用户进行云签名登录。,将调用此回调函数 |


**示例:**

```javascript
function getUserList() {
    var result = uexSignet.getUserList();
    alert(JSON.stringify("getUserList: " + result));
    console.log(JSON.stringify("getUserList: " + result));
}
```

### 🍭 clearCert 清空本地证书存储，按需求调用（比如注销时，是否需要清空证书？）
`  var result = uexSignet.clearCert(JSON.stringify(jsonData));
            alert(JSON.stringify("getUserList: " + result));
            console.log(JSON.stringify("getUserList: " + result));`

**说明:**

注销功能

**参数:**

| 参数名称    | 参数类型   | 是否必选 | 说明                                       |
| ------- | ------ | ---- | ---------------------------------------- |
| appID            | String    |   是      |  业务应用ID|
| msspID           | String    |   是      |  用户在云签名系统中的唯一标识。|


**示例:**

```javascript
function clearCert() {
    var jsonData = {
        msspId:"123456",
        certType:"123456",
    }
    // certType取值：
    //0 ALL_CERT,
    //1 RSA_SIGN_CERT,
    //2 RSA_AUTH_CERT,
    //3 SM2_SIGN_CERT,
    //4 SM2_AUTH_CERT,
    //5 ALL_OFFLINE_CERT,
    //6 RSA_OFFLINE_SIGN_CERT,
    //7 SM2_OFFLINE_SIGN_CERT;
    var result = uexSignet.clearCert(JSON.stringify(jsonData));
    alert(JSON.stringify("getUserList: " + result));
    console.log(JSON.stringify("getUserList: " + result));
}
```

# 3、更新历史

### Ios

API版本: `uexSignet-4.0.0`

最近更新时间:`2019-2-14`


### Android

API版本: `uexSignet-4.0.0`

最近更新时间:`2019-2-14`

| 历史发布版本 | 更新内容 |
| ----- | ----- |
