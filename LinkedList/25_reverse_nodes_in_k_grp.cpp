#include<utility>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    // this solution has higher probability of error
    int find_length(ListNode* head)
    {
        int count=0;
        ListNode*item=head;
        while(item!=nullptr)
        {
            count++;
            item=item->next;
        }
     return count;
    }
    
    ListNode* set_c2(ListNode* c1, int k)
    {
        ListNode* c2=c1;
        k--;
        while(k-->0)
        {
            c2=c2->next;
        }
        return c2;
    }
    
    pair<ListNode*,ListNode*> reverse(ListNode* head, ListNode* tail)
    {
      ListNode* prv=nullptr;
      ListNode* curr= head;
      ListNode*fwd;
      while(curr!=nullptr)
      {
          fwd=curr->next;
          curr->next=prv;
          prv=curr;
          curr=fwd;
      }
      pair<ListNode*,ListNode*> p;
        p.first=tail;
        p.second=head;
        return p;
    }
    
    ListNode* reverseKGroup1(ListNode* head, int k) {
        
        if(head==nullptr || head->next==nullptr)
            return head;
        int len=find_length(head);
        
        int no_of_groups= len/k;
        
        ListNode* c1=head;
        ListNode* c2=head;
        ListNode* dummy= new ListNode(-1);
        ListNode* item=dummy;
            
        for(int i=0;i<no_of_groups;i++)
        {
            c2=set_c2(c1,k);
            ListNode* fwd=c2->next;
            c2->next=nullptr;
            ListNode* currhead=c1;
            ListNode* currtail=c2;
            
            pair<ListNode*,ListNode*> new_pair= reverse(currhead,currtail);
            
            item->next=new_pair.first;
            item=new_pair.second;
            
            c1=fwd;
        }
        item->next=c1;
        return dummy->next;
    }
    // In this,
    //We take curr and fwd to move and addFist to temporary head(th) and temporary tail(tt)
    //once length reaches k, add to original head (oh) and original tail(ot)
    ListNode *th = nullptr;
    ListNode *tt = nullptr;

    void addFirstNode(ListNode *node)
    {
    if (th == nullptr)
    {
        th = node;
        tt = node;
    }
    else
    {
        node->next = th;
        th = node;
    }
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        
        ListNode* curr=head;
        ListNode* fwd;
        
        int len=find_length(head);
        
        int no_of_groups= len/k;
        
        ListNode* oh=nullptr;
        ListNode* ot=nullptr;
        
        while(no_of_groups-->0)
        {
           int tempk=k;
           while(tempk-->0)
           {
               fwd=curr->next;
               curr->next=nullptr;
               addFirstNode(curr);
               curr=fwd;
           }
           if(oh==nullptr)
           {
               oh=th;
               ot=tt;
           }
            else
            {
                ot->next=th;
                ot=tt;
            }
            tt=nullptr;
            th=nullptr;
        }
        ot->next=curr;
        return oh;
    }
};