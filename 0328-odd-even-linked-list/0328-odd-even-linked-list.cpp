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
//     ListNode* oddList(ListNode* head){
//         ListNode* head1 = new ListNode(-1);
//     }
//     ListNode* evenList(ListNode* head){
        
// }
    ListNode* oddEvenList(ListNode* head) {
        ListNode* head1= new ListNode(-1);
        ListNode* temp1=head1;
        ListNode* head2 = new ListNode(-1);
        ListNode* temp2 = head2;
        ListNode* temp = head;
        int turn = 1;
        while(temp!=NULL){
            if(turn ==1){
                temp1->next=temp;
                temp1=temp1->next;
                temp=temp->next;
                temp1->next=NULL;
                turn = 0;
            }
            else{
                temp2->next=temp;
                temp2=temp2->next;
                temp=temp->next;
                temp2->next=NULL;
                turn = 1;
            }
        }
        temp1=head1;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=head2->next;
        return head1->next;
    }
};