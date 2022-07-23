//
//  VideoCacheHelper.h
//  RFRL
//
//  Created by Eugene Zabolotniy on 12/04/2018.
//  Copyright © 2018 RFRL. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VideoCacheHelper : NSObject

+ (NSString *)cachedFileNameForKey:(NSString *)key;
    
@end



@interface NSURL (StripQuery)
    
    /*
     * Returns absolute string of URL with the query stripped out.
     * If there is no query, returns a copy of absolute string.
     */
    
- (NSString *)absoluteStringByStrippingQuery;
    
@end
