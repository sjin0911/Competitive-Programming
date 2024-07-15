#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define p pair<int,int>

int N,M,B;
map<int,int> Map;

bool cmp(const p& a, const p& b){
    return a.first>b.first;
}

int main(){
    int value=99999999, height,Min=99999999,Max=-99999999;

    cin>>N>>M>>B;

    for (int i=0;i<N*M;++i){
        int tmp;
        cin>>tmp;
        if(Map.find(tmp)!=Map.end()){
            Map[tmp]++;
        }else{
            Map.insert({tmp,1});
        }
        Min=min(tmp,Min);
        Max=max(tmp,Max);
    }

    vector<p> H(Map.begin(),Map.end());
    sort(H.begin(),H.end(),cmp);

    // for(int i=0;i<H.size();i++){
    //     cout<<H[i].first<<" ";
    // }

    for(int i=Min;i<=Max;++i){
        int b=B,tvalue=0;
        bool flg=true;

        for(auto it=H.begin();it!=H.end();it++){
            int n=it->second;
            if (it->first>i){
                tvalue+=(it->first-i)*n*2;
                b+=n*(it->first-i);
            }else if(it->first<i) {
                if (b-n*(i-it->first)>=0){
                    tvalue+=(i-it->first)*n;
                    b-=n*(i-it->first);
                }else{
                    flg=false;
                }
            }
            // cout<<i<<" "<<it->first<<" "<<n<<" "<<tvalue<<"\n";
        }
        if(flg){
            if(value>tvalue){
                value=tvalue;
                height=i;
            }else if(value==tvalue&&i>height){
                height=i;
            }
        }
    }
    cout<<value<<" "<<height<<"\n";

    return 0;
}