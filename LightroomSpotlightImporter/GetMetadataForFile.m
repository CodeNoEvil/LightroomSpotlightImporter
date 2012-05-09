//
//  GetMetadataForFile.m
//  LightroomSpotlightImporter
//
//  Created by David Bitton on 5/1/12.
//  Copyright (c) 2012 Code No Evil LLC All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#import <CoreData/CoreData.h>
#import "LSIImporter.h"

Boolean GetMetadataForFile(void *thisInterface, CFMutableDictionaryRef attributes, CFStringRef contentTypeUTI, CFStringRef pathToFile);

//==============================================================================
//
//	Get metadata attributes from document files
//
//	The purpose of this function is to extract useful information from the
//	file formats for your document, and set the values into the attribute
//  dictionary for Spotlight to include.
//
//==============================================================================

Boolean GetMetadataForFile(void *thisInterface, CFMutableDictionaryRef attributes, CFStringRef contentTypeUTI, CFStringRef pathToFile)
{
    // Pull any available metadata from the file at the specified path
    // Return the attribute keys and attribute values in the dict
    // Return TRUE if successful, FALSE if there was no data provided

    Boolean ok = FALSE;
    @autoreleasepool {
        NSError *error = nil;

        if ([(__bridge NSString *)contentTypeUTI isEqualToString:@"com.adobe.lightroom.library"]) {
            // import from an external record file
            
            LSIImporter *importer = [[LSIImporter alloc] init];
            
            ok = [importer importFileAtPath:(__bridge NSString *)pathToFile attributes:(__bridge NSMutableDictionary *)attributes error:&error];
            
            DLog(@"OK: %u", ok);
        }
    }
    
	// Return the status
    return ok;
}
