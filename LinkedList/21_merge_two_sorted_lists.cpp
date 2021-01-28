struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// this was better than 100% of leetcode submission
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr && l2==nullptr) return l1;
        else if(l1==nullptr) return l2;
        else if(l2==nullptr) return l1;
        ListNode* temp;
        ListNode* n1=l1;
        ListNode* n2=l2;
        if(l1->val < l2->val)
        {
            temp=l1;
            n1=l1->next;
        }
        else
        {
            temp=l2;
            n2=l2->next;
        }
        
        ListNode* item=temp;
        ListNode* fwd1;
        ListNode* fwd2;
        while(n1!=nullptr && n2!=nullptr)
        {
          fwd1=n1->next;
          fwd2=n2->next;
          if(n1->val < n2->val)
          {
              item->next=n1;
              item=item->next;
              n1=fwd1;
              
          }
          else
          {
              item->next=n2;
              item=item->next;

              n2=fwd2;
          }
        }
        
       if(n1!=nullptr)
           item->next=n1;
       if(n2!=nullptr)
           item->next=n2;
        return temp;
    }

// this is shorter code got better than 84.11 %

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr || l2==nullptr) return l1==nullptr?l2:l1;
        // ListNode* temp;
        ListNode* n1=l1;
        ListNode* n2=l2;
        /*if(l1->val < l2->val)
        {
            temp=l1;
            n1=l1->next;
        }
        else
        {
            temp=l2;
            n2=l2->next;
        }*/
        //instead of above
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
        // better to return dummy's memory
        ListNode* h=dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return h;
    }