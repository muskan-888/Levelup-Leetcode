//Efficient way to find prime factors of a number
/*
SAMPLE 1:
Enter a number1000000
2 2 2 2 2 2 5 5 5 5 5 5 

SAMPLE 2:
Enter a number4699569
3 7 31 7219
*/
#include<iostream>
#include<math.h>
using namespace std;

void print_primes(int n)
{
    if(n==0)
    return;

    while(n%2==0)
    {
        cout<<2<<" ";
        n=n/2;
    }
    //now number is odd
    // so we will iterate only for odd numbers
    // till sqrt(n)
    // as if no element lies before sqrt(n) when no element after sqrt(n) can divide the number

    for(int i=3;i<=sqrt(n);i=i+2)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>2)
    {
        cout<<n<<" ";
    }
    return;
}

int main()
{
  int n;
  cout<<"Enter a number";
  cin>>n;
  print_primes(n);
}