#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N, C;
int arr[200005]; // 只有存Xi，並且保證輸入都是int

// 注意！！！要用double！！！使用float的話位數不夠
double f(double x){
    double cost = 0;
    for (int i = 0; i < N; i++)
        cost += (x - arr[i]) * (x - arr[i]);
    return cost;
}

// 三分搜，因為cost function會為convex function，詳細見講義
double tenarySearch(double L, double R, double eps){
    while (L + eps < R)
    {
        double ML = L + (R - L) / 3;
        double MR = R - (R - L) / 3;
        double ml_cost = f(ML);
        double mr_cost = f(MR);
        // 若ml_cost小於mr_cost，代表ml_cost更接近答案，把R往左移
        // 反之或相等則把L往右移
        // 正確性詳見講義，有圖搭配更好理解
        if(ml_cost < mr_cost) R = MR;
        else L = ML;
    }
    return L; // return L或R都可以，因為誤差都在1e-9以內
}

__int32_t main(){
    cin >> N >> C;
    double totalCost = 0;
    for (int i = 0; i < N; i++)
    {
        int Y;
        cin >> arr[i] >> Y;
        totalCost += (C - Y) * (C - Y); // 因為C為固定，所以Y軸的Cost可以先算
    }
    // L和R直接設定成最大邊界情況
    double L = -100000;
    double R =  100000;
    double eps = 1e-9; // 誤差值
    double x = tenarySearch(L, R, eps);
    totalCost += f(x);

    // 要設定輸出精準度到小數點後10位才符合誤差1e-9
    cout << fixed << setprecision(10) <<  totalCost << endl;

    return 0;
}

