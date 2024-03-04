//
//  ZJAudioRtmpTalker.h
//  ZJMediaPlayer
//
//  Created by sean on 2022/10/31.
//  Copyright © 2022 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJAudioAECPlayer.h"
#import "ZJMediaEnum.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZJAudioRtmpTalkerDelegate;

@interface ZJAudioRtmpTalker : NSObject

@property (nonatomic,weak) id<ZJAudioRtmpTalkerDelegate> _Nullable delegate;

/// 配置采集器及参数
/// - Parameters:
///   - aecPlayer: 播放器/采集器
///   - sampleRate: 采样率
///   - channels: 通道数
- (void)config:(ZJAudioAECPlayer * _Nullable)aecPlayer sampleRate:(NSInteger)sampleRate channels:(NSInteger)channels;

/// 配置推流参数
/// - Parameters:
///   - type: 类型
///   - name: 名称
///   - value: 值
- (void)config:(ZJ_MEDIA_OPT_TYPE)type name:(NSString * _Nullable)name value:(NSString * _Nonnull)value;

/// 开始初始化并推送数据
/// - Parameter url: RTMP地址
- (void)startTalk:(NSString *)url;

/// 停止对讲
- (void)stopTalk;

/// 是否正在对讲
- (BOOL)isTalking;

@end

#pragma mark - ZJAudioRtmpTalkerDelegate

@protocol ZJAudioRtmpTalkerDelegate <NSObject>
@optional

/// 实时视频对讲状态
/// @param status 对讲状态
/// @param errCode 错误码
- (void)didZJAudioRtmpTalkerWithStatus:(ZJ_MEDIA_TALK_STATUS)status errCode:(NSInteger)errCode;

@end

NS_ASSUME_NONNULL_END
