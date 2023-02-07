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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* heada=headA;
        ListNode* headb=headB;
        while(heada!=NULL){
            while(headb!=NULL){
                if(heada==headb){
                    return heada;
                }
                headb=headb->next;
            }
            headb=headB;
            heada=heada->next;
        }
        return heada;
    }
};