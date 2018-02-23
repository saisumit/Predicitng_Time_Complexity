#include <bits/stdc++.h>
const int MAXN = 1e9;
using namespace std;

// Variable to represent block size. This is made global
// so compare() of sort can use it.
int block;

// Structure to represent a query range
struct Query
{
    int L, R;
};

// Function used to sort all queries so that all queries
// of same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(pair<int,int> x, pair<int,int> y)
{
    // Different blocks, sort by block.
    if (x.first/block != y.first/block)
        return x.first/block < y.first/block;

    // Same block, sort by R value
    return x.second < y.second;
}

// Prints sum of all query ranges. m is number of queries
// n is size of array a[].
void queryResults(int a[], int n, pair<int,int> q[], int m)
{
    // Find block size
    block = (int)sqrt(n);

    // Sort all queries so that queries of same blocks
    // are arranged together.
    if(block!=0)
        sort(q, q + m, compare);

    // Initialize current L, current R and current sum
    int currL = 0, currR = 0;
    int currSum = 0;

    // Traverse through all queries
    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].first, R = q[i].second;

        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L)
        {
            currSum -= a[currL];
            currL++;
        }

        // Add Elements of current Range
        while (currL > L)
        {
            currSum += a[currL-1];
            currL--;
        }
        while (currR <= R)
        {
            currSum += a[currR];
            currR++;
        }

        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1)
        {
            currSum -= a[currR-1];
            currR--;
        }

    }
}

int main()
{
    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("mo_vipul.out","w",stdout);
    for(int i=1;i<=5000;i++)
    {
        int range = 1e6,n;
        if(i<=50)
            n = rand()%(int)(100);
        else
            n = rand()%(int)(1e6);
        int *arr = (int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            arr[i] = rand()%range;
        int m = rand()%(int)(1e6);
        pair<int,int> *q;
        q = (pair<int,int> *)malloc(m*sizeof(pair<int,int>));
        for(int j=0;j<m;j++)
        {
            int l,r;
            if(n!=0)
                l = rand()%n;
            else
                l=0;
            if(n!=0)
                r = rand()%n;
            else
                r=0;
            if(l>r)
            {
                int temp = l;
                l=r;
                r=temp;
            }
            q[j].first = l;
            q[j].second = r;
        }
        const clock_t start_t = clock();
        queryResults(arr,n,q,m);
        double  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;
        free(arr);
        free(q);
        printf("%d,%.12f,%.12f\n",n,p,processor_unit_time);
    }
    return 0;
}
