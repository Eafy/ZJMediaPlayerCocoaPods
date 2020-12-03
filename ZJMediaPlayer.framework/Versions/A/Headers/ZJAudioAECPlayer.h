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
#import <ZJBaseUtils/ZJSingleton.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAudioAECPlayer : NSObject
singleton_h();

/// 是否开启回音消除（默认开启）
@property (nonatomic,assign) BOOL aecEnable;
/// 是否开启增益（默认关闭）
@property (nonatomic,assign) BOOL agcEnable;
/// 音量大小(0~100.0,默认100.0)，只有agcEnable开启的状态下才设置有效
@property (nonatomic,assign) CGFloat volume;
/// 数据包输出大小（默认0，表示由系统控制）
@property (nonatomic,assign) UInt32 dataPktSize;
/// 回音消除释放有效
@property (nonatomic,assign,readonly) BOOL isAecValid;

/// 配置采集器音频参数
/// @param sampleRate 采集采样率
/// @param channels 采集通道数
- (void)configCollectWithSampleRate:(Float64)sampleRate channels:(UInt32)channels;

/// 配置播放器器音频参数
/// @param sampleRate 播放采样率
/// @param channels 播放通道数
- (void)configPlayWithSampleRate:(Float64)sampleRate channels:(UInt32)channels;

/// 麦克风采集的PCM数据回调
/// @param outHandler 麦克风采集的数据Buffer
- (void)collectOutputHandler:(void (^ __nullable)(NSData *outData))outHandler;

/// 麦克风采集的PCM转AAC数据回调
/// @param complete AAC数据Buffer
- (void)collectAACOutputHandler:(void (^ __nullable)(NSData *outData))complete;

/// 播放输入的PCM数据源回调
/// @param inHandler 播放输入的数据Buffer
- (void)playIntputHandler:(void (^ __nullable)(NSMutableData *inData))inHandler;

/// 开始采集数据
- (BOOL)startCollect;

/// 停止采集
- (void)stopCollect;

/// 开始播放
- (BOOL)startPlay;

/// 停止播放
- (void)stopPlay;

/// 清除播放缓存数据
- (void)clearPlayBuffer;

@end

NS_ASSUME_NONNULL_END
