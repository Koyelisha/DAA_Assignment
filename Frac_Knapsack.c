#include<stdio.h>

void knapsack(int n,float profit[100],float weight[100],float capacity){
    float pt=0,x[100];
    int u = capacity;
    int i,j;
    for(i=0;i<n;i++){
        x[i] = 0.0;
    }
    for(i=0;i<n;i++){
        if(weight[i]>u){
            break;
        }else{
            x[i] = 1.0;
            u = u - weight[i];
            pt = pt + profit[i];
        }
    }
    if(i<n){
        x[i] = u/weight[i];
        pt = pt + (profit[i]*x[i]);
    }
    printf("The result vector:-\n");
    for(i=0;i<n;i++){
        printf(" %.2f ",x[i]);
    }
    printf("\nMaximum profit obtained: %.2f",pt);
}

int main(){
    float profit[100],weight[100],ratio[100],capacity;
    int i,j,temp;
    int n; //no of items
    printf("Enter the no of objects: ");
    scanf("%d",&n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%f",&capacity);
    for(i=0;i<n;i++){
        printf("Enter profit and weight respectively: ");
        scanf("%f %f",&profit[i],&weight[i]);
        ratio[i] = profit[i]/weight[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                //sorting the ratios
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                //sorting the profits
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                //sorting the weights
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

            }
        }
    }
    knapsack(n,profit,weight,capacity);
    
    return 0;
}


