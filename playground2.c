#include <stdio.h>
#include <stdlib.h>

int arr2num (int arr[3]) {
    int num = 0;
    for (int i = 0; i < 3; i++) {
        num = num * 10 + arr[i];
    }
    return num;
}

int main() {
    int arr[3] = {2, 2, 3};
    int num = arr2num(arr);
    printf("%d\n", num);
}