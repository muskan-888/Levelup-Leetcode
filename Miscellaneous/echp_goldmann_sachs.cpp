/*Technical assessment

30mins: 2 coding questions
Q1. (story type, just summarising)given a string, find how many pairs of similar characters you can form.
A. store in hashmap with count of alphabets and then run loop on map and return  result by adding it->second/2 to it, 
also return -1 if count is zero.
Q2. I completed previous in just 5-6 mins and was left with 25 mins for this one, but I complicated it and when finally coded the solution, 
it had bugs for which I was not of time.Below is the question.
Scored:20/50


25 mins:Prob. solving
Very bad, managed to do just 2 questions out of 8.
Scored: 10/40

20 mins: Comp. science fundamentals
good enough, did 5 questions
Scored: 25/35

45 mins: advance coding (graph hi aaya)
given matrix with connections shown with one and not connected with zero.Print the higher influental people
(who are connected with maximum no. of other influental people)
Initially I thought, just printing elements with maximum number of children but only 6/12 passed.
Then, thought of storing sum of their children's children and printing maximum of that ==>12/12 passed

Scored: 100/100

15 mins: Behavioural
Same questions of 1)wht you will your teammate left in between(I answered in terms of STAR method)
2) how your passion motivated you towards a goal and result was outstanding.
10 marks each
Score: IDK

section 6: cgpa==>8.5(border line)

Now, The regretfull question,isse karke chainki neend aati(as 3 section mein cutoff paar)

Q2.Given level order traversal , print the nodes with atleast one node and print in inorder.[Ab simple lag rha hn mein ne bohot socha bekar ka
wht if level order na karu toh?] Attempting it now*/

#include<iostream>
#include<queue>
using namespace std;

struct node{
 int idx,val;
 node* left;
 node* right;
 node(int val,int idx)
 {
     this->val=val;
     this->idx=idx;
     left=nullptr;
     right=nullptr;
 }
};

void print1(node* root)
{
    if(root==nullptr)
    return;
    print1(root->left);
    if(root->left || root->right)
    cout<<root->val<<" ";
    print1(root->right);
}
/*INITIALLY
void print(string str)
{
    queue<node*>q;
    node*root=new node(str[0]-'0',0);
    q.push(root);
    while(!q.empty())
    {
       node* x= q.front();
       q.pop();
       int i=x->idx;
       int l=2*i+1;
       int r=2*i+2;
       if(l<str.length() && str[l]!='-')
       {
           node*left=new node(str[l]-'0',l);
           x->left=left;
           q.push(left);
       }
       if(r<str.length() && str[r]!='-')
       {
           node*right=new node(str[r]-'0',r);
           x->right=right;
           q.push(right);
       }
    }
    print1(root);
}
*/

void print(vector<int>&v)
{
    queue<node*>q;
    node*root=new node(v[0],0);
    q.push(root);
    while(!q.empty())
    {
       node* x= q.front();
       q.pop();
       int i=x->idx;
       int l=2*i+1;
       int r=2*i+2;
       if(l<v.size() && v[l]!=-1)
       {
           node*left=new node(v[l],l);
           x->left=left;
           q.push(left);
       }
       if(r<v.size() && v[r]!=-1)
       {
           node*right=new node(v[r],r);
           x->right=right;
           q.push(right);
       }
    }
    print1(root);
}
int main()
{
    //shit vo characters the
    // bas -'0' and inorder traversal mein || instead of &&
    // ig ek aur cheez miss hn, if numbers are double digits? I guess spacing bhi hn inme
    string str="20 9 49 5 12 23 52 - - - 15 - - 50";
    // better to convert it to an array
    vector<int>v;
    int i=0;
    while(i<str.length())
    {
        if(str[i]=='-'){
        v.push_back(-1);
        i+=2;
        }

        else
        {
            int num=0;
            while(str[i]!=' ')
            {
                num=num*10+(str[i]-'0');
                i++;
            }
            v.push_back(num);
            i++;
        }
     }
     print(v);
}

//DONE(nhi hota 25 mins mein, itna dimag nhi lagta, and tension alag hi hoti hn exam mein)