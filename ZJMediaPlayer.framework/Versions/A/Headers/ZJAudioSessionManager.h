//
//  ZJAudioSessionManager.h
//  ZJMediaPlayer
//
//  Created by eafy on 2020/10/20.
//  Copyright © 2020 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZJBaseUtils/ZJSingleton.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZJAudioSessionMode) {
    ZJAudioSessionModeOff,
    ZJAudioSessionModeSpeaker,
    ZJAudioSessionModeMicrophone,
};

@interface ZJAudioSessionManager : NSObject
singleton_h();

- (void)openAudio:(ZJAudioSessionMode)mode handler:(void(^_Nullable)(BOOL success))handler;

- (void)closeAudio:(ZJAudioSessionMode)mode;

@end

NS_ASSUME_NONNULL_END
