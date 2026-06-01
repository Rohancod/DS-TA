#include <stdio.h>

void mergeIntervals(int intervals[][2], int n)
{
    
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (intervals[i][0] > intervals[j][0])
            {
                int temp0 = intervals[i][0], temp1 = intervals[i][1];
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                intervals[j][0] = temp0;
                intervals[j][1] = temp1;
            }
    int res[n][2], k = 0;
    res[k][0] = intervals[0][0];
    res[k][1] = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= res[k][1])//overlapping intervals
        {
            if (intervals[i][1] > res[k][1])// max at end of interval
                res[k][1] = intervals[i][1];
        }
        else // new interval
        {
            k++;
            res[k][0] = intervals[i][0];
            res[k][1] = intervals[i][1];
        }
    }
    printf("Merged intervals: ");
    for (int i = 0; i <= k; i++)
        printf("{%d,%d} ", res[i][0], res[i][1]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    int intervals[n][2];
    for (int i = 0; i < n; i++)
    {
        printf("Interval %d (start end): ", i + 1);
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }
    mergeIntervals(intervals, n);
    return 0;
}