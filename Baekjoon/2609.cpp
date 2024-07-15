#include <iostream>
using namespace std;

int main(){
    int N1,N2,gcd=1,lcm=0,min_n;
    cin>>N1>>N2;
    min_n=min(N1,N2);

    for(int i=2;i<=min_n;++i){
        while(N1%i==0 && N2%i==0){
            N1/=i;
            N2/=i;
            gcd*=i;
        }
    }
    lcm=gcd*N1*N2;
    cout<<gcd<<" "<<lcm<<"\n";

    return 0;
}
/*
24 18
6 72
*/