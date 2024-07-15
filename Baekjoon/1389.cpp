#include <iostream>
#include <vector>
using namespace std;

static int INF=200000000;
vector<vector<int>> dist;

int main(){
    int N,M;
    cin>>N>>M;

    dist.assign(N+1,vector<int> (N+1,INF));
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;

        dist[a][b]=1;
        dist[b][a]=1;
    }
    for(int i=1;i<=N;++i){
        dist[i][i]=0;
    }
    for(int k=1;k<=N;++k){
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    // //test print
    // for(int i=1;i<=N;++i){
    //     for(int j=1;j<=N;++j){
    //         cout<<dist[i][j]<<" ";
    //     }cout<<"\n";
    // }

    int n,min_sum=INF;
    for(int i=1;i<=N;++i){
        int sum=0;
        for(int j=1;j<=N;++j){
            sum+=dist[i][j];
        }
        if(sum<min_sum){
            min_sum=sum;
            n=i;
        }
    }
    cout<<n<<"\n";

    return 0;
}