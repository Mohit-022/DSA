
class Solution {
public:
    void helper(TreeNode* root, string s, vector<string>&v){
        if(root==NULL) return;
        if( root->left==NULL && root->right==NULL ) {
            s+=to_string(root->val);
            v.push_back(s);
            return;
            
        }
        helper(root->left,s+to_string(root->val)+"->",v);
        helper(root->right,s+to_string(root->val)+"->",v);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        
        helper(root,"",v);
        return v;
    }
};