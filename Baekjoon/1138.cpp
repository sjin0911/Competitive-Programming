#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> Arr(N,0);
    for(int i=0;i<N;++i){
        int n,count=0,j=0;
        cin>>n;

        while(j<N){
            if(count==n) break;
            if(Arr[j++]==0)count++;
        }
        while(Arr[j]!=0) j++;
        Arr[j]=i+1;

        for(int i=0;i<N;++i)cout<<Arr[i]<<" ";
        cout<<"\n";
    }
    

    return 0;
}