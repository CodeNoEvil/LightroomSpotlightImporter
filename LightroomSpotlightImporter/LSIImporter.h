//
//  MySpotlightImporter.h
//  LightroomSpotlightImporter
//
//  Created by David Bitton on 5/1/12.
//  Copyright (c) 2012 Code No Evil LLC All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface LSIImporter : NSObject

- (BOOL)importFileAtPath:(NSString *)filePath attributes:(NSMutableDictionary *)attributes error:(NSError **)error;

@end
