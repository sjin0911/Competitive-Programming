#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;

    vector<int> N;
    N.assign(T+1,0);
    
    for(int i=1;i<=T;++i) cin>>N[i];

    for (int i=1;i<=T;++i){
        int n=N[i];
        vector<pair<int,int>> dp;
        dp.assign(n+1,make_pair(0,0));
        dp[0]=make_pair(1,0);
        dp[1]=make_pair(0,1);

        for(int j=2;j<=n;++j){
            dp[j].first=dp[j-1].first+dp[j-2].first;
            dp[j].second=dp[j-1].second+dp[j-2].second;
        }
        cout<<dp[n].first<<" "<<dp[n].second<<"\n";
    }
}