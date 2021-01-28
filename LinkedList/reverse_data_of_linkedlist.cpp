struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//in any ll problem, think if array would be there so how will you do it.
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
void dataReverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *mid = middleNode(head);
    ListNode *nhead = mid->next;
    mid->next = nullptr;

    nhead = reverse(nhead);

    ListNode *curr1 = head;
    ListNode *curr2 = nhead;

    while (curr1 != nullptr && curr2 != nullptr)
    {

        int temp = curr1->val;
        curr1->val = curr2->val;
        curr2->val = temp;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    nhead = reverse(nhead);
    mid->next = nhead;
}