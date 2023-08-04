

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the highest consecutive extended working hours
int GoingOffTheCharts(int arr[], int size) {
    int maxConsecutive = 0;       // To store the highest consecutive extended working hours
    int currentConsecutive = 0;   // To track the current consecutive extended working hours

    for (int i = 0; i < size; i++) {
        if (arr[i] > 6) {  // Check if the working hours are extended than 6
            currentConsecutive++;  // Increment the current consecutive count
            if (currentConsecutive > maxConsecutive) {
                maxConsecutive = currentConsecutive;  // Update the highest consecutive count
            }
        } else {
            currentConsecutive = 0;  // Reset the current consecutive count if regular hours
        }
    }

    return maxConsecutive;
}

int main(void) {
    int size;

    // Open the input file
    FILE *file = fopen("TestCase_02.txt", "r");
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

    // Calculate and print the highest consecutive extended working hours
    int maxConsecutive = GoingOffTheCharts(arr, size);
    printf("Highest consecutive extended working hours: %d\n", maxConsecutive);

    // Free the allocated memory
    free(arr);

    return 0;
}
