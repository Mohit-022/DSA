
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return; // base case
       
        inorder(root->left,ans);  // left work
        ans.push_back(root->val);  // pushing Root in vector
        inorder(root->right,ans);  // right work
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        return ans;
        
    }
};