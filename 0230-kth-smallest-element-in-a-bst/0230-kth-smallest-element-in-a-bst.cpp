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
    int ans;
    int kthSmallest(TreeNode* root,int k){
        someorder(root,k);
        return ans;
    }
    int someorder(TreeNode* root, int k) {
        if(root==NULL ) return k;
        if(k==INT_MIN) return INT_MIN;
        k=someorder(root->left,k);
        if(k==INT_MIN)return INT_MIN;
        k=--k;
        if(k==0) {ans = root->val; return INT_MIN;}
        k=someorder(root->right,k);
        if(k==INT_MIN) return INT_MIN;
        return k;
    }
};