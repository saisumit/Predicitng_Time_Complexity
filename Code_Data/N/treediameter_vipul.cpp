#include <bits/stdc++.h>
const int MAXN = 1e6  ;
#include <algorithm>
#include <vector>
using namespace std;

//vector<int> f(MAXN,0);
//vector<int> G(MAXN,0);

int f[MAXN+4];
int g[MAXN+4];
int diameter;


void dfs(vector<vector<int> > &G, int v, int pv ){

    int ma1 = -1 ;
    int ma2 = -1 ;

    for( int i = 0 ; i <  G[v].size() ; i ++ )
     {
        int ch =  G[v][i] ;
        if(  ch == pv )continue ;
        dfs(G, ch , v ) ;
        if(  f[ch] > ma1 ){  ma2 = ma1 ; ma1 = f[ch]; }
        else if(  f[ch] > ma2 ){  ma2 = f[ch] ; }
     }


    f[v] = 1;

    if(ma1!=-1) f[v] += ma1 ;

    if(ma1!=-1 && ma2!=-1)
         g[v] = 1 + ma1 + ma2 ;

    diameter = max(diameter, max(f[v], g[v]));
}

int main(  )
 {

   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr



   //  int n ;
  freopen("treediameter_sumit2.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr
      //N=2375;
      vector<vector<int> > G(N) ;
      diameter =0 ;

      /* This is the initialisation part */


      if( i < 50 )N = rand()%100 + 1 ;
      for( int i = 1 ; i < N ; i ++ )
        {
           int prev_node = rand()%i;
           G[prev_node].push_back(i);
           G[i].push_back(prev_node);

         }

       const clock_t b1 = clock();

       //dfs(G,0);
       dfs(G,0,-1);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
