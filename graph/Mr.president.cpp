//hackerrank

#include<algorithm>
#include <iostream>
#include<vector>

using namespace std;

bool compare(vector<int>&a,vector<int>&b)
{
	return a[2]<b[2];
}
vector<int>par;

int findpar(int n)
{
	return par[n]==n ? n : par[n]=findpar(par[n]);
}


int main() 
{   ios_base::sync_with_stdio(false);// fast input
	long maintanence=0;// has to be long
	int n,m;cin>>n>>m;
	long k;cin>>k;
	vector<vector<int>>edges;
	for(int i=0;i<m;i++)
	{
       vector<int>v(3);
	   cin>>v[0];
	   cin>>v[1];
	   cin>>v[2];
	   edges.push_back(v);
	   
	}

	sort(edges.begin(),edges.end(),compare);
	par.resize(n+1,0);

	for(int i=1;i<=n;i++)
	par[i]=i;
	vector<int>v;
	for(int i=0;i<m;i++)
	{
		int p1=findpar(edges[i][0]);
		int p2=findpar(edges[i][1]);

		if(p1!=p2)
		{
			par[p1]=p2;
			maintanence+=edges[i][2];
			n--;
			v.push_back(edges[i][2]);
		}
	}
	if(n>1) 
	{
		cout<<-1;
		return 0;
	}
    int convert=0;
	
	for(int i=v.size()-1;i>=0;i--)
	{
		if(maintanence<=k)
		break;
		maintanence-=v[i]; // decreasing maintanence cost of roads with higher mc
		maintanence+=1;// adding mc of super road
		convert++;
	}
	if(maintanence<=k)
	cout<<convert;
	else //if after doing all operation still k is not satisfied
	cout<<-1;
}


