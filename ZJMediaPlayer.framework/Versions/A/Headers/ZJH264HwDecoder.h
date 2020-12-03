//
//  ZJH264HwDecoder.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/12.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <VideoToolbox/VideoToolbox.h>
#import <AVFoundation/AVSampleBufferDisplayLayer.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZJ_H264HWDataType_Image = 0,       //缺省图形，只可显示，无法保存为图片文件
    ZJ_H264HWDataType_Image_Perfect,   //完整图形，可直接保存为图片文件
    ZJ_H264HWDataType_Pixel,           //YUV，Plane通道为3
    ZJ_H264HWDataType_Pixel_Nv12,      //YUV，Plane通道为2
    ZJ_H264HWDataType_Layer,           //仅显示图层
} ZJH264HWDataType;

@protocol ZJH264HwDecoderDelegate <NSObject>

@optional
- (void)didH264HwDecodeInitFailed:(NSInteger)errCode;

- (void)didH264HwDecodeFailedCount:(NSInteger)count;

@end

@interface ZJH264HwDecoder : NSObject

@property (nonatomic,weak) id<ZJH264HwDecoderDelegate> delegate;
@property (nonatomic,assign) ZJH264HWDataType showType;    //显示类型
@property (nonatomic,strong) UIImage *image;            //解码成RGB数据时的IMG
@property (nonatomic,assign) CVPixelBufferRef pixelBuffer;    //解码成YUV420P数据时的解码BUF
@property (nonatomic,strong) AVSampleBufferDisplayLayer *displayLayer;  //显示图层

- (instancetype)init;

/**
 H264视频流解码

 @param videoData 视频帧数据
 @param videoSize 视频帧大小
 @return 视图的宽高(width, height)，当为接收为AVSampleBufferDisplayLayer时返回接口是无效的
 */
- (CGSize)decodeH264VideoData:(uint8_t *)videoData videoSize:(NSInteger)videoSize;

/**
 释放解码器
 */
- (void)releaseHwDecoder;

/**
 视频截图

 @return IMG
 */
- (UIImage *)snapshot;

@end

NS_ASSUME_NONNULL_END
