#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &a,int key){
    int left=0,right=(int)a.size()-1;
    while(right>=left){
        int mid=left+(right-left)/2;

        if(a[mid]==key) return 1;
        else if(a[mid]>key) right=mid-1;
        else if(a[mid]<key) left=mid+1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N,M,tmp;
    vector<int> A;

    //입력
    scanf("%d",&N);
    for(int i=0;i<N;++i) {
        scanf(" %d",&tmp);
        A.push_back(tmp);
    }

    scanf("%d",&M);
    sort(A.begin(),A.end());

    //이진 탐색
    for(int i=0;i<M;++i){
        scanf(" %d",&tmp);
        printf("%d\n",binary_search(A,tmp));
    }

    return 0;
}