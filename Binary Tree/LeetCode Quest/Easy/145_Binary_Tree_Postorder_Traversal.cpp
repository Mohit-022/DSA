
class Solution {
public:
    void postorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return; // base case
        postorder(root->left,ans);  // left work
        postorder(root->right,ans);  // right work
        ans.push_back(root->val);  // pushing Root in vector
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root, ans);
        return ans;
        
    }
};
