  #include<stdio.h>
  void main()
   {
 	int n,q,i,pid[20],bt[20],wt[20],tat[20],rem_bt[20],t,p=0;
	int done;
	float ttat,twt;
	t=0,ttat=0,twt=0,wt[0]=0,tat[0]=0;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	printf("\nEnter the quantum slice:");
	scanf("%d",&q);
	for(i=0;i<n;i++)
		{	
		 printf("\nEnter the burst time of process %d :",i);
		 scanf("%d",&bt[i]);
		 rem_bt[i]=bt[i];
		 pid[i]=i;
		}
	printf("\nPID \t BT \t RT \t WT \t TAT");
	while(1)
		{
			done=1;
			for(i=0;i<n;i++)
			{   
				p++;
				if(rem_bt[i]>0)
				{
    	 			if(rem_bt[i]>q)
    	 				{	
    	 				    if(p<=n)
    	 				    {
    	 				    	wt[i]=t;
    	  						t=t+q;
    	  						tat[i]=t;
    	  						rem_bt[i]-=q;
    	  						done=0;
    	 					}
    	 					else
    	 					{
    	 					    wt[i]=wt[i]+t-tat[i];
    	 						t=t+q;
    	 						tat[i]=t;
    	 						rem_bt[i]-=q;
    	 						done=0;	
							}
						}
					else
    	 				{
    	 				    if(p<=n)
    	 				    	{
    	 				    	 wt[i]=t;
    	 				    	 t=t+rem_bt[i];
    	 				    	 tat[i]=t;
    	 				    	 rem_bt[i]=0;
    	 				    	}
    	 					else
    	 						{
    	 							wt[i]=wt[i]+t-tat[i];
    	 							t=t+rem_bt[i];
    	 							tat[i]=t;
    	 							rem_bt[i]=0;
    	 						}
    	 			    }
    	 	        printf("\n%d \t %d \t %d \t %d \t %d",pid[i],bt[i],rem_bt[i],wt[i],tat[i]);
    	 		}
    	 	}
    	 	if(done==1)
    	 	   break;	
    	}
    for(i=0;i<n;i++)
    	{	
    		ttat+=tat[i];
    		twt+=wt[i];
    	}	
    printf("\nAverage waiting time =%f",twt/n);
    printf("\nAverage turnaround time =%f",ttat/n);
   }