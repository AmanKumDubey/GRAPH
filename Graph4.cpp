#include<bits/stdc++.h>
using namespace std;

                                     //    <--- DFS TRAVERSAL IN GRAPH  --->

void Traverse(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjlist,vector<int>&component){

    component.push_back(node);
    visited[node]=1;
    // for every node recursion call 
    for(auto i:adjlist[node]){
        if(!visited[i]){
            Traverse(i,visited,adjlist,component);
        }
    }
}

vector<vector<int>> DFST(int V,int E, vector<vector<int>>&Adj){

    unordered_map<int,list<int>>adjlist;
    unordered_map<int,bool>visited;
    vector<vector<int>>ans;
    for(int i=0;i<Adj.size();i++){
        int u=Adj[i][0];
        int v=Adj[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int>component;
            Traverse(i,visited,adjlist,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter Number of nodes "<<endl;
    cin>>n;
    cout<<"Enter Number of Edges "<<endl;
    cin>>m;

    vector<vector<int>>Adj(m,{0,0});

    for(int i=0;i<m;i++){
        cin>>Adj[i][0];
        cin>>Adj[i][1];
    }
    vector<vector<int>>ans=DFST(n,m,Adj);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}