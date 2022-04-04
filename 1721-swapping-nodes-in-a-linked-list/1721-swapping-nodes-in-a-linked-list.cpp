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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        int v1=0;
        int v2=0;
        
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        
        ListNode* n1;
        ListNode* n2;
        
        temp=head;
        
        while(temp){
             v1++;
            v2++;
            if(v1==k){
                n1=temp;
            }
            if(v2==n-k+1){
                n2=temp;
            }
           
            temp=temp->next;
            
        }
        int  t1 =n1->val;
        n1->val=n2->val;
        n2->val=t1;
        return head;
        
    }
};