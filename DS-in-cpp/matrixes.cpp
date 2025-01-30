#include<bits/stdc++.h>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;
public:
    Diagonal(){
        n=2;
        A = new int[n];
    }
    Diagonal(int n){
        this->n = n;
        A = new int[this->n];
    }
    ~Diagonal(){
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

class lowerTriangle
{
private:
    int *A;
    int n;
public:
    lowerTriangle(){
        n=2;
        A = new int[n*(n+1)/2];
    }
    lowerTriangle(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~lowerTriangle(){
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

int main(){
    int d, x;
    cout << "Enter the dimension: ";
    cin >> d;

    lowerTriangle lm(d);

    cout << "Enter all elements: ";
    for(int i=1; i<=d; i++){
        for(int j=1; j<=d; j++){
            cin >> x;
            lm.Set(i, j, x);
        }
    }
    lm.Display();

    return 0;

}

void Diagonal::Set(int i, int j, int x){
    if(i==j){
        A[i-1] = x;
    }
}
int Diagonal::Get(int i, int j){
    if(i==j){
        return A[i-1];
    }
    else{
        return 0;
    }
}
void Diagonal::Display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                cout << A[i] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void lowerTriangle::Set(int i, int j, int x){
    if(i>=j){
        A[i*(i-1)/2+j-1] = x;
    }
}
int lowerTriangle::Get(int i, int j){
    if(i>=j){
        return A[i*(i-1)/2 +j-1];
    }
    else{
        return 0;
    }
}
void lowerTriangle::Display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j){
                cout << A[i*(i-1)/2+j-1] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}