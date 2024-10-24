class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Right sum is totalSum minus leftSum and current element
            int rightSum = totalSum - leftSum - nums[i];

            // Check if left sum equals right sum
            if (leftSum == rightSum) {
                return i; // Found the pivot index
            }

            // Update left sum for the next iteration
            leftSum += nums[i];
        }

        return -1; // No pivot index found
    }
};