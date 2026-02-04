#ifndef ENABLE_DISPATCH_TESTS

#include "CppInterOp/Dispatch.h"

#define DISPATCH_API(name, type) CppAPIType::name Cpp::name = nullptr;
CPPINTEROP_API_TABLE
#undef DISPATCH_API

#include "gtest/gtest.h"

TEST(DispatchLoadUnloadTest, Basic) {
  EXPECT_FALSE(Cpp::LoadDispatchAPI("some/random/invalid/directory.so"));
  Cpp::UnloadDispatchAPI(); // should reset for next load to be successfull
  EXPECT_TRUE(Cpp::LoadDispatchAPI(CPPINTEROP_LIB_PATH));
  Cpp::UnloadDispatchAPI(); // should reset for next load to fail
  EXPECT_FALSE(Cpp::LoadDispatchAPI("some/other/random/invalid/directory.so"));
}

#endif
