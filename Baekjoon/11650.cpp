#include <iostream>
#include <vector>
using namespace std;

bool icompare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first<b.first) {
        return true;
    }
    else if (a.first==b.first) {
        return (a.second<b.second)?true:false;
    }
    return false;
}
int main(){
    int N;
    cin>>N;

    vector<pair<int,int>> coord;
    coord.assign(N,make_pair(0,0));

    for (int i=0;i<N;++i) cin>>coord[i].first>>coord[i].second;

    sort(coord.begin(),coord.end(),icompare);
    
    for(int i=0;i<N;++i){
        cout<<coord[i].first<<" "<<coord[i].second<<"\n";
    }
}