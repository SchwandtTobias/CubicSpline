//
//  AppDelegate.h
//  app_cubic_spline
//
//  Created by Tobias Schwandt on 22.06.12.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;

@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (weak) IBOutlet NSTextField *pointList;

- (IBAction)saveAction:(id)sender;

@end
