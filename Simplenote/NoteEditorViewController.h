//
//  NoteEditorViewController.h
//  Simplenote
//
//  Created by Rainieri Ventura on 2/2/12.
//  Copyright (c) 2012 Simperium. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>
#import "Note.h"
#import "SPTextView.h"
@import Simperium_OSX;

@class NoteListViewController;
@class NoteEditorBottomBar;

typedef NS_ENUM(NSInteger, NoteFontSize) {
    NoteFontSizeMinimum = 10,
    NoteFontSizeNormal = 15,
    NoteFontSizeMaximum = 30
};


#pragma mark ====================================================================================
#pragma mark Notifications
#pragma mark ====================================================================================

extern NSString * const SPNoNoteLoadedNotificationName;
extern NSString * const SPNoteLoadedNotificationName;
extern NSString * const SPTagAddedFromEditorNotificationName;
extern NSString * const SPWillAddNewNoteNotificationName;


#pragma mark ====================================================================================
#pragma mark NoteEditorViewController
#pragma mark ====================================================================================

@interface NoteEditorViewController : NSViewController <NSSharingServicePickerDelegate>
{
    IBOutlet NSTableView *tableView;
    IBOutlet NoteListViewController *noteListViewController;
    IBOutlet NSArrayController *notesArrayController;
    IBOutlet NSTokenField *tagTokenField;
    IBOutlet NSButton *restoreVersionButton;
    IBOutlet NSSlider *versionSlider;
    IBOutlet NSTextFieldCell *versionLabel;
    IBOutlet NSTextFieldCell *publishLabel;
    IBOutlet NSButton *publishButton;
    IBOutlet NSButton *shareButton;
    IBOutlet NSView *statusView;
    IBOutlet NSTextField *noNoteText;
    IBOutlet NSMenuItem *wordCountItem;
    IBOutlet NSMenuItem *characterCountItem;
    IBOutlet NSMenuItem *modifiedItem;
    IBOutlet NSMenuItem *pinnedItem;
    IBOutlet NSMenuItem *newItem;
    IBOutlet NSMenuItem *deleteItem;
    IBOutlet NSMenuItem *printItem;
    IBOutlet NSMenuItem *collaborateItem;
    IBOutlet NSMenuItem *historyItem;
    IBOutlet NSMenuItem *publishItem;
}

@property (nonatomic, assign) IBOutlet SPTextView           *noteEditor;
@property (nonatomic, assign) IBOutlet NoteEditorBottomBar  *bottomBar;
@property (nonatomic, strong) IBOutlet NSViewController     *shareViewController;
@property (nonatomic, strong) IBOutlet NSViewController     *publishViewController;
@property (nonatomic, strong) IBOutlet NSViewController     *versionsViewController;
@property (nonatomic,   weak) Note                          *note;

- (void)save;
- (void)displayNote:(Note *)selectedNote;
- (void)displayNotes:(NSArray *)selectedNotes;
- (void)didReceiveNewContent;
- (void)updateTagField;
- (void)willReceiveNewContent;
- (void)didReceiveVersion:(NSString *)version data:(NSDictionary *)data;
- (void)applyStyle;
- (void)showPublishPopover;
- (NSUInteger)wordCount;
- (NSUInteger)charCount;
- (NSUInteger)newCursorLocation:(NSString *)newText oldText:(NSString *)oldText currentLocation:(NSUInteger)cursorLocation;
- (IBAction)deleteAction:(id)sender;
- (IBAction)adjustFontSizeAction:(id)sender;
- (IBAction)showSharePopover:(id)sender;
- (IBAction)showVersionPopover:(id)sender;

@end
