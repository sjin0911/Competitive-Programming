#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){ 
    vector<string> S;

    while(true){
        int tmp;
        cin>>tmp;

        if(tmp==0) break;

        S.push_back(to_string(tmp));
    }

    for(int i=0;i<S.size();++i){
        bool res=true;
        for(int j=0;j<S[i].length();++j){
            if(S[i][j]!=S[i][S[i].length()-j-1]) res=false;
        }
        cout<<(res?"yes":"no")<<endl;
    }

    return 0;
}