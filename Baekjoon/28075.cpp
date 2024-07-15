#include <iostream>
#include <vector>
using namespace std;

const int ROW=2,COL=3;
int N,M;
vector<vector<int>> A(ROW+1,vector<int>(COL+1,0));

int dfs(int n,int m,int x){
    int sum=0;
    //재귀함수 종료조건
    if(n==N) return (m>=M?1:0);

    for(int i=1;i<=ROW;++i){
        for(int j=1;j<=COL;++j){
            if(j==x)  sum+=dfs(n+1,m+A[i][j]/2,j);
            else sum+=dfs(n+1,m+A[i][j],j);
        }
    }

    return sum;

}
int main(){
    cin>>N>>M;

    for(int i=1;i<=ROW;++i){
        for(int j=1;j<=COL;++j) cin>>A[i][j];
    }

    cout<<dfs(0,0,0)<<"\n";

    return 0;
}
