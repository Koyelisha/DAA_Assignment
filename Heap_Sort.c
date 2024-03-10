#include<stdio.h>
#include<conio.h>

void Maxheapify(int arr[],int f,int size);
void maxHeap(int arr[],int beg,int end){
    int i;
    for(i = end/2;i>=beg;i--){
        Maxheapify(arr,i,end);
    }
}

void Maxheapify(int arr[],int f,int size){
    int max = f;
    int l = 2*f;
    int r = 2*f+1;
    if(l<=size && arr[l]>arr[max]){
        max = l;
    }
    if(r<=size && arr[r]>arr[max]){
        max = r;
    }
    if(f!=max){
        int temp = arr[max];
        arr[max] = arr[f];
        arr[f] = temp;
        Maxheapify(arr,max,size);
    }
}

void heapsort(int arr[],int size){
    int i;
    for(i=size;i>=2;i--){
        int t = arr[1];
        arr[1] = arr[i];
        arr[i] = t;
        Maxheapify(arr,1,i-1);
    }
}


int main(){
    int n,i;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=1;i<=n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    maxHeap(arr,1,n);
    heapsort(arr,n);
    printf("\nSorted array\n");
    for(i=1;i<=n;i++){
        printf(" %d ",arr[i]);
    }

    return 0;
}