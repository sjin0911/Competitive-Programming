#include <iostream>
#include <vector>

using namespace std;

const int INF=20000000;

// template <class T> void print(vector <vector<T>> &a){
//     for(int i=0;i<a.size();++i){
//         for(int j=0;j<a[0].size();++j){
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

int main(){

    int M,N;
    vector<vector<char>> A;

    //입력
    cin>>N>>M;
    A.assign(N,vector<char> (M));

    for(int i=0;i<N;++i){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }

    //부르트포스 알고리즘 (무조건 전체탐색)
    int res=INF;
    for(int i=0;i<=N-8;++i){
        for(int j=0;j<=M-8;++j){
            int tmp=0;
            // vector<vector<int>> B;
            // B.assign(8,vector<int> (8,0));

            for(int k=0;k<8;++k){
                for(int l=0;l<8;++l){
                    char cmp=((k+l)%2==0)?'W':'B';

                    if(A[i+k][j+l]!=cmp) {
                        // B[k][l]=1;
                        tmp++;
                    }
                }
                // cout<<endl;
            }
            // cout<<endl;
            res=min(res,min(tmp,64-tmp));
            // print(B);
        }
    }

    //결과 출력
    cout<<res<<endl;

    return 0;
}