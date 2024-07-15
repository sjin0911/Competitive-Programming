#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

const long long INF=1ll<<60;
static int MAX=100000;
int N,K;
vector<bool> visited(MAX+1,false);
int Map[3]={-1,1,2};

void bfs(int start){
    queue<int> q;
    int depth=0;

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int q_siz=q.size();
        depth++;
        // cout<<"---------------------\n";
        // cout<<x<<" ";

        for(int i=0;i<q_siz;++i){
            int x=q.front();
            q.pop();

            for(int j=0;j<3;++j){
                int new_x;
                if(j==2) new_x=x*Map[j];
                else new_x=x+Map[j];

                // cout<<new_x<<" ";

                if(new_x==K){
                    cout<<depth<<"\n";
                    return;
                }
                else if(new_x<0||new_x>MAX)continue;
                else if(visited[new_x]) continue;
                q.push(new_x);
                visited[new_x]=true;
            }
        }   
        // cout<<"\n";
    }//while
}

int main(){
    cin>>N>>K;  

    if(K==N) cout<<0<<"\n";  
    else bfs(N);

    return 0;
}