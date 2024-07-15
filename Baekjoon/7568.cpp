#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> INFO;

int main(){
    int N;
    cin>>N;

    vector<INFO> P(N,make_pair(0,0));
    for(int i=0;i<N;++i) cin>>P[i].first>>P[i].second;

    for(int i=0;i<N;++i){
        int a=P[i].first,b=P[i].second;
        int count=1;
        for(int j=0;j<N;++j){
            if (i!=j && P[j].first>a && P[j].second>b) count++;
        }
        cout<<count<<" ";
    }cout<<"\n";
    return 0;
}
