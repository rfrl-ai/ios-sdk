Pod::Spec.new do |spec|
  spec.name         = "RFRL"
  spec.version      = "1.1.10"
  spec.summary      = "RFRL SDK is a shared library for making referal creatives."
  spec.homepage     = "https://rfrl.ai"
  spec.author       = ''
  spec.source       = { :git => 'https://github.com/rfrl-ai/ios-sdk.git', :tag => '1.1.10' }
  spec.vendored_frameworks = 'RFRL_AI_SDK.xcframework'
  spec.ios.deployment_target = '13.0'
end
