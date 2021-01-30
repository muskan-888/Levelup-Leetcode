
  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
     //brute force:reverse then remove nth node from start
     //then re-reverse(to avoid "ll modified error")
      //brute force: find length then traverse till n-1th node and remove nth node
      
       //one pass solution: O(n)
       //2 pointers with difference=n 
        //when second->next =nullptr, first=at n-1 node
        if(head==nullptr)
            return head;
        ListNode* c1=head;
        ListNode* c2=head;
        while(n-->0)
        {
            c2=c2->next;
        }
        
        if(c2==nullptr)
        {
            ListNode* temp=head;
            head=head->next;
            temp->next=nullptr;
            return head;
        }
        while(c2->next!=nullptr)
        {
          c1=c1->next;
          c2=c2->next;  
        }
        
        ListNode* temp=c1->next;
        c1->next=c1->next->next;
        delete temp;
        return head;
    }
};