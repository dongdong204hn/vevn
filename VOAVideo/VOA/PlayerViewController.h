//
//  PlayerViewController.h
//  AEHTS
//
//  Created by zhao song on 12-10-31.
//  Copyright (c) 2012年 zhao song. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VOAView.h"
#import "FGalleryVideoView.h"
#import "UIImageView+WebCache.h"
#import <AVFoundation/AVFoundation.h>
#import "timeSwitchClass.h"
#import "MyUIViewController.h"
#import "GADBannerView.h"
#import "TextScrollView.h"
#import "MyPageControl.h"
#import "MyLabel.h"
#import "DataBaseClass.h"
#import "LyricSynClass.h"
#import "LocalWord.h"
#import "VOAWord.h"
#import "ASIFormDataRequest.h"
#import "DDXML.h"
#import "DDXMLElementAdditions.h"
#import "ShareToCNBox.h"
#import "SVShareTool.h"
#import "LogController.h"
#import "VOADetail.h"
#import "HPGrowingTextView.h"//评论的自动放大的输入框
#import "NSString+URLEncoding.h"
//#import "MBProgressHUD.h"

#define kHourComponent 0
#define kMinComponent 1
#define kSecComponent 2
#define kCommTableHeightPh 60.0
#define kCommTableHeightPa 80.0
#define kIphoneWidth 480.0
#define kIphone5Width 568.0
#define kAddOne 88.0
#define kAddTwo 44.0
#define kAddThree 22.0

@interface PlayerViewController : UIViewController <FGalleryVideoViewDelegate, MyLabelDelegate, ASIHTTPRequestDelegate,UIActionSheetDelegate, MBProgressHUDDelegate,UIPickerViewDelegate,UIPickerViewDataSource,AVAudioSessionDelegate,UIScrollViewDelegate,UITableViewDelegate,UITableViewDataSource,HPGrowingTextViewDelegate>{
    VOAView *voa;
    
//    UIImageView *thumbnailImg;
    
    FGalleryVideoView *videoView;
    
    CGRect initMyscrollFrame;
//    UILabel			*totalTimeLabel;//总时间
//	UILabel			*currentTimeLabel;//当前时间
    
//    UISlider		*timeSlider;
    
//    NSTimer			*sliderTimer;
    
    BOOL _isPlaying;
    
    BOOL _isFullscreen;
    
    BOOL newFile;
    
//    BOOL timerInValid;
    
    NSString *caption;
    
    NSInteger contentMode;
    
    UIButton *pre;
    
    UIButton *aft;
    
    
}
//@property (nonatomic, retain) IBOutlet UISlider		*timeSlider;

//@property (nonatomic, retain) IBOutlet UILabel			*totalTimeLabel;
//@property (nonatomic, retain) IBOutlet UILabel			*currentTimeLabel;//当前时间
@property (nonatomic, retain) IBOutlet UIButton *pre;   //未使用
@property (nonatomic, retain) IBOutlet UIButton *aft;   //未使用
@property (nonatomic, retain) IBOutlet UIImageView *RoundBack;  //播放页面标记版块的图片
@property (nonatomic, retain) IBOutlet UIView *fixTimeView; //设置定时播放的视图
@property (nonatomic, retain) IBOutlet UIPickerView *myPick;    //设置定时
@property (nonatomic, retain) IBOutlet UIButton  *fixButton;    //开启定时按钮
@property (nonatomic, retain) IBOutlet UIButton *btnOne;    //播放页四个版块按钮
@property (nonatomic, retain) IBOutlet UIButton *btnTwo;
@property (nonatomic, retain) IBOutlet UIButton *btnThree;
@property (nonatomic, retain) IBOutlet UIButton *btnFour;
@property (nonatomic, retain) IBOutlet UIButton  *displayModeBtn;   //显示播放模式的按钮
@property (nonatomic, retain) IBOutlet TextScrollView	*myScroll;  //歌词滚动文本
@property (nonatomic, retain) IBOutlet UITextView *titleWords;  //新闻标题文本框
@property (nonatomic, retain) IBOutlet MyPageControl *pageControl;  //页面控制组件
@property (nonatomic, retain) IBOutlet UIView *titleView;   //顶栏
@property (nonatomic, retain) IBOutlet UIView *btnView; //底栏

