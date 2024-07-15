#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Heap{
private:
    vector<ll> heap;
public:
    Heap(){
        heap.push_back(-1);
    }
    //add x to heap
    void push(ll x){
        heap.push_back(x);
        ll i=(ll)heap.size()-1;

        while(i>0){
            ll p=i/2;

            if(heap[p]<x) break;

            heap[i]=heap[p];
            i=p;
        }
        heap[i]=x;
    }

    ll top(){
        if(heap.size()>1) return heap[1];
        else return 0;
    }

    void pop(){
        if(heap.size()==1) return;

        ll x=heap.back();
        heap.pop_back();

        ll i=1;
        while(i*2<(ll)heap.size()){
            ll child1=i*2,child2=2*i+1;

            if(child2<(ll)heap.size() && heap[child2]<heap[child1]){
                child1=child2;
            }
            if (heap[child1]>=x) break;

            heap[i]=heap[child1];
            i=child1;
        }
        heap[i]=x;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll N;
    cin>>N;

    Heap H;
    while(N>0){
        ll input;
        cin>>input;

        if(input==0){
            cout<<H.top()<<"\n";
            H.pop();
        }else{
            H.push(input);
        }
        N--;
    }
    return 0;
}