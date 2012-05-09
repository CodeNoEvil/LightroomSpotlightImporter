// Copyright 1997-2010 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSData.h>

@interface NSData (OFFileIO)
- (FILE *)openReadOnlyStandardIOFile:(NSError **)outError;
@end

@interface NSMutableData (OFFileIO)
- (FILE *)openReadWriteStandardIOFile:(NSError **)outError;
@end
