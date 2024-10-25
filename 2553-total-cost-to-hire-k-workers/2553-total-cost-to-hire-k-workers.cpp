class Solution {
public:
    long totalCost(vector<int>& costs, int k, int candidates) {
        int left = candidates - 1;
        int right = costs.size() - candidates;
        long result = 0L;

        priority_queue<int, vector<int>, greater<int>> leftSubArray;
        priority_queue<int, vector<int>, greater<int>> rightSubArray;

        if (left < right) {
            for (int i = 0; i <= left; i++) {
                leftSubArray.push(costs[i]);
            }

            for (int i = right; i < costs.size(); i++) {
                rightSubArray.push(costs[i]);
            }
        } else {
            for (int i = 0; i < costs.size(); i++) {
                if (i < candidates) {
                    leftSubArray.push(costs[i]);
                } else {
                    rightSubArray.push(costs[i]);
                }
            }
        }

        while (k != 0) {
            if (rightSubArray.empty() && leftSubArray.empty()) {
                break;
            } else if (rightSubArray.empty()) {
                result += leftSubArray.top();
                leftSubArray.pop();
            } else if (leftSubArray.empty()) {
                result += rightSubArray.top();
                rightSubArray.pop();
            } else if (rightSubArray.top() < leftSubArray.top()) {
                result += rightSubArray.top();
                rightSubArray.pop();
                if (right - 1 > left) {
                    right--;
                    rightSubArray.push(costs[right]);
                }
            } else {
                result += leftSubArray.top();
                leftSubArray.pop();
                if (left + 1 < right) {
                    left++;
                    leftSubArray.push(costs[left]);
                }
            }
            k--;
        }

        return result;
    }
};