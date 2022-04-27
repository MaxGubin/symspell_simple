#ifndef STRING_MUTATOR
#define STRING_MUTATOR

#include <string>


namespace grammarly {
namespace {
template<typename Callback>
void process_mutable_string(std::string& modifiable, int start_index, int num_delete, Callback call) {
    for (auto i = start_index; i < modifiable.length();++i) {
        const auto curr_letter = modifiable[i];
        modifiable.erase(i, 1);
        call(modifiable);
        if (num_delete > 0 && modifiable.length() > 1) {
            process_mutable_string(modifiable, i, num_delete-1, call);
        }
        modifiable.insert(i, 1, curr_letter);
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
        process_mutable_string(modifiable, 0, num_delete-1, call);
    }
}
} // namespace grammarly

#endif // STRING_MUTATOR