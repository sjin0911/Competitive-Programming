#include <iostream>
#include <stack>
using namespace std;

int K;
stack<int> A;

int main(){
    int sum=0;
    cin>>K;

    for(int i=0;i<K;++i){
        int tmp;
        cin>>tmp;

        if(tmp==0) A.pop();
        else A.push(tmp);
    }

    while(!A.empty()){
        sum+=A.top();
        A.pop();
    }
    cout<<sum<<"\n";
    return 0;
}