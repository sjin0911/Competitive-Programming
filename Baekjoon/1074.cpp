#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int divide(int siz,int r,int c){
    if(siz==1) return 2*r+c;
    siz--;
    ll half_siz=pow(2,siz);
    ll half=half_siz*half_siz;

    // cout<<half_siz<<" "<<r<<" "<<c<<"\n";

    if(r<half_siz){
        if(c<half_siz) return divide(siz,r,c);
        else return half*1+divide(siz,r,c-half_siz);
    }else{
        if(c<half_siz) return half*2+divide(siz,r-half_siz,c);
        else return half*3+divide(siz,r-half_siz,c-half_siz);
    }
}
int main(){
    int N,r,c;
    cin>>N>>r>>c;

    cout<<divide(N,r,c)<<"\n";

    return 0;
}