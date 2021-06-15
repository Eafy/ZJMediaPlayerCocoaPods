//
//  ZJMediaConverter.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/25.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZJMediaEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZJMediaConverter : NSObject

/// 是否为AAC添加ADTS头
@property (nonatomic,assign) BOOL addADTSEnable;

/// 接收编码的数据
/// @param complete 回调
- (void)recvData:(void (^ __nullable)(uint8_t *data, int size))complete;

/// 配置转码参数
/// @param inType 编码前帧类型
/// @param inSampleRate 采样率
/// @param inChannels 通道数
/// @param inBitrate 比特率
/// @param outType 编码后帧类型
/// @param outSampleRate 采样率
/// @param outChannels 通道数
/// @param outBitrate 比特率
- (BOOL)configAudioWithInType:(ZJ_MEDIA_TYPE)inType inSampleRate:(UInt32)inSampleRate inChannels:(UInt32)inChannels inBitrate:(UInt32)inBitrate outType:(ZJ_MEDIA_TYPE)outType outSampleRate:(UInt32)outSampleRate outChannels:(UInt32)outChannels outBitrate:(UInt32)outBitrate;

/// 发送编码前音频数据
/// @param data 数据源
/// @param size 数据大小
- (void)sendAudio:(uint8_t *)data size:(uint32_t)size;

@end

NS_ASSUME_NONNULL_END
