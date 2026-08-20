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
    int level(TreeNode* root){
        if(root==NULL ) return 0;
        return 1+max(level(root->left), level(root->right));
    }
    int helper(TreeNode* root, int &maxDia){
        if(root==NULL ) return 0;
        
        int dia=level(root->left)+level(root->right);
        maxDia=max(maxDia, dia);
        helper(root->left, maxDia);
        helper(root->right, maxDia);
        return maxDia;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxDia=INT_MIN;
      
        return helper(root, maxDia);
    }
};