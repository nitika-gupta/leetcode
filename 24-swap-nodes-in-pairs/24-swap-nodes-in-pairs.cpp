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
    ListNode* swapPairs(ListNode* head) {
        ListNode* thead =new ListNode(-1);
        ListNode* curr=head;
        if(curr== NULL || curr->next==NULL){
            return curr;
        }
        ListNode* prev=new ListNode(-1);
        while(curr!=NULL && curr->next!=NULL){
            ListNode* temp=curr->next->next;
            ListNode*temp1=curr->next;
             temp1->next=curr;
            curr->next=temp;
            if(thead->val==-1){
                thead=temp1;
            }
            if(prev->val!=-1){
                prev->next=temp1;
            }
            prev=curr;
            curr=temp;
        }
        return thead;
    }
};