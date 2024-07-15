#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int N;
        cin>>N; 

        vector<int> dp(N+1,0);
        dp[0]=0;
        dp[1]=1; //1
        dp[2]=2; //1+1, 2
        dp[3]=4; //1+1+1, 1+2, 2+1, 3

        for(int i=4;i<=N;++i){
            dp[i]+=dp[i-1]+dp[i-2]+dp[i-3];
        }
        cout<<dp[N]<<"\n";
    }
}