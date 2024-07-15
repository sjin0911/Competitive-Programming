#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    while (true){
        string str;
        stack<char> q;
        bool flg=true;

        getline(cin,str);
        if(str[0]=='.') break;

        for(int i=0;i<str.size();++i){
            char ch=str[i];
            if (ch=='(' || ch=='[') q.push(ch);
            else if (ch==')'){
                if(!q.empty() && q.top()=='(') q.pop();
                else {
                    flg=false;
                    break;
                }
            }
            else if(ch==']'){
                if(!q.empty() && q.top()=='[') q.pop();
                else{
                    flg=false;
                    break;
                }
            }
        }
        if (flg && q.empty()) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}