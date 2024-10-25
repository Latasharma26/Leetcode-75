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
    int longestZigZag(TreeNode* root) {
        return dfs(root, true, 0);  // Start DFS with root, initial direction doesn't matter
    }

private:
    int dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return length - 1;  // If node is NULL, return length minus one (base case)

        // Recursively calculate the ZigZag path from the left and right subtrees
        if (isLeft) {
            // Move to the left child (next move will be to the right) or right child (reset length)
            return std::max(dfs(node->left, false, length + 1), dfs(node->right, true, 1));
        } else {
            // Move to the right child (next move will be to the left) or left child (reset length)
            return std::max(dfs(node->left, false, 1), dfs(node->right, true, length + 1));
        }
    }
};
