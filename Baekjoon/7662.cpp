#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const long long MAXVAL=1LL<<32;
typedef long long ll;

struct DPQ{
private: 
    priority_queue<ll> Maxheap;
    priority_queue<ll, vector<ll>, greater<ll>> Minheap;
    map<ll, ll> Map;
public: 
    void push(ll x){
        Maxheap.push(x);
        Minheap.push(x);


        //if it exist
        if(Map.find(x)!=Map.end()){
            Map[x]+=1;
        }else{
            Map[x]=1;
        }
        cout<<Maxheap.top()<<" "<<Minheap.top()<<" "<<Map[x]<<"\n";
    }
    ll top_max(){
        ll n=MAXVAL;
        if(!Maxheap.empty()){
            n=Maxheap.top();
            while(Map[n]==0){
                Maxheap.pop();
                if(!Maxheap.empty()) n=Maxheap.top();
                else{
                    n=MAXVAL;
                    break;
                }
            }
        }
        return n;
    }
    ll top_min(){
        ll n=MAXVAL;
        if(!Minheap.empty()){
            n=Minheap.top();
            while(Map[n]==0){
                Minheap.pop();
                if(!Minheap.empty()) n=Minheap.top();
                else{
                    n=MAXVAL;
                    break;
                }
            }
        }
        return n;
    }
    void pop_max(){
        ll n=top_max();
        if (n!=MAXVAL) Map[n]-=1;
    }
    void pop_min(){
        ll n=top_min();
        if (n!=MAXVAL) Map[n]-=1;
    }

};

int main(){
    ll T;
    cin>>T;

    while(T--){
        ll N;
        cin>>N;

        DPQ dpq;
        while(N--){
            char cmd;
            ll num;
            cin>>cmd>>num;

            if(cmd=='I'){
                dpq.push(num);
            }else if(cmd=='D'){
                if(num==1) dpq.pop_max();
                else  dpq.pop_min();
            }
        }     
        if(dpq.top_max()!=MAXVAL) cout<<dpq.top_max()<<" "<<dpq.top_min()<<"\n";
        else cout<<"EMPTY\n";  
    }
    return 0;
}



