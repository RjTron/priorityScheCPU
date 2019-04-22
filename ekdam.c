#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int bt[20],at[10],n,i,j,temp,p[10],st[10],ct[10],wt[10],tat[10];
    int totalwt=0,totaltat=0;
    float avgwt,avgtat;
    char pn[10][10],t[10];

    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("Enter process%d:",i+1);
    
        scanf("%s",pn[i]);
        }
    printf("\n");
        for(i=0; i<n; i++)
        {
      printf("enter the arrivaltime, burst time & priority:");
		scanf("%d%d%d",&at[i],&bt[i],&p[i]);
		}
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ct[i]=st[i]+bt[i];
            tat[i]=ct[i]-at[i];
        }
        else
        {
            st[i]=ct[i-1];
            wt[i]=st[i]-at[i];
            ct[i]=st[i]+bt[i];
            tat[i]=ct[i]-at[i];
        }
        totalwt+=wt[i];
        totaltat+=tat[i];
    }
    avgwt=(float)totalwt/n;
    avgtat=(float)totaltat/n;
    printf("\nPname\t arrivaltime\t burst time\t priority\t waitingtime\t turn around time");
    for(i=0; i<n; i++)
    printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],bt[i],p[i],wt[i],tat[i]);
    printf("\n");
    printf("\n Average waiting time is:%f",avgwt);
    printf("\n");
    printf("\n Average turn aroundtime is:%f",avgtat);
    getch();
}
