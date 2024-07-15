#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Rounds(double n){
    int res=n;
    if (n-res<0.5){
        return res;
    }else{
        return res+1;
    }

}
int main(){
    int N;
    double bound_number=0,sum=0,res=0;
    cin>>N;

    vector<int> S(N);
    for (int i=0;i<N;++i) cin>>S[i];

    bound_number=Rounds(N*0.15);
    // cout<<":"<<bound_number<<"\n";

    sort(S.begin(),S.end());
    
    for(std::vector<int>::iterator it=S.begin()+bound_number;it!=S.end()-bound_number;++it){
        sum+=*it;
        // cout<<*it<<" ";
    }
    if (N!=0)
        res=Rounds(sum/(N-2*bound_number));

    cout<<res<<"\n";
    return 0;

}