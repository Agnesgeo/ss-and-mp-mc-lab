#include<stdio.h>
#include<stdlib.h>

struct process
{
   int at;
   int bt;
   int wt;
   int ct;
   int tt;
   int pid;
   int completed;
   int prio;
   int rt;
   int  st;
   int rem;
}p[20],temp;
int i,j,n,total;

void fcfs()
{
  total=0;
  float avg_wt=0,avg_tt=0;
  printf("enter the number of process:");
  scanf("%d",&n);
  printf("enter the  process details\n");
  for(i=0;i<n;i++)
  {
     p[i].pid=i+1;
     printf("Process[%d]:\n",i+1); 
     printf("arrival time,burst time:"); 
     scanf("%d%d",&p[i].at,&p[i].bt);
     printf("\n");
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].at>p[j+1].at)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }
 for(i=0;i<n;i++)
 {
    while(total<p[i].at)
    {
      total++;
    }
    p[i].ct=total+p[i].bt;
   total=p[i].ct;
   p[i].tt=p[i].ct-p[i].at;
   p[i].wt=p[i].tt-p[i].bt;
 }
printf(" PROCESS\tARRIVAL\t\tBURST\tWAITING TIME\tTURN AROUND\n");
for(i=0;i<n;i++)
{
  printf("p[%d]\t  \t%d\t\t%d\t\t%d\t    %d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
  avg_tt+=p[i].tt;
  avg_wt+=p[i].wt;
}
 printf("average waiting time=%f\n",avg_wt/n);
 printf("average turn around time=%f\n",avg_tt/n);
}
void sjf()
{
  total=0;
 p[i].completed=0;
     p[i].rem=p[i].bt;
  int currenttime=0,completed=0,totalburst;
  float avg_wt=0,avg_tt=0;
  printf("enter the number of process:");
  scanf("%d",&n);
  printf("enter the  process details\n");
  for(i=0;i<n;i++)
  {
     p[i].pid=i+1;
     printf("Process[%d]:\n",i+1);
     printf("enter arrival time,burst time:"); 
     scanf("%d%d",&p[i].at,&p[i].bt);
     printf("\n");
     p[i].completed=0;
  }
  for(i=0;i<n;i++)
  {
     totalburst+=p[i].bt;
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].at>p[j+1].at)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }
 for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].at==p[j+1].at && p[j].bt>p[j+1].bt)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }
/*for(i=0;i<n;i++)
{
  p[i].completed=0;
}*/
 while(completed!=n)
 {
      int min_index= -1;
      int minimum=totalburst;
      for(i=0;i<n;i++)
      {
         if(p[i].at<=currenttime && p[i].completed==0)
          {
            if(p[i].bt< minimum)
            {
              minimum=p[i].bt;
              min_index=i;
            }
            if(p[i].bt==minimum)
            {
                if(p[i].at< p[min_index].at)
               {
                  minimum=p[i].bt;
                  min_index=i;
               }
             }
          }
      }
 
      if(min_index==-1)
      {
         currenttime++;
      }
      else
     {
        p[min_index].st=currenttime;
        p[min_index].ct=p[min_index].st+p[min_index].bt;
        p[min_index].tt=p[min_index].ct-p[min_index].at; 
        p[min_index].wt=p[min_index].tt-p[min_index].bt;
        p[min_index].completed=1;
        currenttime=p[min_index].ct;
       completed++;
     }
}
  printf(" PROCESS\tARRIVAL\t\tBURST\tWAITING TIME\tTURN AROUND\n");
  for(i=0;i<n;i++)
  {
   printf("p[%d]\t  \t%d\t\t%d\t\t%d\t    %d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
   avg_tt+=p[i].tt;
   avg_wt+=p[i].wt;
   }
   printf("average waiting time=%f",avg_wt/n);
   printf("average turn around time=%f",avg_tt/n);

}
void priority()
{
  total=0;
  int currenttime=0,completed=0;
  float avg_wt=0,avg_tt=0;
  printf("enter the number of process:");
  scanf("%d",&n);
  printf("enter the  process details\n");
  for(i=0;i<n;i++)
  {
    p[i].pid=i+1;
     printf("Process[%d]:\n",i+1);
     printf("enter arrival time,burst time :"); 
     scanf("%d%d",&p[i].at,&p[i].bt);
     printf("\nenter priority:");
     scanf("%d",&p[i].prio);
     printf("\n");
     p[i].completed=0;
     p[i].rt=p[i].bt;
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].at>p[j+1].at)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }  
 for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].at==p[j+1].at && p[j].bt>p[j+1].bt)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].prio>p[j+1].prio)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }

 while(completed!=n)
 {
      int max_priority=1000;
      int min_index=-1;
      for(i=0;i<n;i++)
      {
         if(p[i].at<=currenttime && p[i].completed==0)
          {
            if(p[i].prio< max_priority)
            {
                max_priority=p[i].prio;
                min_index=i;
            }
         }
      }
      if(min_index==-1)
      {
         currenttime++;
      }
      else
     {
        p[min_index].st=currenttime;
        p[min_index].ct=p[min_index].st+p[min_index].bt;
        p[min_index].tt=p[min_index].ct-p[min_index].at; 
        p[min_index].wt=p[min_index].tt-p[min_index].bt;
        p[min_index].completed=1;
        currenttime=p[min_index].ct;
       completed++;
     }
}
  printf(" PROCESS\tARRIVAL\t\tBURST\tPRIORITY\tWAITING TIME\t\tTURN AROUND\n");
  for(i=0;i<n;i++)
  {
   printf("p[%d]\t  \t%d\t\t%d\t\t%d\t%d\t    %d\n",p[i].pid,p[i].at,p[i].bt,p[i].prio,p[i].wt,p[i].tt);
   avg_tt+=p[i].tt;
   avg_wt+=p[i].wt;
   }
   printf("average waiting time=%f",avg_wt/n);
   printf("average turn around time=%f",avg_tt/n);


}

