#include<bits/stdc++.h>

using namespace std;

            // <---    SHOETET PATH IN DAG WITH WEIGHT ---->
            // <---    USING DFS ---->

class Graph{

    public:
    unordered_map<int,list<pair<int,int>>>adjlist;

    void addEdge(int u,int v, int weight){
        adjlist[u].push_back(make_pair(v,weight));
    }
    void printAdj(){
        for(auto x:adjlist)
        {
            cout<<x.first<<" -> ";
            for(auto y:x.second){
                cout<<" [ "<<y.first<<" , "<<y.second<<" ]";
            }
            cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s){

        visited[node]=1;
        for(auto neighbout:adjlist[node]){
            if(!visited[neighbout.first]){
                dfs(neighbout.first,visited,s);
            }
        }
        s.push(node);
    }

    void getSortestPath(int src, vector<int>&dist,stack<int>&s){
         dist[src]=0;
         while(!s.empty()){
            int top=s.top();
            s.pop();

            if(dist[top]!=INT_MAX){
                for(auto i:adjlist[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
         }
    }
};

int main(){

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);


    g.printAdj();

    int n=6;
    //topological sort
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    int src=1;

    vector<int>dist(n);

    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }

    g.getSortestPath(src,dist,s);
    cout<<"Answer is :"<<endl;

    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}