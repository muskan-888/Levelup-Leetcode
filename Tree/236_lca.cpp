#include<bits/stdc++.h>
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
class Solution {
public:
    TreeNode*ans;
    bool find(TreeNode* root, TreeNode*p,TreeNode*q)
    {
        if(root==nullptr)
            return false;
        if(root==p||root==q)
        {
            ans=root;
            return true;
        }
        
        bool left=find(root->left,p,q);
        bool right=find(root->right,p,q);
        if(left==1 && right==1)
        {
            ans=root;
            return true;
        }
        return left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root,p,q);
        return ans;
    }
};

//sir's method using root_to_node

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

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==nullptr) return root;
    vector<TreeNode*> list1;
    vector<TreeNode*> list2;

    find_node_to_root_path(root,p,list1);
    find_node_to_root_path(root,q,list2);

    int i=list1.size()-1;
    int j=list2.size()-1;
    TreeNode* LCA;
    while(i!=0 && j!=0)
    {
        if(list1[i]!=list2[j])
         break;
        LCA=list1[i];
        i--;
        j--;
    }
    return LCA;
}