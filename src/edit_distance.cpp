#include "edit_distance.h"

namespace grammarly {
DistanceEstimator::DistanceEstimator(std::string_view matching_string):
        matching_string_(matching_string) {
            const size_t string_length = matching_string.length();
            distance_buffer_[0].resize(string_length);
            distance_buffer_[1].resize();
            // 
        }

float DistanceEstimator::calculate_distance(std::string_view matching_string) {
    const size_t 
    int buffer_index = 0;
    // Initialize weights.
    for (auto i = 0; i<; ++i) {

    }
    for()
}
} // namespace grammarly