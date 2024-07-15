#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int,int,int> Coord;

int M,N,H;
vector<vector<vector<int>>> Tomato;
queue<Coord> Ripe;

int bfs(){
    int depth=0;

    while(!Ripe.empty()){
        int Q_siz=Ripe.size();

        // cout<<"------"<<depth<<"------\n";
        // cout<<Q_siz<<"\n";
        
        for(int i=0;i<Q_siz;++i){
            Coord n=Ripe.front();
            int a=get<0>(n),b=get<1>(n),c=get<2>(n);
            Ripe.pop();

            // cout<<a<<" "<<b<<" "<<c<<"\n";

            if(a>0&&Tomato[a-1][b][c]==0){
                Ripe.push(make_tuple(a-1,b,c));
                Tomato[a-1][b][c]=1;
            }if(a<H-1&&Tomato[a+1][b][c]==0){
                Ripe.push(make_tuple(a+1,b,c));
                Tomato[a+1][b][c]=1;
            }
            if(b>0&&Tomato[a][b-1][c]==0){
                Ripe.push(make_tuple(a,b-1,c));
                Tomato[a][b-1][c]=1;
            }
            if(b<N-1&&Tomato[a][b+1][c]==0){
                Ripe.push(make_tuple(a,b+1,c));
                Tomato[a][b+1][c]=1;
            }
            if(c>0&&Tomato[a][b][c-1]==0){
                Ripe.push(make_tuple(a,b,c-1));
                Tomato[a][b][c-1]=1;
            }
            if(c<M-1&&Tomato[a][b][c+1]==0){
                Ripe.push(make_tuple(a,b,c+1));
                Tomato[a][b][c+1]=1;
            }
        }
        if(!Ripe.empty())depth++;
    }
    return depth;
}
bool check(){
    bool flag=true;
    for(int i=0;i<H;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<M;++k){
                if(Tomato[i][j][k]==0){
                    flag=false;
                    break;
                }
            }
        }
    }
    return flag;
}

int main(){
    cin>>M>>N>>H;

    Tomato.assign(H,vector<vector<int>> (N,vector<int> (M,0)));

    for(int i=0;i<H;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<M;++k){
                cin>>Tomato[i][j][k];
                if(Tomato[i][j][k]==1)Ripe.push(make_tuple(i,j,k));
            }
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