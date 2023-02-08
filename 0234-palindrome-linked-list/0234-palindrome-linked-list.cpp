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
    ListNode* reverse(ListNode* a){
        if(a->next==NULL){
            return a ;
        }
         ListNode* abc=reverse(a->next);
        a->next->next = a;
        a->next = NULL;
        return abc;
    }
    bool isPalindrome(ListNode* head) {
    ListNode* a= head;
    ListNode* aa = head;
    ListNode* aaa= head;
    while(aa!=NULL && aa->next!=NULL){
        a=a->next;
        aa=aa->next->next;
    }
         ListNode* abc = reverse(a);
        while(head!=NULL && abc!=NULL){
            if(head->val!=abc->val)return false;
            head=head->next;
            abc=abc->next;
        }
        return true;  
    }
};