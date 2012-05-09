// Copyright 1997-2005, 2011 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSInvocation.h>

@interface NSInvocation (OFExtensions)

+ (NSInvocation *)invocationWithTarget:(id)target action:(SEL)action;

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
- (BOOL)isDefinedByProtocol:(Protocol *)aProtocol;
#endif

@end
