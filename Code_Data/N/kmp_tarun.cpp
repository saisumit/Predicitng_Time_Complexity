#include <bits/stdc++.h>
const int MAXN = 1e6  ;
#include <algorithm>
#include <vector>
using namespace std;
int lps[MAXN+5];
void computeLPSArray(char *pat, int M)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
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
  freopen("kmp_tarun.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr
    char A[N+1];

      /* This is the initialisation part */


      if( i < 50 )N = rand()%100 + 1 ;
      for( int i = 0 ; i < N ; i ++ )
        {
          A[i] = (char)(rand()%(int)(26)  +'a');
         }

      /* This is the initialisation part */


     /* code computaion part */
       struct Node* root  = NULL ;
       const clock_t b1 = clock();

        computeLPSArray(A,N);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
