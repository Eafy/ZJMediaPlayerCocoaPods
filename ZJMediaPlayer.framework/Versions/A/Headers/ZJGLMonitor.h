//
//  ZJGLMonitor.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/14.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <UIKit/UIImage.h>
#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

/// ZJGLMonitor视图对模拟器不友好，最好使用真机调试
@interface ZJGLMonitor : UIView

/// 获取截屏或设置图片
@property (nonatomic,strong) UIImage *image;

/// 加载CVPixelBufferRef类型的画面
/// @param pixelBuffer CVPixelBufferRef
- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer;

/// 加载YUV420P数据画面
/// @param yData Y数据
/// @param uData U数据
/// @param vData V数据
/// @param width 宽度
/// @param height 高度
- (void)displayYUVData:(const unsigned char*)yData uData:(const unsigned char*)uData vData:(const unsigned char*)vData width:(int)width height:(int)height;

@end

NS_ASSUME_NONNULL_END
