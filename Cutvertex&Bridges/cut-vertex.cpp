

/*                                                          In The Name Of Allah                                                                            */
/*                                                       Author: Ibrahim Adnan Tanim                                                                         */

#include <bits/stdc++.h>
using namespace std;

#define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

 vector<int>vec[100];
 int in[100],low[100];
 int timer=1;
 bool  vis[100];
 set<int>art;
 void dfs(int node,int parent)
 {
     vis[node]=true;
     in[node]=low[node]=timer;
     timer++;
     int child=0;
     for(auto it: vec[node])
     {
         if(it==parent)
            continue;
         if(vis[it])
         {
             low[node]=min(low[node],in[it]);
         }
         else
         {
             dfs(it,node);
             ++child;
            
            if(low[it]>=in[node] && parent!=-1)   // cz it connect all its edges or we can say it is a sub root.
             {
                art.insert(node);
             }
         low[node]=min(low[node],low[it]);


         }
     }
     if(parent==-1 && child>1)
        art.insert(node);

 }


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,-1);
    }

    for(auto it: art)
        cout<<it<<" ";
}

int32_t main()
{
   Speed();

    solve();

}

