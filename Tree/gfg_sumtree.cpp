#include<iostream>
using namespace std;
//https://practice.geeksforgeeks.org/problems/sum-tree/1/

struct Node
{
    int data;
    Node* left, * right;
};

pair<bool,int> f(Node*root)
{
    if(root==nullptr)
    return pair<bool,int>(1,0);
    
    if(root->left==nullptr && root->right==nullptr)
    {
        return make_pair(1,root->data);
    }
    
    pair<bool,int>left=f(root->left);
    pair<bool,int>right=f(root->right);
    
    int sum=left.second+right.second;
    pair<bool,int>p;
    p.second=sum+root->data;
    if(root->data!=sum || left.first==0 || right.first==0)
    {
        p.first=0;
    }
    else
    p.first=1;
    return p;
    
    
}