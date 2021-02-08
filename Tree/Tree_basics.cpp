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

int size(TreeNode* node)
{
    return (node==nullptr)?0: size(node->left)+size(node->right)+1;
}

int maximum(TreeNode* node)
{
    if(node==nullptr) return (int)-1e9;

    int left=maximum(node->left);
    int right=maximum(node->right);
    int y=max(left,right);
    return max(y,node->val);
}

//with node, if node==null return 0
//with edge, return -1 as for leaf we will get 1 but it has no edge
int height(TreeNode* node)
{
   return (node==nullptr)?0:max(height(node->left),height(node->right))+1;
}

bool find(TreeNode* node, int key)
{
    if(node==nullptr) return false;
    if(node->val==key) return true;
    bool left=find(node->left,key);
    bool right=find(node->right,key);
    return (left||right);
}
vector<TreeNode*> v;
bool find_node_to_root_path(TreeNode* node,int k)
{
    if(node==nullptr)
    return false;

    if(node->val==k)
    {
        v.push_back(node);
        return true;
    }

    bool left=find_node_to_root_path(node->left,k);
    bool right=find_node_to_root_path(node->right,k);

    if(left || right)
     v.push_back(node);
    return left||right;
}

// without global

vector<TreeNode*> findnode_to_root_path(TreeNode* node,int k)
{
  if(node==nullptr)
  {
      vector<TreeNode*>v;
      return v;
  }
  vector<TreeNode*> left= findnode_to_root_path(node->left,k);
  if(left.size()!=0)
  {
      left.push_back(node);
      return left;
  }
  vector<TreeNode*> right= findnode_to_root_path(node->right,k);
  if(right.size()!=0)
  {
      right.push_back(node);
      return right;
  }

  vector<TreeNode*>v;
  return v; 

}