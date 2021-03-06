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
 TreeNode* createbst(vector<int>& in, vector<int>& post, int insi,int inei,int postsi,int postei)
    {
        if(insi>inei)
        {
            return nullptr;
        }
        
        TreeNode*root=new TreeNode(post[postei]);
        int idx=insi;
        while(idx<=inei)
        {
            if(in[idx]==root->val)
                break;
            idx++;
        }
        int total=idx-insi;
        root->left= createbst(in,post,insi,insi+total-1,postsi,postsi+total-1);
        root->right= createbst(in,post,idx+1,inei,postsi+total,postei-1);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createbst(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }