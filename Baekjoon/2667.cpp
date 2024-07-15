#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int,int> Coord;

//Union-Find
struct UnionFind{
    vector<vector<Coord>> par;
    vector<vector<int>> siz;

    //initialization
    UnionFind(int n):par(n+1,vector<Coord> (n+1,{-1,-1})), siz(n+1,vector<int> (n+1,1)){}

    //find root
    Coord root(Coord x){
        if(par[x.first][x.second]==x) return x;
        else if(par[x.first][x.second].first==-1) return {-1,-1};
        else return par[x.first][x.second]=root(par[x.first][x.second]);
    }
    bool issame(Coord x, Coord y){
        return root(x)==root(y);
    }
    void insert(Coord x){
        par[x.first][x.second]=x;
        siz[x.first][x.second]=1;
    }
    bool unite(Coord x,Coord y){
        x=root(x);
        y=root(y);

        if(x==y) return false;

        if(siz[x.first][x.second]<siz[y.first][y.second]) swap(x,y);

        par[y.first][y.second]=x;
        siz[x.first][x.second]+=siz[y.first][y.second];
        return true;
    }

    int size(Coord x){
        x=root(x);
        return siz[x.first][x.second];
    }
    void print(){
        for(int i=1;i<par.size();++i){
            for(int j=1;j<par[0].size();++j){
                cout<<par[i][j].first<<" "<<par[i][j].second<<"  ";
            }cout<<"\n";
        }
    }
};
int main(){
    int N;
    cin>>N;

    UnionFind uf(N);
    vector<vector<int>> Map(N+1,vector<int> (N+1,0));

    for(int i=1;i<=N;++i){
        string str;
        cin>>str;
        for(int j=1;j<=N;++j){
            Map[i][j]=str[j-1]-'0';

            if(Map[i][j]==1){
                uf.insert({i,j});
                if(i>1 && Map[i-1][j]==1){
                    uf.unite({i-1,j},{i,j});
                }
                if(j>1 && Map[i][j-1]==1){
                    uf.unite({i,j-1},{i,j});
                }
            }
        }
    }
    set<Coord> Res;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
           Res.insert(uf.root({i,j}));
        }
    }
    vector<int> Size;
    for(set<Coord>::iterator it=Res.begin();it!=Res.end();++it){
        if((*it).first!=-1) Size.push_back(uf.size(*it));
    }
    sort(Size.begin(),Size.end());

    cout<<Size.size()<<"\n";
    for(int i=0;i<Size.size();++i){
        cout<<Size[i]<<"\n";
    }

    return 0;
}