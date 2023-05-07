#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int vertices;
    list<int> *adj;
    public:
    Graph(int v){
        vertices = v;
        adj = new list<int>[vertices];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int v){
        bool visited[vertices];
        for(int i=0;i<vertices;i++)
        visited[i] = false;

        
        queue<int> q;
        visited[v] = true;
        q.push(v);
        while(!q.empty()){
            int u = q.front();
            cout<<u<<" ";
            q.pop();

            for(auto& v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
        }
    }

    void DFS(int v){
        bool visited[v];
        for(int i=0;i<vertices;i++)
        visited[i] = false;
        DFST(v,visited);

    }

    void DFST(int v,bool visited[]){
        visited[v] = true;
        cout<<v<<" ";
        for(int i:adj[v]){
            if(visited[i]==false)
            DFST(i,visited);
        }
    }

};
int main() 
{ 
    Graph g(5);
    g.addEdge( 0, 1);
    g.addEdge( 0, 2);
    g.addEdge(1,2 );
    g.addEdge(2,3); 
    g.addEdge(1,3); 
    g.addEdge(3,4);
    g.addEdge(2,4); 
    cout<<"BFS TRAVERSAL"<<"\n";
    g.BFS(0);
    cout<<endl;
    cout<<"DFS TRAVERSAL"<<"\n";
    g.DFS(0);
    return 0; 
}