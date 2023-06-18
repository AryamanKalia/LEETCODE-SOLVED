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
class Solution {
public:
    bool matching(TreeNode* root,TreeNode* subroot){
        if(root==NULL && subroot == NULL){
            return true;
        }
        else if((root==NULL && subroot!=NULL )|| (root!=NULL && subroot==NULL)){
            return false;
        }
        if(root->val==subroot->val){
            return matching(root->left,subroot->left) && matching(root->right,subroot->right);
        }
        return false;
    }
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) {
        return true;
    } else if ((root == NULL && subRoot != NULL) || (root != NULL && subRoot == NULL)) {
        return false;
    }
    if (matching(root, subRoot) == true) {
        return true;
    }
    bool a = isSubtree(root->left, subRoot);
    bool b = isSubtree(root->right, subRoot);
    return a || b;
}
};