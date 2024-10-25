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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val); // Start DFS with the root value as the maximum
    }

private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0; // Base case: if the node is null, return 0

        // Check if the current node is good
        int count = (node->val >= maxVal) ? 1 : 0;
        
        // Update the maximum value on the path
        maxVal = std::max(maxVal, node->val);
        
        // Recur for left and right children
        count += dfs(node->left, maxVal);
        count += dfs(node->right, maxVal);

        return count; // Return the total count of good nodes
    }
};