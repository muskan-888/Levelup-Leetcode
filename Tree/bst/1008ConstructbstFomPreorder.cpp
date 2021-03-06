#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* createbst(vector<int>& preorder,int si,int ei)
    {
        if(si>ei)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[si]);
        int idx=si+1;
        while(idx<=ei)
        {
            if(preorder[idx]>root->val)
                break;
            idx++;
        }

        root->left=createbst(preorder,si+1,idx-1);
        root->right=createbst(preorder,idx,ei);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createbst(preorder,0,preorder.size()-1);
        
    }
};