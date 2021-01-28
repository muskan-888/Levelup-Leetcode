#include<vector>
#include<utility>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    // time: (finding min)*(total no. of elements)= k*(kn)
    // no good writing of code, break it into functions
    // another way of doing it is: k*n^2 only
    //tranverse list and merge 2 lists, then merge 3rd list and (1+2) sorted list
    /*ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return nullptr;
        ListNode* dummy=new ListNode(-1);
        ListNode*prv=dummy;
        ListNode* minNode=lists[0];
        int minidx=0;
        int count;
        while(count<lists.size())
        {
            count=0;
        for(int i=1;i<lists.size();i++)
        { 
            if(lists[i]==nullptr)
                count++;
            else if(lists[i]!=nullptr && (lists[i]->val < minNode->val))
            {
                minNode=lists[i];
                minidx=i;
            }
        }
            if(count==lists.size())
                break;
        prv->next=minNode;
        prv=prv->next;
        lists[minidx]=minNode->next;
        minNode=lists[minidx];
        }
    
    return dummy->next;
    }*/
    
    pair<ListNode*,int> findmin(vector<ListNode*>& lists)
    {
        int count=0;
        
        ListNode* mine=lists[0];
        int minidx=0;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]==nullptr)
            {
                count++;
            }
            //when mine was initialised to nullptr, we update it with first non-null node
            else if(mine==nullptr)
            {
                mine=lists[i];
                minidx=i;
            }
            else if(mine!=nullptr && lists[i]->val<mine->val)
            {
                mine=lists[i];
                minidx=i;
            }
           
        }
        if(count==lists.size())
            return pair<ListNode*,int>(nullptr,0);
        else
        {
            return pair<ListNode*,int>(mine,minidx);
        }
    }
    
    ListNode* mergeKLists1(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return nullptr;
        
        //a min func to find min index and min node for a list
        //if all list element are null, it returns nullptr as node
        pair<ListNode*,int> min_element;
        ListNode* dummy=new ListNode(-1);
        ListNode*prv=dummy;
        do
        {
            min_element=findmin(lists);
            ListNode* minNode=min_element.first;
            int minidx=min_element.second;
             prv->next=min_element.first;
             prv=prv->next;
            if(minNode!=nullptr)
             lists[minidx]=minNode->next;
        }while(min_element.first!=nullptr);
      return dummy->next;
    }
    
    // time: knlog(k)
    //instead of travelling whole array, go for dividing it into 2
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
    ListNode* mergeK(vector<ListNode*>& lists, int si,int ei)
    {
        if(si==ei)
            return lists[si];
        int mid=(si+ei)/2;
        ListNode* left=mergeK(lists,si,mid);
        ListNode* right=mergeK(lists,mid+1,ei);
        
       return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return nullptr;
        
        return mergeK(lists,0,lists.size()-1);
    }
    
    
