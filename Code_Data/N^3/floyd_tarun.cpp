#include <bits/stdc++.h>
const int MAXN = 1e2  ;
#include <algorithm>
#include <vector>
using namespace std;
int floyd(vector<vector<int> > &G,int n)
{
    vector<vector<long long int > > dist(n,vector<long long int> (n));
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        dist[i][j]=G[i][j];
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
   /* for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<dist[i][j]<<" ";
        cout<<endl;
    }*/
}
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("floyd_tarun.out", "w", stdout);
  for( int i  = 1 ;  i  <= 500 ; i ++ )
   {

      //int N  = rand()%MAXN ;  // output meib ibckude kr



      /* This is the initialisation part */


      //if( i < 50 )N = rand()%100 + 1 ;
      int N=i;

      vector<vector<int>  > A(N,vector<int>(N));

      for( int i = 0 ; i < N ; i ++ )
        {
            for(int j = 0 ; j < N ; j++)
            {
                A[i][j] = rand()%(int)( 1e9 )   ;
            }
         }

      /* This is the initialisation part */


     /* code computaion part */
       struct Node* root  = NULL ;
       const clock_t b1 = clock();

        floyd(A,N);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
