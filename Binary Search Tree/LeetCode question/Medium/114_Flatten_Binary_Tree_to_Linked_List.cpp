        
           // morris traversal
           
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* r;
        TreeNode* pred;
        while(curr!=NULL){
            if(curr->left!=NULL){
                r=curr->right;
                curr->right=curr->left;
                // find predecessor
                pred=curr->left;
                while(pred->right!=NULL) pred=pred->right;
                pred->right=r;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        TreeNode* temp=root;
        while(temp!=NULL){
            temp->left=NULL;
            temp=temp->right;
        }
    }
};