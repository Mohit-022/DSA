
class Solution {
public:
    void ReversePreorder(TreeNode* root, int &sum){
        if(root==NULL) return;
        ReversePreorder(root->right,sum);
        sum+=root->val;
        
        root->val=sum;
        ReversePreorder(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum=0;
        ReversePreorder(root,sum);
        return root;
    }
};