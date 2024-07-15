#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    set<string> Heard,Sawn;

    while(N--){
        string name;
        cin>>name;
        Heard.insert(name);
    }
    while(M--){
        string name;
        cin>>name;
        Sawn.insert(name);
    }
    set<string> Res;
    set_intersection(Heard.begin(),Heard.end(),Sawn.begin(),Sawn.end(),inserter(Res,Res.begin()));

    cout<<Res.size()<<"\n";
    for(set<string>::iterator it=Res.begin();it!=Res.end();it++){
        cout<<*it<<"\n";
    }
}