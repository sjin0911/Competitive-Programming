#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using Graph=vector<vector<int>>;
Graph G;
vector<bool> visited_dfs,visited_bfs;

void dfs(int x){
    visited_dfs[x]=true;

    cout<<x<<" ";
    for(int i=0;i<G[x].size();++i){
        int y=G[x][i];
        if(!visited_dfs[y])dfs(y);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);

    visited_bfs[start]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";

        for(int i=0;i<G[x].size();++i){
            int y=G[x][i];
            if(!visited_bfs[y]){
                q.push(y);
                visited_bfs[y]=true;
            }
        }
    }

}

int main(){
    int N,M,V;
    cin>>N>>M>>V;

    visited_dfs.assign(N+1,false);
    visited_bfs.assign(N+1,false);
    G.assign(N+1,vector<int> (0));

    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;

        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        sort(G[i].begin(),G[i].end());
    }
    dfs(V);
    cout<<"\n";
    bfs(V);
    cout<<"\n";
    return 0;
}