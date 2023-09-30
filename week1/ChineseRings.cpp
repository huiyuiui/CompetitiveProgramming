#include <iostream>

using namespace std;

int N;
void recur_in(int n);
void recur_out(int n);

void recur_out(int n){
    if(n == 1){
        cout << "Move ring " << 1 << " out" << endl;
        return;
    }
    else if(n < 1) return;
    recur_out(n - 2);
    cout << "Move ring " << n << " out" << endl;
    recur_in(n - 2);
    recur_out(n - 1);
}

void recur_in(int n){
    if(n == 1){
        cout << "Move ring " << 1 << " in" << endl;
        return;
    }
    else if(n < 1) return;
    recur_in(n - 1);
    recur_out(n - 2);
    cout << "Move ring " << n << " in" << endl;
    recur_in(n - 2);
}

int main(){

    cin >> N;
    recur_out(N);
    return 0;
}

