#include <iostream>
#include <vector>
using namespace std;

static int Max=14;
typedef long long ll;
vector<vector<ll>> Apt;

ll num(int k,int n){
    while(Apt.size()<k+1){
        Apt.push_back(vector<ll> (Max+1,-1));
    }
    if (Apt[k][n]==-1){
        Apt[k][n]=(n>1)?num(k,n-1)+num(k-1,n):num(k-1,1);
    }
    return Apt[k][n];
}

int main(){
    int T;
    cin>>T;

    Apt.assign(1,vector<ll> (Max+1,-1));
    for(int i=1;i<=Max;++i) Apt[0][i]=i;

    while(T>0){
        --T;

        int k,n;
        cin>>k>>n;

        cout<<num(k,n)<<"\n";
    }
    return 0;
}