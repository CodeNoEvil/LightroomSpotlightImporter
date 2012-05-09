// Copyright 2001-2008, 2010-2011 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSObject.h>

@class OFEnumNameTable;
@class NSArray, NSDictionary, NSData, NSSet, NSString;

@interface OFPreference : NSObject
{
    NSString         *_key;
    unsigned          _generation;
    id                _value;
    id                _defaultValue;

    id _controller;
    NSString *_controllerKey;
    BOOL _updatingController;
}

// API

+ (OFPreference *) preferenceForKey: (NSString *) key;
+ (OFPreference *) preferenceForKey: (NSString *) key enumeration: (OFEnumNameTable *)enumeration;

+ (NSSet *)registeredKeys;
+ (void)recacheRegisteredKeys;

+ (void)addObserver:(id)anObserver selector:(SEL)aSelector forPreference:(OFPreference *)aPreference;
+ (void)removeObserver:(id)anObserver forPreference:(OFPreference *)aPreference;

+ (id)coerceStringValue:(NSString *)stringValue toTypeOfPropertyListValue:(id)propertyListValue;

- (NSString *) key;
- (OFEnumNameTable *) enumeration;

- (id)controller;
- (NSString *)controllerKey;
- (void)setController:(id)controller key:(NSString *)controllerKey;

- (id) defaultObjectValue;
- (BOOL) hasNonDefaultValue;
- (void) restoreDefaultValue;

- (id)objectValue;
- (NSString *)stringValue;
- (NSArray *)arrayValue;
- (NSDictionary *)dictionaryValue;
- (NSData *)dataValue;
- (int)intValue;
- (NSInteger)integerValue;
- (unsigned int)unsignedIntValue;
- (NSUInteger)unsignedIntegerValue;
- (float)floatValue;
- (double)doubleValue;
- (BOOL)boolValue;
- (NSArray *)stringArrayValue;
- (NSInteger)enumeratedValue;

- (void)setObjectValue:(id)value;
- (void)setStringValue:(NSString *)value;
- (void)setArrayValue:(NSArray *)value;
- (void)setDictionaryValue:(NSDictionary *)value;
- (void)setDataValue:(NSData *)value;
- (void)setIntValue:(int)value;
- (void)setIntegerValue:(NSInteger)value;
- (void)setUnsignedIntValue:(unsigned int)value;
- (void)setUnsignedIntegerValue:(NSUInteger)value;
- (void)setFloatValue:(float)value;
- (void)setDoubleValue:(double)value;
- (void)setBoolValue:(BOOL)value;
- (void)setEnumeratedValue:(NSInteger)value;

@end

// This provides an API that is much like NSUserDefaults but goes through the thread-safe OFPreference layer
@interface OFPreferenceWrapper : NSObject
+ (OFPreferenceWrapper *)sharedPreferenceWrapper;

- (OFPreference *) preferenceForKey: (NSString *) key;

- (id)objectForKey:(NSString *)defaultName;
- (void)setObject:(id)value forKey:(NSString *)defaultName;
- (void)removeObjectForKey:(NSString *)defaultName;
- (NSString *)stringForKey:(NSString *)defaultName;
- (NSArray *)arrayForKey:(NSString *)defaultName;
- (NSDictionary *)dictionaryForKey:(NSString *)defaultName;
- (NSData *)dataForKey:(NSString *)defaultName;
- (NSArray *)stringArrayForKey:(NSString *)defaultName;
- (int)intForKey:(NSString *)defaultName;
- (NSInteger)integerForKey:(NSString *)defaultName;
- (float)floatForKey:(NSString *)defaultName; 
- (double)doubleForKey:(NSString *)defaultName; 
- (BOOL)boolForKey:(NSString *)defaultName;  
- (void)setInt:(int)value forKey:(NSString *)defaultName;
- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName;
- (void)setFloat:(float)value forKey:(NSString *)defaultName;
- (void)setDouble:(double)value forKey:(NSString *)defaultName;
- (void)setBool:(BOOL)value forKey:(NSString *)defaultName;

- (BOOL)synchronize;
- (void)autoSynchronize;
@end
