// Copyright 2003-2005, 2007-2008, 2010, 2012 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSObject.h>

@class NSArray;
@class OFXMLDocument, OFXMLElement;

@interface OFXMLCursor : NSObject
{
    OFXMLDocument *_document;
    OFXMLElement *_startingElement;
    struct _OFXMLCursorState *_state;
    unsigned int _stateCount;
    unsigned int _stateSize;
}

- initWithDocument:(OFXMLDocument *)document element:(OFXMLElement *)element;
- initWithDocument:(OFXMLDocument *)document;

- (OFXMLDocument *)document;

- (OFXMLElement *)currentElement;
- (id)currentChild;
- (NSString *)currentPath;

- (id)nextChild;
- (id)peekNextChild;
- (void)openElement;
- (void)closeElement;

// Convenience methods that forward to -currentElement
- (NSString *)name;
- (NSArray *)children;
- (NSString *)attributeNamed:(NSString *)attributeName;

// More complex convenience methods
- (BOOL)openNextChildElementNamed:(NSString *)childElementName;

@end

// Error generating functions
extern NSString * const OFXMLLoadError;
extern void OFXMLRejectElement(OFXMLCursor *cursor);
