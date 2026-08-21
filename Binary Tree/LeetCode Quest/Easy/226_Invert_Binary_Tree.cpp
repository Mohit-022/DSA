
class Solution {
public:
    void reverse(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return ;

        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;

    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL ) return root;

        reverse(root);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
    
};