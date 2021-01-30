
 struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* th=nullptr;
    ListNode* tt=nullptr;
    
    void addFirstNode(ListNode* curr)
    {
       if(th==nullptr)
       {
           th=curr;
           tt=curr;
       }
        else
        {
            curr->next=th;
            th=curr;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode *curr = head;
    ListNode *prev = nullptr;

    int idx = 1;

    while (curr != nullptr)
    {
        while (idx >= m && idx <= n)
        {
            ListNode *forw = curr->next;
            curr->next = nullptr;
            addFirstNode(curr);
            curr = forw;
            idx++;
        }

        if (idx > n)
        {
            if (prev != nullptr)
            {
                prev->next = th;
                tt->next = curr;
                return head;
            }
            else
            {
                tt->next = curr;
                return th;
            }
        }

        idx++;
        prev = curr;
        curr = curr->next;
    }

    return head;
    }
};