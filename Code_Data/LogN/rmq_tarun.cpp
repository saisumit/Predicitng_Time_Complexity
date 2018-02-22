#include <bits/stdc++.h>
const int MAXN = 1e6  ;
#include <algorithm>
#include <vector>
using namespace std;
typedef long long Int ;


vector<int> st(4*MAXN,0);

int RMQUtil(int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;

    // If a part of this segment overlaps with the given range
    int mid = ss+(se-ss)/2;
    //cout<<1<<" ";
    return min(RMQUtil( ss, mid, qs, qe, 2*index+1),
                  RMQUtil(mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs > qe)
    {
        swap(qs,qe);
    }

    return RMQUtil(0, n-1, qs, qe, 0);
}

int construct(vector<int> &arr, int ss, int se, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = ss+(se-ss)/2;
    st[si] =  min(construct(arr, ss, mid,  si*2+1),
                     construct(arr, mid+1, se,  si*2+2));
    return st[si];
}

int main(  )
 {

   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr



   //  int n ;
freopen("rmq_tarun.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr

      if( i < 50 )N = rand()%100 + 1 ;


        vector<int> A(N);

        for(int j=0;j<N;j++)
        {
            A[j]=rand()%(int)(1e9);
        }

        construct(A,0,N-1,0);
        int qs = rand()%N;
        int qe = rand()%N;
       const clock_t b1 = clock();

        RMQ(N, qs, qe);


       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       printf("%d,%.15f,%.12f\n",N,k,processor_unit_time);



    }



 }

