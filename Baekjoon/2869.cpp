#include <iostream>
using namespace std;

int main(){
    int A,B,V;
    cin>>A>>B>>V;

    V-=B;
    int ans=V/(A-B);
    if (V%(A-B)!=0) ans+=1;

    cout<<ans<<"\n";
    return 0;
}