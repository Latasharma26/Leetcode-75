#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Frequency map
        int operations = 0;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        for (int num : nums) {
            // Check if this number can form a pair with its complement
            int complement = k - num;
            
            // Ensure we only count each pair once
            if (freq[num] > 0 && freq[complement] > 0) {
                // If both numbers are the same
                if (num == complement) {
                    operations += freq[num] / 2; // Pair them together
                    freq[num] = 0; // Reset count to avoid reuse
                } else {
                    // Form pairs with the minimum count of the two numbers
                    int pairCount = min(freq[num], freq[complement]);
                    operations += pairCount;
                    // Reduce the counts in the frequency map
                    freq[num] -= pairCount;
                    freq[complement] -= pairCount;
                }
            }
        }

        return operations; // Return the total operations
    }
};
