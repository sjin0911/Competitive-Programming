#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); // false
    cin.tie(0); // NULL
    cout.tie(NULL); // 0

    int N;
    cin>>N;
    
    vector<int> Counting(10000,0);
    while(N--){
        int num;
        cin>>num;

        Counting[num-1]++;
    }

    for(int i=0;i<10000;++i){
        while(Counting[i]--){
            cout<<i+1<<"\n";
        }
    }
    return 0;
}