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
