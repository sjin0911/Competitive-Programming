#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main(){
    int T;
    cin>>T;

    while(T--){
        ll M,N,x,y;
        cin>>M>>N>>x>>y;

        ll par=0,Max=lcm(N,M),year=0;
        while(year<=Max){
            year=par*M+x;
            if(year%N==y || (y==N && year%N==0)) break;
            
            par++;
        }
        if(year>Max) cout<<"-1\n";
        else cout<<year<<"\n";
    }

    return 0;
}