void rr()
{
  total=0;
  int slice,i,j=0,time,remain,flag;
  float avg_wt=0,avg_tt=0;
  printf("enter the number of process:");
  scanf("%d",&n);
  printf("enter the  process details\n");
  for(i=0;i<n;i++)
  {
    p[i].pid=i+1;
     printf("Process[%d]:\n",i+1);
     printf("enter arrival time,burst time :"); 
     scanf("%d%d",&p[i].at,&p[i].bt);
     printf("\n");
  }
 printf("enter time slice");
 scanf("%d",&slice);
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
     {
        if(p[j].at>p[j+1].at)
       {
         temp=p[j];
         p[j]=p[j+1];
         p[j+1]=temp;
       }
     }
  }
  for(i=0;i<n;i++)
  {
 p[i].completed=0;
     p[i].rem=p[i].bt;
}
  remain=n;
  int ready[30],count=0;
   printf(" PROCESS\tARRIVAL\t\tBURST\tWAITING TIME\tTURN AROUND\n");
for(time=0,i=0;remain!=0;)
{
  if(p[i].rem<=slice &&p[i].rem>0)
  {
     time+=p[i].rem;
     p[i].rem=0;
    flag=1;
  }
  else if(p[i].rem>0)
  {
     p[i].rem=p[i].rem-slice;
    time=time+slice;
  }
  if(p[i].rem==0 && flag==1)
  {
    remain--;
    printf("p[%d]\t  \t%d\t\t%d\t\t%d\t    %d\n",p[i].pid,p[i].at,p[i].bt,(time-p[i].at-p[i].bt),(time-p[i].at));
    avg_tt+=time-p[i].at;
    avg_wt+=time-p[i].bt-p[i].at;
    flag=0;
  }
 int m=0;
for(j=0;j<n;j++)
{
  if(p[j].at<=time && p[j].rem!=0)
   {
      ready[m++]=j;
   }
}
 if(m>0)
 { 
     count=(count+1)%m;
     i=ready[count];
  }
else
 {
    time++;
 }
}
   printf("average waiting time=%f\n",((avg_wt/n)));
   printf("average turn around time=%f",((avg_tt/n)));


}
void main()
{
  int choice;
  while(1)
  {
     printf(" \n-------MENU------\n 1.FCFS\n 2.SJF\n 3.PRIORITTY\n 4.ROUND ROBIN");
     printf("\n enter choice");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1 : fcfs();
              break;
         case 2 : sjf();
              break;
        case 3 : priority();
              break;
         case 4 : rr();
              break;
        case 0 : exit(0);
        default: printf("enter valid number");
     }
   }
}
