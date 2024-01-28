#include<stdio.h>
#include<stdlib.h>

int Binary_Search(int arr[],int lb,int ub,int x){
    int mid = (lb+ub)/2;
    if(arr[mid]==x){
        return mid ; 
    }else if(arr[mid]>x){
        return Binary_Search(arr,lb,mid-1,x);
    }else{
        return Binary_Search(arr,mid+1,ub,x);
    }
}

int occurrence(int arr[],int lb,int ub,int x){
    int ind = Binary_Search(arr,lb,ub,x);
    int left = ind - 1;
    int right = ind + 1;
    int count=0;
    while(left>=0 && arr[left]==x){
        count++;
        left--;
    } 
    while(right<=ub && arr[right]==x){
        count++;
        right++;
    }
    count++;
    return count;
}

int main(){
    int n,i,arr[100],x;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    printf("Enter element in sorted manner\n");
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to find its occurrence: ");
    scanf("%d",&x);
    int oc = occurrence(arr,0,n-1,x);
    printf("No of occurrence: %d\n",oc);
    
}