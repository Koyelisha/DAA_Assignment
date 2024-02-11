#include<stdio.h>

void CountSort(int n,int arr[100],int k){
    int count[k+1],i,j,m,brr[n];
    //Creating the count array of which each index holding 0 as its initial value
    for(i=0;i<=k;i++){
        count[i] = 0;
    }
    for(i=0;i<n;i++){
        j = arr[i];
        count[j]++;
    }
    //Updating the count array
     i = 0;
     count[i] = count[0];
     for(i=1;i<=k;i++){
         count[i] = count[i] + count[i-1];
     }
     //Sorting the array
     for(i=n-1;i>=0;i--){
        j = arr[i];
        count[j]--;
        brr[count[j]] = j;
     }
     for(i=0;i<n;i++){
         arr[i] = brr[i];
     }
}

int main(){
    int n,i,k;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter element for arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    //Finding out the maximum element
    k = arr[0];
    printf("Actual Array:-\n");
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
        if(arr[i]>k){
            k = arr[i];
        }
    }
    CountSort(n,arr,k);
     printf("Sorted Array:-\n");
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}