#import <Foundation/Foundation.h>

#import "MSLogWithProperties.h"

/**
 * Error attachment log.
 */
@interface MSErrorAttachmentLog : MSLogWithProperties

/**
 * Content type (text/plain for text).
 */
@property(nonatomic, copy) NSString *contentType; // TODO remove nullability warnings.

/**
 * File name.
 */
@property(nonatomic, copy) NSString *filename;

/**
 * Data (plain text or base64 string for binary data).
 */
@property(nonatomic, copy) NSString *data;

/**
 * Initialize an attachment with a given filename and `NSData` object.
 *
 * @param filename The filename the attachment should get. If nil will get an automatically generated filename.
 * @param data The attachment data as `NSData`.
 * @param contentType The content type of your data as MIME type.
 *
 * @return An instance of `MSErrorAttachmentLog`.
 */
- (instancetype)initWithFilename:(NSString *)filename attachmentData:(NSData *)data contentType:(NSString *)contentType;

/**
 * Initialize an attachment with a given filename and text.
 *
 * @param filename The filename the attachment should get. If nil will get an automatically generated filename.
 * @param text The attachment text.
 *
 * @return An instance of `MSErrorAttachmentLog`.
 */
- (instancetype)initWithFilename:(NSString *)filename attachmentText:(NSString *)text;

/**
 * Create an attachment with a given filename and text.
 *
 * @param filename The filename the attachment should get. If nil will get an automatically generated filename.
 * @param text The attachment text.
 *
 * @return An instance of `MSErrorAttachmentLog`.
 */
+ (MSErrorAttachmentLog *)attachmentWithText:(NSString *)text filename:(NSString *)filename;

/**
 * Create an attachement with a given filename and `NSData` object.
 *
 * @param filename The filename the attachment should get. If nil will get an automatically generated filename.
 * @param data The attachment data as NSData.
 * @param contentType The content type of your data as MIME type.
 *
 * @return An instance of `MSErrorAttachmentLog`.
 */
+ (MSErrorAttachmentLog *)attachmentWithBinaryData:(NSData *)data
                                          filename:(NSString *)filename
                                       contentType:(NSString *)contentType;

@end
