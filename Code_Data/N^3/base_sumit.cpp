#include <bits/stdc++.h>
const int MAXN = 1e2  ;
#include <algorithm>
#include <vector>
using namespace std;

int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("base_sumit.out", "w", stdout);

  for( int i  = 1 ;  i  <= 500 ; i ++ )
   {

      //int N  = rand()%MAXN ;  // output meib ibckude kr



      /* This is the initialisation part */

   		int N = i ;
     /* code computaion part */

       const clock_t b1 = clock();
       
       int cnt =  0  ;
       for( int ii = 0 ; ii < N ; ii ++ )
       	for( int j = 0; j < N ; j ++ )
       		for( int k = 0 ; k < N ; k  ++ )
       			cnt ++ ; 

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }


