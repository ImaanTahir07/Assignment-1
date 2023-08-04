
// I use Insertion Sort Algorithm in this problem to sort the queue because it handles datasets which is suitable for arranging queue positions based on bribes.

#include <stdio.h>
#include <stdlib.h>

// Define the maximum size for an array to enhance code readability.
// Any usage of MAX_SIZE will be replaced with the value 100 during preprocessing.
#define MAX_SIZE 100

// Insertion Sort
int BribedQueue(int arr[], int size)
{
    int bribe = 0;
    for (int i = 1; i < size; i++)
    {
        int hold = arr[i];
        int j = i - 1;

        while (hold < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
            bribe++;  // Increment the bribe count for each shift
        }
        arr[j + 1] = hold;  // Return the total number of bribes made during sorting
    }
    return bribe;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    FILE *file = fopen("TestCase_02.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the size of the array from the first line of the file
    if (fscanf(file, "%d", &size) != 1) {
        printf("Error reading array size from file.\n");
        fclose(file);
        return 1;
    }

    // Check if the size is within the valid range
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size: %d\n", size);
        fclose(file);
        return 1;
    }

    // Read the array elements from the second line of the file
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d,", &arr[i]) != 1) {
            printf("Error reading element %d from file.\n", i + 1);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    int bribe=BribedQueue(arr, size);
    printf ("%d" ,bribe);
    return 0;
}
