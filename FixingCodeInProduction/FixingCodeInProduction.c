#include <stdio.h>
#include <stdlib.h>

// Binary Search Used here in this problem. Because Binary Search deals efficiently with sorted arrays.
int FixingCodeInProduction(int arr[], int size, int element) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int middle = start + (end - start) / 2;
        if (arr[middle] == element)
            return middle;
        if (arr[middle] < element)
            start = middle + 1;
        else
            end = middle - 1;
    }
    
    return -1;  // Element not found
}

int main(void) {
    int element, size;

    FILE *file = fopen("TestCase_01.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the element to find
    fscanf(file, "%d", &element);

    // Read the size of the array
    fscanf(file, "%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read the array elements
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d,", &arr[i]) != 1) {
            printf("Error reading element %d from file.\n", i + 1);
            fclose(file);
            free(arr);
            return 1;
        }
    }

    fclose(file);

    int found = FixingCodeInProduction(arr, size, element);
    printf("%d\n", found);

    free(arr);

    return 0;
}
