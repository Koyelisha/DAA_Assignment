#include<stdio.h>

int main(){
    int arr[100],i,X,j,n;
    printf("Enter the range of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element for arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the sum: ");
    scanf("%d",&X);
    i = 0; //Lower bound
    j = n-1; //upper bound
    while(i<j){
        if(arr[i]+arr[j]==X){
            printf("Numbers: %d %d\n",arr[i],arr[j]);
            i++;
            j--;
        }else{
            i++;
        }
    }
    return 0;
}