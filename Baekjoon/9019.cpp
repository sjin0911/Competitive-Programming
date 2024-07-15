#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int,string> instruction;

const int MAX=10001;
vector<vector<instruction>> dslr;
vector<bool> visited;

void bfs(int A,int B){
    queue<instruction> q;
    q.push(make_pair(A,""));
    visited[A]=true;
    
    while(!q.empty()){
        int qsiz=q.size();
        for(int i=0;i<qsiz;++i){
            instruction cur=q.front();
            q.pop();

            int cur_num=cur.first;

            int siz=dslr[cur_num].size();
            for(int j=0;j<siz;++j){
                string cur_str=cur.second;
                if(dslr[cur_num][j].first==B){
                    cout<<cur_str<<dslr[cur_num][j].second<<"\n";
                    return;
                }
                if(!visited[dslr[cur_num][j].first]){
                    visited[dslr[cur_num][j].first]=true;
                    q.push(make_pair(dslr[cur_num][j].first,cur_str.append(dslr[cur_num][j].second)));
                }
            }
        }
    }
}

int main(){
    int T;
    cin>>T;

    dslr.assign(MAX,vector<instruction> (0));
    for(int i=0;i<MAX;++i){
        int tempi=i;

        //D
        tempi=(tempi*2>9999)?(tempi*2)%10000:tempi*2;
        dslr[i].push_back(make_pair(tempi,"D"));

        tempi=i;
        //S
        if(tempi==0) tempi=9999;
        else tempi-=1;
        dslr[i].push_back(make_pair(tempi,"S"));

        tempi=i;
        //L
        int d1=tempi/1000;
        tempi-=d1*1000;
        tempi*=10;
        tempi+=d1;
        dslr[i].push_back(make_pair(tempi,"L"));

        tempi=i;
        //R
        int d4=tempi%10;
        tempi/=10;
        tempi+=d4*1000;
        dslr[i].push_back(make_pair(tempi,"R"));
    }

    while(T>0){
        int A,B;
        cin>>A>>B;

        visited.assign(MAX,false);

        bfs(A,B);
        T--;
    }
}