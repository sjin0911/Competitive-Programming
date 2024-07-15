#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

bool* Eratos(ll n){
    if(n<=1) return NULL;

    bool* PrimeArray=new bool[n+1];
    for(ll i=0;i<n+1;++i) PrimeArray[i]=true;

    PrimeArray[0]=false;
    PrimeArray[1]=false;

    for(ll i=2;i*i<=n;++i){
        if(PrimeArray[i]){
            for(ll j=i*i;j<=n;j+=i){
                PrimeArray[j]=false;
            }
        }
    }
    return PrimeArray;
}
int main(){
    ll M,N,count=0;
    cin>>M>>N;

    bool* Res=Eratos(N);
    for(ll i=M;i<=N;++i)
        if(Res[i]) cout<<i<<"\n";

    return 0;
}
