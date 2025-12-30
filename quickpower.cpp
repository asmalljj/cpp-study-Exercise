long long quickPower(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) { // 如果b的最低位是1
            res *= a;
        }
        a *= a;      // 底数平方
        b >>= 1;     // 指数右移一位
    }
    return res;
}