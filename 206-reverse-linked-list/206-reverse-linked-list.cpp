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
    ListNode* ans;
    void reverse(ListNode* curr){
        if(curr==NULL){
            return;
        }
        if(curr->next==NULL){
            ans=curr;
            return;
        }
        
       reverse(curr->next);
        ListNode* temp=curr->next;
        temp->next=curr;
        curr->next=NULL;
        
       
    }
    ListNode* reverseList(ListNode* head) {
        ans=head;
        reverse(head);
        return ans;
    }
};