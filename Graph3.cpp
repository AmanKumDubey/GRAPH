#include<bits/stdc++.h>
using namespace std;

                                      // <-----BFS TRAVERSAL IN GRAPH------->

void traverseBFS(unordered_map<int,list<int>>&adjlist, unordered_map<int,bool>&visited, vector<int>&ans, int node){

    queue<int>q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        visited[frontNode]=1;
        ans.push_back(frontNode);
        for(auto i: adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
            }
        }
    }
}

vector<int> BFSTr(int vertex, vector<pair<int,int>>&Adj){

    unordered_map<int,list<int>>adjlist;
    unordered_map<int,bool>visited;
    vector<int>ans;

    for(int i=0;i<Adj.size();i++){
        int u=Adj[i].first;
        int v=Adj[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            traverseBFS(adjlist,visited,ans,i);
        }
    }
    return ans;
}
int main(){

    int n,m;

    cout<<"Enter the number of Nodes "<<endl;
    cin>>n;
    cout<<"Enter the number of Edges "<<endl;
    cin>>m;

    // Graph g;

    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.addEdge(u,v,0);
    // }

    // g.printGraph();

    vector<pair<int,int>>Adj(m,{0,0});

    for(int i=0;i<m;i++){
        cin>>Adj[0].first;
        cin>>Adj[0].second;
    }

    vector<int>BFS=BFSTr(n,Adj);

    cout<<"BFS Traversal"<<endl;
    for(auto i:BFS){
        cout<<i<<" ";
    }

    return 0;
}