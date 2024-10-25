#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            // Add current number to the min-heap
            minHeap.push(num);
            // If the size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the min-heap is the Kth largest element
        return minHeap.top();
    }
};
