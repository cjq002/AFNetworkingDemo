//
//  AFNetworkHandle.h
//  AFNetworkingDemo
//
//  Created by CJQ on 2018/10/23.
//  Copyright © 2018年 CL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetwork.h"
#import <AFNetworking/UIKit+AFNetworking.h>

NS_ASSUME_NONNULL_BEGIN

// 服务器请求错误吗
typedef NS_ENUM(NSUInteger, JYNetworkCode) {
	NetworkCodeForSuccess     = 200,  //请求成功
	NetworkCodeForParamError  = 400,  //参数错误
	NetworkCodeForLogin       = 401,  //没有请求权限（需要登录）
	NetworkCodeUserCompetence = 403,  //权限不足
	NetWorkCodeForUnSuccess   = 409,  //请求成功，添加失败，进行提示
	NetworkCodeForNotFound    = 404,  //请求地址不存在
	NetworkCodeForBadRequest  = 500,  //服务器错误
	NetworkCodeForStopRequet  = 501   //拒绝访问
};

// 错误状态码 iOS-sdk里面的 NSURLError.h 文件
typedef NS_ENUM (NSInteger, CLNetworkErrorType) {
	AFNetworkErrorType_TimedOut = NSURLErrorTimedOut,                       		//-1001 请求超时
	AFNetworkErrorType_UnURL = NSURLErrorUnsupportedURL,                            //-1002 不支持的url
	AFNetworkErrorType_ConnectFailed = NSURLErrorCannotConnectToHost,               //-1004 未能连接到服务器
	AFNetworkErrorType_NoNetwork = NSURLErrorNotConnectedToInternet,                //-1009 断网
	AFNetworkErrorType_404Failed = NSURLErrorBadServerResponse,                     //-1011 404错误
	AFNetworkErrorType_3840Failed = 3840,                                           //请求或返回不是纯Json格式
};

// 别名
typedef void (^AFSuccessfulBlock)(id responseObject);
typedef void (^AFFailureBlock)(NSError *error);

@interface AFNetworkHandle : NSObject

/** 请求对象实体 */
@property (nonatomic, strong) AFNetwork *afNetwork;
/** 要禁用交互的View */
@property (nonatomic, strong) UIView *containerView;

// MARK : - 发起请求
- (void)requestMethod:(AFRequestMethod)requestMethod
			urlString:(NSString *)urlString
		   parameters:(id _Nullable)parameters
			  success:(AFSuccessfulBlock)success
			  failure:(AFFailureBlock)failure;

- (void)requestMethod:(AFRequestMethod)requestMethod
			urlString:(NSString *)urlString
			  headers:(id _Nullable)headers
		   parameters:(id _Nullable)parameters
			  success:(AFSuccessfulBlock)success
			  failure:(AFFailureBlock)failure;

/**
 全部类型请求方法：上面都会调用

 @param requestMethod 请求方式
 @param urlString 请求地址
 @param headers 请求头
 @param parameters 请求参数
 @param isJsonBody 是否是json表单
 @param success 成功的回调
 @param failure 失败的回调
 */
- (void)requestMethod:(AFRequestMethod)requestMethod
			urlString:(NSString *)urlString
			  headers:(id _Nullable)headers
		   parameters:(id _Nullable)parameters
		   isJsonBody:(BOOL)isJsonBody
			  success:(AFSuccessfulBlock)success
			  failure:(AFFailureBlock)failure;


/**
 文件上传方法

 @param dataArray 文件对象数组
 @param urlString 请求地址
 @param parameters 请求参数
 @param progress 上传进度的回调
 @param success 成功的回调
 @param failure 失败的回调
 */
- (void)uploadFileDataArray:(NSArray<AFfileItem *> *)dataArray
				  urlString:(NSString *_Nullable)urlString
					headers:(id _Nullable)headers
				 parameters:(id _Nullable )parameters
				   progress:(AFProgressBlock)progress
					success:(AFSuccessfulBlock)success
					failure:(AFFailureBlock)failure;

@end

NS_ASSUME_NONNULL_END
