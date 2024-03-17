#include<stdio.h>

int main(){
    int deadlines[100],profits[100],jobID[100],n,x[100],i,j,temp,tp=0;
    printf("Enter the no of jobs: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        x[i] = 0;
    }
    for(i=0;i<n;i++){
        printf("Enter Job ID,deadline and profit respectively: ");
        scanf("%d%d%d",&jobID[i],&deadlines[i],&profits[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(profits[i]<profits[j]){
                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;

                temp = deadlines[i];
                deadlines[i] = deadlines[j];
                deadlines[j] = temp;

                temp = jobID[i];
                jobID[i] = jobID[j];
                jobID[j] = temp;
            }
        }
    }
    printf("After sorting as per the profit\n");
    for(i=0;i<n;i++){
        printf("%d %d %d\n",jobID[i],deadlines[i],profits[i]);
    }

    for(i=0;i<n;i++){
        int k = deadlines[i] - 1;
        for(j = k;j>=0;j--){
            if(x[j]==0){
                x[j] = jobID[i];
                tp = tp + profits[i];
                break;
            }else if(j<0 && x[j]!=0){
                break;
            }else{
                continue;
            }
        }
    }
    printf("Maximum profit sequence of jobs:-\n");
    for(i=0;i<n;i++){
        if(x[i]==0){
            break;
        }else{
        printf(" %d ",x[i]);
        }
    }
    printf("\nTotal Profit: %d\n",tp);


    return 0;
}

