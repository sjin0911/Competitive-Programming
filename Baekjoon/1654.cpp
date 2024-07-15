#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> K_;
int N,K;

bool check(ll m){
    ll n=0;

    for(int i=1;i<=K;++i)
        n+=K_[i]/m;
    if (n>=N) return true;
    else return false;
}
int main(){
    cin>>K>>N;

    K_.assign(N+1,0);

    ll max=-1;
    for(int i=1;i<=K;++i) {
        cin>>K_[i];
        if(max<K_[i]) max=K_[i];
    }

    ll l=1,r=max+1;
    while(l+1<r){
        ll mid=(l+r)/2;

        if (check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<"\n";
}