#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   // without division
   // zero extra space
   // O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        
        ans[0]=1;
        
        for(int i=1;i<nums.size();i++)
        {
          ans[i]=nums[i-1]*ans[i-1];  
        }
        
        int r=1;
        for(int i=ans.size()-1;i>=0;i--)
        {
            ans[i]*=r;
            r*=nums[i];
        }
        return ans;
    }
};