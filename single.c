#include <stdio.h>

#define SIZE 10

int main()
{
    int arr[SIZE] = {5, 12, 43, 2, 8, 99, 32, 1, 55, 17};
    int max = arr[0];

    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Largest number: %d\n", max);

    return 0;
}
