#include<iostream>
using namespace std;

void bubblesort(int* arr, int len){

    for (int i = 0; i < len; i++){
        int* p = arr;
        for (int j = 0; j < len - 1 - i; j++){
            if (*p > *(p + 1)){
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
            p ++;
        }
        
    }
    int *k = arr;
    for ( int i = 0; i < len; i ++){
        
        cout << *k << endl;
        k ++;
    }
}
int main(){
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, len);
    return 0;

}