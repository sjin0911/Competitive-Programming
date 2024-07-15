#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin>>N;

    priority_queue<double> S;

    for(int i=1;i<=N;++i){
        double tmp;
        cin>>tmp;
        S.push(tmp);
    }
    double M=S.top(),ave=0;

    while(!S.empty()){
        // cout<<S.top()/M*100<<" ";
        ave+=(S.top()/M*100)/N;
        S.pop();
    }
    cout<<ave<<"\n";

    return 0;
}
/*
3
40 80 60
75.0

3
10 20 30
66.666667

4
1 100 100 100
75.25

5
1 2 4 8 16
38.75

2
3 10
65.0

4
10 20 0 100
32.5

1
50
100.0

9
10 20 30 40 50 60 70 80 90
55.55555555555556
*/