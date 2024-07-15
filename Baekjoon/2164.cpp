#include <iostream>
#include <deque>

using namespace std;

int main(){
    int N;
    deque<int> A;

    cin>>N;
    for(int i=N;i>0;--i) A.push_back(i);

    while(A.size()!=1){
        A.pop_back();
        int tmp=A.back();
        A.pop_back();
        A.push_front(tmp);
    }

    cout<<A.back()<<endl;
    return 0;
}