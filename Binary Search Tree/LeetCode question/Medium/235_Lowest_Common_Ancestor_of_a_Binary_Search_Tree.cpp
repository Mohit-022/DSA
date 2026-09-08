
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return root;
        else if(root==p || root==q) return root;
        else if( (root->val) > (p->val) &&  (root->val) < (q->val) ) return root;
        else if( (root->val) > (q->val) &&  (root->val) < (p->val) ) return root;
        else if( (root->val) > (p->val) &&  (root->val) > (q->val)) return helper(root->left, p,q);
        else if( (root->val) < (p->val) &&  (root->val) < (q->val)) return helper(root->right, p,q);
        else return root;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};