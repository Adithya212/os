/* PROGRAM NAME:ROUND ROBIN CPU SCHEDULING
   AUTHOR NAME: CHRISLIN MOLLY VARGHESE
   ROLLNO: 225
*/
#include<stdio.h>  
#include<conio.h>  

void main()  
{  
    // initlialize the variable name  
    int i, n, time=0,count=0, y, time_quantum, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf("ENTER THE NUMBER OF PROCESSES: ");  
    scanf("%d", &n);  
    y = n; // copy of n  
    
    // Accept the Time qunat  
    printf("\nEnter the Time Quantum for the process:");  
    scanf("%d", &time_quantum);  
  
    // Use for loop to enter the details of the process like Arrival time and the Burst Time  
    for(i=0; i<n; i++)  
    {  
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i+1);  
        printf("Arrival time:");  // Accept arrival time  
        scanf("%d", &at[i]);  
        printf("Burst time:"); // Accept the Burst time  
        scanf("%d", &bt[i]);  
        temp[i] = bt[i]; // store the burst time in temp array  
    }  

    // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\nPROCESS NO\t\tBURST TIME\t\t\tTAT\t\t\tWAITING TIME");  
    for(time=0, i = 0; y!=0; )  
    {  
        if(temp[i] <= time_quantum && temp[i] > 0) // define the conditions   
        {  
            time = time + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - time_quantum;  
            time = time + time_quantum;    
        }  
        if(temp[i]==0 && count==1)  
        {  
            y--; //decrement the process no.  
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], time-at[i], time-at[i]-bt[i]);  
            tat+=time-at[i];  
            wt += tat-bt[i];  
            count =0;     
        }       
        if(at[i+1]<=time) // If the arrival time of next proc is less than current time 
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    // represents the average waiting time and Turn Around time  
    avg_wt = wt * 1.0/n;  
    avg_tat = tat * 1.0/n;  
    printf("\n\nAverage Turn Around Time: \t%f", avg_wt);  
    printf("\nAverage Waiting Time: \t%f", avg_tat);  
    getch();  
}  
