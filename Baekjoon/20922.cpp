#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;

    vector<int> S(N,0);
    map<int,int> m;
    for(int i=0;i<N;++i){
        cin>>S[i];
    }

    int l=0,r=1,max_len=0;

    m.insert({S[0],1});
    while(r<=N){
        int n=S[r];

        // cout<<l<<" "<<r<<"\n";

        //if key already exist
        if(!m.insert({n,1}).second){
            m[n]+=1;
            if(m[n]>K){
                max_len=max(max_len,r-l);
                while(l<r){
                    int tmp_n=S[l];
                    m[tmp_n]-=1;
                    l++;
                    if(tmp_n==n) break;
                }
            }
        } 
        r++;
    }
    max_len=max(max_len,r-l-1);

    cout<<max_len<<"\n";
    return 0;
}