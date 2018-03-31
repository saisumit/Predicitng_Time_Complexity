
#include <bits/stdc++.h>
const int MAXN = 1e9;
using namespace std;

int main()
{
    const clock_t time_st = clock();
    for(int i=0;i<=MAXN;i++);
    double k =  float( clock () - time_st )/CLOCKS_PER_SEC;
    double processor_unit_time  =  k/MAXN ;
    freopen("prime_factor_sqrtn_sumit.out","w",stdout);
  
    for(int i=1;i<=5000;i++)
    {
        int n ; 
        if(i<=50)
            n = rand()%(int)(100);
        else
            n = rand()%(int)(1e9);
        
        
        const clock_t start_t = clock();
        
        int cnt = 0 ; 
        	for( int j = 1 ; j < sqrt(n); j ++ )
        			if( n%j == 0 )
             		 	cnt ++ ; 

             		 
        double  p =  float( clock () - start_t ) /  CLOCKS_PER_SEC;

        printf("%d,%.12f,%.12f\n",n,p,processor_unit_time);
    }
    return 0;
}