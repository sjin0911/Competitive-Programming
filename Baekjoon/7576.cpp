#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Coord;

int M,N;
vector<vector<int>> Tomato;
queue<Coord> Ripe;

int bfs(){
    int depth=0;

    while(!Ripe.empty()){
        int Q_siz=Ripe.size();

        // cout<<"------"<<depth<<"------\n";
        // cout<<Q_siz<<"\n";
        
        for(int i=0;i<Q_siz;++i){
            Coord n=Ripe.front();
            int a=n.first,b=n.second;
            Ripe.pop();

            // cout<<a<<" "<<b<<" "<<c<<"\n";

            if(a>0&&Tomato[a-1][b]==0){
                Ripe.push(make_tuple(a-1,b));
                Tomato[a-1][b]=1;
            }if(a<N-1&&Tomato[a+1][b]==0){
                Ripe.push(make_tuple(a+1,b));
                Tomato[a+1][b]=1;
            }
            if(b>0&&Tomato[a][b-1]==0){
                Ripe.push(make_tuple(a,b-1));
                Tomato[a][b-1]=1;
            }
            if(b<M-1&&Tomato[a][b+1]==0){
                Ripe.push(make_tuple(a,b+1));
                Tomato[a][b+1]=1;
            }
        }
        if(!Ripe.empty())depth++;
    }
    return depth;
}
bool check(){
    bool flag=true;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(Tomato[i][j]==0){
                flag=false;
                break;
            }
        }
    }
    return flag;
}

int main(){
    cin>>M>>N;

    Tomato.assign(N,vector<int> (M,0));

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>Tomato[i][j];
            if(Tomato[i][j]==1)Ripe.push({i,j});
        
        }
    }
    int res=0;

    if(!check()){
        res=bfs();
        if(!check()) res=-1;
    }


    cout<<res<<"\n";
    
    return 0;
}