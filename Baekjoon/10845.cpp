#include <iostream>
#include <vector>
using namespace std;

class Queue{
private:
    vector<int> queue;
    int left,right;
public:
    Queue(int N){
        queue.resize(N);
        queue[0]=-1;
        left=right=1;
    }
    void push(int n){
        queue[right++]=n;
    }
    bool empty(){
        return (right-left)==0;
    }
    int pop(){
        return empty()?-1:queue[left++];
    }
    int size(){
        return right-left;
    }
    int front(){
        return empty()?-1:queue[left];
    }
    int back(){
        return empty()?-1:queue[right-1];
    }
    void print(){
        cout<<left<<" "<<right<<endl;
        for(int i=left;i<right;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int N;
    cin>>N;
    Queue que(N);

    for(int i=0;i<N;++i){
        string str;
        cin>>str;

        // cout<<str<<endl;
    
        if(str=="push"){
            int n;
            cin>>n;
            que.push(n);
            
        }else if(str=="pop"){
            cout<<que.pop()<<endl;
        }else if(str=="size"){
            cout<<que.size()<<endl;
        }else if(str=="empty"){
            cout<<(que.empty()?1:0)<<endl;
        }else if(str=="front"){
            cout<<que.front()<<endl;
        }else{
            cout<<que.back()<<endl;
        }
        que.print();
    }
    return 0;
}