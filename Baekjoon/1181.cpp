#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<string> const &input){
    for (long unsigned int i = 0; i < input.size(); i++) {
        cout << input.at(i) << endl;
    }
}

int Cmp(string a,string b){
    const char* Achar=a.c_str();
    const char* Bchar=b.c_str();

    if(a.length()<b.length()){
        return 1;
    }else if(a.length()==b.length()){
        for(long unsigned int i=0;i<a.length();++i){
            if((int)Achar[i]<(int)Bchar[i]) return 1;
            else if((int)Achar[i]>(int)Bchar[i]) return 0;
        }
    }else{
        return 0;
    }
    return 0;
}

int main(){
    int N;
    vector<string> S;

    //입력
    cin>>N;
    S.resize(N);
    for(int i=0;i<N;++i) cin>>S[i];

    sort(S.begin(),S.end(),Cmp);
    S.erase(unique(S.begin(),S.end()),S.end());

    print(S);
}