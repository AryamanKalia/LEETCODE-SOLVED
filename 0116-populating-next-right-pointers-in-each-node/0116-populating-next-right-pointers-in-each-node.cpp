/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         if (root == nullptr)
        return root ;

    std::queue<Node*> q;
    q.push(root);
    q.push(nullptr);  // Level delimiter
    Node* prev = NULL;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if(prev==NULL){}
        else{
            prev->next=current;
        }
        prev=current;
        if (current == nullptr) {
            if (!q.empty())
            { q.push(nullptr); } // Add delimiter for next level
        } else {
            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }
        return root;
    }
};