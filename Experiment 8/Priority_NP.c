#include <stdio.h>
int main()
{
int n,i;
printf("Enter number of processes: ");
scanf("%d",&n);
int at[20], bt[20],pr[20];
int ct[20],tat[20],wt[20];
int done[20] = {0};
for (i = 0;i < n;i++)
{
printf("\nProcess P%d\n",i+1);

printf("Arrival Time: ");
scanf("%d", &at[i]);
printf("Burst Time:");
scanf("%d",&bt[i]);

printf("Priority (Higher number = Higher priority):");
scanf("%d",&pr[i]);
}
int time = 0, completed = 0;
while(completed < n)
{
int max_priority = -1;
int index = -1;

for(i = 0; i < n; i++)
{
if(at[i] <= time && done[i] == 0)
{
if(pr[i] > max_priority)
{
max_priority = pr[i];
index = i;
}
}
}
if(index != -1)
{
time = time + bt[index];
ct[index] = time;
tat[index] = ct[index] - at[index];
wt[index] = tat[index] - bt[index];
done[index] = 1;
completed++;
}
else
{
time++; //CPU Idle
}
}
float avg_wt=0,avg_tat = 0;
printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
for(i = 0;i < n;i++)
{
printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
avg_wt += wt[i];
avg_tat += tat[i];
}
printf("\nAverage Waiting Time = %.2f",avg_wt/n);
printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);
return 0;
}
