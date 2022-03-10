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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1==NULL && l2==NULL)
            return NULL;
        int c=0;
        ListNode* res= new ListNode(0);
        ListNode* l3=res;
        
        while(l1 && l2){
            int sum=l1->val +l2->val +c;
            c=sum/10;
        
            l3->next=new ListNode(sum%10);
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
             int sum=l1->val +c;
            c=sum/10;
        
            l3->next = new ListNode(sum%10);
            
            l3=l3->next;
            l1=l1->next;
        }
        while(l2){
             int sum=l2->val +c;
            c=sum/10;
          
            l3->next = new ListNode(sum%10);
            
            l3=l3->next;
            l2=l2->next;
        }
        if(c>0){
            l3->next=new ListNode(c);
        }
        return res->next;
        
    }
};