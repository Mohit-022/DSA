
class Solution {
public:
    void insert(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL){
                root->left =new TreeNode(val);
            }
            else{
                insert(root->left,val);
            }
        }
        else // if(root->val < val)
        {
            if(root->right == NULL){
                root->right =new TreeNode(val);
            }
            else{
                insert(root->right,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            root=new TreeNode(val);
            return root;
        }
        else{
            insert(root, val);
            return root;
        }
    }
};