#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;

    int M,cursor;
    vector<char> editor;
    for(int i=0;i<str.size();++i){
        editor.push_back(str[i]);
    }

    cursor=editor.size();
    cin>>M;
    while(M--){
        char cmd;
        cin>>cmd;

        cout<<cursor<<"\n";
        if(cmd=='L'){
            if(cursor!=0) cursor--;
        }else if(cmd=='D'){
            if(cursor<editor.size()) cursor++;
        }else if(cmd=='B'){
            if(cursor!=0){
                for(int i=cursor-1;i<editor.size()-1;++i){
                    editor[i]=editor[i+1];
                }
                editor.pop_back();
            }
        }else if(cmd=='P'){
            char ch;
            int sz=editor.size();
            cin>>ch;

            editor.push_back(ch);
            if(cursor<sz){
                for(int i=editor.size()-2;i>=cursor;--i){
                    editor[i+1]=editor[i];
                }
                editor[cursor]=ch;
            }else{
                cursor++;
            }
        }
         for(int i=0;i<editor.size();++i){
            cout<<editor[i];
        }
        cout<<"\n";
    }
   
    return 0;
}