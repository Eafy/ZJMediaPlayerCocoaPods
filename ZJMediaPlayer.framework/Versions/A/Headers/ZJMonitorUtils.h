//
//  ZJMonitorUtils.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/14.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJMonitorUtils : NSObject

/**
 将RGB24数据转化为UIImage

 @param buff RGB24数据
 @param width width
 @param height height
 @return return UIImage
 */
+ (UIImage *)getImageWithCBuff:(u_char *)buff width:(NSInteger)width height:(NSInteger)height;

/**
 将YUV420P转化为RGB24数据
 
 @param y Y数据
 @param u U数据
 @param v V数据
 @param linesize YUV数据线性大小
 @param w 宽度
 @param h 高度
 @param rgb RGB缓存地址
 */
+ (void)getRGB24FromYUV420P:(u_char *)y u:(u_char *)u v:(u_char *)v linesize:(int *)linesize w:(int)w h:(int)h rgb:(u_char *)rgb;

/**
 将RGB24转化为YUV420P数据

 @param rgbBuf RGB数据
 @param width width
 @param height height
 @param yBuf Y缓存地址
 @param uBuf U缓存地址
 @param vBuf V缓存地址
 */
+ (void)getYUV420PFromRGB24:(u_char *)rgbBuf width:(NSInteger)width height:(NSInteger)height y:(u_char *)yBuf u:(u_char *)uBuf v:(u_char *)vBuf;

/**
 RGB24转RGBA
 #返回需要手动释放

 @param rgb24 rgb24
 @param width width
 @param height height
 @return rgba,需要手动释放
 */
+ (char *)rgb24ToRgba:(char *)rgb24 width:(int)width height:(int)height;

/**
 RGBA转RGB24
 #返回需要手动释放

 @param rgba rgba
 @param width width
 @param height height
 @return rgb24,需要手动释放
 */
+ (char *)rgbaToRgb24:(char *)rgba width:(int)width height:(int)height;

#pragma mark -

/// 从CVPixelBufferRef拷贝YUV数据(需要手动释放内存)
/// @param pixelBuffer CVPixelBufferRef，NV12格式
/// @param width 视频宽度
/// @param height 视频高度
+ (u_char *)copyBufferFromNV12PixelBuffer:(CVPixelBufferRef)pixelBuffer width:(size_t *_Nullable)width height:(size_t *_Nullable)height;

/// 从CVPixelBufferRef拷贝YUV数据(需要手动释放内存)
/// @param pixelBuffer CVPixelBufferRef，NV12格式
/// @param y y数据Buffer，需要手动释放
/// @param uv uv数据Buffer，需要手动释放
/// @param width 视频宽度
/// @param height 视频高度
+ (void)copyBufferFromNV12PixelBuffer:(CVPixelBufferRef)pixelBuffer y:(u_char *_Nullable *_Nullable)y uv:(u_char *_Nullable *_Nullable)uv width:(size_t *_Nullable)width height:(size_t *_Nullable)height;

/// 从CVPixelBufferRef拷贝YUV数据(需要手动释放内存)
/// @param pixelBuffer CVPixelBufferRef
/// @param y Y数据Buffer,不需要申请内存，需要用后释放
/// @param u U数据Buffer,不需要申请内存，需要用后释放
/// @param v V数据Buffer,不需要申请内存，需要用后释放
/// @param w 画面宽度
/// @param h 画面高度
+ (BOOL)copyBufferFromYUV420PixelBuffer:(CVPixelBufferRef)pixelBuffer y:(u_char *_Nullable *_Nullable)y u:(u_char * _Nullable *_Nullable)u v:(u_char *_Nullable *_Nullable)v w:(size_t * _Nullable)w h:(size_t * _Nullable)h;

/// 根据NV12数据创建CVPixelBufferRef
/// @param buffer 数据
/// @param w 宽度
/// @param h 高度
+ (CVPixelBufferRef)createPixelBufferRefFromNV12buffer:(u_char *)buffer width:(size_t)w height:(size_t)h;

/// 根据NV12数据创建CVPixelBufferRef
/// @param y y数据
/// @param uv uv数据
/// @param w 宽度
/// @param h 高度
+ (CVPixelBufferRef)createPixelBufferRefFromNV12buffer:(u_char *)y uv:(u_char *)uv width:(size_t)w height:(size_t)h;

/// UIImage转RGB类型的CVPixelBufferRef
/// @param image 图形数据
+ (CVPixelBufferRef)imageToRGBPixelBuffer:(UIImage *)image;

/// UIImage转YUV类型的CVPixelBufferRef
/// @param image 图形数据
+ (CVPixelBufferRef)imageToYUVPixelBuffer:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
