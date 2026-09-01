
class Solution {
public:
    void helper(TreeNode* root, int targetSum,int currSum,vector<vector<int>>&ans,vector<int>v){
        if(root==NULL) return ;
        v.push_back(root->val);
        currSum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(currSum==targetSum) {
                ans.push_back(v);
                return;
            }
        }
       
        helper(root->left,targetSum, currSum,ans,v);
        helper(root->right,targetSum, currSum,ans,v);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(root,targetSum,0,ans,v);
        return ans;

    }
};