#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N,K,flag=1;
    queue<int> M;
    cin>>N>>K;

    for(int i=1;i<=N;++i) M.push(i);

    cout<<"<";
    while(M.size()!=1){
        int n=M.front();
        M.pop();
        if (flag%K==0){
            cout<<n<<", ";
        }else{
            M.push(n);
        }
        flag++;
    }
    cout<<M.front()<<">\n";
}