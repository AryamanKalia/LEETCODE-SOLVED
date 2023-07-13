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
    TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->val = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        // If the tree is empty, create a new node and return it as the root
        return createNode(data);
    } else {
        // Recursively insert the data in the appropriate subtree
        if (data <= root->val)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0 ; i<preorder.size();i++){
            root=insert(root,preorder[i]);
        }
        return root;
    }
};