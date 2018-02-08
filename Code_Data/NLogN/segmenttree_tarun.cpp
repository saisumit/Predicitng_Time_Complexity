#include <bits/stdc++.h>
const int MAXN = 1e6  ;

using namespace std;
int t[ 4*MAXN + 5 ] ;
void build (vector<int>&  a, int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}
int main(  )
 {


   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8;
   for( int i = 1 ; i <= NUM_LOOPS ; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr
    //cout<<processor_unit_time<<" ";

   //  int n ;
  //freopen("segmenttree_sumit.out", "w", stdout);
  for( int i  = 0 ;  i  < 5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr
      vector<int>A( N) ;

      /* This is the initialisation part */


      if( i < 50 )N = (rand()%100)+1;
      for( int i = 0 ; i < N ; i ++ )
        {
          A[i] = rand()%(int)( 1e9 )   ;

         }
      /* This is the initialisation part */


     /* code computaion part */

       const clock_t b1 = clock();

        build(A,1,0,N-1);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */

        printf("%d,%0.12lf,%0.12lf\n",N,k,processor_unit_time);




    }




  }



