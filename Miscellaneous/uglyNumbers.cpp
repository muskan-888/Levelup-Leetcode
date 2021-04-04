#include<iostream>
#include<vector>
#define ull unsigned long long
using namespace std;
    ull getNthUglyNo(int n) {
	   //Time: O(n)
	   //Space: O(n)
	   
	   //not int, vector type is ull
	   
	   vector<ull>v(n);
	   v[0]=1;
	   int i2=0;
	   int i3=0;
	   int i5=0;
	   // running loop from 1 to n-1
	   for(int i=1;i<n;i++)
	   {
	       v[i]=min(v[i2]*2,min(v[i3]*3,v[i5]*5));
	       
	       // all ifs as for equal values say in case of 2*3 and 3*2
	       //we will increment both
	       if(v[i]==v[i2]*2)
	       {
	           i2+=1;
	       }
	           
	       if(v[i]==v[i3]*3)
	       {
	           i3+=1;
	       }
	  
	       if(v[i]==v[i5]*5)
	       {
	           i5+=1;
	       }
	           
	       
	   }
	   // returning last index
	   return v[n-1];
	}