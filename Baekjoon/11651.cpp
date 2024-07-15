#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> Coor;
bool comp(Coor x, Coor y){
    if (x.second==y.second) return x.first<y.first;
    return x.second<y.second;
}
int main(){
    int N;
    cin>>N;

    vector<Coor> C(N,make_pair(0,0));

    for(int i=0;i<N;++i){
        cin>>C[i].first>>C[i].second;
    }

    sort(C.begin(),C.end(),comp);

    for(int i=0;i<N;++i){
        cout<<C[i].first<<" "<<C[i].second<<"\n";
    }
    return 0;
}