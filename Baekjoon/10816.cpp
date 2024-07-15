#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> A,B;
    int N,M;

    cin>>N;
    A.resize(N);
    for(int i=0;i<N;++i) cin>>A[i];

    cin>>M;
    B.resize(M);
    for(int i=0;i<M;++i) cin>>B[i];

    sort(A.begin(),A.end());
    for(int i=0;i<M;++i){
        auto iter1=lower_bound(A.begin(),A.end(),B[i]);
        auto iter2=upper_bound(A.begin(),A.end(),B[i]);
        cout<<iter2-iter1<<" ";
    }

    return 0;
}