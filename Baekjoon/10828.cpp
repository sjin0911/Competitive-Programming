#include <iostream>
#include <vector>
using namespace std;

class Stack{
private:
    vector<int> stack;
    int size;
public:
    Stack(int N){
        stack.resize(N);
        stack[0]=-1;
        size=0;
    }
    void push(int n){
        stack[++size]=n;
    }
    int pop(){
        return (size==0?-1:stack[size--]);
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size==0;
    }
    int top(){
        return stack[size];
    }
    // void print(){
    //     for(int i=0;i<=size;++i) cout<<stack[i]<<" ";
    //     cout<<"\n";
    // }
};
int main(){
    int N;
    cin>>N;
    Stack st(N);

    for(int i=0;i<N;++i){
        string str;
        cin>>str;

        // cout<<str<<endl;
    
        if(str=="push"){
            int n;
            cin>>n;
            st.push(n);
        }else if(str=="pop"){
            cout<<st.pop()<<endl;
        }else if(str=="size"){
            cout<<st.getsize()<<endl;
        }else if(str=="empty"){
            cout<<(st.isempty()?1:0)<<endl;
        }else{
            cout<<st.top()<<endl;
        }
        // st.print();
    }
    return 0;
}