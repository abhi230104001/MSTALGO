/// 1. sort by ebge and add those edge which has low weight and does not form cycle
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
using namespace std;
int find(int x,vector<int>& parent){
    return parent[x] = parent[x]==x?x:find(parent[x],parent);
}
 void dsu(int x,int y,vector<int>& parent,vector<int>& rank){
    x = find(x,parent);
    y = find(y,parent);
    if(x==y) return;
    if(rank[x]>=rank[y]){
        parent[y] = x;
        rank[x]++;
    }
    else{
        parent[x] = y;
        rank[y]++;
    }
 }

 // implementing graph by edge list;

 struct Edge{
    int src;
    int dest;
    int wt;
 };
 bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
 }

 ll kruskal(vector<Edge>& input,int n, int e){// total tc of kruskal is O(v+eloge);
    sort(input.begin(),input.end(),cmp);//o(eloge);
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i =0;i<=n;i++){
        parent[i] = i;
    }
    int ecount = 0;// for counting the e is e<=n-1
    ll ans = 0;
    int i =0;
    while(ecount<n-1&&i<input.size()){// o(v)
       Edge curr = input[i];
        int srcpar = find(curr.src,parent);//o(*loge)->const v->no.of vertex
        int destpar = find(curr.dest,parent);
        if(srcpar!=destpar){// to check cycle if src and dest have parent then there is cycle due to that edge can be consider
            dsu(srcpar,destpar,parent,rank);//o(*loge)->const
            ecount++;
            ans += curr.wt;
        }
        i++;// edge include or not we must have to move our index;
    }
    return ans;
 }
int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i =0;i<e;i++){
   cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskal(v,n,e);

}