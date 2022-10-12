

/*                                                          In The Name Of Allah                                                                            */
/*                                                       Author: Ibrahim Adnan Tanim                                                                         */

#include <bits/stdc++.h>
using namespace std;

#define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=3e6+1;
vector<int>v[mx];
int in[mx];
int low[mx];
bool vis[mx];
int timer=1;
bool isbridge=false;
vector<pair<int,int>>vec;
void dfs(int node,int parent)
{
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(auto child: v[node])
    {
        if(child==parent)
            continue;
        if(vis[child])
        {

           low[node]=min(low[node],in[child]);   // This is backedge so we need to check whether there is any lowest ancestor avilable or not.

        }
        else
        {
           // Forward edge
            dfs(child,node);
           
            if(low[child]>in[node])
            {
              cout<<"Bridges are ->";
                cout<<node<<" "<<child<<endl;
                return ;
            }
               
         low[node] = min(low[node], low[child]);  

        }
    }

}
void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
      if(!vis[i])
        dfs(i,-1);
    }

   
}

int32_t main()
{
   Speed();
   solve();

}
