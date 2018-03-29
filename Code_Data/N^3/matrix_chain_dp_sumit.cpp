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
  freopen("matrix_chain_dp_sumit.out", "w", stdout);
  for( int i  = 1 ;  i  <= 500 ; i ++ )
   {

      //int N  = rand()%MAXN ;  // output meib ibckude kr



      /* This is the initialisation part */


      //if( i < 50 )N = rand()%100 + 1 ;
      int N=i;

      vector<vector<pair<int,int> > > dp(N,vector<pair<int,int> >(N));
      vector<int> A( N ) ; 

      for( int i = 0 ; i < N ; i ++ )
        {
                A[i] = rand()%(int)( 1e9 )   ;
            
         }
      
     for(int i=0;i<N;i++)
     	for(int j=0;j<N;j++)
        dp[i][j].first=INT_MAX,dp[i][j].second=INT_MAX;

     for(int i=0;i<N;i++)
        dp[i][i].first=0,dp[i][i].second= A[i];
      /* This is the initialisation part */


     /* code computaion part */

       const clock_t b1 = clock();

	  for(int a=1;a< N ;a++)
		   { 
			   	int i=0;
			       for(int j=a;j<N;j++)
			       { for(int k=i;k<j;k++)
			          if((dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second)<dp[i][j].first)
			                       { dp[i][j].first=dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second;
			                         dp[i][j].second=(dp[i][k].second+dp[k+1][j].second)%100;
			                       }
			          i++;
			       }
	 
	   		}

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }


