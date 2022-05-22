//
//  ZJAudioTool.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/27.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAudioTool : NSObject

/// 获取ADTS头数据
/// @param adtsHead ADTS头数组，默认长度7
/// @param packetLen 源数据包长度
/// @param profileType Main:1,LC:2,SSR:3,LTP:4,SBR:5
/// @param sampleRate 采样率
/// @param channels 通道数
+ (void)addADTSForAAC:(char *)adtsHead packetLen:(int)packetLen profileType:(int)profileType sampleRate:(int)sampleRate channels:(int)channels;

/// 计算实际的音频大小和分贝数
/// @param data PCM音频数据
/// @param size 数据大小
///  @return Size(声音大小，分贝数)
+ (CGSize)calculateRealVolume:(const char *)data size:(int)size;

@end

NS_ASSUME_NONNULL_END
