#include <iostream>    
using namespace std;    
class Animal {                                          //  base class declaration.  
    public:    
    string color = "Black";      
};     
class Dog: public Animal                       // inheriting Animal class.  
{      
 public:    
    string color = "Grey";      
};    
int main(void) {    
     Animal d= Dog();      
    cout<<d.color;     
}    


#include <iostream>
#include<vector>
using namespace std;

int countOccurrence(int n,string grid[],string word)// n is the number of rows/columns in the grid, grid contains all the characters. 
    // word is the given input string whose number of occurrences has to be found.
{
    int count=0;
    
    // WRITE YOUR CODE HERE
    vector<vector<char>> v;
    for(int i=0;i<n;i++)
    {
        string s=grid[i];
        vector<char>vi;
        for(int j=0;j<n;j++)
        {
            vi.push_back(s[j]);
        }
        v.push_back(vi);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==word[0])
            {
                int x,y;
                //1,0
                int k=0;
                for(x=i,y=j;k<word.length()&& x<n;x++)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(k==word.length())
                count++;
                //1,1
                k=0;
                for(x=i,y=j;k<word.length()&& y<n && x<n;x++,y++)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(k==word.length())
                count++;
                //0,1
                k=0;
                for(x=i,y=j;k<word.length()&& y<n;y++)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(k==word.length())
                count++;
                //-1,1
                k=0;
                for(x=i,y=j;k<word.length()&& x>=0 && y<n;x--,y++)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(k==word.length())
                count++;
                //-1,0
                k=0;
                for(x=i,y=j;k<word.length()&& x>=0;x--)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if( k==word.length())
                count++;
                //-1,-1
                k=0;
                for(x=i,y=j;k<word.length()&& x>=0 && y>=0;x--,y--)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(x==-1 && k==word.length())
                count++;
                //0,-1
                k=0;
                for(x=i,y=j;k<word.length()&& y>=0;y--)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(k==word.length())
                count++;
                //1,-1
                k=0;
                for(x=i,y=j;k<word.length()&& x<n && y>=0;x++,y--)
                {
                    if(v[x][y]!=word[k])
                    break;
                    k++;
                }
                if(k==word.length())
                count++;
                
                
            }
        }
    }
    
    return count;
}

int main() 
{
    int n;
    cin >> n;
    string grid[n];
    for(int i=0; i<n; i++)
    {
        cin>>grid[i];
    }
    string word;
    cin>>word;
    cout<<countOccurrence(n,grid,word);
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

vector<int> climbingScoreboard(int s, int scores[], int x, int trial[]) // s is the number of players and scores contains the top s scores, 
// x is the number of attempts allowed per player, trial contains Ekta's scores in x attempts
{
    vector<int> res;
    for(int i=0; i<x; i++)
        res.push_back(0);
    
    // WRITE YOUR CODE HERE
    unordered_map<int,int> mymap;
    
    int rank=1;
    for(int i=0;i<s;i++)
    {
        if(mymap.find(scores[i])!=mymap.end())
        continue;
        mymap[scores[i]]=rank;
        rank++;
    }
    int minrank=(int)1e9;
    for(int i=0;i<x;i++)
    {
        int pscore=trial[i];
        if(mymap.find(pscore)!=mymap.end())
        {
            minrank=min(minrank,mymap[pscore]);
            res[i]=minrank;
        }
        else {
         int j;
         for(j=0;j<s;j++)
         {
             if(scores[j]<pscore)
             {
                 break;
             }
         }
         if(j!=s){
         minrank=min(minrank,mymap[scores[j]]);
         mymap[pscore]=mymap[scores[j]];
         res[i]=minrank;
         int prv=-1;
         for(;j<s;j++)
         {
            if(prv!=scores[j]){
            mymap[scores[j]]+=1;}
            prv=scores[j];
         }
         }
         else {
           mymap[pscore]=mymap[scores[j-1]]+1;
           minrank=min(minrank,mymap[pscore]);
           res[i]=minrank;
         }
        }
    }
    return res;
}

int main()
{
    int scores_count,trial_count;
    cin >> scores_count;
    int scores[scores_count];
    for(int i=0; i<scores_count; ++i)
    {
        cin>>scores[i];
    }
    cin >> trial_count;
    int trial[trial_count];
    for(int i=0; i<trial_count; ++i)
    {
        cin>>trial[i];
    }
    vector<int> rank = climbingScoreboard(scores_count,scores,trial_count,trial);
    for(int i=0; i<trial_count-1;++i )
    {
        cout<<rank[i]<<" ";
    }
    cout<<rank[trial_count-1];
    return 0;
}