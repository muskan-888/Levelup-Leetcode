//Hackerrank
//since we have to make components, we will use unionfind
//final answer= ab+ac+ad+
//              bc+bd+
//              cd+
//where a,b,c,d are populations of different  countries
#include<vector>
#include<iostream>
using namespace std;
vector<int>par;
vector<int>size;

int findpar(int n)
{
    return par[n]==n?n:par[n]=findpar(par[n]);
}

void merge(int p1,int p2) // no need though, as you can choose anyone as a leader
{
    if(size[p1]>size[p2])
    {
        par[p2]=p1;  
        size[p1]+=size[p2];  
    }
    else 
    {
        par[p1]=p2;
        size[p2]+=size[p1];    
    }
}
long journeyToMoon(int n, vector<vector<int>> astronaut) 
{
 for(int i=0;i<n;i++)
 {
     par.push_back(i);
     size.push_back(1);
 }
 
 for(int i=0;i<astronaut.size();i++)
 {
    int x=astronaut[i][0];
    int y=astronaut[i][1];
    int p1=findpar(x);
    int p2=findpar(y);
    if(p1!=p2)
    {
        merge(p1,p2);
    }
 }
  long sum=0;
 int l=0;
 for(int i=0;i<n;i++)
 {
     if(par[i]==i)
     {
         sum+=size[i]*l;
         l+=size[i];
         
     }
 }
 return sum;
}

