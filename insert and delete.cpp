
#include <stdio.h>

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, value;

    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;

    printf("Array after insertion:");
    for (i = 0; i < n; i++) {
    	printf("enter the position to delete:");
    	scanf("%d",&pos);
    	for(i=pos;i<n-1;n++){
    		n--;
    		
		}

    printf("Array after deletion:");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

