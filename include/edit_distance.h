#ifndef _EDIT_DISTANCE_H_
#define _EDIT_DISTANCE_H_
#include <string_view>
#include <vector>

namespace grammarly {


// Optimized distance calculator.
class DistanceEstimator {
    public:

        // Distance constants:
        static constexpr float kSkipWeight = 1.f;
        static constexpr float kReplaceWeight = 1.f;

        DistanceEstimator(std::string_view matching_string);
        float calculate_distance(std::string_view matching_string);
    private:
    std::string_view matching_string_;
    std::vector<float> distance_buffer0_;
    std::vector<float> distance_buffer1_;
};

} // namespace grammarly

#endif // _EDIT_DISTANCE_H_