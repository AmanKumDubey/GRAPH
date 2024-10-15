#include<bits/stdc++.h>
using namespace std;


             // <---    TOPOLOGICAL SORT IN DIRECTED GRAPH ---->
             // <---    KAHN'S Alogithm ---->


vector<int> TOPOSORT(vector<vector<int>>&adj, int v, int e)
{

    unordered_map<int,list<int>>adjlist;
    for(int i=0;i<e;i++){
        int u=adj[i][0];
        int v=adj[i][1];

        adjlist[u].push_back(v);
    }

    // find all indegree
    vector<int>inDegree(v,0);
    for(auto i:adjlist){
        for(auto j:i.second){
            inDegree[j]++;
        }
    }
    // push 0' Degree in queue
    queue<int>q;
    for(int i=0;i<v;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    // Here BFS 
    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour:adjlist[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){

    int n, m;
    cout<<"Enter no. of nodes "<<endl;
    cin>>n;
    cout<<"Enter no. of vertex :"<<endl;
    cin>>m;

    vector<vector<int>>adj;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj.push_back({u,v});

    }
    vector<int>ans=TOPOSORT(adj,n,m);

    cout<<"TopoLogicalSort Using Kahn's Algorithm : "<<endl;
    for(auto x:ans){
        cout<<x<< " ";
    }

    return 0;
}