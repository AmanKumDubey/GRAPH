#include<bits/stdc++.h>
using namespace std;

            // <---    TOPOLOGICAL SORT IN DIRECTED GRAPH ---->
             // <---    Through DFS Traversal ---->

void topoSort(int node,vector<bool>&visited,unordered_map<int,list<int>>&adjlist,stack<int>&s){

    visited[node]=1;
    for(auto neighbour:adjlist[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,visited,adjlist,s);
        }
    }
    s.push(node);
}
vector<int> TopoSortDFS(vector<vector<int>>&edges,int n, int m){

    unordered_map<int,list<int>>adjlist;
    vector<bool>visited(n,0);
    vector<int>ans;

    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
    }

    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topoSort(i,visited,adjlist,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    
    int m,n;
    cout<<"Enter no. of all nodes : "<<endl;
    cin>>n;
    cout<<"Enter no. of all vertex : "<<endl;
    cin>>m;

    vector<vector<int>>edges;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        edges.push_back({u,v});
    }

    vector<int>ans=TopoSortDFS(edges,n,m);

    cout<<"Topological Sort "<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}