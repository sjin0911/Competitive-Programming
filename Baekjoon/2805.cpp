#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ll N,M;
    cin>>N>>M;

    vector<ll> tree(N,0);
    for(ll i=0;i<N;++i) cin>>tree[i];

    sort(tree.begin(),tree.end());

    ll max=tree[N-1],min=0;
    while(max>=min){
        cout<<max<<" "<<min<<"\n";
        ll m=(max+min)/2,sum=0;

        for(ll i=0;i<N;++i){
            if(tree[i]>m) sum+=tree[i]-m;
        }
        if(sum>=M) min=m+1;
        else max=m-1;

    }
    cout<<max<<"\n";

    return 0;
}