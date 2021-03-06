#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

const int N = 15;
vector<vector<Edge>> graph(N);

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
}

void display()
{
    for (int i = 0; i < N; i++)
    {
        cout << to_string(i) + " -> ";
        for (Edge e : graph[i])
        {
            cout << "(" + to_string(e.v) + ", " + to_string(e.w) + ") ";
        }
        cout << endl;
    }
}
void dfs(int i,vector<bool>&visited,vector<int>&ans)
{
  visited[i]=1;
  for(Edge e:graph[i])
  {
      if(!visited[e.v])
       dfs(e.v,visited,ans);
  }
  ans.push_back(i);
}
void topologicalOrder_DFS()
{
  vector<bool>visited(N,false);
  visited[0]=true;
  vector<int> ans;
  for(int i=0;i<N;i++)
  {
      if(!visited[i])
      {
          dfs(i,visited,ans);
      }
  }
  for(int ele:ans)
  {
      cout<<ele<<" ";
  }

}
void constructGraph()
{
    addEdge(1, 5, 10);
    addEdge(1, 3, 10);
    addEdge(1, 7, 10);
    addEdge(3, 2, 10);
    addEdge(4, 3, 10);
    addEdge(4, 6, 10);
    addEdge(4, 8, 10);
    addEdge(6, 2, 10);
    addEdge(7, 9, 10);
    addEdge(7, 6, 10);
    addEdge(8, 10, 10);
    addEdge(8, 11, 10);
    addEdge(8, 7, 10);
    addEdge(9, 10, 10);
    addEdge(10, 14, 10);
    addEdge(10, 5, 10);
    addEdge(11,7, 10);
    addEdge(12, 8, 10);
    addEdge(12, 11, 10);
    addEdge(12, 13, 10);
    addEdge(14, 13, 10);
    
    topologicalOrder_DFS();
}

int main()
{
    constructGraph();
    return 0;
}