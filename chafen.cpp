#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<int> nEw(n + 1); 
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for ( int i = 0; i < m; i++){
        int l, r, c;
        cin >> l >> r >> c;
        for ( int j = l; j <= r; j ++){
            nEw[j] += c;
        }
    }
    for(int i = 1; i <= n; i++){
        arr[i] += nEw[i];
        cout << arr[i] << " ";
    }
    
}