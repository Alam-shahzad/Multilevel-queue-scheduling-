#include<stdio.h>
#include<conio.h>

int main() 
{ 
      int i, li, ct=0,x,count=0,time_q,j,wt=0,tt=0,pos,z,p[10],prio[10],at[10],bt[10],temp[10],b; 
	  printf("\nEnter total number of process:"); 
	   scanf("%d", &li); 
       x = li; 
       for(i=0;i<li;i++) 
       {
	     p[i]=i+1;
	     prio[i]=0;
            printf("\nEnter total the arival time and burst time[%d]\n", i + 1);
            printf("Arrival time:\t");
            scanf("%d",&at[i]);
            printf("Burst time:\t");
            scanf("%d",&bt[i]); 
            temp[i]=bt[i];
       }   
      printf("\nEnter the time quantum:"); 
      scanf("%d",&time_q); 
      printf("\nProcess ID\t Burst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(ct=0,i=0;x!=0;)   
      { 

		    for(z=0;z<li;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<li;j++)
			{
			    if(prio[j]<prio[pos])
				pos=j;	
			}		 
		temp1=prio[z];
		prio[z]=prio[pos];
		prio[pos]=temp1;

			temp1=bt[z];
			bt[z]=bt[pos];
			bt[pos]=temp1;
		 			temp1=at[z];
				at[z]=at[pos];
			at[pos]=
			temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		
			if(temp[i]<=time_q&&temp[i]>0) 
            { 
                  ct=ct+temp[i]; 
                  temp[i]=0; 
                  count=1; 
            } 
            
			else if(temp[i]>0) 
            { 
                  temp[i]=temp[i]-time_q; 
                  ct=ct+time_q; 
            } 

	for(b=0;b<li;b++)
		{
			if(b==i)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[i] == 0 && count == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i],bt[i],ct-at[i],ct-at[i]-bt[i],prio[i]);
                  wt=wt+ct-at[i]-bt[i]; 
                  tt=tt+ct-at[i]; 
                  count= 0; 
            } 
            if(i==li-1) 
            {
                  i=0; 
			}
            else if(at[i + 1] <=ct) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}
