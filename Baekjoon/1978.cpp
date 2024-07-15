#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> A;

    cin>>N;
    A.resize(N);

    for(int i=0;i<N;++i) cin>>A[i];

    int res=0;
    for(int i=0;i<N;++i){
        bool tmp=true;
        for(int j=2;j<A[i];++j){
            // cout<<j<<" "<<A[i]<<endl;
            if(A[i]%j==0) tmp=false;
        }
        if(A[i]==1) tmp=false;
        res=(tmp?res+1:res);
    }
    cout<<res<<endl;
    return 0;
}