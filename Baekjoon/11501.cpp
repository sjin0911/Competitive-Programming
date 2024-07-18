#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int N,profit=0;
        cin>>N;

        vector<int> Price(N,0),Price_sorted(N,0);
        for(int i=0;i<N;++i){
            cin>>Price[i];
            Price_sorted[i]=Price[i];
        }
        sort(Price_sorted.begin(),Price_sorted.end(),greater<int>());
        int idx=0;

        for(int i=0;i<N;++i){
            int cur=Price[i];

            if(idx<N&&cur<Price_sorted[idx]) profit+=Price_sorted[idx]-cur;
            else if(cur==Price_sorted[idx]) idx++;
        }

        cout<<profit<<"\n";
    }
    return 0;
}