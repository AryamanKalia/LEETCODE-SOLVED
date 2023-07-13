class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* temp = new TreeNode(-1,NULL,NULL);
        preorder(root,temp);
        root->left = nullptr;
        root->right = temp->right->right;
    }
    
    TreeNode* preorder(TreeNode* root,TreeNode* temp){
        if (root ==NULL) return temp ;
        temp->right=new TreeNode(root->val,NULL,NULL);
        TreeNode* temp2=temp->right;
        temp2->left=NULL;
       temp2 = preorder(root->left,temp2);
        temp2=preorder(root->right,temp2);
        return temp2;
    }
};
