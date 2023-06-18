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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>an;
        q.push(root);
        q.push(NULL);
        vector<int>san; 
        TreeNode* prev;
        if(root==NULL)return an;
        while(q.empty()!=true){
            
            if(q.front()!=NULL){
                san.push_back(q.front()->val);
                if(q.front()->left!=NULL)q.push(q.front()->left);
                if(q.front()->right!=NULL)q.push(q.front()->right);
                prev=q.front();
                q.pop();
            }
            else{
                q.push(NULL);
                if(prev!=NULL)
                q.pop();
                else break;
                prev=NULL;
                an.push_back(san);
                san.clear();
                
            }
        }
        return an;
    }
};