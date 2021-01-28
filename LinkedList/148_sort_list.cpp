
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    // this is nlogn method merge sort
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        //very imp to dry run, you got deadly signal for this while loop condition
        //while(fast!=nullptr && fast->next=nullptr)
        //as it will fail for 2 elements list
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr || l2==nullptr) return l1==nullptr?l2:l1;
        ListNode* n1=l1;
        ListNode* n2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* item=dummy;
        ListNode* fwd1;
        ListNode* fwd2;
        while(n1!=nullptr && n2!=nullptr)
        {
          fwd1=n1->next;
          fwd2=n2->next;
          if(n1->val < n2->val)
          {
              item->next=n1;
              n1=fwd1;
              
          }
          else
          {
              item->next=n2;
              n2=fwd2;
          }
         item=item->next;

        }
      
       if(n1!=nullptr)
           item->next=n1;
       if(n2!=nullptr)
           item->next=n2;
        ListNode* h=dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return h;
    }
    ListNode* sortList(ListNode* head) 
    {
        //find mid node
        //call the function to divide both ll parts
        //on coming back from recursion call, merge the two ll
        //and return
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode*midNode=middleNode(head);
        ListNode* midnext=midNode->next;
        midNode->next=nullptr;
        ListNode* leftsortedlist=sortList(head);
        ListNode* rightsortedlist=sortList(midnext);
        return mergeTwoLists(leftsortedlist,rightsortedlist);
    }
};