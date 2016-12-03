#ifdef __APPLE__

#import <Foundation/Foundation.h>
#include "gameplay.h"

using namespace gameplay;

extern int __argc;
extern char** __argv;

/**
 * Main entry point.
 */
int main(int argc, char** argv)
{
#ifndef DEBUG
    //do receipt validation first thing in main function
    NSString *receiptPath = [[[NSBundle mainBundle] appStoreReceiptURL] path];
    // Test whether the receipt is present at the above path
    
    if (![[NSFileManager defaultManager] fileExistsAtPath:receiptPath]) {
        //NSLog(@"receipt validation failed.");
        // Validation fails
        exit(173);
    }
#endif

    
    __argc = argc;
    __argv = argv;
    NSAutoreleasePool *p = [[NSAutoreleasePool alloc] init];
    Game* game = Game::getInstance();
    Platform* platform = Platform::create(game);
    GP_ASSERT(platform);
    int result = platform->enterMessagePump();
    delete platform;
    [p release];
    return result;
}

#endif