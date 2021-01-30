
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
   //S0LUTION 1
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
      
        if(headA==nullptr || headB==nullptr)
           return 0;
        
        ListNode* slow=headA;
        ListNode* fast=headA;
        //n time
        while(slow->next!=nullptr)
        {
            slow=slow->next;
        }
        ListNode* tail=slow;
        slow->next=headB;
        slow=headA;
        //a+b time
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
               break;
        }
        
        if(fast!=slow)
        {
            tail->next=nullptr;
            return nullptr;
        }
        slow=headA;
        //a time
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        tail->next=nullptr;
        return slow;
        }
        //Total time=n+a+b+a=2a+b+n
        
    //SOLUTION 2
    //Length of one list=n 
    //Length of other list=m
    //run longer one difference(len(l1)[whichever is greater]-len(l2))=n-m
    //put both pointer at start of both lists
    //and run till they reach same point
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA==nullptr || headB==nullptr)
           return nullptr;
        
        ListNode *l1=headA;
        ListNode *l2=headB;
        int len1=0,len2=0;
        while(l1!=nullptr)
        {
            len1++;
            l1=l1->next;
        }
        
        while(l2!=nullptr)
        {
            len2++;
            l2=l2->next;
        }
        ListNode *biggerlist=len1>len2?headA:headB;
        ListNode *smallerlist=len1>len2?headB:headA;
        
        int count=len2>len1?len2-len1:len1-len2;
        while(biggerlist!=nullptr && count!=0)
        {
            count--;
            biggerlist=biggerlist->next;
        }
        
        while(biggerlist!=nullptr && smallerlist!=nullptr && smallerlist!=biggerlist)
        {
            biggerlist=biggerlist->next;
            smallerlist=smallerlist->next;
        }
        return biggerlist;
    }
    
};