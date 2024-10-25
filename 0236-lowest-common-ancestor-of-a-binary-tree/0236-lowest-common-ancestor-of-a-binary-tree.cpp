/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if we reach a null node or find either p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Recursively search in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are non-null, the current node is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // If only one side is non-null, return that side
        return left != nullptr ? left : right;
    }
};