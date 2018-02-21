#include <bits/stdc++.h>
const int MAXN = 1e6  ;
#include <algorithm>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *le,*ri;
};
node *root1=NULL;
node *newnode(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->le=temp->ri=NULL;
    return temp;
}
node *inserta(node *root1,int x)
{
    if(root1==NULL)
    return newnode(x);
    if(x<root1->data)
    root1->le=inserta(root1->le,x);
    else if(x>root1->data)
    root1->ri=inserta(root1->ri,x);
    return root1;
}
void create(vector<int> A,int n)
{
    root1=NULL;
    for(int i=0;i<n;i++)
    {
        root1=inserta(root1,A[i]);
    }
}
void deallocate(node *root1)
{
    if(root1==NULL)
    return;
    deallocate(root1->le);
    deallocate(root1->ri);
    free(root1);
}
int main(  )
 {



   const clock_t begin_time = clock();
   int NUM_LOOPS = (int)1e8 ;
   for( int i = 1 ; i <= NUM_LOOPS; i ++ ) ;
   double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
   double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr


   //  int n ;
  freopen("bst_tarun.out", "w", stdout);
  for( int i  = 0 ;  i  <  5000 ; i ++ )
   {

      int N  = rand()%MAXN ;  // output meib ibckude kr

    vector<int> A(N);

      /* This is the initialisation part */


      if( i < 50 )N = rand()%100 + 1 ;
      for( int i = 0 ; i < N ; i ++ )
        {
          A[i] = rand()%(int)(1e9);
         }

      /* This is the initialisation part */


     /* code computaion part */
       struct Node* root  = NULL ;
       const clock_t b1 = clock();

        create(A,N);
        //inorder(root1);

       double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC; // output meib ibckude kr

       /* code computaion part */

        deallocate(root1);


       printf("%d,%.12f,%.12f\n",N,k,processor_unit_time);



    }



 }
