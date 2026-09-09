
class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right!=NULL){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        else if(root->val == key){
            // case 1: no child
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            // case 2: 1 child node
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
            // case 3: 2 child node 
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* pred= iop(root); //ipo=inorder to predesesor
                root->val=pred->val;
                root->left= deleteNode(root->left, pred->val);
                
            }

        }
        else if(root->val > key){   // go left
            root->left=deleteNode(root->left, key);
        }
        else if(root->val < key){    // go right
            root->right=deleteNode(root->right, key);
        }
        return root;
    }
};