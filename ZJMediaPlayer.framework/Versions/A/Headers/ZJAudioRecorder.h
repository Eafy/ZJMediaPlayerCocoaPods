//
//  ZJAudioRecorder.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

#define kNumberRecordBuffers    5
#define kBufferDurationSeconds .5

@protocol ZJAudioRecordDelegate;

@interface ZJAudioRecorder : NSObject

@property (nonatomic,weak) id<ZJAudioRecordDelegate> delegate;

/// 初始化音频采集器
/// @param sampleRate 采样率
/// @param channels 通道数
/// @param delegate 输出代理
- (instancetype)initAudioRecorderWithSampleRate:(Float64)sampleRate channels:(UInt32)channels delegate:(id<ZJAudioRecordDelegate>)delegate;

/// 开始采集PCM
/// @param bufferSize PCM输出一包数据的大小
- (BOOL)start:(int)bufferSize;

/// 开始采集AAC
- (BOOL)startAAC;

/// 停止采集
- (void)stop;

@end

@protocol ZJAudioRecordDelegate

/// 接收采集的数据
/// @param codecId 0：PCM，1：AAC
/// @param buff 采集的数据
/// @param length 采集数据的大小
- (void)recvRecordingWithCodecId:(NSInteger)codecId data:(char *)buff length:(NSInteger)length;

@end
