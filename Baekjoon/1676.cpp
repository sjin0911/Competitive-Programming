#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;

    int count5=0,count2=0,res;

    for (int i=1;i<=N;++i){
        int tmp=i;
        while (tmp%5==0){
            count5++;
            tmp/=5;
        }
        tmp=i;
        while (tmp%2==0){
            count2++;
            tmp/=2;
        }
    }
    res=min(count5,count2);
    cout<<res<<"\n";
    return 0;
}
