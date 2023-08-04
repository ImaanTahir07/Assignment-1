#include <stdio.h>
#include <stdlib.h>

// Bubble Sort to sort the array
void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate median
int SelectingTheMedian(int arr[], int size) {
    BubbleSort(arr, size);

    return arr[size / 2]; //middle element of the array is the median
}

int main() {
    int size;

    FILE *file = fopen("TestCase_01.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    // Read the number of elements from the file

    fscanf(file, "%d", &size);

    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }


    // Read the array elements from the file
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d,", &arr[i]) != 1) {
            printf("Error reading element %d from file.\n", i + 1);
            fclose(file);
            free(arr);
            return 1;
        }
    }
    // Close the input file
    fclose(file);

    // Calculate and print the median using Bubble Sort
    int median = SelectingTheMedian(arr, size);
    printf("Median: %d\n", median);
 // Free the allocated memory
    free(arr);

    return 0;
}
