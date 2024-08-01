//
//  FFMediaConverter.hpp
//  ZJMediaPlayer
//
//  Created by eafy on 2023/10/21.
//  Copyright © 2023 ZJ<lizhijian_21@163.com>. All rights reserved.
//

#ifndef FFMediaConverter_hpp
#define FFMediaConverter_hpp

#include <stdio.h>
#include <string>
#include "CDefType.hpp"
#include "FFMediaRecorder.hpp"
#include "FFMediaReader.hpp"

ZJ_NAMESPACE_FFMPEG_BEGIN

class FFMediaConverter: public FFMediaRecorder, FFMediaReader {
public:
    FFMediaConverter(void *pUserData = nullptr);
    ~FFMediaConverter();
    
    /// 设置路径
    /// - Parameters:
    ///   - inPath: 文件输入路径
    ///   - outPath: 输出文件路径
    void SetPath(std::string inPath, std::string outPath) {
        m_sInPath = inPath;
        m_sOutPath = outPath;
    }
    
    /// 是否强转
    /// - Parameter isForce: 是否强制转码
    void SetForce(bool isForce) {
        m_bForce = isForce;
    }
    
    /// 开始转码
    int Start(std::function<void(void *pUserData, bool success, std::string path)> cb);
    
    /// 主动停止
    void Stop();
    
private:
    static void didReadMediaThread(void *arg);
    void StartReadMediaThread();
    void StopReadMediaThread();
    
private:
    void *m_pUserData = nullptr;
    std::string m_sInPath = "";
    std::string m_sOutPath = "";
    bool m_bForce = false;
    
    std::function<void(void *pUserData, bool success, std::string path)> m_pCB = nullptr;
    CThread *m_pReadMediaThread = nullptr;
};


ZJ_NAMESPACE_FFMPEG_END
#endif /* FFMediaConverter_hpp */
