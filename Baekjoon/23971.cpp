#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H,W,N,M;
    cin>>H>>W>>N>>M;

    int res=0;
    N++;
    M++;

    res=H/N+(H%N==0?0:1);
    // cout<<res<<" ";
    res*=W/M+(W%M==0?0:1);

    cout<<res<<"\n";
    return 0;
}