# MNFST SDK for iOS ![Version](https://img.shields.io/github/v/tag/mmnfst/mnfst_sdk_ios?style=plastic&label=version)

MNFST SDK is a shared library.

It is used to share functionality:
1. Taking picture for refferal creatives.
2. Generating creative by server side.
3. Automatic recognition for prohibited content.
4. Sending creative for handy moderation for quality definitions.

## Requirements

- Swift 5+
- Xcode 13.0+
- iOS 12.0+

## How to integrate

1. To add a package dependency to your Xcode project, select File > Add Packages and enter its repository URL. After that click on "Add package"

<img width="798" alt="Screenshot 2022-02-22 at 12 45 57" src="https://user-images.githubusercontent.com/16333850/155127520-93dd13f1-1171-4713-859a-3d56d07a6561.png">

<img width="1097" alt="Screenshot 2022-02-22 at 14 56 39" src="https://user-images.githubusercontent.com/16333850/155127875-129ac4d4-2f90-4539-aaaa-8d866579548b.png">

2. Import MNFST_SDK and use client key for initialization

<img width="746" alt="Screenshot 2022-02-22 at 15 00 12" src="https://user-images.githubusercontent.com/16333850/155128176-5613a7a7-1d7c-4392-9a7e-8dfa2d2d0a2c.png">

## ⚠️⚠️⚠️ **WARNING** ⚠️⚠️⚠️
You need to add `NSCameraUsageDescription`, `NSPhotoLibraryUsageDescription` keys in `Info.plist` of your project, because we use camera and photo library for working our sdk, otherwise will be crash.

## Creative requirements
### Story

| Option    | Value |
|-----|-----|
| Image/Video resoluton (front/back) | 1080х1920px |
| Image format | PNG |
| Video duration (MOV format with alpha channel) | 7 seconds |
| Safe zone | 820х1920px |
| Max MOV file size | 150Mb |
| Max MP4 file size | 1,5Mb |
| Framerate | 30fps |

### Feed

| Option    | Value |
|-----|-----|
| Image/Video resoluton (front/back) |  1080х1080px |
| Image format | PNG |
| Video duration (MOV format with alpha channel) | 7 seconds |
| Safe zone | 820х1920px |
| Max MOV file size | 150Mb |
| Max MP4 file size | 1,5Mb |
| Framerate | 30fps |

### Public interface 

**MnfstSdkManager :** 

buildFlowContext - this method return context for sdk


**MnfstFlowContext :** 

buildCameraViewController - create view controller for taking picture of creatice.

generateCreative - generate creative, that will be saved on device.

performImageRecognition - start recognition of creative for prohibited content.

performCreativeModeration - start handy moderation for quality definitions.

