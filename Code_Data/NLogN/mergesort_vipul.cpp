#include <bits/stdc++.h>
const int MAXN = 1e8;


using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
/*void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}*/

/* Driver program to test above functions */
int main()
{

    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("mergesort_final.out","w",stdout);
    for(int i=1;i<=5000;i++)
    {
        int range = 1e6,n;
        if(i<=50)
            n = rand()%(int)(100);
        else
            n = rand()%(int)(1e6);
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%range;
    //nt arr[] = {12, 11, 13, 5, 6, 7};
    //int arr_size = sizeof(arr)/sizeof(arr[0]);

    //printf("Given array is \n");
    //printArray(arr, arr_size);
        const clock_t start_t = clock();
        mergeSort(arr, 0, n - 1);
        double  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;
        //cout<<n<<" --- "<<processor_unit_time<<" --- "<<k<<endl;
        printf("%d,%.12f,%.12f\n",n,p,processor_unit_time);
    }

    //printf("\nSorted array is \n");
    //printArray(arr, arr_size);
    return 0;
}
