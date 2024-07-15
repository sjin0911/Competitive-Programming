#include <iostream>
#include <vector>
using namespace std;

//Union-Find
struct UnionFind{
    vector<int> par,siz;

    //initialization
    UnionFind(int n):par(n+1,-1), siz(n+1,1){}

    //find root
    int root(int x){
        if(par[x]==-1) return x;
        else return par[x]=root(par[x]);
    }
    bool issame(int x, int y){
        return root(x)==root(y);
    }
    bool unite(int x,int y){
        x=root(x);
        y=root(y);

        if(x==y) return false;

        if(siz[x]<siz[y]) swap(x,y);

        par[y]=x;
        siz[x]+=siz[y];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }

    void print(){
        for(int i=0;i<par.size();++i){
            cout<<i<<": "<<siz[i]<<"\n";
        }
    }
};
int main(){
    int N,M;
    cin>>N>>M;

    UnionFind uf(N);
    while(M--){
        int a,b;
        cin>>a>>b;

        uf.unite(a,b);
    }
    cout<<uf.size(1)-1<<"\n";
    return 0;
}