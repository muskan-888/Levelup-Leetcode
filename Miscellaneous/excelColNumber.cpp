#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string ExcelColumn(int n)
    {
        // Your code goes here
        map<int,char>m;
        char ch='A';
        //if mod with 26 is zero, we require it to be 'Z'
        m[0]='Z';
        for(int i=1;i<=25;i++){
        m[i]=(char)ch;
        ch++;
        }
        string ans="";
        while(n!=0)
        {
            // to reverse the string
            string t=ans;
            ans=m[(n%26)];
            ans+=t;
            if(n%26==0)
            n=(n/26)-1;
            else
            n=n/26;
        }
        return ans;
    }
};