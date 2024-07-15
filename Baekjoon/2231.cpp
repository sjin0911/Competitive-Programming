#include <iostream>
using namespace std;

int main(){
    long long int N,res=0,n;
    cin>>N;

    for(long long int i=1;i<N;++i){
        n=i;
        res=n;
        do{
            res+=n%10;
            n/=10;
        }while(n>0);
        if(res==N) {
            cout<<i<<"\n";
            return 0;
        }   
    }
    cout<<"0\n";
    return 0;

}