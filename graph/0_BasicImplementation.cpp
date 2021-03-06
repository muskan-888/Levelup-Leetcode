#include<vector>
#include<iostream>
using namespace std;
class edge
{
public:
 int v;
 int w;
 edge(int v,int w)
 {
     this->v=v;
     this->w=w;
 }
};
const int N=7;
vector<vector<edge>> graph(N);

void addEdge(int u,int v,int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));

}

//g++ 0_BasicImplementation.cpp -o out && ./out
void display()
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<" :-- ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<"["<<graph[i][j].v<<","<<graph[i][j].w<<"] ";
        }
        cout<<"\n";
    }
}

int findEdge(int u,int v)
{
    int idx=-1;
    for(int i=0;i<graph[u].size();i++)
    {
      if(graph[u][i].v==v)
      {
          return idx=i;
      }
        
    }
    return idx;
}

void removeEdge(int u,int v)
{
  for(int i=0;i<graph[u].size();i++)
  {
      if(graph[u][i].v==v)
        graph[u].erase(graph[u].begin()+i);
  }
  for(int i=0;i<graph[v].size();i++)
  {
      if(graph[v][i].v==u)
        graph[v].erase(graph[v].begin()+i);
  }
   
}

void construct()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

}
int main()
{
   construct();
   display();

}


