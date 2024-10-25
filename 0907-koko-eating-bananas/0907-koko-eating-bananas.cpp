#include <vector>
#include <algorithm>
#include <cmath> // for ceil

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1; // Minimum speed
        int right = *std::max_element(piles.begin(), piles.end()); // Maximum speed

        while (left < right) {
            int mid = left + (right - left) / 2; // Middle speed
            int hours = 0;

            // Calculate total hours needed at speed `mid`
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; // Ceil(pile / mid)
            }

            // If hours needed is less than or equal to h, we can try a slower speed
            if (hours <= h) {
                right = mid; // Try for a smaller speed
            } else {
                left = mid + 1; // Increase the speed
            }
        }

        // When left == right, we have found the minimum speed
        return left;
    }
};
