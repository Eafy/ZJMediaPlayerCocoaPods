//
//  ZJAuthManager.h
//  ZJMediaPlayer
//
//  Created by eafy on 2021/10/11.
//  Copyright © 2021 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAuthManager : NSObject

+ (instancetype _Nonnull)shared;

/// SDK授权Lincese
/// @param key 授权Key
/// @param secret 授权secret
- (BOOL)configWithKey:(NSString * _Nonnull)key secret:(NSString * _Nonnull)secret;

/// 打开DEBUG模式（仅调试调用才生效）
- (void)openDebugMode;

/// 是否认证通过
- (BOOL)isAuthOK;

@end

NS_ASSUME_NONNULL_END
