
#include <stdio.h>
#define MAX_SIZE 50

void bubblesort(int arr[],int arr2[],int arr3[],int arr4[],int size);
void swap(int *a,int *b);
int main(){
    int n,time=0;
    float avgwt=0,avgtat=0;
    int PRIORITY[MAX_SIZE];
    int AT[MAX_SIZE],BT[MAX_SIZE],CT[MAX_SIZE],WT[MAX_SIZE],TAT[MAX_SIZE];
    int P[MAX_SIZE];
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    printf("\nEnter the Arrival Time ,Burst Time and Priority for the following processes\n");
 
    for(int i =0; i<n; i++){
        printf("\np[%d]",i+1);
        printf("\nArrival Time:");
        scanf("%d",&AT[i]);
        printf("Burst Time:");
        scanf("%d",&BT[i]);
        printf("Priority:");
        scanf("%d",&PRIORITY[i]);
        P[i] = i+1;
    }
    bubblesort(PRIORITY,BT,P,AT,n);
    time = AT[0]; // initial time 
    for(int i =0;i<n;i++){
        time += BT[i]; // increasing the Time

        CT[i] = time;   
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i]-BT[i];

        avgtat+=TAT[i];
        avgwt+=WT[i];
    }
    avgtat /= n;
    avgwt /= n;

    printf("\nProcess\tPriority\tArrival Time\tBurst Time\tCompletion\tTurnAround\tWaiting\n");
    for(int i=0;i<n;i++){
        printf("P[%d]\t",P[i]);
        printf("%d\t",PRIORITY[i]);
        printf("\t%d\t",AT[i]);
        printf("\t%d\t",BT[i]);
        printf("\t%d\t",CT[i]);
        printf("\t%d\t",TAT[i]);
        printf("\t%d\t\n",WT[i]);


    }
    printf("\nAverage TurnAroundTime : %f",avgtat);
    printf("\nAverage WaitingTime : %f",avgwt);

    return 0;
}
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[],int arr2[],int arr3[],int arr4[],int size){
    for (int i = 0; i < size-1; i++){
        int temp = 0;
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){ 
                swap(&arr[j],&arr[j+1]);
                swap(&arr2[j],&arr2[j+1]);
                swap(&arr3[j],&arr3[j+1]);
                swap(&arr4[j],&arr4[j+1]);
            }
        }
    }
}