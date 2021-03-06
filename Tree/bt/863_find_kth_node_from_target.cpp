//IMPORTANT QUESTION

#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
 int val;
 TreeNode*left;
 TreeNode*right;
 TreeNode(int val)
 {
    this->val=val;
    this->left=nullptr;
    this->right=nullptr;
 }
};
//Time: O(n)
//from a node we can print K downwards
void printKdown(TreeNode* root,int k,TreeNode* block,vector<int>&ans)
{
    if(root==nullptr || k<0 || root==block) return;
    if(k==0)
    {
        ans.push_back(root->val);
        return;
    }

    printKdown(root->left,k-1,block,ans);
    printKdown(root->right,k-1,block,ans);
    return;
}

//now we take node to root path and at every node in that vector, we will print k nodes down from there
// also blocking from where we have come

bool find_node_to_root_path(TreeNode* node,TreeNode* k,vector<TreeNode*>&v)
{
    if(node==nullptr)
    return false;

    if(node==k)
    {
        v.push_back(node);
        return true;
    }

    bool left=find_node_to_root_path(node->left,k,v);
    bool right=find_node_to_root_path(node->right,k,v);

    if(left || right)
     v.push_back(node);
    return left||right;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
{
    //ans
    vector<int>ans;

    if(root==nullptr) return ans;
    vector<TreeNode*> list1;
    
    //contains node to root path
    find_node_to_root_path(root,target,list1);
    
    //block node
    TreeNode* block=nullptr;
    
    printKdown(list1[0],k,block,ans);

    
    //tranversing
    for(int i=1;i<list1.size();i++)
    {
        block=list1[i-1];
        printKdown(list1[i],k-i,block,ans);
    } 
    return ans;
}

//Optimised: To not find root to node path
//Avoiding that space and time:O(n)


int distanceatK1(TreeNode*root,TreeNode* target,int k,vector<int>&ans){
    if(root==nullptr )
    {
        return -1;
    }
    if(root==target)
    {
        block=nullptr;
        printKdown(root,k,nullptr,ans);
        return 1;
    }
    int left=distanceatK(root->left,target,k,ans);
    if(left!=-1)
    {
      printKdown(root,k-left,root->left,ans);
      return left+1;
    }
    bool right=distanceatK(root->right,target,k,ans);
    if(right!=-1)
    {
      printKdown(root,k-right,root->right,ans);
      return right+1;
    }
    return -1;
}


vector<int> distanceK1(TreeNode* root, TreeNode* target, int k) 
{
        vector<int> ans;
        int t=distanceatK1(root,target,k,ans);
        return ans;

}


// struct node{
//     int data;
//     int depth;
//     node*left;
//     node*right;
//     node(int data){
//         this->data=data;
//         left=right=NULL;
        
//     }

// };

// int find(int ino[],int istart,int iend,int x){
//     for(int i=istart;i<=iend;i++){
//         if(ino[i]==x)
//         return i;
//     }
//     return -1;
// }

// node* buildTree(int pre[],int ino[],int pstart,int pend,int istart,int iend){
//     if(pstart>pend)
//     return NULL;
    
//     node*root=new node(pre[pstart]);
//     int index=find(ino,istart,iend,pre[pstart]);
//     int l=index-istart;
//     root->left=buildTree(pre,ino,pstart+1,pstart+l,istart,index-1);
//     root->right=buildTree(pre,ino,pstart+l+1,pend,index+1,iend);
//     return root;

// }
// void set_depth(node*&root){
// int c=0;
//     queue<node*>q;
//      queue<node*>q1;

//      if(root==NULL)
//      return;
//      q.push(root);
//      while(!q.empty()||!q1.empty()){
//          while(!q.empty()){
//              node*curr=q.front();
//              q.pop();
//              curr->depth=c;
//              if(curr->left)
//              q1.push(curr->left);
//              if(curr->right)
//              q1.push(curr->right);
//          }
//          c++;
//          while(!q1.empty()){
//              node*curr=q1.front();
//              q1.pop();
//              curr->depth=c;
//              if(curr->left)
//              q.push(curr->left);
//              if(curr->right)
//              q.push(curr->right);
//          }
//          c++;


//      }
// }

// void print(node*root){
//     if(!root)
//     return;
//     queue<node*>q;
//         queue<node*>q1;

//     q.push(root);
//     while(!q.empty()||!q1.empty()){
//         while(!q.empty()){
//         node*curr=q.front();
//         q.pop();
//         cout<<curr->data<<" "<<curr->depth<<" || ";
//         if(curr->left)
//         q1.push(curr->left);
//         if(curr->right)
//         q1.push(curr->right);
//         }
//         cout<<"\n";
//         while(!q1.empty()){
//         node*curr=q1.front();
//         q1.pop();
//         cout<<curr->data<<" "<<curr->depth<<" || ";
//         if(curr->left)
//         q.push(curr->left);
//         if(curr->right)
//         q.push(curr->right);
//         }
//         cout<<"\n";
//     }
// }

// set <int> myset;
// void print_At(node*root,int t){
// if(root==NULL)
// return;
// if(root->depth==t){
// myset.insert(root->data);
// }
// print_At(root->left,t);
// print_At(root->right,t);
// return;
// }
// pair<bool,int> print_at_k(node*root,int x,int y){
    
//     if(root==NULL)
//     {
//         pair<bool,int>p(0,0);
//     return p;
//     }
//     if(root->data==x){
//         pair<bool,int>curr;
//         curr.first=1;
//         curr.second=root->depth;
//         int t=root->depth+y;
//         print_At(root,t);
//         return curr;
//     }
//     pair<bool,int> left=print_at_k(root->left,x,y);
//     pair<bool,int> right=print_at_k(root->right,x,y);
     
//      if(!left.first&&!right.first)
//      return right;
    
// if(!left.first&&right.first){
//     int r=(right.second)-root->depth;
    
//     if(r==y)
//       myset.insert(root->data);
     
//      else if(r<y){
//          int t=(root->depth)+(y-r);
//          print_At(root->left,t);}
//     return right;
// }

// if(left.first&&!right.first){
//      int r=(left.second)-root->depth;
//      if(r==y)
//       myset.insert(root->data);
     
//      else if(r<y){
//                   int t=(root->depth)+(y-r);

//          print_At(root->right,t);
//      }
     
//     return left;
// }
// }

// int main(){
//     int n,pre[10000],ino[10000],x,y;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>pre[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>ino[i];
//     }

//     node*root=buildTree(pre,ino,0,n-1,0,n-1);
//     set_depth(root);
//     //print(root);
//     int t;
//     cin>>t;
//     for(int j=0;j<t;j++){
//         cin>>x>>y;
//         print_at_k(root,x,y);
        
//         if(myset.empty()){
//             cout<<0;
//         }
//         else{
//             for(auto it=myset.begin();it!=myset.end();it++){
//             cout<<*it<<" ";
//         }  }
//         cout<<"\n";
//         myset.clear();
//           }
//     }


// pair<Node*,int> printk(Node*node,Node*target,int k)
// {
//   if(node==null)
//   return pair<Node*,int>(node,-1);

//   if(node==target)
//   {
//       print_at_k()
//   }
// }