
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <unordered_set>

#include "string_mutator.h"

namespace grammarly {

namespace {

TEST(StringMutatorTest, Simple) {
    bool double_generation = false;
    std::unordered_set<std::string> generated_strings;
    auto call = [&double_generation, &generated_strings] (std::string_view s) {
        double_generation |= !generated_strings.insert(std::string(s)).second;
    };
    mutate_by_deletion("abc", 3, call);

    ASSERT_FALSE(double_generation);
    EXPECT_THAT(generated_strings, ::testing::UnorderedElementsAreArray({"abc", "bc", "ab", "ac", "a", "b", "c"}));

}
} // namespace
} // namespace grammarly