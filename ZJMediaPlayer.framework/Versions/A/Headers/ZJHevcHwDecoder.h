//
//  ZJHevcHwDecoder.h
//  ZJMediaPlayer
//
//  Created by lzj on 2021/5/12.
//  Copyright © 2021 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreImage/CoreImage.h>
#import <VideoToolbox/VideoToolbox.h>
#import <AVFoundation/AVSampleBufferDisplayLayer.h>
#import "ZJH264HwDecoder.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJHevcHwDecoder : ZJH264HwDecoder

/// HEVC视频流解码
/// @param videoData 视频帧数据
/// @param videoSize 视频帧大小
///@return 视图的宽高(width, height)，当为接收为AVSampleBufferDisplayLayer时返回接口是无效的
- (CGSize)decodeHevcVideoData:(uint8_t *)videoData videoSize:(NSInteger)videoSize;

/// 释放解码器
- (void)releaseHwDecoder;

@end

NS_ASSUME_NONNULL_END
