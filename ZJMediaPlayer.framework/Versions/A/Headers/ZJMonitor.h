//
//  ZJMonitor.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/14.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJMonitor : UIImageView

/// 显示图片
/// @param image UIImage
- (void)displayImage:(UIImage *)image;

/// 加载RGB24画面数据
/// @param rgbData rgb24数据
/// @param width 宽
/// @param height 高
- (void)displayRgb24Data:(const u_char *)rgbData videoWidth:(NSInteger)width videoHeight:(NSInteger)height;

/// 加载YUV420（NV12）数据
/// @param y y数据
/// @param uv uv数据
/// @param w 宽度
/// @param h 高度
- (void)displayYuv420Data:(u_char *)y uv:(u_char *)uv w:(NSInteger)w h:(NSInteger)h;

@end

NS_ASSUME_NONNULL_END
