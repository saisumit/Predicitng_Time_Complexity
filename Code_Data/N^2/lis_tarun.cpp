#include <bits/stdc++.h>
const int MAXN = 1e4  ;
#include <algorithm>
#include <vector>
using namespace std;

int lis( vector<int> &arr, int n )
{

    /* Initialize LIS values for all indexes */
    vector<int> lis(n,1);
    int i,j;
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
}
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("lis_tarun.out", "w", stdout);
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

            lis(A,N);


       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */

        //print(A,N);

       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
