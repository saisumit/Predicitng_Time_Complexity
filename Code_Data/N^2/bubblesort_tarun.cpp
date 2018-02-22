#include <bits/stdc++.h>
const int MAXN = 1e4  ;
#include <algorithm>
#include <vector>
using namespace std;
void bubble(vector<int> &A,int n)
{
    for (int i = 0; i < n-1; i++)
    {
       for (int j = 0; j < n-i-1; j++)
           {
                if (A[j] > A[j+1])
                    swap(A[j], A[j+1]);
            }
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
  freopen("bubblesort_tarun.out", "w", stdout);
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

            bubble(A,N);


       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */

        //print(A,N);

       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }

