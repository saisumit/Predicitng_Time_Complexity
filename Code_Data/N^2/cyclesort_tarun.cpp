#include <bits/stdc++.h>
const int MAXN = 1e4  ;
#include <algorithm>
#include <vector>
using namespace std;
void cycleSort (vector<int>  &arr, int n)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on
    // the right place
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }

    // Number of memory writes or swaps
    // cout << writes << endl ;
}
void print(vector<int> a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("cyclesort_tarun.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr



      /* This is the initialisation part */


      if( i < 50 )N = rand()%(int)(100) + 1 ;

       vector<int> A( N ) ;
      for( int i = 0 ; i < N ; i ++ )
        {
          A[i] = rand()%(int)( 1e9 )   ;
         }

      /* This is the initialisation part */
    //cout<<N<<" ";

     /* code computaion part */
       struct Node* root  = NULL ;
       const clock_t b1 = clock();

            cycleSort(A,N);


       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */

        //print(A,N);

       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
