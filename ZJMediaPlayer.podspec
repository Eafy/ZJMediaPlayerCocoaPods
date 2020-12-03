Pod::Spec.new do |s|
  s.name         = "ZJMediaPlayer"
  s.version      = "1.0.0"
  s.summary      = "ZJ Meida Player SDK for iOS at CocoaPods."

  s.description  = <<-DESC
	  ZJ Meida Player SDK for iOS at CocoaPods.
                   DESC

  s.homepage     = "https://github.com/Eafy/ZJMediaPlayerCocoaPads"
  s.license      = { :type => "Apache License 2.0" }
  s.author       = { "Eafy" => "lizhijian_21@163.com" }
  s.platform     = :ios, "9.0"
  s.requires_arc = true
  s.libraries = 'c++','z','bz2','iconv'
  s.frameworks = 'CoreMedia','VideoToolbox','AudioToolbox', 'AVFoundation','OpenGLES','GLKit'
  s.dependency 'ZJLog', '~> 1.1.4'
  s.dependency 'ZJBaseUtils', '~> 1.1.0'
  
  s.source       = { :git => "https://github.com/Eafy/ZJMediaPlayerCocoaPods.git", :tag => "v#{s.version}" }
  s.ios.vendored_frameworks = "ZJMediaPlayer.framework"

end

#推送命令
#pod trunk push ZJMediaPlayer.podspec --verbose --allow-warnings --use-libraries
