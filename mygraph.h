#include <iostream>
#include <list>
#include <queue>
using namespace std;

class MyGraph
{
  public:
    MyGraph(int N):m_N(N)
    {
        m_adj = new list<int> [m_N+1];
    }
    void addedge(int u, int v)
    {
        (*(m_adj+u)).push_back(v);
        (*(m_adj+v)).push_back(u);
        //m_adj[u].push_back(v);
        //m_adj[v].push_back(u);
    }
    
    void printGraph()
    {
        for(int i=1;i<=m_N;i++)
        {
            cout << i ;
            list<int>::iterator itr = m_adj[i].begin();
            for(;itr!=m_adj[i].end();itr++)
                cout << "-->" << *itr;
            cout << endl;
        }
    }
  
  void bfs(int source)
  {
        bool (*visited) = new bool[m_N+1];
        
        for(int i=1;i<=m_N;i++)
            visited[i] = false;
    
        q.push(source);
        cout << source ;
        visited[source] = true;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(list<int>::iterator itr = m_adj[i].begin();
                itr != m_adj[i].end();
                itr++)
            {
                if(!visited[*itr])
                {
                    cout << " " << *itr;
                    visited[*itr] = 1;
                    q.push(*itr);
                }
            }
  }
  private:
    int m_N;
    list<int>(*m_adj);
    queue<int>q;
};

int main(int argc, char** argv)
{
    MyGraph graphobj(6);
    graphobj.addedge(1,2);
    graphobj.addedge(1,3);
    graphobj.addedge(1,5);
    graphobj.addedge(3,4);
    graphobj.addedge(3,5);
    graphobj.addedge(4,6);
    graphobj.addedge(5,2);
    graphobj.addedge(6,1);
    graphobj.printGraph();
      
    cout << "------ BFS -------" << endl;
    graphobj.bfs(1);
}
