#include <iostream>
#include <map>
#include <vector> 
#include <string>
using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;

        map<string,int> Map;
        while(n--){
            string clothes,type;
            cin>>clothes>>type;
            
            if(Map.find(type)!=Map.end())Map[type]+=1;
            else Map[type]=1;
        }

        int res=1;
        for(map<string,int>::iterator it=Map.begin();it!=Map.end();++it){
            res*=(it->second+1);
        }

        cout<<--res<<"\n";
    }
}