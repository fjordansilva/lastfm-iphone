/* TagEditorViewController.h - Displays and manages a modal tag editor view
 * 
 * Copyright 2009 Last.fm Ltd.
 *   - Primarily authored by Sam Steele <sam@last.fm>
 *
 * This file is part of MobileLastFM.
 *
 * MobileLastFM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MobileLastFM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MobileLastFM.  If not, see <http://www.gnu.org/licenses/>.
 */

#import <UIKit/UIKit.h>
#import "Three20/Three20.h"

@interface TagsModel: NSObject <TTModel> {
	NSMutableArray *_delegates;
	NSMutableArray *_topTags;
	NSMutableArray *_userTags;
	NSMutableArray *_allTopTags;
	NSMutableArray *_allUserTags;
}

@property (nonatomic, retain) NSMutableArray *topTags;
@property (nonatomic, retain) NSMutableArray *userTags;

- (id)initWithTopTags:(NSArray *)topTags userTags:(NSArray *)userTags;
- (void)loadTags;
- (void)search:(NSString *)text;

@end

@interface TagsDataSource : TTSectionedDataSource {
	TagsModel *_tags;
}
- (id)initWithTopTags:(NSArray *)topTags userTags:(NSArray *)userTags;
@end

@protocol TagEditorViewControllerDelegate
- (void)tagEditorDidCancel;
- (void)tagEditorAddTags:(NSArray *)tags;
- (void)tagEditorRemoveTags:(NSArray *)tags;
@end

@interface TagEditorViewController : UIViewController<UITableViewDataSource,UITableViewDelegate,UITabBarDelegate,UITextFieldDelegate> {
	TTPickerTextField *textField;
	TagsDataSource *_tags;
	NSMutableDictionary *tagActions;
	NSMutableArray *_cells;
	id<TagEditorViewControllerDelegate> delegate;
}
@property (retain, nonatomic) id<TagEditorViewControllerDelegate> delegate;
- (IBAction)tagButtonPressed:(id)sender;
- (IBAction)cancelButtonPressed:(id)sender;
- (IBAction)doneButtonPressed:(id)sender;
@end
