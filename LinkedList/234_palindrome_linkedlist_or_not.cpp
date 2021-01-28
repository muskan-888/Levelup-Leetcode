struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
      if(head==nullptr || head->next==nullptr)
      {
          return head;
      }
      ListNode* prv=nullptr;
      ListNode*curr= head;
      ListNode*fwd;
      while(curr!=nullptr)
      {
          fwd=curr->next;
          curr->next=prv;
          prv=curr;
          curr=fwd;
      }
        return prv;
    }
    bool isPalindrome2(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return 1;
        // we get the middle address
        ListNode* mid=middleNode(head);
        // we reverse rest of the list
        ListNode* reversehead=reverse(mid->next);
        mid->next=nullptr;
        ListNode *curr1=head;
        ListNode* curr2=reversehead;
        bool res=true;
        while(curr1!=nullptr && curr2!=nullptr)
        {
            if(curr1->val != curr2->val)
            {
                res=false;
                break;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        // we changed ll so undoing the changes made
        mid->next=reverse(reversehead);
        return res;
    }
    
    //recursive
    bool isPalindrome(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
        {
            return 1;
        }
        
    }
    
};