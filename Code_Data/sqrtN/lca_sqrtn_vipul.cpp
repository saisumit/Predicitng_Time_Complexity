#include <bits/stdc++.h>


using namespace std;
const int MAXN = 1e5 ;

int block_sz;
int depth[MAXN+5],parent[MAXN+5],jump_parent[MAXN+5];         // block
//int size = sqrt(height);
/*int *depth;       // stores depth for each node
int *parent;      // stores first parent for
                       // each node
int *jump_parent;*/

void dfs(int cur, int prev,vector<vector<int> > &G)
{
    // marking depth of cur node
    depth[cur] = depth[prev] + 1;

    // marking parent of cur node
    parent[cur] = prev;

    // making jump_parent of cur node
    if (depth[cur] % block_sz == 0)

        /* if it is first node of the block
           then its jump_parent is its cur parent */
        jump_parent[cur] = parent[cur];

    else

        /* if it is not the first node of this block
           then its jump_parent is jump_parent of
           its parent */
        jump_parent[cur] = jump_parent[prev];


    // propogating the marking down the subtree
    for (int i = 0; i<G[cur].size(); ++i)
        if (G[cur][i] != prev)
            dfs(G[cur][i], cur,G);
}

int LCANaive(int u,int v)
{
    if (u == v)  return u;
    if (depth[u] > depth[v])
        swap(u, v);
    v = parent[v];
    return LCANaive(u,v);
}

int LCASQRT(int u, int v)
{
    while (jump_parent[u] != jump_parent[v])
    {
        if (depth[u] > depth[v])

            // maintaining depth[v] > depth[u]
            swap(u,v);

        // climb to its jump parent
        v = jump_parent[v];
    }

    // u and v have same jump_parent
    return LCANaive(u,v);
}

int maxDepth(vector<vector<int> > &G)
{
   int h=0;
   int ws=0;
   queue<int> q;
   q.push(0);
   ws=1;
   while(!q.empty())
   {
        int v = q.front();
        q.pop();
        for(int i=0;i<G[v].size();i++)
        {
            q.push(G[v][i]);
        }
        ws--;
        if(ws==0)
        {
            h++;
            ws=q.size();
        }
   }
   return h;
}

int main()
{
    const clock_t begin_time = clock();
    int NUM_LOOPS = (int)1e8;
    for( int i = 1 ; i <= NUM_LOOPS ; i ++ ) ;
    double k =  float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    double processor_unit_time  =  k/NUM_LOOPS ;  // output meib ibckude kr

    freopen("lca_sqrtn_vipul.out", "w", stdout);
    for(int j=0;j<5000;j++)
    {
        int N  = (rand()%MAXN)+1;
        //if( j < 50 )
        //N = rand()%100 + 1 ;
        vector<vector<int> > G( N+1 ) ;
        for( int i = 1 ; i < N ; i ++ )
        {
            int prev_node = rand()%i;
            G[prev_node].push_back(i);
        }
       /* depth = (int *)malloc(sizeof(int)*(N+1));
        jump_parent = (int *)malloc(sizeof(int)*(N+1));
        parent = (int *)malloc(sizeof(int)*(N+1));*/

        int h = maxDepth(G);
        //cout<<h<<endl;
        block_sz = sqrt(h);
        depth[0] = -1;
        dfs(1, 0,G);

        const clock_t b1 = clock();

        int start = rand()%N ;
        int en = rand()%N ;
        LCASQRT( start , en ) ;

        double  k =  float( clock () - b1 ) /  CLOCKS_PER_SEC;
        printf("%d,%.15f,%.12f\n",N,k,processor_unit_time);
    }
    return 0;
}