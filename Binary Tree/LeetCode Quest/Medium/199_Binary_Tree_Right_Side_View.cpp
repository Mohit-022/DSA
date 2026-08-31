
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(levels(root->left), levels(root->right));
    }
    void nthLevel(TreeNode*root, vector<int>&ans, int curr, int level){
        if(root==NULL) return;
        if(curr==level){
            ans[curr]=root->val;
            return;
        }
        nthLevel(root->left,ans, curr+1,level);
        nthLevel(root->right, ans, curr+1,level);
    }
    void levelorder(TreeNode* root, vector<int>&ans){
        if(root==NULL) return;
        int n=ans.size();
        for(int i=0;i<n;i++){
            nthLevel(root,ans,0,i);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(levels(root),0);
        levelorder(root,ans);
        return ans;
    }
};