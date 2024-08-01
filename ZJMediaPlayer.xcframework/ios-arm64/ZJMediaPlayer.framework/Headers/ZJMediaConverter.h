//
//  ZJMediaConverter.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/25.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJMediaEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJMediaConverter : NSObject

/// 是否强制转换
@property (nonatomic, assign) BOOL isForce;
/// 是否正在转换
@property (readonly) BOOL isConverting;

/// 文件转码
/// @param fromFile 原始文件
/// @param toFile 输出文件
- (BOOL)formFile:(NSString *)fromFile toFile:(NSString *)toFile complete:(nullable void (^)(BOOL success, NSString *path))complete;

/// 中断/停止
- (void)stop;

@end

NS_ASSUME_NONNULL_END
