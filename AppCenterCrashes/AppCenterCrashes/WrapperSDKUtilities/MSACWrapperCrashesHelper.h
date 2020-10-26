// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#import <Foundation/Foundation.h>

#import <AppCenterCrashes/MSACCrashHandlerSetupDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class MSACErrorReport;
@class MSACErrorAttachmentLog;
@class MSACException;

/**
 * This general class allows wrappers to supplement the Crashes SDK with their own behavior.
 */
@interface MSACWrapperCrashesHelper : NSObject

/**
 * Sets the crash handler setup delegate.
 *
 * @param delegate The delegate to set.
 */
+ (void)setCrashHandlerSetupDelegate:(id<MSACCrashHandlerSetupDelegate>)delegate;

/**
 * Gets the crash handler setup delegate.
 *
 * @return The delegate being used by Crashes.
 */
+ (id<MSACCrashHandlerSetupDelegate>)getCrashHandlerSetupDelegate;

/**
 * Enables or disables automatic crash processing.
 *
 * @param automaticProcessing Passing NO causes SDK not to send reports immediately, even if "Always Send" is true.
 */
+ (void)setAutomaticProcessing:(BOOL)automaticProcessing;

/**
 * Gets a list of unprocessed crash reports. Will block until the service starts.
 *
 * @return An array of unprocessed error reports.
 */
+ (NSArray<MSACErrorReport *> *)unprocessedCrashReports;

/**
 * Resumes processing for a given subset of the unprocessed reports.
 *
 * @param filteredIds An array containing the errorId/incidentIdentifier of each report that should be sent.
 *
 * @return YES if should "Always Send" is true.
 */
+ (BOOL)sendCrashReportsOrAwaitUserConfirmationForFilteredIds:(NSArray<NSString *> *)filteredIds;

/**
 * Sends error attachments for a particular error report.
 *
 * @param errorAttachments An array of error attachments that should be sent.
 * @param incidentIdentifier The identifier of the error report that the attachments will be associated with.
 */
+ (void)sendErrorAttachments:(NSArray<MSACErrorAttachmentLog *> *)errorAttachments withIncidentIdentifier:(NSString *)incidentIdentifier;

/**
 * Track handled exception directly as model form.
 * This API is used by wrapper SDKs.
 *
 * @param exception model form exception.
 * @param properties dictionary of properties.
 * @param attachments a list of attachments.
 *
 * @return handled error ID.
 */
+ (nullable NSString *)trackModelException:(MSACException *)exception
                            withProperties:(nullable NSDictionary<NSString *, NSString *> *)properties
                           withAttachments:(nullable NSArray<MSACErrorAttachmentLog *> *)attachments;

/**
 * Get a generic error report representation for an handled exception.
 * This API is used by wrapper SDKs.
 *
 * @param errorID handled error ID.
 *
 * @return an error report.
 */
+ (MSACErrorReport *)buildHandledErrorReportWithErrorID:(NSString *)errorID;

@end

NS_ASSUME_NONNULL_END
