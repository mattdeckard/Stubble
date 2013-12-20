#import "SBLTransactionManager.h"
#import "SBLTimesMatcher.h"

#define WHEN(methodCall...) ({ [SBLTransactionManager.currentTransactionManager invokeWhenMethodForObjectInBlock:^(){ (void)methodCall; }]; })

#define verify(methodCall...) macro_dispatcher(verify, methodCall)(methodCall)
// Compiler reports the following line is never used, but it is
#define verify1(methodCall...) verify2(times(1), methodCall)
#define verify2(timesMatcher, methodCall...) ({ [SBLTransactionManager.currentTransactionManager invokeVerifyMethodForObjectInBlock:^(){ (void)methodCall; } times:timesMatcher]; })
#define verifyNever(args) verify(never(), args)

#define times(times) ({ [SBLTimesMatcher exactly:times]; })
#define atLeast(times) ({ [SBLTimesMatcher atLeast:times]; })
#define never() ({ [SBLTimesMatcher never]; })
#define between(atLeast, atMost) ({ [SBLTimesMatcher between:atLeast andAtMost:atMost]; })

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL(__VA_ARGS__, 5,4,3,2,1)
#define VA_NUM_ARGS_IMPL(_1,_2,_3,_4,_5,N,...) N

#define macro_dispatcher(func, ...) \
            macro_dispatcher_(func, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(func, nargs) \
            macro_dispatcher__(func, nargs)
#define macro_dispatcher__(func, nargs) \
            func ## nargs

//#define any() _Pragma("clang diagnostic push") \
//_Pragma("clang diagnostic ignored \"-Wconversion\"") \
//({ SBLMatcher *matcher = [SBLMatcher any]; [SBLTransactionManager.currentTransactionManager addMatcher:matcher]; (__bridge void *)matcher; }) \
//_Pragma ("clang diagnostic pop") \

#define any() _Pragma("clang diagnostic push") \
	_Pragma("clang diagnostic ignored \"-Wconversion\"") \
	 ({ SBLMatcher *matcher = [SBLMatcher any]; [SBLTransactionManager.currentTransactionManager addMatcher:matcher]; [matcher placeholder]; }) \
	_Pragma("clang diagnostic pop")

#define anyObjectReference(...) anyWithPlaceholder(&@"placeholder")
#define anyWithPlaceholder(...) ({ [SBLTransactionManager.currentTransactionManager addMatcher:[SBLMatcher any]]; __VA_ARGS__; })
#define anyCGRect() anyWithPlaceholder(CGRectZero)

@interface SBLMock : NSObject

+ (id)mockForClass:(Class)class;
+ (id)mockForProtocol:(Protocol *)protocol;

@end
