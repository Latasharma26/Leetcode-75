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
    void collectLeaves(TreeNode* root, std::vector<int>& leaves) {
        if (!root) return;
        // If it's a leaf node, add its value
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        // Otherwise, go left and right
        collectLeaves(root->left, leaves);
        collectLeaves(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1, leaves2;
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        return leaves1 == leaves2; // Compare the two leaf sequences
    }
};