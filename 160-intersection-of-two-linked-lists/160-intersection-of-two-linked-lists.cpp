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
        
        
        ListNode* t1=headA;
        ListNode* t2=headB;
        
        int c1=0,c2=0;
        while(t1!=NULL){
            c1++;
            t1=t1->next;
        }
        while(t2!=NULL){
            c2++;
            t2=t2->next;
        }
        
        int d=abs(c1-c2);
        if(c1>c2){
            while(d>0){
            headA=headA->next;
            d--;
            }
        }
        else if(c2>c1){
            while(d>0){
            headB=headB->next;
            d--;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
            
        }
        return NULL;
    }
};