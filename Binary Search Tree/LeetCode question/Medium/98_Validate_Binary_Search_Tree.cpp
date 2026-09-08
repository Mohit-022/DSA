
class Solution {
public:
    // long long maxTree(TreeNode* root){
    //     if(root==NULL) return LLONG_MIN;
    //     return max((long long)(root->val), max( maxTree(root->left), maxTree(root->right) ) );
    // }
    // long long minTree(TreeNode* root){
    //     if(root==NULL) return LLONG_MAX;
    //     return min((long long) (root->val), min( minTree(root->left), minTree(root->right) ) );
    // }
    // bool isValidBST(TreeNode* root) {
    //     if(root==NULL) return true;
    //     else if(root->left==NULL && root->right ==NULL) return true;
    //     else if( (long long) (root->val) <= maxTree(root->left) ) return false;
    //     else if( (long long)(root->val) >= minTree(root->right) ) return false;
    //     return isValidBST(root->left) &&  isValidBST(root->right);
        

    // }
    bool preorder(TreeNode* root, vector<int>&v){
        if(root==NULL) return true;
        preorder(root->left,v) ;
        v.push_back(root->val);
        preorder(root->right,v);
        return true;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
};