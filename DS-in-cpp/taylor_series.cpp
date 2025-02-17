#include<bits/stdc++.h>
using namespace std;

double taylor(int x, int n){
    static double p=1, f=1;
    double r;

    if(n==0)
        return 1;
    r = taylor(x, n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

int main(){
    int x, n;

    cout << "Enter x and n: ";
    cin >> x >> n;

    double e = taylor(x, n);
    cout << e << endl;

    return 0;
}