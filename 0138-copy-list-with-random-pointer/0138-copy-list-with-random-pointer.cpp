/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        // create a map from original nodes to copied nodes
        unordered_map<Node*, Node*> maper;
        // create a dummy node for the new head
        Node* newhead = new Node(-1);
        // create two pointers for the original and copied lists
        Node* temp = head;
        Node* temp2 = newhead;
        // iterate through the original list and copy each node
        while(temp != NULL){
            // create a new node with the same value as the original node
            temp2->next = new Node(temp->val);
            // add the pair of original and copied nodes to the map
            maper[temp] = temp2->next;
            // move both pointers to the next nodes
            temp = temp->next;
            temp2 = temp2->next;
        }
        // reset the pointers to the heads of both lists
        temp = head;
        temp2 = newhead->next;
        // iterate through both lists and copy the random pointers
        while(temp != NULL){
            // if the original node has a random pointer, find its corresponding copied node in the map and assign it to the copied node's random pointer
            if(temp->random != NULL){
                temp2->random = maper[temp->random];
            }
            // otherwise, set the copied node's random pointer to NULL
            else{
                temp2->random = NULL;
            }
            // move both pointers to the next nodes
            temp = temp->next;
            temp2 = temp2->next;
        }
        // return the head of the copied list
        return newhead->next;        
    }
};