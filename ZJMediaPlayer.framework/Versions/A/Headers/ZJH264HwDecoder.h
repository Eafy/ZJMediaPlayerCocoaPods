//
//  ZJH264HwDecoder.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/12.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreImage/CoreImage.h>
#import <VideoToolbox/VideoToolbox.h>
#import <AVFoundation/AVSampleBufferDisplayLayer.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZJHWDataShowType_Pixel,           //YUV，Plane通道为3
    ZJHWDataShowType_Pixel_Nv12,      //YUV，Plane通道为2
    ZJHWDataShowType_Image,           //UIImage图形
    ZJHWDataShowType_Layer,           //仅显示图层
} ZJHWDataShowType;

@protocol ZJH264HwDecoderDelegate <NSObject>

@optional
- (void)didH264HwDecodeInitFailed:(NSInteger)errCode;

- (void)didH264HwDecodeFailedCount:(NSInteger)count;

@end

@interface ZJH264HwDecoder : NSObject

@property (nonatomic,weak) id<ZJH264HwDecoderDelegate> delegate;
@property (nonatomic,assign) ZJHWDataShowType showType;    //显示类型
/// 解码失败最大次数，默认3次
@property (nonatomic,assign) NSInteger decodeMaxFailCount;
/// 设置是否在后台，后台则不会解码
@property (readonly) BOOL isBackground;

@property (nonatomic,strong) UIImage * _Nullable image;            //解码成RGB数据时的IMG
@property (nonatomic,assign) CVPixelBufferRef _Nullable pixelBuffer;    //解码成YUV420P数据时的解码BUF
@property (nonatomic,strong) AVSampleBufferDisplayLayer * _Nullable displayLayer;  //显示图层

- (instancetype)init;

/// H264视频流解码
/// @param videoData 视频帧数据
/// @param videoSize 视频帧大小
/// @return 视图的宽高(width, height)，当为接收为AVSampleBufferDisplayLayer时返回接口是无效的
- (CGSize)decodeH264VideoData:(uint8_t *)videoData videoSize:(NSInteger)videoSize;

/// 移除解码器
- (void)removeHwDecoder;
///  释放解码器
- (void)releaseHwDecoder;

/// 根据CVPixelBufferRef获取UIImage（可保存为文件）
/// @param pixelBuffer CVPixelBufferRef
- (UIImage *)pixelBufferToPerfectImage:(CVPixelBufferRef)pixelBuffer;

/// 视频截图
- (UIImage *)snapshot;

@end

NS_ASSUME_NONNULL_END
