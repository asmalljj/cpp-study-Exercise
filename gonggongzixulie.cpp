#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
    函数：lcs(s1, s2)
    返回字符串 s1 和 s2 的最长公共子序列（LCS）的长度

    子序列（subsequence）：
    - 可以删除一些字符，但不能改变剩下字符的相对顺序
    - 不要求连续

    例如：
    s1 = "abcde"
    s2 = "ace"
    LCS = "ace" 长度为 3
*/
int lcs(const string& s1, const string& s2){
    int m = s1.size(), n = s2.size();

    /*
        dp[i][j] 的含义：
        s1 的前 i 个字符（s1[0..i-1]）
        s2 的前 j 个字符（s2[0..j-1]）
        的最长公共子序列长度

        注意：dp 数组维度是 (m+1)*(n+1)
        dp[0][*] 和 dp[*][0] 代表有一方为空字符串，所以 LCS 必然为 0
    */
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 遍历 s1 的前 i 个字符
    for (int i = 1; i <= m; i++){
        // 遍历 s2 的前 j 个字符
        for (int j = 1; j <= n; j++){

            /*
                如果当前字符相同：
                s1[i-1] == s2[j-1]
                则 LCS 可以在 dp[i-1][j-1] 的基础上 +1
            */
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else{
                /*
                    如果当前字符不相同：
                    那么 LCS 只能来自两种情况：

                    1) 不使用 s1[i-1] 这个字符 -> dp[i-1][j]
                    2) 不使用 s2[j-1] 这个字符 -> dp[i][j-1]

                    两者取最大
                */
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // dp[m][n] 即 s1 和 s2 的最长公共子序列长度
    return dp[m][n];
}

int main(){
    /*
        T 是固定的标准字母表字符串
        目标是与输入字符串 x 求 LCS
    */
    string T = "abcdefghijklmnopqrstuvwxyz";

    int n;
    cin >> n;  // 输入测试组数

    while (n --){
        string x;
        cin >> x;

        /*
            len = x 和字母表 T 的最长公共子序列长度
            代表 x 中按顺序出现了多少个字母表中的字符

            举例：
            x = "abdfg"
            T = "abcdefghijklmnopqrstuvwxyz"
            LCS = "abdfg"
            len = 5
        */
        int len = lcs(x, T);

        /*
            字母表总长度是 26
            len 表示 x 已经能按顺序匹配到的字母数
            26 - len 就表示还缺多少个字母才能得到完整字母表子序列

            换句话说：
            最少需要添加多少字符，使得整个字母表成为 x 的一个子序列
        */
        cout << 26 - len << endl;
    }

    return 0;
}
