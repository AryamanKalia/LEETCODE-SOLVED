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
    bool validstuff(TreeNode* root,  long long int llim,  long long int hlim){
        if(root==NULL)return true;
        if(root->val>llim && root->val<hlim){
            bool b1 = validstuff(root->left,llim,root->val);
            bool b2 = validstuff(root->right,root->val,hlim);
            return b1*b2;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return validstuff(root,numeric_limits<long long int >::min(),numeric_limits<long long int>::max());
    }
};