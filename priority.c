  #include<stdio.h>
  void main()
   {
  	int n,i,j,bt[20],pid[20],p[20],temp1,temp2,temp3,t=0,wt[20],tat[20];
  	float ttat=0,twt=0;
  	printf("\nEnter the number of processes:");
  	scanf("%d",&n);
  	printf("\nEnter the burst time and priority of processes");
  	for(i=0;i<n;i++)
  		{	
  		 printf("\nBurst time of process %d ? :",i);
  		 scanf("%d",&bt[i]);
  		 printf("\nPriority of process %d ? :",i);
  		 scanf("%d",&p[i]);
  		 pid[i]=i;
  		}
    for(i=0;i<n-1;i++)
    	{	
    	 for(j=i+1;j<n;j++)
    	 	{	
    	 		if(p[i]>p[j])
    	 			{	
    	 			 temp1=bt[i];
    	 			 temp2=pid[i];
    	 			 temp3=p[i];
    	 			 bt[i]=bt[j];
    	 			 pid[i]=pid[j];
    	 			 p[i]=p[j];
    	 			 bt[j]=temp1;
    	 			 pid[j]=temp2;
    	 			 p[j]=temp3;
    	 			}
    	 	}
    	}
    for(i=0;i<n;i++)
    	{
    	 wt[i]=t;	
    	 t=t+bt[i];
    	 tat[i]=t;
    	 ttat+=tat[i];
    	 twt+=wt[i];
    	}
    printf("\n PID \t BT \t WT \t TAT");
    for(i=0;i<n;i++)
    	{	
    	 printf("\n %d \t %d \t %d \t %d",pid[i],bt[i],wt[i],tat[i]);
    	}
    printf("\nAverage waiting time =%f",twt/n);
    printf("\nAverage turnaround time =%f",ttat/n);
   }


