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
   TreeNode* createbst(vector<int>& in, vector<int>& pre, int insi,int inei,int presi,int preei)
    {
        if(insi>inei)
        {
            return nullptr;
        }
        
        TreeNode*root=new TreeNode(pre[presi]);
        int idx=insi;
        while(idx<=inei)
        {
            if(in[idx]==root->val)
                break;
            idx++;
        }
        int total=idx-insi;
        root->left= createbst(in,pre,insi,insi+total-1,presi+1,presi+total);
        root->right= createbst(in,pre,idx+1,inei,presi+1+total,preei);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     return createbst(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);

    }
};