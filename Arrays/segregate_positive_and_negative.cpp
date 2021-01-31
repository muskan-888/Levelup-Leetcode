#include<iostream>
#include<vector>
using namespace std;

//takes O(n) time and O(1) space
// Brute force: 
//(1) sort and reverse
//(2) make another array and two pointers positive and negative

// In this, we define regions
// p pointer holds the boundary of positive numbers(including p)
// itr is travelling unexplored region
//[0,p]==>positive
//[p+1,itr)==>negative
//[itr,v.size()-1]==>unexplored
void segregatePosAndNega(vector<int>&v)
{
    int p=-1;
    int itr=0;
    while(itr<v.size())
    {
        if(v[itr]>=0)
        {
            p++;
            swap(v[p],v[itr]);
        }
        itr++;
    }
    return;
}

int main()
{
 vector<int>v(6,0);
 v[0]=-1;
 v[1]=4;
 v[2]=8;
 v[3]=-17;
 v[4]=24;
 v[5]=32;

 segregatePosAndNega(v);

 for(int i=0;i<6;i++)
 {
     cout<<v[i]<<" ";
 }
}