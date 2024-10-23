#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 10

int arr[SIZE] = {5, 12, 43, 2, 8, 99, 32, 1, 55, 17};

int main()
{
    int max1 = arr[0], max2 = arr[SIZE / 2];
    pid_t pid = fork();

    if (pid == 0)
    { // Process con
        for (int i = 1; i < SIZE / 2; i++)
        {
            if (arr[i] > max1)
            {
                max1 = arr[i];
            }
        }
        printf("Max from child process: %d\n", max1);
    }
    else
    {               // Process cha
        wait(NULL); // Đợi process con kết thúc
        for (int i = SIZE / 2 + 1; i < SIZE; i++)
        {
            if (arr[i] > max2)
            {
                max2 = arr[i];
            }
        }
        printf("Max from parent process: %d\n", max2);

        int final_max = (max1 > max2) ? max1 : max2;
        printf("Largest element (multiprocess): %d\n", final_max);
    }

    return 0;
}
