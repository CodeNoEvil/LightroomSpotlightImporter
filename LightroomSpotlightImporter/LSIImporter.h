//
//  MySpotlightImporter.h
//  LightroomSpotlightImporter
//
//  Created by David Bitton on 5/1/12.
//  Copyright (c) 2012 Code No Evil LLC All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface LSIImporter : NSObject

//@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
//@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
//@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;

- (BOOL)importFileAtPath:(NSString *)filePath attributes:(NSMutableDictionary *)attributes error:(NSError **)error;

@end
