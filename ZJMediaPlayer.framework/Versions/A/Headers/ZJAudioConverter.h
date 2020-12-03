//
//  ZJAudioConverter.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/21.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <ZJBaseUtils/ZJSingleton.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAudioConverter : NSObject
singleton_h();

/// 数据包编码帧数（AAC默认1024，其他默认1）
@property (nonatomic,assign) UInt32 framesPerPacket;
/// 是否使用硬编码（默认开启）
@property (nonatomic,assign) BOOL isUseHardwareEncode;

/// 配置转换器
/// @param dstDesc 输入音频参数
/// @param srcDesc 目标音频参数
- (void)configWithInputDescription:(AudioStreamBasicDescription)dstDesc encodeDescription:(AudioStreamBasicDescription)srcDesc;

/// 配置AAC编码器
/// @param sampleRate AAC采样率（0时使用原始的音频参数）
/// @param channels AAC通道数（0时使用原始的音频参数）
/// @param bitRate AAC比特率（0时使用原始的音频参数）
- (void)configAACWithSsampleRate:(Float64)sampleRate channels:(UInt32)channels bitRate:(UInt32)bitRate;

/// 设置转换器
- (BOOL)setup;

/// 取消转换器
- (void)cancel;

/// 转换器是否有效
- (BOOL)isValid;

/// 接收编码数据
/// @param complete 数据回调
- (void)recvData:(void (^ __nullable)(NSData *outData))complete;

/// 发送需要转换的源数据
/// @param data 数据源
- (void)push:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
