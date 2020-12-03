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

@end

NS_ASSUME_NONNULL_END
