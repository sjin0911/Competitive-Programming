#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<ll,vector<ll>, greater<ll>> Q;
    for(int i=0;i<N*N;++i){
        int n;
        cin>>n;

        Q.push(n);
        if(Q.size()>N) Q.pop();
    }
    cout<<Q.top()<<"\n";
    return 0;
}