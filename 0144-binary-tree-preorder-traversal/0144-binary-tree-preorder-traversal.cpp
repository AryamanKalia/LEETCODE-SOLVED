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
     void helper(TreeNode* root,vector<int>* abc){
        
        if(root==NULL){return ;}
         (*abc).push_back(root->val);
        helper(root->left,abc);
         helper(root->right,abc);
     }
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> abc;
        helper(root,&abc);
        return abc;
    }
};