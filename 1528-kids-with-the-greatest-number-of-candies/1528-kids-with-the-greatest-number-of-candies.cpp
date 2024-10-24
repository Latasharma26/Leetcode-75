class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Step 1: Find the maximum number of candies any kid has
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        // Step 2: Create a result vector
        vector<bool> result;
        
        // Step 3: Iterate through the candies array and check the condition for each kid
        for (int candy : candies) {
            // If the current kid's candies + extraCandies >= maxCandies, they can have the most candies
            result.push_back(candy + extraCandies >= maxCandies);
        }
        
        // Return the result vector
        return result;
    }
};
