#import "STBStubbleCore.h"

#define WHEN(...) ({ [STBStubbleCore.core prepareForWhen]; (void)__VA_ARGS__; [STBStubbleCore.core performWhen]; })
// #define VERIFY(...) ({ [STBStubbleCore.core prepareForVerify]; (void)__VA_ARGS__; [STBStubbleCore.core performVerify]; })


@interface STBMock : NSObject

+ (id)mockForClass:(Class)class;

@end





//STBMockObject *verify(id mock);
//
//STBMockObject *when(id mock);

// ********************
// Mockito syntax
//when(mockedList.get(0)).thenReturn("first");




// ********************
// Mock objects have verify, reject, stub methods

//[[mockObject verify:times(2)] myMethod:@"Blargh"];

//[[mockObject.when myMethod:@"Blargh" param2:any()] thenReturn:@"Ack"];
//
//[[[mockObject when] myMethod:@"Blargh" param2:any()] thenReturn:@"Ack"];
//
//
//when([mockObject myMethod:@"Blargh"]);
//

//[[when.mockObject myMethod:@"Blargh" param2:any()] thenReturn:@"DGnadosg"]

// ********************
// All calls are C and look like verify(mockObject), or any(), etc.
//
//[verify(mockObject, times(2)) myMethod:any()];
//[verify(mockObject, never()) myMethod:any()];
//
//[[when(mockObject) myMethod:@"Blargh" param2:any() param3:captor(&myInt)] thenReturn:@"Baz"];
//
//[[stub(mockObject) doStuff:@"Blah"] andReturn:@"Baz"];
//
//[mockObject doStuff:@"Blah"]; // evaluates to @"Baz"


