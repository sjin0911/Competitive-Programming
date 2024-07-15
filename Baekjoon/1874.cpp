#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int N,num;
    stack<int> st;
    vector<char> res;
    vector<int> n;
    cin>>N;
    num=N;

    int i=0,k=0;
    bool flag=true;

    n.assign(N,0);
    for(int j=0;j<N;++j) cin>>n[j];

    while(num){
        num--;
        while(st.empty()||st.top()!=n[k]){
            st.push(++i);
            res.push_back('+');
            if(i>N+1){
                flag=false;
                break;
            }
        }
        if(!st.empty()&&st.top()==n[k]){
            res.push_back('-');
            st.pop();
        }
        if(!flag) break;
        k++;
    }

    if(!flag){ 
        cout<<"NO\n";
        return 0;
    }

    for(int j=0;j<res.size();++j){
        cout<<res[j]<<"\n";
    }
    return 0;
}
