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
 @param para YUV数据参数(0:width,1:height,2~4:linesize)
 @param rgb RGB缓存地址
 */
+ (void)getRGB24FromYUV420P:(u_char *)y u:(u_char *)u v:(u_char *)v para:(int *)para rgb:(u_char *)rgb;

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


@end

NS_ASSUME_NONNULL_END
