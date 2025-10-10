#include<iostream>
using namespace std;

void hanoi(int n, char b, char d, char t, int &count) {
    if (n == 1) {
        cout << b << "-->" << d << endl;
        count++;
        return;
    }
    hanoi(n - 1, b, t, d, count);
    cout << b << "-->" << d << endl;
    count++;
    hanoi(n - 1, t, d, b, count);
}
int main() {
    int n;
    int count = 0;
    cin >> n;
    char b = 'A', d = 'C', t = 'B';
    hanoi(n, b, d, t, count);
    cout << count << endl;
    return 0;
}