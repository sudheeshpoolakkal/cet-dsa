#include<stdio.h>
void insert(int arr[], int n);
void display(int arr[], int n);
void bubble_sort(int arr[], int n);
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    insert(arr,n);
    
    printf("Original array: ");
    display(arr,n);

    printf("Sorted array: ");
    bubble_sort(arr,n);
    return 0;
}

void insert(int arr[], int n){
    printf("Enter the elements for the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int swapped = 0;
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}