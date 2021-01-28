

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    // iterative
    ListNode* reverseList2(ListNode* head) {
        //put this condition everytime
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
        // once done writing the code, dry run for these edge cases
        //1. nullptr
        //2. single node
        //3. double node
        //4. even
        //5. odd
    }
    
    //recursive
    //faith: func reverse list 
    ListNode* reverseList(ListNode* head) { 
       if(head==nullptr || head->next==nullptr) 
           return head;
       ListNode* temp=head->next;
       head->next=nullptr; 
       ListNode* nhead=reverseList(temp);
       temp->next=head;
       return nhead; 
        
    }
};