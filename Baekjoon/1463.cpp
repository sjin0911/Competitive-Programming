#include <iostream>
#include <vector>
using namespace std;

const long long MAX=1000002;
typedef long long ll;
//1부터 N까지 가는데 각 정수별로 소요되는 횟수를 저장하는 배열
vector<ll> dp(MAX,MAX);

ll for_dp(ll n){
    if(dp[n]!=MAX) return dp[n];

    if(n%6==0){
        dp[n]=min(for_dp(n/2)+1,for_dp(n/3)+1);  
    }else if(n%3==0){
        dp[n]=min(for_dp(n-1)+1,for_dp(n/3)+1);
    }else if(n%2==0){
        dp[n]=min(for_dp(n-1)+1,for_dp(n/2)+1);
    }else dp[n]=min(dp[n],for_dp(n-1)+1);

    return dp[n];
}


int main(){
    ll N;
    cin>>N;

    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;

    cout<<for_dp(N)<<"\n";

    //dp print
    // for(int i=0;i<dp.size();++i){
    //     cout<<dp[i]<<" ";
    // }

    // for(int i=0;i<arr.size();++i) cout<<arr[i]<<" ";
    // cout<<"\n";

    return 0;
}