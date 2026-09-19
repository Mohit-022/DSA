
class Solution {
public:
    TreeNode* find(TreeNode* root, int start){
        if(root==NULL) return NULL;
        if(root->val==start) {
            return root;
        }
        TreeNode* left=find(root->left,start);
        if(left!=NULL) return left;
        return find(root->right, start);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(levels(root->left), levels(root->right));
    }
    void parentMark( TreeNode* root, unordered_map< TreeNode*, TreeNode* >&parent){
        if(root==NULL) return;
        if(root->left!=NULL){
            parent[root->left]=root;
        }
        if(root->right!=NULL){
            parent[root->right]=root;
        }
        parentMark(root->left, parent);
        parentMark(root->right, parent);
    }
    int amountOfTime(TreeNode* root, int start) {
        int timeCount;
        TreeNode* tempNode= find(root,start);  // finding start root
        if(root==tempNode) {
            timeCount=levels(root);
            return timeCount-1;
        }

        unordered_map< TreeNode*, TreeNode* >parent; // first node = child, second node =parent... storing parent in map
        parentMark(root,parent);  // marking node with parent and inserting in parent map

        queue< pair<TreeNode*,int> >q; // first node = 
        q.push ({tempNode,0});

        unordered_set<TreeNode*>isInfected; // to mark that is tree already infected or not... if yes do not count agian
        isInfected.insert(tempNode);
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int level=q.front().second;
            q.pop();
            timeCount= max(timeCount,level);
            if(temp->left!=NULL){ // root->left exist
                if(isInfected.find(temp->left)==isInfected.end()) {  // not infected
                    q.push({temp->left,level+1});
                    isInfected.insert(temp->left);
                }  
            }
            if(temp->right!=NULL){  // root->right exist
                if(isInfected.find(temp->right)==isInfected.end()){
                    q.push({temp->right,level+1});
                    isInfected.insert(temp->right);
                }        
            }
            if(parent.find(temp)!=parent.end()){  // if parent exist
                if(isInfected.find(parent[temp])==isInfected.end()) {
                    q.push({parent[temp],level+1});
                    isInfected.insert(parent[temp]);
                }
            }   
        }
    return timeCount;
    }
    
};