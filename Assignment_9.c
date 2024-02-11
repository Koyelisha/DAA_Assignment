#include<stdio.h>

int median(int arr[100],int n){
    int mid,e,f,g=0;
    mid = n/2;
    if(n%2==0){
        e = arr[mid];
        f = arr[mid-1];
        g = (e+f)/2;
        return g;
    }else{
        return arr[mid];
    }
}

int main(){
    int n,i,k=0,med;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int arr[n],brr[n],c[2*n];
    printf("Enter elements in sorted manner\n");
    for(i=0;i<n;i++){
        printf("Enter element at arr[%d]: ",i);
        scanf("%d",&arr[i]);
        c[k] = arr[i];
        k++;
    }
    for(i=0;i<n;i++){
        printf("Enter element at brr[%d]: ",i);
        scanf("%d",&brr[i]);
        c[k] = brr[i];
        k++;
    }
    med = median(c,2*n);
    printf("Median of two arrays: %d\n",med);
    return 0;
}