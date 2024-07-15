#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=200000000;

int main(){
    vector<int> tri;
    int tmp;

    while(true){
        tri.clear();
        for(int i=0;i<3;++i){
            cin>>tmp;
            tri.push_back(tmp);
        }
        if(tmp==0) break;
        sort(tri.begin(),tri.end());

        cout<<((tri[2]*tri[2]==tri[0]*tri[0]+tri[1]*tri[1])?"right":"wrong")<<endl;
    }
    
    return 0;
}