@property (nonatomic, retain) UIAlertView *alert;   
@property (nonatomic, retain) UITableView *commTableView;   //评论表视图
@property (nonatomic, retain) UIView *containerView;  //包含评论输入框的栏
@property (nonatomic, retain) UIView *myView;   //评论页
@property (nonatomic, retain) HPGrowingTextView *textView;  //评论输入框
@property (nonatomic, retain) VOAView *voa;
@property (nonatomic, retain) UITextView *imgWords;//文章简介
@property (nonatomic, retain) TextScrollView	*textScroll;//显示文章内容
@property (nonatomic, retain) TextScrollView	*commScroll;
@property (nonatomic, retain) UIImageView     *myImageView;//显示图片
@property (nonatomic, retain) UIButton * playbackButton;
@property (nonatomic, retain) UIButton    *modeBtn;//播放模式按钮
@property (nonatomic, retain) UIButton      *downloadFlg;//已下载
@property (nonatomic, retain) UIButton      *downloadingFlg;//下载中
@property (nonatomic, retain) UIButton		*collectButton;//下载按钮
@property (nonatomic, retain) UIButton        *clockButton;//定时按钮
//@property (nonatomic, retain) UIButton		*shareSenBtn;//下载按钮

@property (nonatomic, retain) UILabel     *myHighLightWord;  //标记屏幕所取单词的标签

@property (nonatomic, retain) MyLabel *explainView; //展示取词翻译页面的标签
@property (nonatomic, retain) MyLabel *senLabel;    //显示同步歌词的标签

@property (nonatomic, retain) NSArray         *hoursArray;  
@property (nonatomic, retain) NSArray         *minsArray;
@property (nonatomic, retain) NSArray         *secsArray;

@property (nonatomic, retain) NSMutableArray	*lyricArray;
@property (nonatomic, retain) NSMutableArray	*lyricCnArray;
@property (nonatomic, retain) NSMutableArray	*timeArray;
@property (nonatomic, retain) NSMutableArray	*indexArray;
@property (nonatomic, retain) NSMutableArray	*lyricLabelArray;
@property (nonatomic, retain) NSMutableArray	*lyricCnLabelArray;
@property (nonatomic, retain) NSMutableArray    *listArray;//播放列表
@property (nonatomic, retain) NSMutableArray    *commArray;

@property (nonatomic, retain) FGalleryVideoView *videoView; //视频播放界面实例
@property (nonatomic, retain) GADBannerView *bannerView;    //广告条
@property (nonatomic, retain) MBProgressHUD *HUD;

@property (nonatomic, retain) VOAWord *myWord;  //屏幕取词取到的单词
@property (nonatomic, retain) AVPlayer	*wordPlayer;    //播放单词发音
@property (nonatomic, retain) UIImageView *senImage;    //单击句子时屏幕截取的句子图片

@property (nonatomic, retain) NSTimer         *fixTimer;    //定时播放的定时器

@property (nonatomic, retain) NSString *userPath;   //当前播放视频文件的本地路径

@property (nonatomic) BOOL newFile; //标记是否是播放新的一篇新闻
@property (nonatomic) BOOL isFree;  //标记是否免费
@property (nonatomic) BOOL isiPhone;
@property (nonatomic) BOOL needFlushAdv;    //标记是否还需要刷新广告栏
//@property (nonatomic) BOOL isExisitNet;
@property (nonatomic) BOOL flushList;   //标记是否需要刷新播放列表
@property (nonatomic) BOOL localFileExist;  //标记当前播放的视频在本地是否存在
@property (nonatomic) BOOL downloaded;  //标记是否刚刚下载，是的话点击播放自动切换到本地视频播放(暂未做)
@property (nonatomic) BOOL isFixing;    //标记是否正在定时播放中
@property (nonatomic) BOOL isNewComm;   //标记是否刚发表了新评论
@property (nonatomic) BOOL keyboardFlg; //
@property (nonatomic) BOOL isFive;  //标记是狗iphone5

@property (nonatomic) NSInteger contentMode;    //1：在线播放 2：本地播放
@property (nonatomic) NSInteger nowUserId;  //当前用户id    
@property (nonatomic) NSInteger playMode;   //三种播放循环模式
@property (nonatomic) NSInteger playIndex;//当前播放位置
@property (nonatomic) NSInteger nowPage;    //当前取到的评论页数
@property (nonatomic) NSInteger totalPage;  //评论总页数
@property (nonatomic) NSInteger commCellNum;    //当前评论表示图中评论数
@property (nonatomic) NSInteger category;   //新闻类别  
//@property (nonatomic) int		engLines;   //
//@property (nonatomic) int		cnLines;
@property (nonatomic) int       fixSeconds; //定时播放秒数




//@property (nonatomic, retain) AVPlayer * player;
void audioRouteChangeListenerCallback ( void     *inUserData,
                                       AudioSessionPropertyID    inPropertyID,
                                       UInt32                    inPropertyValueSize,
                                       const void                *inPropertyValue );

+ (PlayerViewController *)sharedPlayer ;

- (void) toggleFullScreen;

@end
