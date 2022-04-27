
#include <gtest/gtest.h>

#include "string_mutator.h"

namespace grammarly {

namespace {

TEST(StringMutatorTest, Simple) {
    auto call = [] (std::string_view _) {};
    mutate_by_deletion("abc", 3, call);

}
} // namespace
} // namespace grammarly