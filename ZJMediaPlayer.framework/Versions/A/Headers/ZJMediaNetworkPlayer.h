//
//  ZJMediaNetworkPlayer.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/2.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import "ZJMediaStreamPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJMediaNetworkPlayer : ZJMediaStreamPlayer

/// 开始播放网络流视频
/// @param url RTMP地址
- (void)start:(NSString *)url;

- (BOOL)restart;

@end

NS_ASSUME_NONNULL_END
