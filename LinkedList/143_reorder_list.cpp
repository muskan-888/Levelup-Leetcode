#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prv=nullptr;
        ListNode* curr=head;
        ListNode* fwd;
        while(curr!=nullptr)
        {
            fwd=curr->next;
            curr->next=prv;
            prv=curr;
            curr=fwd;
        }
        return prv;
        
    }
    void reorderList(ListNode* head) {
        
        if(head==nullptr|| head->next==nullptr)
            return ;
        
        ListNode* temp= middleNode(head);
        ListNode* nhead=reverse(temp->next);
        temp->next=nullptr;
        ListNode* n1=head;
        ListNode* n2=nhead;
        ListNode* item=n1;
        ListNode* fwd1;
        ListNode* fwd2;
        while(n1!=nullptr && n2!=nullptr)
        {
          fwd1=n1->next;
          fwd2=n2->next;
          
          n1->next=n2;
          n2->next=fwd1;
          
          n1=fwd1;
          n2=fwd2;  
          
        }
        /*
        if(n1!=nullptr)
            item->next=n1;
        if(n2!=nullptr)
        {
            item->next=n2;
        }*/
    }
    void printList(ListNode *node)
    {
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    }
    // Extra Question: retrieve the original array from the reordered one
    //sol1: 2 ll , keep addLast for one ll and addFirst for other
    //try it
    //sol2: using pointers
    void againReorder(ListNode* head)
    {
        if(head==nullptr||head->next==nullptr)
        return;
        //we have 3 pointers
        ListNode* c1=head;
        ListNode* c2=head->next;
        // we require to store c1 and c2
        // also you should not touch real heads, make copies
        //ListNode* h1=c1;
        ListNode* h2=c2;
        ListNode* f;
        // traverse in ll and 
        // for even stoppage condition is c2->next!=null
        //for odd stoppage condition is c2!=nullptr;
        while(c2!=nullptr && c2->next!=nullptr)
        {
            f=c2->next;

            c1->next= f;
            c2->next=f->next;

            c1=c1->next;
            c2=c2->next;
        }

        // now we have 2 ll c1 and c2, 
        // reverse c2 to get original second half ll
        // add to c1->next
        ListNode* h=reverse(h2);
        c1->next=h;
    }

int main()
{
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(4);
    ListNode* e=new ListNode(5);

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    reorderList(a);
    printList(a);
    againReorder(a);
    printList(a);
}