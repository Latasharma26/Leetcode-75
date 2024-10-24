class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Step 1: Calculate the sum of the first 'k' elements
        double maxSum = 0.0;
        double currentSum = 0.0;
        
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }
        
        maxSum = currentSum; // Initialize maxSum with the first window sum

        // Step 2: Slide the window from the (k+1)th element to the end
        for (int i = k; i < nums.size(); ++i) {
            currentSum += nums[i] - nums[i - k]; // Update the window sum
            maxSum = max(maxSum, currentSum); // Update maxSum if needed
        }

        // Step 3: Calculate and return the average
        return maxSum / k;
    }
};