#include <iostream>
#include <vector>
using namespace std;

//Union-Find
struct UnionFind{
	vector<int> par,siz,d;

	//initialization
	UnionFind(int n): par(n), siz(n,1), d(n,0) {
        for(int i=0;i<n;++i) par[i]=i;
    }
	
	//find root
	int root(int x){
		if(par[x]==x) return x;
		else {
            int y=par[x];
            par[x]=root(par[x]);
            d[x]+=d[y];
            return par[x];
        }
	}
	
	bool issame(int x, int y){
		return root(x)==root(y);
	}
	
	bool unite(int x, int y, int z){
		if(issame(x,y)) return false;
		
        z+=d[x]-d[y];
        x=root(x);
		y=root(y);
		if (siz[x]<siz[y]) {
            swap(x,y);
            z=-z; //merge technique
        }
		par[y]=x;
		siz[x]+=siz[y];
        d[y]=z;
		return true;
	}

	int size(int x){
		return siz[root(x)];
	}

    int dist(int i){
        return d[i];
    }

    void print(){
        for(int i=1;i<d.size();++i){
            cout<<d[i]<<" ";
        }
        cout<<"\n\n";
    }
};

int main(){
    int N,M;
    cin>>N>>M;

    UnionFind UF(N+1);

    while(M--){
        int l,r,d;
        cin>>l>>r>>d;

        if (!UF.unite(l,r,d)&&UF.dist(r)-UF.dist(l)!=d) {
            cout<<"No\n";
            return 0;
        }
        UF.print();
    }
    cout<<"Yes\n";
    return 0;
}