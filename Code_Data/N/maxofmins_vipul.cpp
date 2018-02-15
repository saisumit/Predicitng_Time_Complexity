#include <bits/stdc++.h>
const int MAXN = 1e8;

using namespace std;

void printMaxOfMin(int arr[], int n)
{
    stack<int> s; // Used to find previous and next smaller

    // Arrays to store previous and next smaller
    int *left;
    int *right;
    left = (int *)malloc((n+1)*sizeof(int));
    right = (int *)malloc((n+1)*sizeof(int));

    // Initialize elements of left[] and right[]
    for (int i=0; i<n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    // Fill elements of left[] using logic discussed on
    // https://www.geeksforgeeks.org/next-greater-element/
    for (int i=0; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (!s.empty())
            left[i] = s.top();

        s.push(i);
    }

    // Empty the stack as stack is going to be used for right[]
    while (!s.empty())
        s.pop();

    // Fill elements of right[] using same logic
    for (int i = n-1 ; i>=0 ; i-- )
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if(!s.empty())
            right[i] = s.top();

        s.push(i);
    }

    // Create and initialize answer array
    int *ans;
    ans = (int *)malloc((n+1)*sizeof(int));
    for (int i=0; i<=n; i++)
        ans[i] = 0;
    //memset(ans,0,sizeof(ans));

    // Fill answer array by comparing minimums of all
    // lengths computed using left[] and right[]
    for (int i=0; i<n; i++)
    {
        // length of the interval
        int len = right[i] - left[i] - 1;

        // arr[i] is a possible answer for this length
        // 'len' interval, check if arr[i] is more than
        // max for 'len'
        ans[len] = max(ans[len], arr[i]);
    }

    // Some entries in ans[] may not be filled yet. Fill
    // them by taking values from right side of ans[]
    for (int i=n-1; i>=1; i--)
        ans[i] = max(ans[i], ans[i+1]);
    free(left);
    free(right);
    free(ans);

}

// Driver program
int main()
{
    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("maxofmins_vipul.out","w",stdout);
    for(int z=1;z<=5000;z++)
    {
        int range = 1e6,n;
        if(z<=50)
            n = rand()%(int)(100);
        else
            n = rand()%(int)(1e6);
        int *arr;
        arr = (int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            arr[i] = rand()%range;

        const clock_t start_t = clock();
        printMaxOfMin(arr,n);
        double  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;
        printf("%d,%.12f,%.12f\n",n,p,processor_unit_time);
        free(arr);
    }
    return 0;
}
