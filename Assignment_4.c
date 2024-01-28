#include<stdio.h>

void Bitonic(int arr[],int n){
    int i,bi,count=0;
    printf("Bitonic Elements: ");
    for(i=0;i<n;i++){
       if(arr[i]>arr[i-1] && arr[i]>arr[i+1] ){
            count++;
            printf("%d ",arr[i]);
       }
    }
}

int main(){
    int n,arr[100],i;
    printf("Enter the range of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    Bitonic(arr,n);
    return 0;
}