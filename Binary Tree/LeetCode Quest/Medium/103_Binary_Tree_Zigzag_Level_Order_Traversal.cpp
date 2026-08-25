
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    void levelorder(TreeNode* root, int crr, int level, vector<int>&v){
        if(root==NULL) return;
        if(crr==level){
            v.push_back(root->val);
            return;
        }
        if(level%2!=0){
            levelorder(root->left,crr+1, level, v);
            levelorder(root->right,crr+1, level, v);
        }else{
            levelorder(root->right,crr+1, level, v);
            levelorder(root->left,crr+1, level, v);
        
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int n=levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            levelorder(root,1,i,v);
            ans.push_back(v);
        }
        return ans;
    }
};