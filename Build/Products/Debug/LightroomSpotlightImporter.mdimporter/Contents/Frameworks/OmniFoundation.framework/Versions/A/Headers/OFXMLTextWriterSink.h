// Copyright 2009-2010 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <OmniFoundation/OFXMLMaker.h>

/* OFXMLTextWriterSink is a concrete subclass of XMLSink which writes its nodes into a libxml2 'xmlTextWriter'. */
@interface OFXMLTextWriterSink : OFXMLSink
{
    struct _xmlTextWriter *writer;
#ifdef DEBUG
    OFXMLMaker *currentElt;
#endif
}

// API
- initWithTextWriter:(struct _xmlTextWriter *)w freeWhenDone:(BOOL)shouldFree;
- (void)flush;

@end

