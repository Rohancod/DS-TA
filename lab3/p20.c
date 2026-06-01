#include <stdio.h>

int main()
{
    int n = 0;
    printf("enter size of array ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter element number %d ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("duplicate number is present");
                break;
            }
        }
    }
    return 0;
}