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
#import "ZJAudioAECPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZJMediaPlayerDelegate;

@interface ZJMediaStreamPlayer : NSObject

/// 代理
@property (nonatomic,weak) id<ZJMediaPlayerDelegate> _Nullable delegate;
/// OpenGL视图(推荐)
@property (nonatomic,strong) ZJGLMonitor * _Nullable glMonitor;
/// 音频播放及采集器
@property (readonly) ZJAudioAECPlayer *audioAECPlayer;
/// 是否开启硬解码(默认开启，硬解码失败自动切换软解码)
@property (nonatomic,assign) BOOL hwDecodeEnable;
/// 是否静音
@property (nonatomic,assign) BOOL mute;

/// 用户传递的附带信息
@property (nonatomic,strong) id userInfo;
/// 播放地址（可能为空）
@property (nonatomic,copy) NSString *url;
/// 是否获取SEI信息，0：不获取，1：用户数据，2：内部私有信息(使用statisticalInfo信息)
@property (nonatomic,assign) NSInteger seiInfoType;

/// 视频播放配置参数
/// @param config 配置表
- (BOOL)config:(ZJMediaStreamConfig)config;

/// 开始播放器
- (BOOL)start;

/// 停止播放
- (void)stop;

/// 打开视频
- (void)openVideo;

/// 打开音频
- (void)openAudio;

/// 关闭视频
- (void)closeVideo;

/// 关闭音频
- (void)closeAudio;

/// 播放视频数据
/// @param data 数据区
/// @param size 数据大小
/// @param ts 时间戳(毫秒)
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
/// @param isLoadMode 是否启动缓冲模式（支持预缓存的功能，加载缓存时间为cacheTime）
/// @param cacheTime 最小的缓存时间，默认1秒
/// @param pursueTime 设置追赶时间，默认3秒（启动缓冲模式，则会失效）
- (void)setMediaLoadMode:(BOOL)isLoadMode cacheTime:(CGFloat)cacheTime pursueTime:(CGFloat)pursueTime;

/// 设置降噪级别（0~3，0表示关闭）及音频大小增益
/// @param nLevel 级别，默认0
/// @param gainVolume 增益音量（-50~50），0xFFFF表示关闭，1表示原声音，0表示静音
- (void)setDenoiseLevel:(NSUInteger)nLevel gainVolume:(CGFloat)gainVolume;

/// 设置是否音视频同步
/// @param sync 是否同步，默认YES
- (void)setMediaSyncMode:(BOOL)sync;

/// 通话是否开启免提模式（设置1次只生效1次）
/// @param isCallSpeaker @(YES)：扬声器
- (void)setIsCallSpeaker:(NSNumber * _Nullable)isCallSpeaker;

/// 设置音视频延迟播放时间(仅同步模式有效)
/// @param vDelay 视频延迟时间，默认50
/// @param aDelay 音频延迟时间，默认0
- (void)setSyncDelayTime:(NSInteger)vDelay aDelay:(NSInteger)aDelay;

#pragma mark - 录制相关

/// 开始录制视频（支持MP4、FLV、AMR）
/// @param filePath filePath 保存视频的沙盒路径，必须以.mp4为文件后缀
- (void)startRecord:(NSString *_Nonnull)filePath;

/// 停止视频录制(如视频中断，则会自动停止录像)
- (void)stopRecord;

/// 是否正在录制视频
- (BOOL)isRecording;

/// 获取正在录制视频的时长(毫秒)
- (long)getRecordDuration;

/// 录制采集的音视频数据
/// @param filePath 文件路径
- (void)startRecordCollect:(NSString *_Nonnull)filePath;

@end

@protocol ZJMediaPlayerDelegate <NSObject>
@optional

/// 视频播放状态
/// @param player  播放器
/// @param status 播放状态，JM_MEDIA_PLAY_STATUS，收到调停止接口不会回调
/// @param errCode 错误码，0表示无错误
- (void)didMediaPlayerPlay:(ZJMediaStreamPlayer *_Nonnull)player status:(ZJ_MEDIA_PLAY_STATUS)status errCode:(NSInteger)errCode;

/// 音视频流信息(每秒更新一次，若视频宽高变化则会立即更新)
/// @param player 播放器
/// @param statInfo 统计信息对象
- (void)didMediaPlayerStatisticalInfo:(ZJMediaStreamPlayer *_Nonnull)player statInfo:(ZJMediaStatisticalInfo *)statInfo;

/// 视频录制回调函数
/// @param player 播放器
/// @param status 录制状态
/// @param filePath 录制的实际路径
/// @param errCode 错误码，0表示无错误
- (void)didMediaPlayerRecord:(ZJMediaStreamPlayer *_Nonnull)player status:(ZJ_MEDIA_RECORD_STATUS)status filePath:(NSString *_Nullable)filePath errCode:(NSInteger)errCode;

/// 处理YUV420P数据（若继续内部处理，不允许修改画面宽高）
/// @param player 播放器
/// @param yData Y数据
/// @param uData U数据
/// @param vData V数据
/// @param width 宽度
/// @param height 高度
/// @return YES：内部继续处理，NO：内部不再处理
- (BOOL)didMediaPlayerHandleVideoData:(ZJMediaStreamPlayer *_Nonnull)player dataY:(char *)yData dataU:(char *)uData dataV:(char *)vData width:(NSInteger)width height:(NSInteger)height;

/// 处理PCM数据
/// @param player 播放器
/// @param pcmData PCM数据
/// @param size PCM数据长度地址
/// @return YES：内部继续处理，NO：内部不再处理
- (BOOL)didMediaPlayerHandleAudioData:(ZJMediaStreamPlayer *_Nonnull)player data:(char *)pcmData size:(NSInteger *)size sampleRate:(NSInteger)sampleRate channels:(NSInteger)channels;

/// 获取SEI信息
/// @param player 播放器
/// @param data SEI数据
/// @param size SEI大小
- (void)didMediaPlayerRecvSeiInfo:(ZJMediaStreamPlayer *_Nonnull)player data:(uint8_t *)data size:(NSInteger)size;

@end

NS_ASSUME_NONNULL_END
