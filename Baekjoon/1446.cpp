#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const long long int INF=10001;

int main(){
    int N,D;
    cin>>N>>D;

    //0:start loc, 1:finish loc, 2:len
    vector<tuple<int, int, int>> Path(N,make_tuple(0,0,0));
    vector<int> Dp(D+1,INF);
    for(int i=0;i<N;++i) cin>>get<0>(Path[i])>>get<1>(Path[i])>>get<2>(Path[i]);

    sort(Path.begin(),Path.end(),[](tuple<int,int,int> a, tuple<int,int,int> b){
        return get<1>(a)<get<1>(b);
    });

    // for(int i=0;i<N;++i) cout<<get<0>(Path[i])<<" "<<get<1>(Path[i])<<" "<<get<2>(Path[i])<<"\n";
    Dp[0]=0;
    for(int i=1;i<=D;++i){
        Dp[i]=min(i,Dp[i-1]+1);
        for(int j=0;j<N;++j){
            int stime=get<0>(Path[j]), etime=get<1>(Path[j]), len=get<2>(Path[j]);
            if(etime==i) Dp[i]=min(Dp[i],Dp[stime]+len);
            else if(etime>i) break;
        }
    }
    // for(int i=0;i<=D;++i){
    //     cout<<Dp[i]<<" ";
    // }
    cout<<Dp[D]<<"\n";
}