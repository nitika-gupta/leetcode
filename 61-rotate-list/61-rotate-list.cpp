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
        if(head==NULL || head->next==NULL)
            return head;
         
        
        int c=0;
        
        ListNode* temp=head;
        ListNode* th=head;
        while(temp){
            c++;
            temp=temp->next;
            
        }
        cout<<c;
        
        k=k%c;
        if(k%c==0)
            return head;
        temp=head;
        int n=c-k;
        cout<<n;
        while(n>1){
            temp=temp->next;
            n--;
        }
        
        
        
        th=temp->next;
        temp->next=NULL;
        cout<<th->val;
        temp=th;
        if(th!=NULL){
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
            return th;
            
        }
        return head;
        
    }
};