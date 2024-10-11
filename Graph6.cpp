#include<bits/stdc++.h>
using namespace std ;

                // <---    CHEAK CYCLE DETECTION IN UNDIRECTED GRAPH ---->
                // <---    Through DFS Traversal ---->

bool isCycleDFS(int node, int parent,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjlist){
;
    visited[node]=true;
    for(auto neighbour:adjlist[node]){
        if(!visited[neighbour]){
            bool cycledetection=isCycleDFS(neighbour,node,visited,adjlist);
            if(cycledetection){
                return true;
            }
            else if(neighbour!=parent){
                // cycle present
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int n, int m,vector<vector<int>>&Adj)
{
    unordered_map<int,bool>visited;
    unordered_map<int,list<int>>adjlist;

    for(int i=0;i<m;i++){
        int u=Adj[i][0];
        int v=Adj[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            return isCycleDFS(i,-1,visited,adjlist);
        }
    }

    return 0;
}
int main(){

    int n,m;
    cout<<"Enter no. of nodes "<<endl;
    cin>>n;
    cout<<"Enter no. of edges "<<endl;
    cin>>m;


    vector<vector<int>>Adj(m,{0,0});
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Adj.push_back({u,v});
    }

    if(isCycle(m,n,Adj)){
        cout<<"Cyclic Graph "<<endl;
    }
    else{
        cout<<"Not Cyclic "<<endl;
    }

    return 0;
}