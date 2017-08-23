/// Test suite for the action module.
///
/// Link all test files with the `gtest_main` library to create a command-line
/// test runner.
///
#include <stdexcept>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "action.hpp"
#include "util.hpp"


using testing::Test;

using namespace argparse;


/// Test fixture for the Store test suite.
///
/// This is used to group tests and provide common set-up and tear-down
/// code. A new test fixture is created for each test to prevent any side
/// effects between tests. Member variables and methods are injected into
/// each test that uses this fixture.
///
/// This will be parametrized over all logging levels.
///
class StoreTest: public Test
{
protected:

    /// Set up the test fixture before each test.
    ///
    StoreTest():
        action(data)
    {}

    ValueMap data;
    Store action;
};


/// Test the function operator.
///
TEST_F(StoreTest, func)
{
    ValueMap args("key1", "val1");
    action(args);
    ASSERT_EQ(data.get("key1"), "val1");
    return;
}
