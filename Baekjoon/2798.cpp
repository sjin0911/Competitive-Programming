#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    vector<int> A;

    cin>>N>>M;
    A.resize(N);
    for(int i=0;i<N;++i) cin>>A[i];

    int res=0;
    for(int i=0;i<N;++i){
        int tmp=0;
        for(int j=i+1;j<N;++j){
            for(int k=j+1;k<N;++k){
                tmp=A[i]+A[j]+A[k];
                if(tmp>M) tmp=0;
                else res=max(tmp,res);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}