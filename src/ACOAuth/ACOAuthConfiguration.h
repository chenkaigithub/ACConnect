//
//  ACOAuthConfiguration.h
//  ACOAuth
//
//  Created by Jason Kichline on 7/29/11.
//  Copyright 2011 Jason Kichline. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKeychain.h"

typedef enum {
	ACOAuthSignatureMethodHMAC_SHA1,
	ACOAuthSignatureMethodPlainText
} ACOAuthSignatureMethod;

@interface ACOAuthConfiguration : NSObject {
	NSURL* baseURL;
	NSURL* requestTokenURL;
	NSString* requestTokenMethod;
	NSURL* accessTokenURL;
	NSString* accessTokenMethod;
	NSURL* authorizationURL;
	NSString* authorizationMethod;
	NSURL* callbackURL;
	
	NSString* consumerKey;
	NSString* consumerSecret;
	NSString* token;
	NSString* tokenSecret;
	NSString* verifier;
	NSString* identifier;
	NSString* css;
	NSString* javascript;
	
	BOOL authenticateImmediately;
	NSMutableDictionary* parameters;
	
	UIColor* tintColor;
	UIViewController* parentViewController;
	
	ACOAuthSignatureMethod signatureMethod;
	ACKeychain* keychain;
}

@property (nonatomic, retain) NSURL* baseURL;
@property (nonatomic, retain) NSURL* requestTokenURL;
@property (nonatomic, retain) NSString* requestTokenMethod;
@property (nonatomic, retain) NSURL* accessTokenURL;
@property (nonatomic, retain) NSString* accessTokenMethod;
@property (nonatomic, retain) NSURL* authorizationURL;
@property (nonatomic, retain) NSString* authorizationMethod;
@property (nonatomic, retain) NSURL* callbackURL;
@property (nonatomic) BOOL authenticateImmediately;
@property (nonatomic, retain) NSString* consumerKey;
@property (nonatomic, retain) NSString* consumerSecret;
@property (nonatomic, retain) NSString* token;
@property (nonatomic, retain) NSString* tokenSecret;
@property (nonatomic, retain) NSString* verifier;
@property (nonatomic, retain) NSString* identifier;
@property (nonatomic, retain) NSString* css;
@property (nonatomic, retain) NSString* javascript;

@property (nonatomic, retain) NSMutableDictionary* parameters;

@property (nonatomic, retain) UIColor* tintColor;
@property (nonatomic, retain) UIViewController* parentViewController;

@property ACOAuthSignatureMethod signatureMethod;

@property (readonly) BOOL isValid;
@property (readonly) NSString* signatureKey;

-(id)initWithConsumerKey:(NSString*)consumerKey andSecret:(NSString*)consumerSecret forBaseURL:(NSURL*)baseURL;
+(ACOAuthConfiguration*)configurationWithConsumerKey:(NSString*)consumerKey andSecret:(NSString*)consumerSecret forBaseURL:(NSURL*)baseURL;
-(void)saveToKeychain;
-(void)removeFromKeychain;

@end
