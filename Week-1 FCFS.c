#include<stdio.h>
int n,i,j,pos,temp,choice,Burst_time[20],Waiting_time[20],Turn_around_time[20],process[20],total=0;
float avg_Turn_around_time=0;
avg_Waiting_time=0;
int FCFS(){
  Waiting_time[0]=0;
  for(i=1;i<n;i++){
    Waiting_time[i]=0;
    for(j=0;j<i;j++){
       Waiting_time[i]+=Burst_time[j];
    }
    printf("\n process\tBurst time\tWaiting time\tTurn around time");
    for(i=0;i<n;i++){
        Turn_around_time[i]=Burst_time[i]+Waiting_time[i];
        avg_Waiting_time+=Waiting_time[i];
        avg_Turn_around_time+=Turn_around_time[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,Burst_time[i],Waiting_time[i],Turn_around_time[i]);
    }
    avg_Waiting_time=(float)(avg_Waiting_time)/(float)i;
    avg_Turn_around_time=(float)(avg_Turn_around_time)/(float)i;
    printf("\n Average Waiting Time :%2f",avg_Waiting_time);
    printf("\n Average Turn around Time:%2f\n",avg_Turn_around_time);
    return 0;
  }
}
void main(){
  printf("Enter the total no of processes:");
  scanf("%d",&n);

  printf("Enter Burst Time:\n");
  for(int i=0;i<n;i++){
    printf("P[%d]:",i+1);
    scanf("%d",&Burst_time[i]);
    process[i]=i+1;
  }
  FCFS();
}


//OUTPUT
Enter the total number of processes: 3
Enter Brust Time:
P[1]: 2
P[2]: 3
P[3]: 4

Process Burst Time Waiting Time Turn Around Time
P[1] 2 0 2
P[2] 3 2 5
P[3] 4 5 9

Avg. Waiting time: 2.33
Avg. Turn Around Time: 5.33


