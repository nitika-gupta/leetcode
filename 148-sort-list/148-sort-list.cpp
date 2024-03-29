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
    ListNode* middle(ListNode* head){
        if(head==NULL){
            return NULL;
        }
       ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        return mid;
                
    }
    
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h= new ListNode(0);
        ListNode* head=h;
        
        if(l1 ==NULL && l2==NULL){
            return NULL;
        }
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
    
        while(l1 && l2){
        if(l1->val==l2->val){
            head->next= new ListNode(l1->val);
            head=head->next;
            l1=l1->next;
            head->next= new ListNode(l2->val);
            l2=l2->next;
            head=head->next;
        }
        else if(l1->val<l2->val){
             head->next=new ListNode(l1->val);
             head=head->next;
             l1=l1->next;
         }
            else if(l2->val< l1->val){
                head->next= new ListNode(l2->val);
                head=head->next;
                l2=l2->next;
            }
        }
        if(l1)
            head->next=l1;
        
        if(l2)
            head->next=l2;
        
        return h->next;
    }
        
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid =middle(head);
        ListNode* head1=sortList(head);
        ListNode* head2=sortList(mid);
        ListNode * ans= mergeTwoLists(head1,head2);
        return ans;
    }
};