#include <bits/stdc++.h>
const int MAXN = 1e8;


using namespace std;

void max_heapify (long long int Arr[ ], int i, int N)
{
    long long int left = 2*i+1;                   //left child
    long long int right = 2*i +2;           //right child
    long long int largest=i;
    if(left< N and Arr[left] > Arr[i] )
          largest = left;
    if(right < N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    }
 }

void build_maxheap (long long int Arr[ ],int N)
{
    for(int i = (N/2)-1 ; i >= 0 ; i-- )
    {
        max_heapify (Arr, i,N) ;
    }
}

int main()
{
    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("heapify_vipul.out","w",stdout);
    for(int i=1;i<=5000;i++)
    {
        long long int range = 1e9,n;
        if(i<=50)
            n = rand()%(int)(100);
        else
            n = rand()%(int)(1e6);
        long long int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%range;
        build_maxheap(arr,n);
        int index = rand()%(int)(n);
        arr[index] = rand()%range;
        const clock_t start_t = clock();
        max_heapify(arr,index,n);
        float  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;
        //cout<<n<<" --- "<<processor_unit_time<<" --- "<<k<<endl;
        printf("%d,%.15f,%.12f\n",n,p,processor_unit_time);
    }
    return 0;
}
