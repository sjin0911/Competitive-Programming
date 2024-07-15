#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
int main(){
    ll N,M,res=0;
    string S;
    cin>>N>>M;
    cin>>S;

    for(ll i=0;i<M;++i){
        if(S[i]=='I'){
            ll idx=i,n_oi=0;
            while (i<M-2 && S[i+1]=='O' && S[i+2]=='I'){
                i+=2;
                n_oi++;
            }
            if(n_oi>=N){
                res+=n_oi-N+1;
            }
        }
    }

    cout<<res<<"\n";
    return 0;
}