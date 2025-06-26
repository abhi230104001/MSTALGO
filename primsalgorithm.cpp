#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<int,int>
 vector<list<pair<int,int>>> gr;
 
 void add_edge(int u,int v,int wt,bool bidir = true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
 }

ll prim(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>> pq;//{wt,vertex}
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int,int> mp;// map store vertex and it's minimum distance
    for(int i =1;i<=n;i++){
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    int totalcount = 0;// 0->n-1 total edges
    int result = 0;
    while(totalcount<n&& !pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        totalcount++;
        result += curr.first;
        pq.pop();
        for(auto neighbour: gr[curr.second]){
            if(!vis.count(neighbour.first)&&mp[neighbour.first]>neighbour.second){
                pq.push({neighbour.second,neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
    
}
 int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1,list<pair<int,int>> ());// 1 base indexing is taken here
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prim(src,n);
    return 0;
 }
 // i/p on which written code cheked:
 /* 5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1
 ans-> 15*/