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

TreeNode* createbst(vector<int>& pre, vector<int>& post, int presi,int preei,int postsi,int postei)
    {
        if(presi>preei)
        {
            return nullptr;
        }
        
        if(presi==preei)
        {
            TreeNode*root=new TreeNode(post[postei]);
            return root;
        }
        TreeNode*root=new TreeNode(post[postei]);
        int val=pre[presi+1];
        int idx=postsi; 
        while(idx<postei)
        {
            if(post[idx]==val)
                break;
            idx++;
        }
        int total=idx-postsi;
        root->left= createbst(pre,post,presi+1,presi+total+1,postsi,idx);
        root->right= createbst(pre,post,presi+total+2,preei,idx+1,postei-1);
        return root;
        
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return createbst(pre,post,0,pre.size()-1,0,post.size()-1);
        
    }