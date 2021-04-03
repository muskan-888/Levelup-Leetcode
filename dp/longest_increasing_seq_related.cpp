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
 int lengthm(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==0)
            return dp[i]=1;
        int maxx=0;
        if(dp[i]!=0) return dp[i];
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                maxx=max(maxx,lengthm(j,nums,dp));
            }
        }
        maxx++;
       return dp[i]=maxx;
    }
    int lengthOfLISm(vector<int>& nums) {
        int gmax=0;
        vector<int>dp(nums.size(),0);
       for(int i=nums.size()-1;i>=0;i--) 
       {
           gmax=max(gmax,lengthm(i,nums,dp));
       }
      
      return gmax;  
    }

//TABULATION

int lengthOfLISt(vector<int>& nums) {
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
void print_lis(int nums[],int gmax,int maxx,int idx,vector<int>&v,vector<int>dp)
{
    if(v.size()==gmax)
    {
        
        for(int i=v.size()-1;i>=0;i--)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<=idx;i++)
    {
       if(nums[i]<nums[idx]&&dp[i]==maxx-1)
       {
           v.push_back(nums[i]);
           print_lis(nums,gmax,maxx-1,i,v,dp);
           //v.pop_back();
       }
    }
   return;
    // how we will set range of so many elements?
    //vector<int> c=insert(v,0,)
}

int main()
{
    int nums[]={0,8,4,12,21,10,6,14,1,9,5,13,3,11,7,15,14};
    int n=17;
    vector<int>dp(n,0);
    int gmax=0;
    for(int i=0;i<n;i++)
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

    for(int i=0;i<n;i++)
    {
        if(dp[i]==gmax)
        {
            vector<int>v;
            v.push_back(nums[i]);
            print_lis(nums,gmax,gmax,i,v,dp);
        }
    }

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

// 673 No. of longest subsequences

class Solution {
public:
    int gmax=1;
    int glen=1;
   void nlis(vector<int>& nums,vector<vector<int>>& dp)
    {
       int n=nums.size();
       dp[0][0]=1;
       dp[0][1]=1;
       for(int i=1;i<n;i++)
       {
           int maxx=0;
           for(int j=0;j<i;j++)
           {
               if(nums[j]<nums[i])
               {
                   maxx=max(maxx,dp[j][0]);
               }
           }
           dp[i][0]=maxx+1;
           int count=0;
           for(int j=0;j<i;j++)
           {
               if(nums[j]<nums[i]&&dp[j][0]==maxx)
               {
                  count+=dp[j][1];
               }
           }
           dp[i][1]= (count==0)?1:count;
           if(dp[i][0]==gmax)
           {
               glen+=dp[i][1];
           }
           else if(dp[i][0]>gmax)
           {
               gmax=dp[i][0];
               glen=dp[i][1];
           }
       }
    }
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector<int>v(2,0);
        int n=nums.size();
        vector<vector<int>>dp(nums.size(),v);
        nlis(nums,dp);
        int maxx=0;
        /*for(int j=0;j<n;j++)
        {
                maxx=max(maxx,dp[j][0]);
        }
        int count=0;
        for(int j=0;j<n;j++)
        {
               if(dp[j][0]==maxx)
               {
                  count+=dp[j][1];
               }
        }*/
        return glen;
    }
};

