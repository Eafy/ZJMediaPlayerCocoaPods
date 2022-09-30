//
//  ZJAudioPCMPlayer.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/17.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAudioPCMPlayer : NSObject

/**
 初始化PCM音频播放器,默认已启动播放

 @param sampleRate 采样率
 @param channels 通道数
 @return obj
 */
- (instancetype)initWithSampleRate:(Float64)sampleRate channels:(UInt32)channels;

/**
 开始播放

 @return YES:已启动
 */
- (BOOL)start;

/**
 停止播放并释放资源
 */
- (void)stop;

/**
 填入需要播放的PCM音频数据

 @param data PCM数据
 @param length PCM音频数据长度
 @return 实际读取PCM数据的长度
 */
- (NSInteger)play:(const char *)data length:(NSInteger)length;

/**
 填入需要播放的PCM采样数据

 @param sampleBuffer 采样Buffer
 @return 实际读取PCM数据的长度
 */
- (NSInteger)play:(CMSampleBufferRef)sampleBuffer;

- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
