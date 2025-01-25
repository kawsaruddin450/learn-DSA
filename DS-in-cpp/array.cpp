#include<bits/stdc++.h>
using namespace std;

int main(){
    array<int, 10> arr;
    arr[0] = 1;

    cout << "First element: " << arr[0] << endl;

    array<int, 4> arr2 = {1, 2, 3, 4};
    cout << "Elements of second array: " ;
    for(auto ele: arr2){
        cout << ele << " ";
    }

    array<int, 5> arr3 = {1, 2, 3, 4, 5};
    cout << arr3.front() << endl;
    cout << arr3.back() << endl;
    cout << arr3.at(3) << endl;
}