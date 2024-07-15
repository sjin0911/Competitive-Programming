#include <iostream>
#include <set>
using namespace std;

int main(){
    int N;
    set<int> A;

    cin>>N;
    for(int i=0;i<N;++i){
        int tmp;
        scanf("%d",&tmp);
        A.insert(tmp);
    }

    for(set<int>::iterator iter=A.begin();iter!=A.end();iter++){
        printf("%d\n",*iter);
    }
    return 0;
}