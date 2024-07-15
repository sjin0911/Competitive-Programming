#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

const int INF=200000000;

int main(){
    int N,M,ndigit=pow(10,7),count=INF,origin_N,new_N_max,new_N_min;
    vector<bool> Button(10,true);
    vector<int> Num;

    cin>>N>>M;

    origin_N=N;
    new_N_max=N;
    new_N_min=N;
    for(int i=0;i<M;++i){
        int x;
        cin>>x;
        Button[x]=false;
    }

    string N_str=to_string(origin_N),new_N_max_str=to_string(new_N_max),new_N_min_str=to_string(new_N_min);

    if(M!=10){
        bool flg_max=true,flg_min=false;
        while(true){        
            flg_max=true; flg_min=false;

            for(int i=0;i<new_N_max_str.size();++i){
                if(!Button[new_N_max_str[i]-'0']) {
                    flg_max=false;
                    break;
                }
            }

            if(new_N_min>=0){
                flg_min=true;
                for(int i=0;i<new_N_min_str.size();++i){
                    if(!Button[new_N_min_str[i]-'0']) {
                        flg_min=false;
                        break;
                    }
                }
            }
            if(flg_min||flg_max) break;

            new_N_max_str=to_string(++new_N_max);
            new_N_min_str=to_string(--new_N_min);
        }
        if(flg_max) count=min(count,(int)new_N_max_str.size()+abs(origin_N-new_N_max));
        if(flg_min) count=min(count,(int)new_N_min_str.size()+abs(origin_N-new_N_min));

        //print
        // cout<<new_N_min<<" "<<new_N_max<<"\n";        
    }
    count=min(count,abs(origin_N-100));

    cout<<count<<"\n";

    return 0;
}