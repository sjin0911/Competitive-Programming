#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;++i){
        stack<char> vps,tmp;
        string str;
        cin>>str;
        
        tmp.push(str[0]);

        for(int j=str.size()-1;j>0;--j){
            vps.push(str[j]);
            // cout<<vps.top()<<endl;
        }

        while(!vps.empty()){
            char in=vps.top(),out;

            if(!tmp.empty()) {
                out=tmp.top();

                // cout<<out<<" "<<in<<endl;

                if(out=='('&&in==')'){
                    tmp.pop();
                    vps.pop();
                }
                else{
                    tmp.push(in);
                    vps.pop();
                }
            }else{
                // cout<<in<<endl;
                tmp.push(in);
                vps.pop();
            }
        }

        cout<<(tmp.empty()?"YES":"NO")<<endl;
    }

    return 0;
}
