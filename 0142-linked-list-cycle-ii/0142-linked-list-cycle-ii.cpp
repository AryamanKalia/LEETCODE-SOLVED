/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* temp3 = head;
        while(temp1!=NULL && temp1->next!=NULL){
            temp1=temp1->next->next;
            temp2=temp2->next;
            if(temp1==temp2){break;}
        }
        if(temp1==NULL || temp1->next==NULL){return  NULL;}
        while(temp1!=temp3){
            temp1=temp1->next;
            temp3=temp3->next;
        }
        return temp3;
    }
};