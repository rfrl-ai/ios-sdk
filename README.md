# RFRL_AI SDK for iOS ![Version](https://img.shields.io/github/v/tag/mmnfst/mnfst_sdk_ios?style=plastic&label=version)

RFRL_AI SDK is a shared library.

It is used to share functionality:
1. Taking picture for refferal creatives.
2. Generating creative by server side.
3. Automatic recognition for prohibited content.
4. Sending creative for handy moderation for quality definitions.

## Requirements

- Swift 5+
- Xcode 14.0+
- iOS 14.0+

## How to integrate

1. To add a package dependency to your Xcode project, select File > Add Packages and enter its repository URL. After that click on "Add package"

<img width="844" alt="Screenshot 2022-04-02 at 18 00 27" src="https://user-images.githubusercontent.com/16333850/161392355-897e8228-f4f8-4faa-9ca4-53e56e1d4e7c.png">

<img width="1095" alt="Screenshot 2022-04-02 at 18 01 45" src="https://user-images.githubusercontent.com/16333850/161392370-7fee393f-3070-4dbe-ac93-ef2cb99c443b.png">

2. Import MNFST_SDK and use client key for initialization

<img width="657" alt="Screenshot 2022-04-02 at 19 28 48" src="https://user-images.githubusercontent.com/16333850/161392389-c456ee32-49d3-4914-b83e-2e1d75427614.png">

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

`buildFlowContext` – returns context for sdk


**MnfstFlowContext :** 

`buildCameraViewController` - creates view controller for taking picture of creatice.

`generateCreative` - generates creative, that will be saved on device.

`performImageRecognition` - starts recognition of creative for prohibited content.

`performCreativeModeration` - starts handy moderation for quality definitions.

