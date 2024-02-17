#include<stdio.h>

int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb + 1;
    int end = ub ;
    while(1){
        while(arr[start]<pivot && start<=end){
            start++;
        }
        while(arr[end]>=pivot && start<=end){
            end --;
        }
        if(start>end){
            break;
        }
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }

    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

int median(int arr[],int n){
    int lb = 0;
    int ub = n-1;
    int mid = n/2;
    while(lb<ub){
        int pivot = partition(arr,lb,ub);
        if(pivot==mid){
            return pivot;
        }else if(pivot<mid){
            lb = pivot+1;
        }else{
            ub = pivot-1;
        }
    }
    return mid;
}

int main(){
    int n;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    int med = median(arr,n);
    printf(" Median: %d\n",med);
    if(n%2==0){
        printf("Left neighbour: %d\n",arr[med-1]);
        printf("Right neighbour: %d\n",arr[med]);
    }else{
        printf("Left neighbour: %d\n",arr[med-1]);
        printf("Right neighbour: %d\n",arr[med+1]);
    }
    return 0;
}