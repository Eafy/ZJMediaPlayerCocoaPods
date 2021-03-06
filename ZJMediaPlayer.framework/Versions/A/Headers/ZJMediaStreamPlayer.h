//
//  ZJMediaStreamPlayer.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/2.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJMediaEnum.h"
#import "ZJMediaErrno.h"
#import "ZJGLMonitor.h"
#import "ZJMediaStatisticalInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZJMediaPlayerDelegate;

@interface ZJMediaStreamPlayer : NSObject

/// 代理
@property (nonatomic,weak) id<ZJMediaPlayerDelegate> _Nullable delegate;
/// OpenGL视图(推荐)
@property (nonatomic,strong) ZJGLMonitor * _Nullable glMonitor;
/// 是否开启硬解码(默认开启，硬解码失败自动切换软解码)
@property (nonatomic,assign) BOOL hwDecodeEnable;
/// 是否静音
@property (nonatomic,assign) BOOL mute;

/// 视频播放配置参数
/// @param config 配置表
- (BOOL)config:(ZJMediaStreamConfig)config;

/// 开始播放器
- (BOOL)start;

/// 停止播放
- (void)stop;

/// 开启视频
- (void)openVideo;

/// 开启音频
- (void)openAudio;

/// 关闭视频
- (void)closeVideo;

/// 关闭音频
- (void)closeAudio;

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

/// 设置播放的缓存队列时间
/// @param cacheTime 最小的缓存时间，默认1秒
/// @param pursueTime 设置追赶时间，默认3秒
- (void)setMediaCacheTime:(NSInteger)cacheTime pursueTime:(NSInteger)pursueTime;

/// 设置降噪级别（0~3），0表示关闭
/// @param nLevel 级别，默认3
- (void)setDenoiseLevel:(NSUInteger)nLevel;

/// 设置是否音视频同步
/// @param sync 是否同步，默认NO
- (void)setMediaSyncMode:(BOOL)sync;

#pragma mark - 录制相关

- (UIImage *_Nullable)snapshot;

/// 开始录制视频
/// @param filePath filePath 保存视频的沙盒路径，必须以.mp4为文件后缀
- (void)startRecord:(NSString *_Nonnull)filePath;

/// 停止视频录制(如视频中断，则会自动停止录像)
- (void)stopRecord;

/// 是否正在录制视频
- (BOOL)isRecording;

/// 获取正在录制视频的时长(毫秒)
- (long)getRecordDuration;

@end

@protocol ZJMediaPlayerDelegate <NSObject>
@optional

/// 视频播放状态
/// @param status 播放状态，JM_MEDIA_PLAY_STATUS，收到调停止接口不会回调
/// @param errCode 错误码，0表示无错误
- (void)didMediaPlayerPlay:(ZJMediaStreamPlayer *_Nonnull)player status:(ZJ_MEDIA_PLAY_STATUS)status errCode:(NSInteger)errCode;

/// 音视频流信息(每秒更新一次，若视频宽高变化则会立即更新)
/// @param player 播放器
/// @param statInfo 统计信息对象
- (void)didMediaPlayerStatisticalInfo:(ZJMediaStreamPlayer *_Nonnull)player statInfo:(ZJMediaStatisticalInfo *)statInfo;

/// 视频录制回调函数
/// @param status 录制状态
/// @param filePath 录制的实际路径
/// @param errCode 错误码，0表示无错误
- (void)didMediaPlayerRecord:(ZJMediaStreamPlayer *_Nonnull)player status:(ZJ_MEDIA_RECORD_STATUS)status path:(NSString *_Nullable)filePath errCode:(NSInteger)errCode;

@end

NS_ASSUME_NONNULL_END
