#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

static NSString * _Nonnull const kDefaultAlphaVideoFileExtension = @"mp4";

@class TSHAlphaVideoController;

@protocol TSHAlphaVideoDelegate<NSObject>

@optional

- (void)alphaVideoWillPlay:(nonnull TSHAlphaVideoController *)alphaVideo;
- (void)alphaVideoDidPlay:(nonnull TSHAlphaVideoController *)alphaVideo;

- (void)alphaVideo:(nonnull TSHAlphaVideoController *)alphaVideo
didPlayFrameAtTimeInterval:(NSTimeInterval)timeInterval
previousTimeInterval:(NSTimeInterval)previousTimeInterval;

- (BOOL)alphaVideoShouldStop:(nonnull TSHAlphaVideoController *)alphaVideo;
- (void)alphaVideoWillStop:(nonnull TSHAlphaVideoController *)alphaVideo;
- (void)alphaVideoDidStop:(nonnull TSHAlphaVideoController *)alphaVideo;

- (void)memoryWarningStoppedVideo:(nonnull TSHAlphaVideoController *)alphaVideo;

@end

typedef NS_ENUM(NSInteger, TSHAlphaVideoState) {
    TSHAlphaVideoStateStopped = 0,
    TSHAlphaVideoStateLoading,
    TSHAlphaVideoStatePlaying,
    TSHAlphaVideoStatePaused
};

@interface TSHAlphaVideoController : UIViewController<AVPlayerItemOutputPullDelegate>

+ (nullable TSHAlphaVideoController *)videoWithRGBVideoFile:(nullable NSString *)rgbVideoFilename
                                               withDelegate:(nullable id<TSHAlphaVideoDelegate>)delegate;
- (nullable instancetype)initWithRGBVideoFile:(nullable NSString *)rgbVideoFilename
                                 withDelegate:(nullable id<TSHAlphaVideoDelegate>)delegate;

@property (nonatomic, weak, nullable) id<TSHAlphaVideoDelegate> delegate;

@property (nonatomic, assign) BOOL repeats;
@property (nonatomic, assign) BOOL stopInsteadOfPauseWhenViewEntersBackground;
@property (nonatomic, assign) BOOL shouldStopAggressivelyOnMemoryWarning;
@property (nonatomic, assign) BOOL disablesIdleTimerWhilePlaying;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, readonly) TSHAlphaVideoState state;

- (void)play:(void (^_Nullable)())didStart;
- (void)restart:(void (^_Nullable)())didStart;
- (void)stop;
- (void)pause;
- (void)removeGlView;

- (void)seekToTime:(NSTimeInterval)seconds;

// Used to load the video resources in memory, which is useful when you want to
// just load the video and have it ready to play later on without the slight load delay.
// For example, when you are running two videos back-to-back, you can load the second video
// so it is ready to play directly after the first video is finished.
- (void)loadVideo;
- (void)loadVideoWithCompletionBlock:(nullable void (^)(BOOL success))completionBlock;

- (CGSize)videoSize;
- (nullable AVPlayer *)playerForVideoURL;

@end
