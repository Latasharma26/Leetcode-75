#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2; // Avoid potential overflow

            // Compare mid with its next element
            if (nums[mid] < nums[mid + 1]) {
                // Move to the right half
                left = mid + 1;
            } else {
                // Move to the left half (including mid)
                right = mid;
            }
        }
        
        // left and right converge to a peak index
        return left;
    }
};
