/// Test suite for the util module.
///
/// Link all test files with the `gtest_main` library to create a command-line
/// test runner.
///
#include <stdexcept>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "util.hpp"


using std::out_of_range;
using std::string;
using std::vector;
using testing::Test;

using namespace argparse;


/// Test fixture for the ValueMap test suite.
///
/// This is used to group tests and provide common set-up and tear-down
/// code. A new test fixture is created for each test to prevent any side
/// effects between tests. Member variables and methods are injected into
/// each test that uses this fixture.
///
/// This will be parametrized over all logging levels.
///
class ValueMapTest: public Test
{
protected:
    ValueMapTest() {
        for (const auto& key: keys) {
            map.insert(key, values);
        }
        return;
    }

    vector<string> keys = {"key1", "key2"};
    vector<string> values = {"val1", "val2"};
    ValueMap map;
};


/// Test the constructor methods.
///
TEST_F(ValueMapTest, ctor)
{
    ValueMap map;
    ASSERT_EQ(map.values(keys[0]), vector<string>());
    map = ValueMap(keys[0], values[0]);
    ASSERT_EQ(map.values(keys[0]), vector<string>({values[0]}));
    map = ValueMap(keys[0], values);
    ASSERT_EQ(map.values("key1"), values);
    return;
}


/// Test the get() methods.
///
TEST_F(ValueMapTest, get)
{
    ASSERT_EQ(map.get(keys[0]), values[0]);
    ASSERT_EQ(map.get("none", "default"), "default");
    ASSERT_THROW(map.get("none"), out_of_range);
    return;
}


/// Test the values() methods.
///
TEST_F(ValueMapTest, values)
{
    ASSERT_EQ(map.values(keys[0]), values);
    ASSERT_EQ(map.values("none"), vector<string>());
    return;
}


/// Test the keys() method.
///
TEST_F(ValueMapTest, keys)
{
    ASSERT_EQ(map.keys(), keys);
    return;
}


/// Test the insert() methods.
///
TEST_F(ValueMapTest, insert)
{
    map.insert("key1", "val3");
    values.push_back("val3");
    ASSERT_EQ(map.values("key1"), values);
    map.insert("key3", values);
    ASSERT_EQ(map.values("key3"), values);
    return;
}


/// Test the merge() methods.
///
TEST_F(ValueMapTest, merge)
{
    ValueMap other;
    other.insert("key1", "val3");
    other.insert("key3", "val3");
    map.merge(other);
    ASSERT_EQ(map.values("key1"), vector<string>({"val1", "val2", "val3"}));
    ASSERT_EQ(map.values("key3"), vector<string>({"val3"}));
    map.merge(other, false);  // overwrite
    ASSERT_EQ(map.values("key1"), vector<string>({"val3"}));
    return;
}
