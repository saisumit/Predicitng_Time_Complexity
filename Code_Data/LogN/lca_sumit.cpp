 #include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 ;
const int LOGMAX = 20 ;
int T[MAXN];
int P[MAXN][ LOGMAX ] ;
int L[MAXN] ;
int N ;


 void PreProcess( vector<vector<int> >&g)
  {
      int i, j;

  //we initialize every element in P with -1
      for (i = 0; i < N; i++)
          for (j = 0; 1 << j < N; j++)
              P[i][j] = -1;

  //the first ancestor of every node i is T[i]
      for (i = 0; i < N; i++)
          P[i][0] = T[i];

  //bottom up dynamic programing
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];  // 2^(j-1) * 2^(j-1) = 2^j

  }

  void  bfs ( vector<vector<int> >&g)
   {

       queue<int> q;
       while( !q.empty())q.pop();

       q.push( 0 ) ;
       L[0] = 0 ;

      while ( !q.empty() )
       {

          int v = q.front() ;
          q.pop() ;
         // cout<< "V" << v << endl;
          for( int i = 0 ; i < g[v].size() ; i ++ )
                 {
                   int ch =  g[v][i] ;
                     L[ch] = L[v] + 1  ;
                     //cout<< "Ch" << ch << endl;
                     q.push(ch);
                 }


       }

     return ;

   }



  int query(int p, int q)
  {
      int tmp, log, i;

  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          swap( p , q ) ;

  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

int main(  )
 {

   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("lca_sumit.out", "w", stdout);

  for( int i  = 0 ;  i  < 5000  ; i ++ )
   {


      N  = rand()%MAXN ;  // output meib ibckude kr

      if( i < 50 )N = rand()%100 + 1 ;

      T[0] = 0 ;
        for( int i = 1 ; i < N ; i ++ )
         {
            T[i] = rand()% i ;
           // cout<<T[i]<<endl ;
         }
        vector<vector<int> >g(N) ;

         for( int i = 1 ; i <  N ; i ++ )
           {

              g[ T[i] ].push_back( i ) ;

           }


           bfs( g ) ;

           PreProcess(g);





           const clock_t b1 = clock();

           int start = rand()%N ;
           int end = rand()%N ;

          // cout<<start<<" "<<end<<endl;

            query ( start , end ) ;


           double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

           printf("%d,%.15f,%.12f\n",N,k,processor_unit_time);









    }



 }


