#include <stdio.h>

int main()
{
int n, i;
printf("Enter number of processes: ");
scanf("%d", &n);
int at[20], bt[20];
int ct[20] = {0}, tat[20] = {0}, wt[20] = {0};
int remaining_bt[20];
int completed = 0, time = 0;
for(i = 0; i < n; i++)
{
printf("\nProcess P%d\n", i+1);
printf("Arrival Time: ");
scanf("%d", &at[i]);
printf("Burst Time: ");
scanf("%d", &bt[i]);
remaining_bt[i] = bt[i];  // Initialize remaining burst time
}
while(completed < n)
{
int max_remaining = -1;
int index = -1;


for(i = 0; i < n; i++)
{
if(at[i] <= time && remaining_bt[i] > 0)
 {
 if(remaining_bt[i] > max_remaining)
 {
 max_remaining = remaining_bt[i];
 index = i;
 }
 }
 }
if(index != -1)
{
remaining_bt[index]--;   // Execute for 1 time unit
time++;

if(remaining_bt[index] == 0)
            {
                completed++;
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        }
        else
        {
            time++;   // If no process has arrived
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i],
               ct[i], tat[i], wt[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
