#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int n;
    cout << "Enter a number: " ;
    cin >> n;

    int factorial = fact(n);
    cout << "Factorial: " << factorial;
    return 0;
}