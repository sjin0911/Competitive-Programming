#include <iostream>
#include <deque>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;

int main(){
    ll T;
    queue<char> P;
    deque<int> X;
    ll n;
    char ch;
    string str;

    cin>>T;
    while(T>0){  
        T--;
        
        cin.ignore();
        cin>>str;

        for(int i=0;i<str.size();++i){
            P.push(str[i]);
        }
        cin>>n;


        // while(!P.empty()){
        //     cout<<P.front()<<" ";
        //     P.pop();
        // }

        cin>>ch;
        while(n>0){
            int n_;
            cin>>n_;

            X.push_back(n_);
            n--;

            if(n!=0)cin>>ch;
        }
        cin>>ch;

        bool order=true,error=false;
        while(!P.empty()){
            char p=P.front();
            P.pop();

            // cout<<p<<" ";

            if(p=='R'){
                order=!order;
            }else if(p=='D'){
                if(X.empty()) error=true;
                else if(order) X.pop_front();
                else X.pop_back();
            }
        }
        if(error){
            cout<<"error\n";
            continue;
        }

        cout<<"[";
        while(!X.empty()){
            if(X.size()==1){
                cout<<X.front();
                X.pop_front();
                break;
            }
            if(order){
                cout<<X.front();
                X.pop_front();
            }else{
                cout<<X.back();
                X.pop_back();
            }cout<<",";
        }cout<<"]\n";
    }

    return 0;
}