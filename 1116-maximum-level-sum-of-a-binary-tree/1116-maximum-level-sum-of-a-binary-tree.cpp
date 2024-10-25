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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int maxLevel = 1;
        int currentLevel = 1;

        // Perform BFS traversal
        while (!q.empty()) {
            int levelSize = q.size();
            int currentSum = 0;

            // Traverse all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;

                // Add the child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Update the maximum sum and level
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = currentLevel;
            }

            // Move to the next level
            currentLevel++;
        }

        return maxLevel;
    }
};