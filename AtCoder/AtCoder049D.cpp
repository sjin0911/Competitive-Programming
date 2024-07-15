#include <iostream>
#include <vector>
#include <map>
using namespace std;

using ll=long long;
//Union-Find
struct UnionFind{
	vector<int> par,siz;

	//initialization
	UnionFind(int n): par(n,-1), siz(n,1) {}
	
	//find root
	int root(int x){
		if(par[x]==-1) return x;
		else return par[x]=root(par[x]);
	}
	
	bool issame(int x, int y){
		return root(x)==root(y);
	}
	
	bool unite(int x, int y){
		x=root(x);
		y=root(y);
	
		if(x==y) return false;
		
		if (siz[x]<siz[y]) swap(x,y);
		
		par[y]=x;
		siz[x]+=siz[y];
		return true;
	}

	int size(int x){
		return siz[root(x)];
	}
};

int main(){
	ll N,K,L;	
	cin>>N>>K>>L;

	UnionFind UFp(N+1),UFr(N+1);

	for(int i=0;i<K;++i){
		int p,q;
		cin>>p>>q;
		UFp.unite(p,q);
	}
	for(int i=0;i<L;++i){
		int r,s;
		cin>>r>>s;
		UFr.unite(r,s);
	}

	map<pair<int,int>,int> F;
	for(int i=1;i<=N;++i){
		++F[{UFp.root(i),UFr.root(i)}];
	}
	
	for(int i=1;i<=N;++i){
		cout<<F[{UFp.root(i),UFr.root(i)}]<<" ";
	}
	return 0;
}   