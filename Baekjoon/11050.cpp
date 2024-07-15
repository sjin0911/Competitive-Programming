#include <iostream>
using namespace std;

int main(){
    int N,K,res=1;
    cin>>N>>K;

    for(int i=K+1;i<=N;++i){
        res*=i;
    }
    for(int i=1;i<=(N-K);++i){
        res/=i;
    }
    cout<<res<<"\n";
}