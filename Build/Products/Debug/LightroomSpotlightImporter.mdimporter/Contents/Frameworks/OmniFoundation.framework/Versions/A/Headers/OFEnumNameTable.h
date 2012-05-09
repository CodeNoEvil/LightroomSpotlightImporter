// Copyright 2002-2008, 2010, 2012 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFArray.h>

@interface OFEnumNameTable : NSObject
{
@private
    NSInteger _defaultEnumValue;
    CFMutableArrayRef _enumOrder;
    CFMutableDictionaryRef _enumToName;
    CFMutableDictionaryRef _enumToDisplayName;
    CFMutableDictionaryRef _nameToEnum;
}

- initWithDefaultEnumValue:(NSInteger)defaultEnumValue;
- (NSInteger)defaultEnumValue;

- (void)setName:(NSString *)enumName forEnumValue:(NSInteger)enumValue;
- (void)setName:(NSString *)enumName displayName:(NSString *)displayName forEnumValue:(NSInteger)enumValue;

- (NSString *)nameForEnum:(NSInteger)enumValue;
- (NSString *)displayNameForEnum:(NSInteger)enumValue;
- (NSInteger)enumForName:(NSString *)name;
- (BOOL)isEnumValue:(NSInteger)enumValue;
- (BOOL)isEnumName:(NSString *)name;

- (NSUInteger)count;
- (NSInteger)enumForIndex:(NSUInteger)enumIndex;
- (NSInteger)nextEnum:(NSInteger)enumValue;
- (NSString *)nextName:(NSString *)name;

// Comparison
- (BOOL)isEqual:(id)anotherEnumeration;

// Masks

@end
