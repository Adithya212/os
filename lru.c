#include <stdio.h>
int findlru(int time[],int n){
    int minimum=time[0],pos=0,i;
    for(i=1;i<n;i++){
        if (time[i]<minimum)
        {
            minimum=time[i];
            pos=i;
        }
    return pos;  
    }

}
int main(){
    int np,nf,p[20],frames[20],n,i,avail,count=0,j,k,flag1,flag2,counter=0,timer[20],pos;
    
    printf("Enter the number of pages");
    scanf("%d",&np);
    printf("Enter the page number");
    for(i=0;i<np;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the number offrames");
    scanf("%d",&nf);
    for(i=0;i<nf;i++){
        frames[i]=-1;
    }
    for(i=0;i<np;i++){
        flag1=flag2=0;
        printf("%d\t\t",p[i]);
        for(j=0;j<nf;j++){
            if (frames[j]==p[i])
            {
                counter++;
                timer[j]=counter;
                flag1=flag2=1;
                break;
            }
        }
        //initially no elements/miss
        if(flag1==0){
            for (j = 0; j <nf; j++)
            {
               if (frames[j]==-1)
               {
                count++;
                counter++;
                timer[j]=counter;
                frames[j]=p[i];
                flag2=1;
                break;
               }
               
            }
            
        }
        if (flag2==0)
        {
            pos=findlru(timer,nf);
            frames[pos]=p[i];
            count++;
            counter++;
            timer[pos]=counter;
        }
        for(j=0;j<nf;j++){
            printf("%d\t",frames[j]);
        }
        printf("\n"); 
    }
    return 0;
    }



