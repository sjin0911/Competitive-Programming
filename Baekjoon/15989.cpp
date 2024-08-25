#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;

        vector<vector<int>> dp(10001,vector<int>(4,0));
        dp[1][1]=1; //1
        dp[2][1]=1; dp[2][2]=1; //1+1, 2
        dp[3][1]=1; dp[3][2]=1; dp[3][3]=1; //1+1+1, 1+2, 3

        for(int i=4;i<=n;++i){
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-2][1]+dp[i-2][2];
            dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
        }

        //print dp
        // for(int i=0;i<=n;++i){
        //     cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<"\n";
        // }
        // cout<<"\n";

        cout<<dp[n][1]+dp[n][2]+dp[n][3]<<"\n";
    }
}