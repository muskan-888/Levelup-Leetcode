#include<iostream>
using namespace std;
class LinkedList
{
   private:
    
    class Node{
      public:
      int data;
      Node*next;
      Node(int d)
      {
          this->data=d;
          this->next=nullptr;
      }
    };
    Node* head=nullptr;
    Node* tail=nullptr;
    int noOfnodes=0;
    
    public:

    int size()
    {
        return this->noOfnodes;
    }

    bool isEmpty(){
        return this->noOfnodes==0;
    }


    //to add data
    //1. add first element
    //2. add last element
    //3. add at given index
    protected:
    void handleSizeZero(Node* node)
    {
        this->head=node;
        this->tail=node;
    }
    
    void addFirstNode(Node* node)
    {
        if(this->size()==0)
        {
            handleSizeZero(node);
        }
        else
        {
            node->next=this->head;
            this->head=node;
        }
        this->noOfnodes++;
        
    }

    void addLastNode(Node* node)
    {
        if(this->size()==0)
        {
            handleSizeZero(node);
        }
        else
        {
            this->tail->next=node;
            this->tail=node;
        }
        this->noOfnodes++;
    }
    Node* getNodeAt(int idx)
    {
        Node* temp=head;
        while(idx-->0)
        {
            temp=temp->next;
        }
        return temp;
    }
    void addNodeat(Node* node,int idx)
    {
        if(idx==0)
        {
            addFirstNode(node);
        }
        else if(idx==size())
        {
            addLastNode(node);
        }
        else
        {
            Node*prv=getNodeAt(idx-1);
            Node*fwd=prv->next;
            prv->next=node;
            node->next=fwd;
            this->noOfnodes++;
        }
    }

    public:

    void addFirst(int data)
    {
        Node* node=new Node(data);
        addFirstNode(node);
    }


    void addLast(int data)
    {
        Node* node=new Node(data);
        addLastNode(node);
    }

    void addAt(int data,int idx)
    {
        if(idx<0||idx>size())
        {
            //Exception
            cout<<"INVALID INDEX";
            return;
        }
        Node* node=new Node(data);
        addNodeat(node,idx);
    }
    //to remove data
    //1. remove first element
    //2. remove last element
    //3. remove at given index
    protected:
    void handleSizeZero1()
    {
        this->head=nullptr;
        this->tail=nullptr;
    }
    Node* removeFirstNode()
    {
        Node* temp=this->head;
        if(size()-1==0)
        {
             handleSizeZero1();
        }
        else
        {
            this->head=this->head->next;
        }
        temp->next=nullptr;
        this->noOfnodes--;
        return temp;
    }
    public:

    int removeFirst()
    {
        if(size()==0)
        {
            //Exception
            cout<<"LL is empty\n";
            return -1;
        }
        return removeFirstNode()->data;
    }

    protected:
    Node* removeLastNode()
    {
        Node* temp=this->tail;
        if(size()==1)
        {
            handleSizeZero1();
        }
        else
        {
            Node* secondLastNode=getNodeAt(size()-2);
            secondLastNode->next=nullptr;
            this->tail=secondLastNode;
            
        }
        this->noOfnodes--;
        return temp;
        
    }
    public:

    int removeLast()
    {
        if(size()==0)
        {
            //Exception
            cout<<"LL is empty\n";
            return -1;            
        }
        Node* node=removeLastNode();
        return node->data;
    }
    protected:
    Node* removeNodeat(int idx)
    {
        if(idx==0)
        {
            return removeFirstNode();
        }
        else if(idx==size()-1)
        {
            return removeLastNode();
        }
        else
        {
            Node* prv=getNodeAt(idx-1);
            Node* temp=prv->next;
            Node* fwd=temp->next;
            prv->next=fwd;
            temp->next=nullptr;
            this->noOfnodes--;
            return temp;
        }
        
    }
    public:
    int removeAt(int idx)
    {
       if(size()==0)
       {
           //exception
           cout<<"LL is empty\n";
           return -1;
       }
       else if(idx<0 || idx>=size())
        {
            //Exception
            cout<<"Invalid Index\n";
            return -2;            
        } 
        Node* node=removeNodeat(idx);
        return node->data;
    }
    //to get data
    //1. of first element
    public:
    int getFirst()
    {
        if(size()==0)
        {
            //exception
            cout<<"LL is empty\n";
            return -1;
        }
        return this->head->data;
    }
    //2. of last element
    public:
    int getLast()
    {
        if(size()==0)
        {
            //exception
            cout<<"LL is empty\n";
            return -1;
        }
        return this->tail->data;
    }
    //3. of given index
    public:
    int getAt(int idx)
    {
       if(size()==0)
       {
           //exception
           cout<<"LL is empty\n";
           return -1;
       }
       else if(idx<0 || idx>=size())
        {
            //Exception
            cout<<"Invalid Index\n";
            return -1;            
        } 
        return getNodeAt(idx)->data;
    }
    //extra
    public:
    void display()
    {
        if(size()==0)
        {
            //exception
            cout<<"ll is empty\n";
            return;
        }
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        return;

    }

};

int main()
{
    LinkedList ll;
    ll.addFirst(1);
    ll.addAt(2,1);
    ll.addAt(3,2);
    ll.addAt(4,3);
    ll.addAt(5,4);
    cout<<ll.getFirst();
    cout<<"\n";
    cout<<ll.getLast();
    cout<<"\n";
    cout<<ll.getAt(3);
    cout<<"\n";
    ll.addLast(6);
    ll.display();
    cout<<"Remove at 5"<<ll.removeAt(5);
    ll.display();
    cout<<"Remove First"<<ll.removeFirst();
    cout<<"Remove Last"<<ll.removeLast();
    ll.display();
    
}