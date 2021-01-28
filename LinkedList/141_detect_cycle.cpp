struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle1(ListNode *head) {
       if(head==nullptr || head->next==nullptr)
           return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return 1;
        }
        return 0;
    }
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(!fast || !fast->next){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};