#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;

    stack<int> strarr;

    int num=0;
    for(int i=0;i<str.size();++i){
        int ch_to_int=str[i]-'0';
        if(ch_to_int>=0 && ch_to_int<=9){
            num*=10;
            num+=ch_to_int;
        }else{
            //-1: +, -2; -
            int s;
            if(str[i]=='+') s=-1;
            else s=-2;

            strarr.push(num);
            strarr.push(s);
            num=0;
        }
    }
    strarr.push(num);

    int res=0,curnum=0;
    while(!strarr.empty()){
        int n=strarr.top();
        strarr.pop();

        cout<<n<<" ";
        //case '-'
        if(n==-2){
            res-=curnum;
        }
        //case '+'
        else if(n==-1){
            curnum+=strarr.top();
            strarr.pop();
        }else{
            curnum=n;
        }

        cout<<curnum<<" "<<res<<"\n";
    }
    res+=curnum;

    cout<<res<<"\n";
    
    return 0;
}