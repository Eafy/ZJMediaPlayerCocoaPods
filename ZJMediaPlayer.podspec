Pod::Spec.new do |s|
  s.name         = "ZJMediaPlayer"
  s.version      = "1.4.0"
  s.summary      = "ZJ Meida Player SDK for iOS at CocoaPods."
  s.description  = "ZJ Meida Player SDK for iOS at CocoaPods，Supported H.264、Hevc、AAC and other formats."

  s.homepage     = "https://github.com/Eafy/ZJMediaPlayerCocoaPads"
  s.license      = { :type => "Apache License 2.0" }
  s.author       = { "Eafy" => "lizhijian_21@163.com" }
  s.platform     = :ios, "9.0"
  s.requires_arc = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  s.libraries = 'c++','z','bz2','iconv'
  s.frameworks = 'CoreMedia','VideoToolbox','AudioToolbox', 'AVFoundation','OpenGLES','GLKit'
  s.dependency 'ZJLog'
  
  s.source       = { :git => "https://github.com/Eafy/ZJMediaPlayerCocoaPods.git", :tag => "v#{s.version}" }
  s.ios.vendored_frameworks = "ZJMediaPlayer.framework"
  s.vendored_libraries = 'ZJMediaPlayer.framework/**/*.a'

end

#推送命令
#pod trunk push ZJMediaPlayer.podspec --verbose --allow-warnings --use-libraries
