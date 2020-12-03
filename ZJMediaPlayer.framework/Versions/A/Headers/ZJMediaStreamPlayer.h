//
//  ZJMediaStreamPlayer.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/2.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJMeidaEnum.h"
#import "ZJMeidaErrno.h"
#import "ZJMonitor.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJMediaStreamPlayer : NSObject

/// 显示视图
@property (nonatomic,strong) ZJMonitor *monitor;

/// 视频播放配置参数
/// @param config 配置表
- (BOOL)config:(ZJMediaStreamConfig)config;

/// 开始播放器
- (BOOL)start;

/// 开始播放视频
- (BOOL)startVideo;

/// 开始播放音频
- (BOOL)startAudio;

/// 停止播放
- (void)stop;

/// 停止播放视频
- (void)stopVideo;

/// 停止播放音频
- (void)stopAudio;

/// 播放视频数据
/// @param data 数据区
/// @param size 数据大小
/// @param ts 时间戳
- (BOOL)playVideo:(u_char *)data size:(NSUInteger)size timestamp:(NSUInteger)ts;

/// 播放音频数据
/// @param data 数据区
/// @param size 数据大小
/// @param ts 时间戳
- (BOOL)playAudio:(u_char *)data size:(NSUInteger)size timestamp:(NSUInteger)ts;

/// 清除视频缓存队列
- (void)clearVideoBuffer;

/// 清除音频缓存队列
- (void)clearAudioBuffer;

@end

NS_ASSUME_NONNULL_END
