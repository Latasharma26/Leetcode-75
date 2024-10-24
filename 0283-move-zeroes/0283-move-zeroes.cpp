class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex = 0; // Pointer to the last non-zero element

        // Move non-zero elements to the front of the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i]; // Place non-zero at the last non-zero index
            }
        }

        // Fill the rest of the array with zeros
        for (int i = lastNonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0; // Fill remaining positions with 0
        }
    }
};
