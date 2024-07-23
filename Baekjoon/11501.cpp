#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ll T;
    cin>>T;

    while(T--){
        ll N,profit=0;
        cin>>N;

        vector<ll> Price(N,0),Price_sorted(N,0),Max(N,-1);
        for(ll i=0;i<N;++i)cin>>Price[i];

        for(ll i=N-2;i>=0;--i){
            if(Price[i+1]>Max[i+1]) Max[i]=Price[i+1];
            else Max[i]=Max[i+1];
        }
        for(ll i=0;i<N;++i){
            if(Max[i]>Price[i]) profit+=Max[i]-Price[i];
        }
        cout<<profit<<"\n";
    }
    return 0;
}