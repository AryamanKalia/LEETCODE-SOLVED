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
    int maxlevel=INT_MIN;
    unordered_map<int,int> ans;
    void rightside(TreeNode* root,int level){
        if(root==NULL){
            return;
        }
        if(ans.find(level)==ans.end())
        ans[level]=root->val;
        maxlevel=max(level,maxlevel);
        rightside(root->right,level+1);
        rightside(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>anss;
        rightside(root,0);
        for(int i = 0; i<=maxlevel;i++){
            anss.push_back(ans[i]);
        }
        return anss;
    }
};