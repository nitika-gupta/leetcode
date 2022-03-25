// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
      Node* reverse(Node * head)
    {
        // Initialize current, previous and
        if(head==NULL)
            return NULL;
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head==NULL || head->next==NULL)
        return head;
        
        
        int count=0;
        //cout<<count;
        Node* h=head;
        while(h){
            h=h->next;
            count++;
        }
        
        k=k%count;
        if(k==0){
            return head;
        }
        head= reverse(head);
      //  cout<< head->data;
      k=count-k-1;
        Node * temp=head;
      //  if(count%2==0)
        while(k!=0){
            temp=temp->next;
            k--;
        }
        
        Node* t1=temp->next;
        temp->next=NULL;
        head=reverse(head);
        t1=reverse(t1);
        
        Node* t2=head;
        while(t2->next){
            t2=t2->next;
        }
        t2->next=t1;
        return head;
        
        
        
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends