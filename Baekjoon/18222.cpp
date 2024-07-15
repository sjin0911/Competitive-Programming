#include <iostream>
using namespace std;

int func(long long int len,long long int k){
    if(k==1) return 0;
    return (len/2>k)?func(len/2,k):(1-func(len/2,k-len/2));
}