#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin>>N;

    for(int n=0;n<N;++n){
        int file_num,idx;
        cin>>file_num>>idx;

        queue<int> F;
        priority_queue<int> q;


        for(int i=0;i<file_num;++i){
            int imp;
            cin>>imp;
            F.push(imp);
            q.push(imp);
        }
        int max_imp=q.top(),count=0;
        q.pop();

        while(idx!=-1){
            int top=F.front();
            if(top<max_imp){
                F.pop();
                F.push(top);

                if(idx==0){
                    idx=F.size()-1;
                }
                else{
                    --idx;
                }
            }
            else{
                count++;
                --idx;

                F.pop();
                
                if(!q.empty()){
                    max_imp=q.top();
                    q.pop();
                }
            }
        }
        cout<<count<<"\n";
    }

    return 0;
}