#include<iostream>
#include<vector>
using namespace std;
//RECURSION
//This gives tle, bohot saari calls hn
int length(int i,vector<int>&nums)
    {
        if(i==0)
            return 1;
        // not -1e9, becoz if we dont find any small element we have to return 1 for just that element
        int maxx=0;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                maxx=max(maxx,length(j,nums));
            }
        }
        maxx++;
       return maxx;
    }
    int lengthOfLIS(vector<int>& nums) {
        //here, if no lis, so min value will be 1 only(can put gmax=1 as well)
        int gmax=0;
       for(int i=nums.size()-1;i>=0;i--) 
       {
           gmax=max(gmax,length(i,nums));
       }
      
      return gmax;  
    }
//MEMOISATION

// using dp array
 int length(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==0)
            return dp[i]=1;
        int maxx=0;
        if(dp[i]!=0) return dp[i];
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                maxx=max(maxx,length(j,nums,dp));
            }
        }
        maxx++;
       return dp[i]=maxx;
    }
    int lengthOfLIS(vector<int>& nums) {
        int gmax=0;
        vector<int>dp(nums.size(),0);
       for(int i=nums.size()-1;i>=0;i--) 
       {
           gmax=max(gmax,length(i,nums,dp));
       }
      
      return gmax;  
    }

//TABULATION

int lengthOfLIS(vector<int>& nums) {
    // idx element depends on previos values
    // And we just take max of all previous indexes values and store max+1 in my current index
    vector<int>dp(nums.size(),0);
    int gmax=0;
    for(int i=0;i<nums.size();i++)
    {
        
        dp[i]=1;
        int maxx=0;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                maxx=max(maxx,dp[j]);
            }
        }
        dp[i]=maxx+1;
        gmax=max(gmax,dp[i]);
    }
        return gmax;
}

// minimum Number of deletion to be performed to make array sorted (array
// contain -1e7 <= ele <= 1e7)

//if we find the lis of the array, we know longest sorted subsequence kya hogi, so phir hume, total arr length se subtract that value of lis length
//that would be minimum deletion required
//copy pasted above code
int min_deletion(vector<int>& nums) {
    // idx element depends on previos values
    // And we just take max of all previous indexes values and store max+1 in my current index
    vector<int>dp(nums.size(),0);
    int gmax=0;
    for(int i=0;i<nums.size();i++)
    {
        
        dp[i]=1;
        int maxx=0;
        for(int j=0;j<i;j++)
        {
            // a bit change, you will take equal elements into consideration,as sorting ki baat ho rhi hn 
            if(nums[j]<=nums[i])
            {
                maxx=max(maxx,dp[j]);
            }
        }
        dp[i]=maxx+1;
        gmax=max(gmax,dp[i]);
    }
    //and this is changed
    return nums.size()-gmax;
}


//Print all lis
void print_lis(vector<int>&dp)
{
    int maxx=0;
    for(int i=0;i<dp.size();i++)
    {
        maxx=max(maxx,dp[i]);
    }
    vector<vector<int>>v;
    // how we will set range of so many elements?
    //vector<int> c=insert(v,0,)
}

// Longest increasing sum subsequence
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

// in this on comparing elements we dont need to store lis length, we can store the sum so far till present index and take that as max

int max_sum_inc_sub(vector<int>& nums) {
    vector<int>dp(nums.size(),0);
    int gmax=0;
    for(int i=0;i<nums.size();i++)
    {
        
        dp[i]=nums[i];
        int maxx=0;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                maxx=max(maxx,dp[j]);
            }
        }
        dp[i]=maxx+nums[i];
        gmax=max(gmax,dp[i]);
    }
        return gmax;
}

// Maximum Sum Increasing Subsequence of Maximum Length.

// now find max sum and that should be in maximum length
//will see tomorrow
int max_sum__longest_inc_sub(vector<int>& nums) {
    int n=nums.size();
    vector<pair<int,int>>dp(n,make_pair(0,0));
    int gmax=0;
    for(int i=0;i<nums.size();i++)
    {
        int maxx=0;
        int maxsum=0;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                if(dp[j].first==maxx)
                {
                    maxsum=max(dp[j].second,maxsum);
                }
                else if(dp[j].first>maxx)
                {
                    maxx=max(maxx,dp[j].first);
                }
            }
        }
        dp[i].first=maxx+1;
        dp[i].second=maxsum+nums[i];
        gmax=max(gmax,dp[i].second);
    }
        return gmax;
}