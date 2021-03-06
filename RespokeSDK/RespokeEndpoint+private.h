//
//  RespokeEndpoint+private.h
//  Respoke SDK
//
//  Copyright 2015, Digium, Inc.
//  All rights reserved.
//
//  This source code is licensed under The MIT License found in the
//  LICENSE file in the root directory of this source tree.
//
//  For all details and documentation:  https://www.respoke.io
//

#import "RespokeEndpoint.h"
#import "RespokeSignalingChannel.h"
#import "RespokeClient+private.h"


@interface RespokeEndpoint (private)


/**
 *  Initialize a new endpoint instance
 *
 *  @param channel The signaling channel to use
 *  @param client  The client to which the endpoint belongs
 *
 *  @return The newly initialized instance
 */
- (instancetype)initWithSignalingChannel:(RespokeSignalingChannel*)channel endpointID:(NSString*)newEndpointID client:(RespokeClient*)newClient;


/**
 *  Expose the mutable version of the connections list to the rest of the SDK
 *
 *  @return The mutable connections list for this endpoint
 */
- (NSMutableArray*)getMutableConnections;


/**
 *  Returns a connection with the specified ID, and optionally creates one if it does not exist
 *
 *  @param connectionID  The ID of the connection
 *  @param skipCreate    Whether or not to create a new connection if it is not found
 *
 *  @return The connection that matches the specified ID, or nil if not found and skipCreate is true
 */
- (RespokeConnection*)getConnectionWithID:(NSString*)connectionID skipCreate:(BOOL)skipCreate;


/**
 *  Process a received message
 *
 *  @param message The body of the message
 *  @param timestamp The message timestamp
 */
- (void)didReceiveMessage:(NSString*)message withTimestamp:(NSDate*)timestamp;


/**
 *  Process a sent message
 *
 *  @param message The body of the message
 *  @param timestamp The message timestamp
 */
- (void)didSendMessage:(NSString*)message withTimestamp:(NSDate*)timestamp;


/**
 *  Set the presence value for this endpoint
 *
 *  @param newPresence The new presence value
 */
- (void)setPresence:(NSObject*)newPresence;


/**
 *  Find the presence out of all known connections with the highest priority (most availability)
 *  and set it as the endpoint's resolved presence.
 */
- (void)resolvePresence;


/**
 *  Associate a direct connection object with this endpoint
 *
 *  @param newDirectConnection  The direct connection to associate
 */
- (void)setDirectConnection:(RespokeDirectConnection*)newDirectConnection;


@end