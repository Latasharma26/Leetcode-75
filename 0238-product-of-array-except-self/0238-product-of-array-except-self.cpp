class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);  // Initialize the result array with 1
        
        // Step 1: Calculate the prefix product for each element
        int prefixProduct = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefixProduct;  // Store the prefix product in result[i]
            prefixProduct *= nums[i];   // Update the prefix product
        }
        
        // Step 2: Calculate the suffix product and update the result array
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffixProduct; // Multiply by the suffix product
            suffixProduct *= nums[i];   // Update the suffix product
        }
        
        return result;
    }
};
