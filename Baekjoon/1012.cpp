#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>* G;
int** Arr;
bool* Visited;

int dfs(int x){
    int count=0;
    bool flg=false;
    
    Visited[x]=true;

    //test print
    // cout<<x<<" ";

    for(int i=0;i<G[x].size();++i){
        int y=G[x][i];
        if(!Visited[y]) {
            count++;
            dfs(y);
        }
    }

    return count;
}
int main(){
    int T;
    cin>>T;

    while(T>0){
        int M,N,K,count=0;
        cin>>M>>N>>K;

        int siz=M*N;

        G=new vector<int>[siz];
        Visited=new bool[siz];
        Arr=new int*[M];
        for(int i=0;i<M;++i) Arr[i]=new int[N];

        for(int i=0;i<siz;++i) Visited[i]=false;

        for(int i=0;i<K;++i){
            int x,y;
            cin>>x>>y;
            Arr[x][y]=1;

            int node_num=x*N+y;
            G[node_num].push_back(node_num);
            if(y-1>=0&&Arr[x][y-1]==1){
                G[node_num].push_back(node_num-1);
                G[node_num-1].push_back(node_num);
            }
            if(y+1<N&&Arr[x][y+1]==1){
                G[node_num].push_back(node_num+1);
                G[node_num+1].push_back(node_num);
            }
            if(x-1>=0&&Arr[x-1][y]==1){
                G[node_num].push_back(node_num-N);
                G[node_num-N].push_back(node_num);
            }
            if(x+1<M&&Arr[x+1][y]==1){
                G[node_num].push_back(node_num+N);
                G[node_num].push_back(node_num);
            }
        }

        //print graph
        // for(int i=0;i<siz;++i){
        //     cout<<i<<"  ";
        //     for(int j=0;j<G[i].size();++j)
        //         cout<<G[i][j]<<" ";
        //     cout<<"\n";
        // }

        //dfs
        for(int i=0;i<siz;++i) {
            if(dfs(i)>0||(G[i].size()==1)) count++;

            //print dfs
            // dfs(i);
            // cout<<"\n";
        }
        cout<<count<<"\n";

        delete[] G;
        delete[] Visited;
        --T;
    }
    return 0;
}
/*
1
6 10 14
0 0 
0 1
1 1
2 4
3 4
4 1
4 2
4 7
4 8 
4 9
5 4
5 7
5 8
5 9

5
*/
