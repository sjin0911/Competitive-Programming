#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<vector<int>> Maze;
typedef pair<int,int> Coor;
int N,M;

int bfs(Coor init){
    int depth=0;
    queue<Coor> q;
    q.push(init);

    while(!q.empty()){
        int siz=q.size();
        bool find=false;

        depth++;
        for(int i=0;i<siz;++i){
            Coor cur=q.front();
            int cur_x=cur.first,cur_y=cur.second;
            q.pop();

            if (cur_x==N-1 && cur_y==M-1){
                find=true;
                break;
            }

            if (cur_x>0 && Maze[cur_x-1][cur_y]==1){
                q.push(make_pair(cur_x-1,cur_y));
                Maze[cur_x-1][cur_y]=0;
            }
            if (cur_x<N-1 && Maze[cur_x+1][cur_y]==1){
                q.push(make_pair(cur_x+1,cur_y));
                Maze[cur_x+1][cur_y]=0;
            }
            if (cur_y>0 && Maze[cur_x][cur_y-1]==1){
                q.push(make_pair(cur_x,cur_y-1));
                Maze[cur_x][cur_y-1]=0;
            }
            if (cur_y<M-1 && Maze[cur_x][cur_y+1]==1){
                q.push(make_pair(cur_x,cur_y+1));
                Maze[cur_x][cur_y+1]=0;
            }
        }

        if(find) return depth;
    }
    return -1;

}
int main(){
    cin>>N>>M;

    Maze.assign(N,vector<int> (M,0));

    string str;
    for(int i=0;i<N;++i){
        cin>>str;
        for(int j=0;j<M;++j){
            Maze[i][j]=str[j]-'0';
        }
    }
    cout<<bfs(make_pair(0,0))<<"\n";
    return 0;
}