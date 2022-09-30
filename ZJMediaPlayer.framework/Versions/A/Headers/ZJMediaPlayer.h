//
//  ZJMediaNetworkPlayer.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/2.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import "ZJGLMonitor.h"
#import "ZJMediaStreamPlayer.h"
#import "ZJAuthManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJMediaPlayer : ZJMediaStreamPlayer

/// 是否侦测完整视频流（默认开启，谨慎关闭，否则可能无法侦测到音视频流）
@property (nonatomic, assign) BOOL sniffAllEnable;
/// 预缓冲时间，默认0，网络视频且具备音频才有效（毫秒）
@property (nonatomic, assign) NSInteger preCacheDuration;

/// 设置播放器可选参数和值
/// @param type 类型
/// @param name 名称，如果为nil，则清除已设置的参数
/// @param value 数值
- (void)config:(ZJ_MEDIA_OPT_TYPE)type name:(NSString * _Nullable)name value:(NSString * _Nonnull)value;

/// 开始播放网络流视频
/// @param url RTMP地址
- (void)start:(NSString * _Nonnull)url;

/// 重新拉流播放
- (BOOL)restart;

/// 暂停播放
- (void)pause;

/// 恢复播放
- (void)resume;

/// 定位（仅本地文件有效）
/// @param msTime 毫秒
- (BOOL)seek:(NSInteger)msTime;

@end

NS_ASSUME_NONNULL_END
