#include<stdio.h>
#include<stdlib.h>
void main()
{
 	int i,n,bt[20],st[20],et[20];
 	float wt=0,tat=0;
 	st[0]=0,et[0]=0;
 	printf("Enter the number of processes:");
 	scanf("%d",&n);
	printf("\n Enter the burst time of processes:");
 	for(i=0;i<n;i++)
  		{
   			printf("\n Enter the burst time of process %d=",i);
   			scanf("%d",&bt[i]);
   			et[i]=st[i]+bt[i];
   			st[i+1]=et[i];
   		}
	printf("\n PID \t BT \t ST \t ET");
	for(i=0;i<n;i++)
		{
			printf("\n %d \t %d \t %d \t %d",i,bt[i],st[i],et[i]); 
		}
	 for(i=0;i<n;i++)
 		{
            wt=wt+st[i];
  			tat=tat+et[i];
 		}
 	printf("\n Average waiting time=%f",wt/n);
 	printf("\n Average turnaround time=%f",tat/n);
 }

