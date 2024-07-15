#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void SelectionSort(vector<pair<ll,ll>> &v){
    int N=v.size();

    for(int i=1;i<N;++i){
        int idx=i;
        while(idx>0&&v[idx-1].first>v[idx].first){
            swap(v[idx],v[idx-1]);
            --idx;
        }

    }
}

int main(){
    int N,M;
    cin>>N>>M;

    vector<pair<ll,ll>> A(N,make_pair(0,0));

    for(int i=0;i<N;++i) cin>>A[i].first>>A[i].second;
    // sort(A.begin(),A.end());
    SelectionSort(A);

    int idx=0;
    ll cost=0;
    while(M){
        if(A[idx].second<=M){
            M-=A[idx].second;
            cost+=A[idx].first*A[idx].second;
        }else{
            cost+=A[idx].first*M;
            M=0;
        }
        idx++;
    }
    cout<<cost<<"\n";
    return 0;
}