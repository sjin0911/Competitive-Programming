#include <iostream>
using namespace std;

long long func(long long n,long long k){
    if(k==0) return 1;
    return (k%2==0)?func(n,k/2)*func(n,k/2):n*func(n,k-1);
}