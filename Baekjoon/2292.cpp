#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll sum(int i){
    ll sum=1;
    for(int j=1;j<=i;++j){
        sum+=6*j;
    }
    return sum;
}
int main(){
    ll N;
    cin>>N;

    // vector<ll> dp;
    int Max=N,idx=1;
    // dp.assign(Max,0);
    // dp[0]=1;

    while(idx<Max){
        // dp[idx]=dp[idx-1]+6*idx;
        // if(dp[idx-1]<N&&dp[idx]>N) break;
        if(sum(idx-1)<N&&sum(idx)>=N) break;
        idx++;
    }

    if(N==1) idx=0;
    cout<<idx+1<<"\n";
    return 0;
}
/*
1 6 12 18 24*/