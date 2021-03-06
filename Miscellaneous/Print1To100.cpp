//task to print 1 to 100 without using any digits/numbers 
#include<iostream>
#include<vector>
using namespace std;
void f()
{
 int x;
 int*p2=&x;
 int*p1=p2;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
 ++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;++p1;
vector<int>v;
 while(p1>p2)
 {
    v.push_back(p1-p2);
    p1--;
 } 
 
 while(!v.empty())
 { auto i=v.back();
    cout<<i<<"\n";
   v.pop_back();
 }
}

// one solution
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
for(int i=('J'-'I');i<='d';i++)
cout<<i<<"\n";
return 0;
}
