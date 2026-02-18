#include<stdio.h>
int main()
{
int n, i;

printf("Enter of processes:\n");
scanf("%d",&n);
int at[n], bt[n], rem_bt[n];
int ct[n], tat[n], wt[n];

for(i = 0; i < n; i = i+1)
{
printf("Enter arrival time of processes %d:\n",i+1);
scanf("%d",&at[i]);

printf("Enter burst Time of processes %d:\n",i+1);
scanf("%d",&bt[i]);

rem_bt[i] = bt[i];
ct[i] = 0;
tat[i] = 0;
wt[i] = 0;
}

int tq;
printf("Enter time quantum:\n");
scanf("%d",&tq);

int time = 0;
int completed = 0;

while(completed<n)
{
for(i = 0; i < n; i++)
{
if(at[i] <= time && rem_bt[i] > 0)
{
if(rem_bt[i] <= tq)
{
time = time+rem_bt[i];
rem_bt[i]  = 0;

ct[i] = time;
completed = completed+1;
}
else
{
time = time + tq;
rem_bt[i] = rem_bt[i] - tq;
}
}
}

int ready = 0;
for(i = 0; i < n; i=i+1)
{
if(at[i] <= time && rem_bt[i] > 0)
{
ready = 1;
}
}
if(ready == 0)
{
time = time+1;
}
}
for(i = 0; i < n; i += 1)
{
tat[i] = ct[i]- at[i];
wt[i] = tat[i] - bt[i];
}

float avg_wt = 0;
float avg_tat = 0;

printf("\nProcesses\tAT\tBT\tCT\tTAT\tWT\n");
for(i = 0; i < n; i += 1)
{
printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

avg_wt =avg_wt + wt[i];
avg_tat = avg_tat + tat[i];
}

avg_wt = avg_wt / n;
avg_tat = avg_tat / n;

printf("\nAverage Waiting Time = %.2f\n",avg_wt);
printf("\nAverage Turnaround Time = %.2f\n",avg_tat);
return 0;
}
