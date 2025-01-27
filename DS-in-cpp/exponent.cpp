#include<bits/stdc++.h>
using namespace std;

 
int exponent(int m, int n){
    static int pow = 1;
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return exponent(m*m, n/2);
    }
    else{
        return m*(exponent(m*m, n/2));
    }
}

int main(){
    int m, n;
    cout << "Enter two numbers (base and power): ";
    cin >> m >> n;

    int result = exponent(m, n);
    cout << "Exponential result: " << result << endl;

    return 0;
}