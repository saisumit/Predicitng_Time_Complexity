#include <bits/stdc++.h>
const int MAXN = 1e8;


using namespace std;

int binarySearch(long long int arr[], int l, int r, long long int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
   }

   // We reach here when element is not
   // present in array
   return -1;
}

int main()
{
    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("binarysearch_vipul.out","w",stdout);
    for(int i=1;i<=5000;i++)
    {
        long long int range = 1e9;
        int n;
        if(i<=50)
            n = rand()%(int)(100);
        else
            n = rand()%(int)(1e6);
        long long int arr[n];
        for(int j=0;j<n;j++)
        {
            if(j==0)
                arr[j] = rand()%range;
            else
                arr[j] = rand()%range+arr[j-1];
        }
    //nt arr[] = {12, 11, 13, 5, 6, 7};
    //int arr_size = sizeof(arr)/sizeof(arr[0]);

    //printf("Given array is \n");
    //printArray(arr, arr_size);
        long long int x;
        if(i%2)
            x = rand()%(int)(1e9);
        else
        {
            int ind = rand()%n;
            x = arr[ind];
        }
        const clock_t start_t = clock();
        binarySearch(arr, 0, n - 1,x);
        double  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;
        //cout<<n<<" --- "<<processor_unit_time<<" --- "<<k<<endl;
        printf("%d,%.15f,%.12f\n",n,p,processor_unit_time);
    }
    return 0;
}
