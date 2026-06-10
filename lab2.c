#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = A[high];
        int i = low - 1;
        int j;

        for (j = low; j < high; j++) {
            if (A[j] < pivot) {
                i++;
                swap(&A[i], &A[j]);
            }
        }

        swap(&A[i + 1], &A[high]);
        int pi = i + 1;

        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    for(i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    printf("Generated array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    clock_t start, end;
    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime Taken: %f seconds\n", time_taken);

    return 0;
}
