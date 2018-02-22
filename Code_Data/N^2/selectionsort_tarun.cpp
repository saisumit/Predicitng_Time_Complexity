#include <bits/stdc++.h>
const int MAXN = 1e4  ;
#include <algorithm>
#include <vector>
using namespace std;
void selectionSort(vector<int>  &A, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (A[j] < A[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(A[min_idx], A[i]);
    }
}
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("selectionsort_tarun.out", "w", stdout);
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

            selectionSort(A,N);


       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */

        //print(A,N);

       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
