#include<bits/stdc++.h>
using namespace std;

// Implement Graph and Print all adjecent

class Graph{
    public:
    unordered_map<int,list<int>>adjl;

    void addEdge(int u, int v, bool direction){
        // direction= 0->undirected
        // direction=1->directed graph


        adjl[u].push_back(v);
        if(direction==0){
            adjl[v].push_back(u);
        }
    }
    void printAdlist(){
        for(auto i:adjl){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
        
    }
};
int main(){

    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter thr number of edges "<<endl;
    cin>>m;

    Graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdlist();
    return 0;
}