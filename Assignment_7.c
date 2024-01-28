#include<stdio.h>
void merge(int arr[],int lb,int mid,int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;
    int brr[100];
    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            brr[k] = arr[i];
            i++;
            k++;
        }else{
            brr[k] = arr[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            brr[k] = arr[j];
            k++;
            j++;
        }
    }else{
        while(i<=mid){
            brr[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k] = brr[k];
    }
}

void mergesort(int arr[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
int main(){
    int arr[100],i,n;
    printf("Enter the range of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("2nd largest: %d\n",arr[n-2]);
    printf("2nd smallest: %d\n",arr[1]);
}