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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* a1= head;
        ListNode* a2=NULL;
     int count= 0;
        while(a1!=NULL){
            a2=a1;
            count++;
            a1=a1->next;
        }
        a2->next=head;
        k=count-(k%count);
        a1=head;
        int count1=0;
        for(count1= 0; count1<k-1;count1++){
            a1=a1->next;
        }
        a2=a1->next;
        a1->next=NULL;
        return a2;
        
        
    }
};