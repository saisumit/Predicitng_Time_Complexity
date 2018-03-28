#include <bits/stdc++.h>
const int MAXN = 1e2;

using namespace std;


vector<vector<int> > matrixmultiply(vector<vector<int> > mat1, vector<vector<int> > mat2,int n)
{
    vector<vector<int> > res(n,vector<int>(n,1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            res[i][j] = 0;
            for(int k=0;k<n;k++)
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return res;

}

int main()
{
    const clock_t begin_time = clock();
    int NUM_LOOPS = (int)1e8 ;
    for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
    double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
    freopen("matrix_multiply_vipul.out", "w", stdout);
    for( int i  = 1 ;  i  <= 500 ; i ++ )
    {

      //int N  = rand()%MAXN ;  // output meib ibckude kr



      /* This is the initialisation part */


      //if( i < 50 )N = rand()%100 + 1 ;
        int N=i;

        vector<vector<int> > mat1(N,vector<int>(N));
        vector<vector<int> > mat2(N,vector<int>(N));

        for( int i = 0 ; i < N ; i ++ )
        {
            for(int j = 0 ; j < N ; j++)
            {
                mat1[i][j] = rand()%(int)( 1e3 );
                mat2[i][j] = rand()%(int)( 1e3 );
            }
        }

      /* This is the initialisation part */


     /* code computaion part */
        const clock_t b1 = clock();

        matrixmultiply(mat1,mat2,N);

        double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */



        printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);
       }
}
