#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Pair;

bool comp(Pair &a,Pair &b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
int main(){
    int N;
    cin>>N;

    deque<Pair> Meeting,Room;   
    for(int i=0;i<N;++i){
        ll s,e;
        cin>>s>>e;

        Meeting.push_back(make_pair(s,e));
    }
    sort(Meeting.begin(),Meeting.end(),comp);

    // while(!Meeting.empty()){
    //     cout<<"("<<Meeting.front().first<<", "<<Meeting.front().second<<") ";
    //     Meeting.pop_front();
    // }

    Room.push_back(Meeting.front());
    Meeting.pop_front();

    while(!Meeting.empty()){
        Pair n=Meeting.front(),prev=Room.back();
        Meeting.pop_front();

        if(prev.second<=n.first) Room.push_back(n);
    }
    // while(!Room.empty()){
    //     cout<<"("<<Room.front().first<<", "<<Room.front().second<<") ";
    //     Room.pop_front();
    // }
    cout<<Room.size()<<"\n";
    return 0;
}