#include<stdio.h>
#include<math.h>
#define ll long long int
int fib(ll n){
    double phi=(1+sqrt(5))/2;
    return round(pow(phi,n)/sqrt(5));
}
