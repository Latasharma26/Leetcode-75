class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num; // Update first if num is smaller or equal
            } else if (num <= second) {
                second = num; // Update second if num is smaller or equal
            } else {
                // Found a number greater than both first and second
                return true;
            }
        }
        
        return false; // No triplet found
    }
};
