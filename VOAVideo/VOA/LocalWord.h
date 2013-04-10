//
//  LocalWord.h
//  VOAAdvanced
//
//  Created by song zhao on 12-6-29.
//  Copyright (c) 2012年 buaa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "worddatabase.h"
@interface LocalWord : NSObject {
    NSString *_key; //单词
    NSString *_audio; //发音
    NSString *_pron; //音频
    NSString *_def; //词义
}

@property(nonatomic,retain) NSString *key;
@property(nonatomic,retain) NSString *audio;
@property(nonatomic,retain) NSString *pron;
@property(nonatomic,retain) NSString *def;

- (id) initWithKey:(NSString *) _key audio:(NSString *) _audio pron:(NSString *) _pron def:(NSString *) _def ;

+ (NSString *)decodeFromPercentEscapeString: (NSString *) input ;//URL编码转换正常编码

+ (id) findByKey:(NSString *) key ;

@end
