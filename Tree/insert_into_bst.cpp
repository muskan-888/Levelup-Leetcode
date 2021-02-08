
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
    //recursive
    TreeNode* insertIntoBST1(TreeNode* root, int val) {
        if(root==nullptr)
        {
            TreeNode* node=new TreeNode(val);
            return node;
        }
        
        if(root->val>val)
        {
            root->left=insertIntoBST(root->left, val);
        }
        else if(root->val<val)
        {
             root->right=insertIntoBST(root->right, val);
        }
        
        return root;
    }
    //iterative
     TreeNode* insertIntoBST(TreeNode* root, int val)
     {
         if(root==nullptr)
         {
            TreeNode* node=new TreeNode(val);
            return node;
         }
         TreeNode* item=root;
         while(item!=nullptr)
         {
             if(item->val>val)
            {
                
                if(item->left==nullptr)
                {
                    TreeNode* node=new TreeNode(val);
                    item->left=node;
                    break;
                }
                item=item->left; 
                 
            }
            else if(item->val<val)
            {
                if(item->right==nullptr)
                {
                    TreeNode* node=new TreeNode(val);
                    item->right=node;
                    break;
                }
                item=item->right;  
            }
         }
         
        return root;
     }
};