#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T, c, n;
    
    // 读取测试组数
    cin >> T;
    
    for (int i = 0; i < T; i++){
        // 读取载货重量和古董个数
        cin >> c >> n;
        
        // 定义数组存储古董重量
        int weights[n];
        
        // 读取每个古董的重量
        for (int j = 0; j < n; j++){
            cin >> weights[j];
        }
        
        // 使用STL排序（升序）
        sort(weights, weights + n);

        // 贪心算法：优先选择重量轻的古董
        int totalWeight = 0, count = 0;
        for (int k = 0; k < n; k++){
            if (totalWeight + weights[k] <= c){
                totalWeight += weights[k];
                count++;
            }
            else{
                break;
            }
        }
        
        // 输出结果
        cout << count << endl;
    }
    
    return 0;
}