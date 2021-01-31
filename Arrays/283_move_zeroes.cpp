#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=-1,itr=0;
        for(;itr<nums.size();)
        {
            if(nums[itr]!=0)
            {
                p++;
                swap(nums[p],nums[itr]);
            }
             itr++;
        }
    }
};