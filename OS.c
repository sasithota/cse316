#include<stdio.h>

int main(){
  int timeQuantum,n,bt[10],at[10],t[10],pl[10],b[10];
  printf("\nEnter Number of processes: ");
  scanf("%d",&n);
  printf("\nEnter Time Quantum : ");
  scanf("%d",&timeQuantum);
  for(int i=0;i<n;i++){
    printf("\nEnter Arrival time for p%d: ",i);
    scanf("%d",&at[i]);
    b[i]=at[i];
    printf("\nEnter Burst time for p%d: ",i);
    scanf("%d",&bt[i]);
    t[i]=bt[i];
  }
  int m,k,ra[10],tem;
  for(m=0;m<n-1;m++){
    for(k=m+1;k<n;k++){
        if(b[m]>b[k]){
            tem= b[m];
            b[m]=b[k];
            b[k]=tem;
        }
    }
   }
   int z=0;
   for(m=0;m<n;m++){
    for(k=0;k<n;k++){
        if(b[m]==at[k]){
            ra[z]=k;
            z++;
        }

    }
   }
   for(m=0;m<n;m++){
    printf(" %d",ra[m]);
   }

  int tp = n,time,tat,ct,wt;

  printf("\nprocess\t\tarrival\t\tburst\t\tcompletion\t\ttat\t\twt\n");
  int j=0,f=0;

  while(tp!=0){

            if(t[j]<=timeQuantum && t[j]>0){
                time = time + t[j];
                ct = time;
                t[j]=0;
                f=1;
            }
            else if(t[j]>0){
                time = time + timeQuantum;
                t[j] = t[j] - timeQuantum;

            }
            if(t[j]==0 && f==1){

                tat = ct - at[j];
                wt = tat-bt[j];
                printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",j,at[j],bt[j],ct,tat,wt);
                tp--;
                f=0;
            }

            if(j==n-1){
                j=0;
            }
            else if(at[j+1]<=time){
                    j++;
                    }
            else{
                j=0;
            }
        }
}
