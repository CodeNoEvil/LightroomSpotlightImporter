// Copyright 2002-2005, 2007-2008, 2010 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <Foundation/NSGeometry.h>

@class NSArray, NSMutableArray;

/*" Returns the centerpoint of the circle passing through the three specified points. "*/
extern NSPoint OFCenterOfCircleFromThreePoints(NSPoint point1, NSPoint point2, NSPoint point3);

/*" Returns a rect constrained to lie within boundary. This differs from NSIntersectionRect() in that it will adjust the rectangle's origin in order to place it within the boundary rectangle, and will only reduce the rectangle's size if necessary to make it fit. "*/
extern NSRect OFConstrainRect(NSRect rect, NSRect boundary);

/*" Returns a minimum rectangle containing the specified points. "*/
static inline NSRect OFRectFromPoints(NSPoint point1, NSPoint point2)
{
    return NSMakeRect(MIN(point1.x, point2.x), MIN(point1.y, point2.y),
                      (CGFloat)fabs(point1.x - point2.x), (CGFloat)fabs(point1.y - point2.y));
}

/*" Returns a rectangle centered on the specified point, large enough to contain the other point. "*/
static inline NSRect OFRectFromCenterAndPoint(NSPoint center, NSPoint corner)
{
    return NSMakeRect((CGFloat)(center.x - fabs( corner.x - center.x )),
                      (CGFloat)(center.y - fabs( corner.y - center.y )),
                      (CGFloat)(2 * fabs( corner.x - center.x )),
                      (CGFloat)(2 * fabs( corner.y - center.y )));

}

/*" Returns a rectangle centered on the specified point, and with the specified size. "*/
static inline NSRect OFRectFromCenterAndSize(NSPoint center, NSSize size) {
    return NSMakeRect(center.x - (size.width/2), center.y - (size.height/2),
                      size.width, size.height);
}

extern CGFloat OFSquaredDistanceToFitRectInRect(NSRect sourceRect, NSRect destinationRect);
extern NSRect OFClosestRectToRect(NSRect sourceRect, NSArray *candidateRects);
extern void OFUpdateRectsToAvoidRectGivenMinimumSize(NSMutableArray *rects, NSRect rectToAvoid, NSSize minimumSize);
/*" Returns YES if sourceSize is at least as tall and as wide as minimumSize, and that neither the height nor the width of minimumSize is 0. "*/
static inline BOOL OFSizeIsOfMinimumSize(NSSize sourceSize, NSSize minimumSize)
{
    return (sourceSize.width >= minimumSize.width) && (sourceSize.height >= minimumSize.height) && (sourceSize.width > 0.0) && (sourceSize.height > 0.0);
}

extern NSRect OFLargestRectAvoidingRectAndFitSize(NSRect parentRect, NSRect childRect, NSSize fitSize);
#define OFLargestRectAvoidingRect(parentRect, childRect) OFLargestRectAvoidingRectAndFitSize(parentRect, childRect, NSZeroSize)

/*" Returns the rectangle containing both inRect and the point p. "*/
extern NSRect OFRectIncludingPoint(NSRect inRect, NSPoint p);

