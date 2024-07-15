#include <iostream>
#include <algorithm>
using namespace std;

class MEMBER{
public:
    int age;
    string name;
};
MEMBER* M=new MEMBER[100001];

bool cmp(MEMBER a,MEMBER b){
    return a.age<b.age;
}
int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;++i) {
        cin>>M[i].age>>M[i].name;
    }

    stable_sort(M,M+N,cmp);

    for(int i=0;i<N;++i)
        cout<<M[i].age<<" "<<M[i].name<<'\n';

    return 0;
}