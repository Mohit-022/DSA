
class Solution {
public:
    bool exist(TreeNode *root, TreeNode *target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exist(root->left,target) || exist(root->right,target); // if found return true
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q ) return root; // agr root hi p ya q ho to return root

       // agr ek left and ek right mtlb root hi ancestor hai
        else if( exist(root->left,p) && exist(root->right,q) ) return root; 
        else if( exist(root->left,q) && exist(root->right,p) ) return root;

        // agr dono left me hai to left ke trf jao 
        else if( exist(root->left, p) && exist(root->left,q) ) return lowestCommonAncestor(root->left, p, q);
        // agr dono right me hai to right ke trf search kro
        else return lowestCommonAncestor(root->right, p, q);
        


    }
};