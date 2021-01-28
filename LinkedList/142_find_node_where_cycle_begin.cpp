struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 ListNode *detectCycle(ListNode *head) {
        
       if(head==nullptr || head->next==nullptr)
           return 0;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
               break;
        }
        
        if(fast!=slow)
            return nullptr;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
  