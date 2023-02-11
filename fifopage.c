#include <stdio.h>
int main(){
    int np,nf,p[20],frames[20],n,i,avail,count=0,j,k;
    
    printf("Enter the number of pages");
    scanf("%d",&np);
    printf("Enter the page number");
    for(i=1;i<=np;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the number offrames");
    scanf("%d",&nf);
    for(i=0;i<nf;i++){
        frames[i]=-1;
    }
    //algo
    k=0;
    for(i=1;i<=np;i++){
        avail=0;
        printf("%d\t\t",p[i]);
        for(j=0;j<nf;j++){
            if(frames[i]==p[i])
                avail=1;
        }        
        if(avail==0){
            frames[k]=p[i];
            k=(k+1)%nf;
            count++;
        for(j=0;j<nf;j++){
            printf("%d\t",frames[j]);
        }
            
        
        }
        printf("\n");
    }
    return 0;

    }
    
    

