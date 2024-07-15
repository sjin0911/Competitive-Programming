#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define MAX 10000

template<typename T>
class Deque{
private:
    vector<T> deque;
    int left,right;
public:
    Deque(){
        left=0;
        right=0;
        deque.assign(MAX,0);
    }
    void push_front(T x){
        deque[right]=deque[right-1];
        for(int i=right-1;i>left;--i){
            deque[i]=deque[i-1];
        }
        deque[left]=x;
        right++;
    }
    void push_back(T x){
        deque[right]=x;
        right++;
    }
    T pop_front(){
        if(left==right){
            return -1;
        }
        return deque[left++];
    }
    T pop_back(){
        if(left==right){
            return -1;
        }
        return deque[--right];
    }
    int size(){
        return (right-left);
    }
    int empty(){
        return (right==left)?1:0;
    }
    T front(){
        return (right==left)?-1:deque[left];
    }
    T back(){
        return (right==left)?-1:deque[right-1];
    }
    void print(){
        cout<<left<<" "<<right<<"\n";
        for(int i=0;i<10;++i){
            cout<<deque[i]<<" ";
        }
        cout<<"\n\n";
    }
};

int main(){
    int N;
    string line,buffer,tmp;
    Deque<int> D;
    cin>>N;
    getline(cin,buffer);

    for(int i=0;i<N;++i){
        getline(cin,line);

        vector<string> cmd;
        istringstream ss (line);
        while(getline(ss,tmp,' ')){
            cmd.push_back(tmp);
        }
        if (!cmd[0].compare("push_front")){
            int x=stoi(cmd[1]);
            D.push_front(x);
        }
        else if (!cmd[0].compare("push_back")){
            int x=stoi(cmd[1]);
            D.push_back(x);
        }
        else if (!cmd[0].compare("pop_front")){
            cout<<D.pop_front()<<"\n";
        }
        else if (!cmd[0].compare("pop_back")){
            cout<<D.pop_back()<<"\n";
        }
        else if (!cmd[0].compare("size")){
            cout<<D.size()<<"\n";
        }
        else if (!cmd[0].compare("empty")){
            cout<<D.empty()<<"\n";
        }
        else if (!cmd[0].compare("front")){
            cout<<D.front()<<"\n";
        }
        else if (!cmd[0].compare("back")){            
            cout<<D.back()<<"\n";
        }
        // D.print();
    }
    return 0;
}