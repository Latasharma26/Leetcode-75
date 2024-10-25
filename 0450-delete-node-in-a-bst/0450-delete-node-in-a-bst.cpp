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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        // Step 1: Search for the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Search in the left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Search in the right subtree
        } else {
            // Node to delete found (root->val == key)
            
            // Case 1: Node with only one child or no child
            if (!root->left) return root->right; // Node has no left child, replace with right child
            if (!root->right) return root->left; // Node has no right child, replace with left child
            
            // Case 2: Node with two children
            // Find the in-order successor (smallest value in the right subtree)
            TreeNode* successor = findMin(root->right);
            // Replace the value of the node to be deleted with the successor's value
            root->val = successor->val;
            // Delete the in-order successor
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root;
    }
    
    // Helper function to find the minimum value node in the subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};