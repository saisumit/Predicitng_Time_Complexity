#include <bits/stdc++.h>
const int MAXN = 1e6  ;
#include <algorithm>
#include <vector>
using namespace std;

void dfs( vector<vector<int> >&G , int vtx )
 {
    for( int i : G[vtx] )
       dfs( G , i ) ;

 }
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr



   //  int n ;
  freopen("treedfs_sumit.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr
      vector<vector<int> >G( N ) ;


      /* This is the initialisation part */


      if( i < 50 )N = rand()%100 + 1 ;
      for( int i = 1 ; i < N ; i ++ )
        {
           int prev_node = rand()%i  ;
           G[prev_node].push_back(i) ;

         }

       const clock_t b1 = clock();

       dfs(G,0);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }



