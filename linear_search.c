// with function
#include <stdio.h>
#include <time.h>
void insert(int arr[], int n);
void linear_search(int arr[], int n);

int main()
{   
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    insert(arr,n);
    linear_search(arr,n);
    return 0;
}

void insert(int arr[], int n)
{
    int i;
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void linear_search(int arr[], int n)
{
    int i, found = 0, key;
    printf("Enter an element to search: ");
    scanf("%d", &key);
    printf("Element found at positions: ");
    for (i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            found++;
            printf("%d ", i + 1);
        }
    }
    if (found == 0)
    {
        printf("Element is not found in the array!\n");
    }
    else
    {
        printf("\nElement found %d times.\n", found);
    }
    
}