#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n<=0){
        return 0;
    }
    return n + sum(n-1);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = sum(n);
    cout << "Summation: " << result << endl;

    return 0;

}