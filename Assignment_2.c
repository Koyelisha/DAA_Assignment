#include<stdio.h>

int Binary_Search(int arr[],int lb,int ub,int k){
    int mid = (lb+ub)/2;
    if(arr[mid]==k){
        return mid+1;
    }else if(arr[mid]>k){
        return Binary_Search(arr,lb,mid-1,k);
    }else if(arr[mid]<k){
        return Binary_Search(arr,mid+1,ub,k);
    }else{
        return -1;
    }
}

int main(){
    int n,i,b,arr[100],x;
    printf("Enter the range of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter the data to be searched: ");
    scanf("%d",&x);
    b = Binary_Search(arr,0,n-1,x);
    printf("Found at pos %d\n",b);
    return 0;
}