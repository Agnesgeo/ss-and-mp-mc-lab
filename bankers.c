#include<stdio.h>
#include<stdlib.h>

int allocation[10][10],max[10][10],need[10][10],n,m;
void readMatrix(int a[10][10])
{
  int i,j;
   for(i=0;i<n;i++)
     { printf("p[%d]:",i+1); 
     for(j=0;j<m;j++)
         {
            scanf("%d",&a[i][j]);
         }
     }
}

void display(int b[10][10])
{
printf("\t");  int i ,j;
  for (i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
        {
            printf("%d\t",b[i][j]);
        }
  printf("\n");
    }
}

void calculate()
{
  int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        need[i][j]=max[i][j]-allocation[i][j];
}

void banker()
{
  int avail[10],safeseq[10],finish[10],i,j,k,s,flag,ind=0;
  for (i=0;i<n;i++)
  {
     finish[i]=0;
  }
  for (i=0;i<m;i++)
  {
     scanf("%d",&avail[i]);
  }
  for (s=0;s<n;s++)
  {
     for (i=0;i<n;i++)
     {
        flag=0;
        if(finish[i]==0)
        {
           for (j=0;j<m;j++)
           {
              if(avail[j]<need[i][j])
               {
                   flag=1;
                   break;
               }
            }
            if(flag==0)
             {
          	 finish[i]=1;
          	 safeseq[ind]=i;
              	 ind++;
          	 for (k=0;k<n;k++)
                 {
             		avail[k]+=allocation[i][k];
                 }

            }
       }
    }
  }
  flag=0;
  for (i=0;i<n;i++)
  {
     if(finish[i]==0)
     {
       printf("deadlock");
       flag=1;
     }
   }
   printf("PROCESS\tALLOCATION\tMAX\t\tNEED\n");
   {
     for(i=0;i<n;i++)
     {
        printf("p[%d]\t",i+1);
         for(j=0;j<m;j++)
           {
             printf(" %d",allocation[i][j]);
          }
         printf("\t\t");
           for(j=0;j<m;j++)
            {
              printf(" %d",max[i][j]);
          }
           printf("\t\t");
            for(j=0;j<m;j++)
          {
            printf(" %d",need[i][j]);
          }
          
        printf("\n"); 
       }
    printf("\n");
     }
   if(flag==0)
   {
      for (i=0;i<n;i++)
      {
      printf("p%d\t",safeseq[i]+1);
      }
      printf("\n");
   }
}

int main()
{
  printf("enter the number of process:");
  scanf("%d",&n);
  printf("enter the resoucres:");
  scanf("%d",&m);
  printf("enter allocation matrix\n");
  readMatrix(allocation);
  printf("enter max matrix\n");
  readMatrix(max);
  calculate();
  printf("need matrix:\n");
  printf("enter available matrix");
  banker();
}
