#include<iostream>
using namespace std;
int maxgongyue(int m, int n){
    while(n != 0){
        int temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}//求 319 和 377 的最大公约数。

// 377 ÷ 319 = 1 ... 58 (377除以319，商1，余58)

// 319 ÷ 58 = 5 ... 29 (用除数319除以余数58，商5，余29)

// 58 ÷ 29 = 2 ... 0 (用除数58除以余数29，商2，余0)

// 当余数为 0 时，当前的除数 29 就是最大公约数。
int mingongbei(int m, int n){
    int i = maxgongyue(m, n);
    return (m * n / i);
}//两个数的乘积 = 它们的最大公约数 × 它们的最小公倍数
int main(){
    int m, n;
    cin >> m >> n;
    cout << maxgongyue(m, n) << " " << mingongbei(m, n) << endl;
}
