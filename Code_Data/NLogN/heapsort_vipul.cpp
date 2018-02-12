// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8;


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


// Driver program
int main()
{
    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("heapsort_final.out","w",stdout);
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
        const clock_t start_t = clock();
        heapSort(arr,n);
        double  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;
        //cout<<n<<" --- "<<processor_unit_time<<" --- "<<k<<endl;
        printf("%d,%.12f,%.12f\n",n,p,processor_unit_time);
    }
    return 0;
}
