#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> Map,Dist;
vector<vector<bool>> visited;
pair<int,int> st;

void bfs(){
    queue<pair<int,int>> q;
    q.push(st);
    int depth=1;
    visited[st.first][st.second]=true;
    
    while(!q.empty()){
        int siz=q.size();
        while(siz--){
            pair<int,int> cur=q.front();
            q.pop();
            int l=cur.first, r=cur.second;

            Dist[l][r]=depth;
            
            if(l<n-1 && Map[l+1][r] && !visited[l+1][r]){ q.push({l+1,r}); visited[l+1][r]=true;}
            if(r<m-1 && Map[l][r+1] && !visited[l][r+1]){ q.push({l,r+1}); visited[l][r+1]=true;}
            if(l>0 && Map[l-1][r] && !visited[l-1][r]){ q.push({l-1,r}); visited[l-1][r]=true;}
            if(r>0 && Map[l][r-1] && !visited[l][r-1]){ q.push({l,r-1}); visited[l][r-1]=true;}
        }
        depth++;
    }
}
int main(){
    cin>>n>>m;
    Map.assign(n, vector<int> (m,0));
    Dist.assign(n, vector<int> (m,0));
    visited.assign(n, vector<bool> (m,false));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>Map[i][j];
            if(Map[i][j]==2) st={i,j};
        }
    }
    bfs();

    cout<<"\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!Map[i][j]) cout<<"0 ";
            else cout<<Dist[i][j]-1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}