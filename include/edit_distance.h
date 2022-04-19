#ifndef _EDIT_DISTANCE_H_
#define _EDIT_DISTANCE_H_
#include <string_view>
#include <vector>

namespace grammarly {


// Optimized distance calculator.
class DistanceEstimator {
    public:
        DistanceEstimator(std::string_view matching_string);
        float calculate_distance(std::string_view matching_string);
    private:
    std::string_view matching_string_;
    std::vector<float> distance_buffer_[2];
};
`
} // namespace grammarly

#endif // _EDIT_DISTANCE_H_