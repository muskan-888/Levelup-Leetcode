//issue aa rha hn

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(vector<int>a,vector<int>b)
{
    return a[2]<b[2];
}
int minCost(int n,vector<int>&wells,vector<vector<int>>&pipes)
{
   vector<bool>vis(wells.size()+1,0);

   for(int i=1;i<=n;i++)
   {
       vector<int>v;
       v.push_back(i);
       v.push_back(i);
       v.push_back(wells[i-1]);
       pipes.push_back(v);
   }

   sort(pipes.begin(),pipes.end(),compare);
   int viscount=0;
   int i=0;
   int weight=0;
   while(viscount<n)
   {
       vector<int>v=pipes[i];
       i++;
       if(vis[v[0]]==0)
       {
           vis[v[0]]=1;
           viscount++;
           weight+=v[2];
       } 
   }

   return weight;
}