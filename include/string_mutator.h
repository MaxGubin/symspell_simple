#ifndef STRING_MUTATOR
#define STRING_MUTATOR

#include <string>


namespace grammarly {
namespace {
template<typename Callback>
void process_mutable_string(std::string& modifiable, int num_delete, Callback call) {
    for (auto iter = std::begin(modifiable); iter != std::end(modifiable);++iter) {
        const auto curr_letter = *iter;
        modifiable.erase(iter);
        call(modifiable);
        if (num_delete > 0) {
            process_mutable_string(modifiable, num_delete-1, call);
        }
        modifiable.insert(iter, curr_letter);

    }
}

} // namespace
template<typename Callback>
void mutate_by_deletion(std::string_view str, int num_delete, Callback call) {
    // Always first for the whole string.
    call(str);
    // Create a buffer string.
    std::string modifiable{str};
    if (num_delete > 0) {
        process_mutable_string(modifiable, num_delete-1, call);
    }
}
} // namespace grammarly

#endif // STRING_MUTATOR