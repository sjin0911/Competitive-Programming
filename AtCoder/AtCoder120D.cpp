#include <iostream>
#include <vector>
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
	ll N,M;
    cin>>N>>M;
    
    vector<ll> A(M),B(M),C(M);
    UnionFind UF(N+1);

    for(int i=0;i<M;++i) cin>>A[i]>>B[i];

    ll cnt=N*(N-1)/2;
    for(int i=M-1;i>=0;--i){
        C[i]=cnt;
        if(!UF.issame(A[i],B[i]))
            cnt-=UF.size(A[i])*UF.size(B[i]);
        UF.unite(A[i],B[i]);
    }   

    for(int i=0;i<M;++i){
        cout<<C[i]<<"\n";
    }
    return 0;
}   