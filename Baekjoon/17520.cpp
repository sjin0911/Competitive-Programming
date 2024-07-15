#include <iostream>
using namespace std;

const long long int MAX=16769023;

int num(int k){
    int sum=2;

    for(int i=2;i<k;++i){
        if(i%2==0) sum=(sum*2)%MAX;
    }
    return sum;
}
int main(){
    long long int K;
    cin>>K;
    cout<<num(K)<<"\n";

    return 0;
}