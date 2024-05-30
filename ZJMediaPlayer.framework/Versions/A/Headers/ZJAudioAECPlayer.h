//
//  ZJAudioAECPlayer.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/19.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAudioAECPlayer : NSObject

+ (instancetype _Nonnull)shared;

/// 是否开启回音消除（默认关闭，中途开启无效）
@property (nonatomic,assign) BOOL aecEnable;
/// 设置增益效果数值（默认0）
@property (nonatomic,assign) Float32 agcValue;
/// PCM数据包输出大小（默认0，表示由系统控制）
@property (nonatomic,assign) UInt32 dataPktSize;
/// 回音消除是否有效
@property (nonatomic,assign,readonly) BOOL isAecValid;
/// 关闭自动的AudioSessionCategory处理（默认false）
@property (nonatomic,assign) BOOL isCloseAutoCategory;
/// 播放模式是否跟随系统静音，默认不开启
@property (nonatomic,assign) BOOL isSoloAmbient;
/// 通话是否开启免提模式（设置1次只生效1次， -1：不启动，0：不开启，1：开启
@property (nonatomic,assign) NSInteger callSpeakerMode;
/// 输出音量大小[0~100]，默认-1，表示不设置
@property (nonatomic,assign) CGFloat volume;

@property (readonly) AudioStreamBasicDescription playDescription;
@property (readonly) AudioStreamBasicDescription collectDescription;

/// 配置采集信息
/// @param sampleRate 采样率
/// @param channels 通道数
- (void)configCollectWithSampleRate:(Float64)sampleRate channels:(UInt32)channels;

/// 配置播放信息
/// @param sampleRate 采样率
/// @param channels 通道数
- (void)configPlayWithSampleRate:(Float64)sampleRate channels:(UInt32)channels;

/// 麦克风采集的PCM数据回调
/// @param outHandler 麦克风采集的数据Buffer
- (void)collectOutputHandler:(void (^ __nullable)(NSData *outData))outHandler;

/// 麦克风采集的PCM转AAC数据回调
/// @param outHandler AAC数据Buffer
- (void)collectAACOutputHandler:(void (^ __nullable)(NSData *outData))outHandler;

/// 播放输入的PCM数据源回调
/// @param inHandler 播放输入的数据Buffer
- (void)playIntputHandler:(void (^ __nullable)(NSMutableData *inData))inHandler;

/// 开始播放或采集（若停止过，每次启动都需要重新配置信息参数）
- (void)start:(void(^_Nullable)(BOOL success))handler;

/// 停止采集
- (void)stopCollect;

/// 是否正在采集
- (BOOL)isCollecting;

/// 停止播放
- (void)stopPlay;

/// 是否正在播放
- (BOOL)isPlaying;

/// 清除播放缓存数据
- (void)clearPlayBuffer;

/// 播放音频数据
/// - Parameters:
///   - buf: 数据源
///   - size: 大小
- (BOOL)play:(NSData *)data;

/// 设置声音音量大小增益及降噪级别
/// - Parameters:
///   - gainVolume: 大小增益[-50,50]，0：关闭
///   - denoiseLevel: 降噪级别[-1,3]，-1：关闭
- (void)setGainVolume:(CGFloat)gainVolume denoiseLevel:(NSInteger)denoiseLevel;

@end

NS_ASSUME_NONNULL_END
