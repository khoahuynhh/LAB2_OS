#include <stdio.h>
#include <pthread.h>

#define SIZE 10

int arr[SIZE] = {5, 12, 43, 2, 8, 99, 32, 1, 55, 17};
int max1, max2;

void *findMaxPart(void *arg)
{
    int start = *(int *)arg;
    int end = start + (SIZE / 2);
    int max = arr[start];

    for (int i = start + 1; i < end; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    if (start == 0)
    {
        max1 = max;
    }
    else
    {
        max2 = max;
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int start1 = 0;
    int start2 = SIZE / 2;

    pthread_create(&thread1, NULL, findMaxPart, &start1);
    pthread_create(&thread2, NULL, findMaxPart, &start2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int final_max = (max1 > max2) ? max1 : max2;
    printf("Largest element (multithread): %d\n", final_max);

    return 0;
}
