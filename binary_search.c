#include <stdio.h>
#include <time.h>

// Function prototype
void binary_search(int arr[], int n, int key);

int main()
{   
    int n, i, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in sorted order: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter an element to search: ");
    scanf("%d", &key);

    // ⏱️ Start timing
    clock_t start = clock();

    binary_search(arr, n, key);

    // ⏱️ End timing
    clock_t end = clock();

    // ⏱️ Calculate and display time
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_spent);

    return 0;
}

// binary search function
void binary_search(int arr[], int n, int key)
{
    int low = 0, high = n - 1, found = 0;

    while(low <= high){
        int mid = (low + high) / 2;
        if(key == arr[mid])
        {
            printf("Element found at position %d", mid + 1);
            found = 1;
            break;
        }
        else if(key < arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    if(found == 0)
        printf("Element not found!");
}
