#include<bits/stdc++.h>

using namespace std;

                                                // <---    CHEAK CYCLE DETECTION IN UNDIRECTED GRAPH ---->

bool isCycle(int node, unordered_map<int,list<int>>&adjlist, unordered_map<int,bool>&visited){

    unordered_map<int,int>parent;
    parent[node]=-1;
    queue<int>q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour:adjlist[front]){
            if(visited[neighbour]==1 && parent[front]!=neighbour){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return 0;
}

bool isCycleGraph(vector<vector<int>>&Adj,int n,int m){

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

            bool ans=isCycle(i,adjlist,visited);
            if(ans){
                return 1;
            }
        }
    }
    return 0;
}

int main(){

    int n,m;
    cout<<"Enter no. of nodes "<<endl;
    cin>>n;
    cout<<"Enter no. of vetex "<<endl;
    cin>>m;

    vector<vector<int>>Adj(m,{0,0});
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Adj.push_back({u,v});
    }
    

    bool iscycle=isCycleGraph(Adj,n,m);

    if(iscycle==1){
        cout<<"In this Graph deteect Cycle "<<endl;
    }
    else{
        cout<<"There is no dectect any Cycle in this Graph "<<endl;
    }


    return 0;
}