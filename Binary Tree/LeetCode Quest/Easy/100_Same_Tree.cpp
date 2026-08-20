
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q== NULL ) return false;  // use of AND & OR operator

        if(p->val!=q->val) return false;
        
        bool lft_tree= isSameTree(p->left , q->left);
        if(lft_tree==false ) return false;

        bool rgt_tree= isSameTree(p->right, q->right);
        if(rgt_tree ==false) return false;

        return true;

    }
};