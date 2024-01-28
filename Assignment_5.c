#include <stdio.h>

int mergesort_inv(int a[], int tmp[], int l, int r);
int merge_inv(int a[], int tmp[], int l, int half, int r);
int mergeSort(int a[], int n);

int mergesort_inv(int a[], int tmp[], int l, int r)
{
    int half, inv_cnt = 0;
    if (r > l)
    {
        half = (r + l) / 2;
        inv_cnt = inv_cnt + mergesort_inv(a, tmp, l, half);
        inv_cnt = inv_cnt + mergesort_inv(a, tmp, half + 1, r);
        inv_cnt += merge_inv(a, tmp, l, half + 1, r);
    }
    return inv_cnt;
}

int merge_inv(int a[], int tmp[], int l, int half, int r)
{
    int i, j, k;
    int inv_cnt = 0;

    i = l;
    j = half;
    k = l;

    while ((i <= half - 1) && (j <= r))
    {
        if (a[i] <= a[j])
        {
            tmp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            tmp[k] = a[j];
            k++;
            j++;
            inv_cnt = inv_cnt + (half - i);
        }
    }

    while (i <= half - 1)
    {
        tmp[k] = a[i];
        k++;
        i++;
    }

    while (j <= r)
    {
        tmp[k] = a[j];
        k++;
        j++;
    }

    for (i = l; i <= r; i++)
        a[i] = tmp[i];

    return inv_cnt;
}

int mergeSort(int a[], int n)
{
    int tmp[n];
    return mergesort_inv(a, tmp, 0, n - 1);
}

int main()
{
    int a[] = {2,4,1,3,5};
    int n = sizeof(a) / sizeof(a[0]);
    int res = mergeSort(a, n);
    printf("Inversions: %d\n", res);
    return 0;
}
