#include <stdio.h>
void input(int arr[], int n);
// Function prototype
void binary_search(int arr[], int n);

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);
    binary_search(arr, n);
    return 0;
}

void input(int arr[], int n)
{

    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// binary search function
void binary_search(int arr[], int n)
{
    int low = 0, high = n - 1, found = 0,key;
    printf("Enter an element to search: ");
    scanf("%d", &key);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
        {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == 0)
        printf("Element not found!");
}