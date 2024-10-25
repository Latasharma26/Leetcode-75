/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // To handle the case where the path itself is equal to targetSum
        return dfs(root, targetSum, 0, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, int targetSum, long long currentSum, std::unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        // Update the current sum
        currentSum += node->val;

        // Calculate the number of valid paths that end at this node
        int count = prefixSumCount[currentSum - targetSum];

        // Update the count of currentSum in the map
        prefixSumCount[currentSum]++;

        // Recur for left and right children
        count += dfs(node->left, targetSum, currentSum, prefixSumCount);
        count += dfs(node->right, targetSum, currentSum, prefixSumCount);

        // Restore the state for the current node before returning
        prefixSumCount[currentSum]--;

        return count; // Return the total count of valid paths
    }
};