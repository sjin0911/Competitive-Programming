#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    vector<int> V,Mode;
    int N,sum=0,max_count=0;
    cin>>N;

    V.resize(N);
    for(int i=0;i<N;++i){
        cin>>V[i];
        sum+=V[i];
    }
    sort(V.begin(),V.end());
    
    //print
    // for(int i=0;i<N;++i){
    //     cout<<V[i]<<" ";
    // }
    // cout<<"\n";

    if(N==1){
        Mode.push_back(V[0]);
        max_count=1;
    }
    else{
        for(int i=1;i<N;++i){
            int count=1;
            while(V[i]==V[i-1]){
                i++;
                count++;
            }
            if(count==max_count){
                Mode.push_back(V[i-1]);
            }else if(count>max_count){
                Mode.clear();
                Mode.push_back(V[i-1]);
                max_count=count;
            }
        }
    }
    
    //print
    // for(int i=0;i<Mode.size();++i){
    //     cout<<Mode[i]<<" ";
    // }
    // cout<<"\n";

    int Ave=round(sum/(double)N);
    int Mid=V[N/2];
    int Max=(Mode.size()>1)?Mode[1]:Mode[0];
    int Ran=V[N-1]-V[0];
    
    cout<<Ave<<"\n";
    cout<<Mid<<"\n";
    cout<<Max<<"\n";
    cout<<Ran<<"\n";

    return 0;
}