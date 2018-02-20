#include <bits/stdc++.h>
const int MAXN = 1e9  ;
#include <algorithm>
#include <vector>
using namespace std;
typedef long long Int ;
//vector<int> f(MAXN,0);
//vector<int> G(MAXN,0);
Int exp( Int b , Int p )
{
   Int ans = 1 ;
   while( p )
    {
       if( p&1 )ans =  ans*b ;
       b = b*b ;
       p = p/2 ;

    }

   return ans ;
}

int main(  )
 {

   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr



   //  int n ;
  freopen("binary_exp_sumit.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr

      if( i < 50 )N = rand()%100 + 1 ;
      Int b = rand()%MAXN + 1;

       const clock_t b1 = clock();
       exp( b , N  ) ;
       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       printf("%d,%.15f,%.12f\n",N,k,processor_unit_time);



    }



 }
