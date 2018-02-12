#include <bits/stdc++.h>
const int MAXN = 1e6  ;
#include <algorithm>
#include <vector>
using namespace std;
bool linear(vector<int> A,int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==x)
        return true;

    }
    return false;
}
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("linearsearch_tarun.out", "w", stdout);
  for( int i  = 0 ;  i  <  5 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr
      vector<int>A( N ) ;


      /* This is the initialisation part */


      if( i < 50 )N = rand()%100 + 1 ;
      for( int i = 0 ; i < N ; i ++ )
        {
          A[i] = rand()%(int)( 1e9 )   ;
         }

        int x = rand()%(int)(1e9);
      /* This is the initialisation part */


     /* code computaion part */
       struct Node* root  = NULL ;
       const clock_t b1 = clock();

        linear(A,N,x);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
