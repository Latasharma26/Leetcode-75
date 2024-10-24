class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;  // Left pointer
        int zeroCount = 0;  // Count of zeros
        int maxLength = 0;  // Maximum length of the window

        // Step through the array with the right pointer
        for (int right = 0; right < nums.size(); ++right) {
            // If we encounter a zero, increment the zero count
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If the count of zeros exceeds k, move the left pointer
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;  // Decrement zero count if we move past a zero
                }
                left++;  // Shrink the window from the left
            }

            // Update the maximum length of the window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;  // Return the maximum length found
    }
};