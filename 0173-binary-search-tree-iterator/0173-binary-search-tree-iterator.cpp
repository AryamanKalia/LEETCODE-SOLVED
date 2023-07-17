/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* root ;
    int startno = INT_MIN;
    BSTIterator(TreeNode* root) {
        this->root=root;
        int no = root->val;
        while(root!=NULL){
            if(root->left==NULL){
                root=root->right;
            }
            else if(root->left!=NULL){
                root=root->left;
                no = min(no,root->val);
                
            }
        }
        startno = no-1;
    }
    
    int next() {
       TreeNode* temp = root;
        int find=startno+1;
        int found = INT_MAX;
        TreeNode* storage = NULL;
        while(temp!=NULL){
            if(temp->val<find){
                temp=temp->right;
            }
            else if(temp->val >=find){
                found=min(found,temp->val);
                temp=temp->left;
            }
        }
        return startno=found;
    }
    
    bool hasNext() {
        TreeNode* temp = root;
        int find=startno+1;
        int found = INT_MAX;
        bool ff= false;
        while(temp!=NULL){
            if(temp->val<find){
                temp=temp->right;
            }
            else if(temp->val >=find){
                ff=true;
                found=min(found,temp->val);
                temp=temp->left;
            }
        }
        return ff;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */