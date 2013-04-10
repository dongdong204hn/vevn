//
//  FGalleryVideoView.h
//  FirstAVPlayer
//  基于AVplayer的视频播放器
//  Created by zhao song on 12-10-31.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AVFoundation/AVPlayer.h"
#import "timeSwitchClass.h"
#import "SevenProgressBar.h"

@protocol FGalleryVideoViewDelegate;

@interface FGalleryVideoView : UIView {
    BOOL _isPlaying; 
    BOOL _isNomal; //标记是否正常模式还是全屏模式
    CGRect initialFrame; //初始播放面板大小
}

@property (nonatomic, retain) UISlider *timeSlider; //播放进度条
@property (nonatomic, retain) SevenProgressBar  *loadProgress;//缓冲进度
@property (nonatomic, retain) NSTimer			*sliderTimer;   //播放时主定时器
@property (nonatomic, retain) NSTimer			*hideTimer; //控制自动隐藏视频控制栏的定时器
@property (nonatomic, retain) UILabel			*totalTimeLabel;    //总时长标签
@property (nonatomic, retain) UILabel			*currentTimeLabel;//当前时间
@property (nonatomic,unsafe_unretained) NSObject <FGalleryVideoViewDelegate> *videoDelegate;    //视频协议实例
@property (nonatomic, retain) UIButton * playbackButton;    //视频播放按钮
@property (nonatomic, retain) UIButton *lanBtn; //切换同步歌词的语言种类 中/英切换
@property (nonatomic, retain) AVPlayer * player;    //播放器
@property (nonatomic, retain) NSMutableArray * timeArray;   //歌词时长数组
@property (nonatomic) BOOL  isPlaying; //标记是否正在播放
@property (nonatomic) BOOL  showPic;//保证视频初始加载好以后跳到0.3秒以显示视频图画
@property (nonatomic) BOOL  notValid;//标志定时器hideTimer当前是否无效
@property (nonatomic) BOOL  isEng;//标志当前显示的歌词是否英文
//@property (nonatomic) BOOL  noTouch;//标志是否可以自动隐藏控制栏
@property (nonatomic) int   playerFlag; //1：联网播放 0：本地播放
@property (nonatomic) NSInteger  hideSec; //记录多少秒后隐藏控制栏
@property (nonatomic) NSInteger sen_num; //标记当前正在播放第几句（从1开始）

//暂未用
- (void)setVideoFillMode:(NSString *)fillMode;


- (void)togglePlayback:(id)sender;
- (void)play;
- (void)pause;

- (void)zeroAfterEnd;

- (void)toggleControls;
- (void)toggleScreenControls;
- (void)showControls:(BOOL)animated;
- (void)hideControls:(BOOL)animated;
- (void)hideSelf:(id)sender;
- (void)showSelf:(id)sender;

- (void) changeSliderFrame;

- (void)enableTimer ;

- (void)disableTimer ;

- (void)playerItemDidReachEnd:(NSNotification *)notification;

@end

@protocol FGalleryVideoViewDelegate

// indicates single touch and allows controller repsond and go toggle fullscreen
- (void)didTapVideoView:(FGalleryVideoView*)videoView;
- (void)playerItemDidReachEnd:(FGalleryVideoView*)videoView;
- (void)playSenID:(NSInteger)senID isEng:(BOOL)isEng;

@end
