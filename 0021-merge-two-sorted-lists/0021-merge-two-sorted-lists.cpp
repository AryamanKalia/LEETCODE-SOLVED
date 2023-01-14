/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1 ;
        ListNode* temp2 = list2;
        ListNode* temp33 = new ListNode();
        ListNode* temp3  = temp33;
        while(temp1!=NULL || temp2!=NULL){
            if(temp1==NULL){
                temp3->next=temp2;
               temp2=NULL;
            }else
            if(temp2==NULL){
                temp3->next=temp1;
                temp1=NULL;
            }
            else
            if(temp1->val<=temp2->val){
                temp3->next=temp1;
                temp1=temp1->next;
                temp3=temp3->next;
                temp3->next=NULL;
            }else{
                temp3->next=temp2;
                temp2=temp2->next;
                temp3=temp3->next;
                temp3->next=NULL;
                
            }
        }
        return temp33->next;
    }
};