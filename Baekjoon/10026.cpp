#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Coord;
vector<vector<char>> Painting;
int N;

int bfs(){
    vector<vector<bool>> Visited(N,vector<bool> (N,false));
    queue<Coord> q;
    int G=0;

    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(!Visited[i][j]){
                q.push({i,j});
                Visited[i][j]=true;

                char c=Painting[i][j];
                if(c=='G')Painting[i][j]='R';
                while(!q.empty()){
                    Coord cur=q.front();
                    int x=cur.first,y=cur.second;
                    q.pop();

                    if(x>0 && !Visited[x-1][y] && Painting[x-1][y]==c){
                        Visited[x-1][y]=true;
                        q.push({x-1,y});

                        if(c=='G') Painting[x-1][y]='R';
                    }
                    if(y>0 && !Visited[x][y-1] && Painting[x][y-1]==c){
                        Visited[x][y-1]=true;
                        q.push({x,y-1});

                        if(c=='G') Painting[x][y-1]='R';
                    }
                    if(x<N-1 && !Visited[x+1][y] && Painting[x+1][y]==c){
                        Visited[x+1][y]=true;
                        q.push({x+1,y});

                        if(c=='G') Painting[x+1][y]='R';
                    }
                    if(j<N-1 && !Visited[x][y+1] && Painting[x][y+1]==c){
                        Visited[x][y+1]=true;
                        q.push({x,y+1});

                        if(c=='G') Painting[x][y+1]='R';
                    }

                }
                G++;
            }
        }
    }
    return G;

}
int main(){
    cin>>N;

    Painting.assign(N,vector<char> (N,0));

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin>>Painting[i][j];
        
    cout<<bfs()<<" ";
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cout<<Painting[i][j];
        cout<<"\n";
    
    cout<<bfs()<<"\n";;
}   