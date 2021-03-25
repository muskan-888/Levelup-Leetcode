//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

#include<iostream>
#include<vector>
using namespace std;
    /*You are required to complete below method */
    int mod=(int) 1e9+7;
    // '&' should be used str as well 
    long long count(string &str,int i,int j,vector<vector<long long>>&dp)
    {
        //if length is 2 or 1
        if(i>=j) 
        {
            dp[i][j]=(i==j)?1:0;
            return dp[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long a=count(str,i+1,j,dp);
        long long b=count(str,i,j-1,dp);
        long long c=count(str,i+1,j-1,dp);
        //analysis in notebook
        return dp[i][j]= ((str[i]!=str[j])? a+b-c + mod: a+b+1) %mod;
        
    }
    long long int  countPS(string str)
    {
       int n=str.length();    
       vector<vector<long long>>dp;
       vector<long long> v(n,-1);
       for(int i=0;i<n;i++) dp.push_back(v);
       return count(str,0,n-1,dp);
    }
     