#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(pair<int,string> a, pair<int,string> b){
    return a.second<b.second;
}
int main(){
    int p,m;
    cin>>p>>m;

    vector<vector<pair<int,string>>> Room(0,vector<pair<int,string>> (0));
    while(p--){
        int l;
        string n;
        cin>>l>>n;

        bool flg=false;
        for(int i=0;i<Room.size();++i){
            if(abs(Room[i][0].first-l)<=10 && Room[i].size()<m){
                Room[i].push_back({l,n});
                flg=true;
                break;
            }
        }       
        if(!flg){
            Room.push_back(vector<pair<int,string>> (1,{l,n}));
        }
    }

    for(int i=0;i<Room.size();++i){
        int siz=Room[i].size();
        if(siz==m) cout<<"Started!\n";
        else cout<<"Waiting!\n";
        sort(Room[i].begin(),Room[i].end(),comp);
        for(int j=0;j<siz;++j){
            cout<<Room[i][j].first<<" "<<Room[i][j].second<<"\n";
        }   
    }
}