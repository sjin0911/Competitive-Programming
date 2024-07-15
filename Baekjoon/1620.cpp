#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    cin.tie(NULL);
    int idx=1;
    map<string,string> Map;
    while(N--){
        string name;
        cin>>name;

        Map[name]=to_string(idx);
        Map[to_string(idx)]=name;
        idx++;
    }
    while(M--){
        string for_search;
        cin>>for_search;
        cout<<Map[for_search]<<"\n";
    }
    return 0;
}