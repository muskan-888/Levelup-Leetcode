//given a positive integer how will you find its square root up to 5 decimal places
#include<iostream>
//you can simply use sqrt 
// or use binary search
using namespace std;

float f(int n)
{
    int start=1,end=n;

    float ans;
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(mid*mid == n)
        {
            ans=mid;
            break;
        }

        else if(mid*mid < n)
        {
            ans=start;
            start=mid+1;
        }
        else
        end=mid-1;
    }

    float increment=0.1;

    for(int i=0;i<5;i++)
    {
        while(ans*ans <= n)
        {
            ans+=increment;
        }

        ans-=increment;
        increment/=10;
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<f(n);
}