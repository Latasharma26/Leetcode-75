#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int n = nums1.size();
        std::vector<std::pair<int, int>> pairs(n);
        
        // Create pairs of (nums1[i], nums2[i]) and sort by nums2 in descending order
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums1[i], nums2[i]};
        }
        
        // Sort pairs by nums2 value in descending order
        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        long long maxScore = 0;
        long long sum = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Iterate through the sorted pairs
        for (int i = 0; i < n; ++i) {
            int num1 = pairs[i].first;
            // Add the current nums1 to the sum
            sum += num1;
            minHeap.push(num1);

            // If we have more than k elements, remove the smallest
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // Calculate the current score using the minimum nums2 (from pairs[i])
            if (minHeap.size() == k) {
                maxScore = std::max(maxScore, sum * pairs[i].second);
            }
        }

        return maxScore;
    }
};
