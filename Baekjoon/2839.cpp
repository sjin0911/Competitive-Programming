#include <iostream>
#include <vector>
using namespace std;

const long long MAX=1LL^60;

int main(){
    int N,bag=0;
    cin>>N;

    vector<int> dp (N+1,MAX);
    dp[0]=0;
    dp[1]=-1;
    dp[2]=-1;

    for(int i=3;i<=N;++i){
        if (dp[i-3]!=-1) dp[i]=min(dp[i],dp[i-3]+1);
        if (i>=5 && dp[i-5]!=-1) dp[i]=min(dp[i],dp[i-5]+1);

        if (dp[i]==MAX) dp[i]=-1;
        // for(int j=0;j<=i;++j){
        //     cout<<dp[j]<<" ";
        // }cout<<"\n";
    }
    cout<<dp[N]<<"\n";
    return 0;
}