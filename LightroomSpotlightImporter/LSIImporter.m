//
//  MySpotlightImporter.m
//  LightroomSpotlightImporter
//
//  Created by David Bitton on 5/1/12.
//  Copyright (c) 2012 Code No Evil LLC
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//        
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "FMDatabase.h"
#import "FMResultSet.h"
#import "LSIImporter.h"

@interface LSIImporter ()

@end

@implementation LSIImporter

int executeSQLCallback(void *context, int argc, char **argv, char **azColName) {

    NSMutableArray *files = (__bridge NSMutableArray*)context;
    
    NSString *filename = [NSString stringWithFormat:@"%s", argv[0]];
    DLog(@"Filename: %@", filename);
    [files addObject:filename];
    
    return 0;
}

- (BOOL)importFileAtPath:(NSString *)filePath attributes:(NSMutableDictionary *)spotlightData error:(NSError **)error
{
    BOOL success = NO;

    NSMutableArray *files = [NSMutableArray array];
    
//    OSLDatabaseController *databaseController = [[OSLDatabaseController alloc] initWithDatabasePath:filePath error:error];
//    success = [databaseController executeSQL:@"SELECT originalFilename FROM AgLibraryFile" withCallback:executeSQLCallback context:(__bridge void*)files error:error];
    
    FMDatabase *database = [FMDatabase databaseWithPath:filePath];
    [database open];
    FMResultSet *resultSet = [database executeQuery:@"SELECT originalFilename FROM AgLibraryFile"];
    success = (resultSet != nil);
    while ([resultSet next]) {
        [files addObject:[resultSet stringForColumn:@"originalFilename"]];
    }
    [database close];
    
    DLog(@"Query Success: %u File Count: %u", success, [files count]);
    
    [spotlightData setObject:[NSArray arrayWithArray:files] forKey:@"com_adobe_lightroom_library_files"];
    
    DLog(@"Files: %@", [spotlightData objectForKey:@"com_adobe_lightroom_library_files"]);
    
    return success;
}

@end
