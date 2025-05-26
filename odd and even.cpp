#include <stdio.h>

int main() {
    int arr[] = {5,18,90,53,87,100,34};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Even numbers in the array:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\nOdd numbers in the array:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
