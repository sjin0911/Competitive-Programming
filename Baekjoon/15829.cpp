#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const ll R=31, M=1234567891;

int main(){
    ll L,hash=0;
    cin>>L;

    ll i=1;
    while(L--){
        char ch;
        cin>>ch;

        ll n=ch-'a'+1;
        hash=(hash+(n*i))%M;
        i=(i*31)%M;
    }
    cout<<hash<<"\n";
}