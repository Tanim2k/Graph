


#include<bits/stdc++.h>
using namespace std;

#define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


vector<pair<int,int>> vec[100];

int dis[100];
bool isvisted[100];
int ans=0;
class oder
{
public:
  bool operator()(const pair<int,int> &a,const pair<int,int> &b)
  {
    return a.second>b.second;
  }
};
void prims(int s)
{
  dis[s]=0;
   for(int i=0;i<100;i++)
    dis[i]=INT_MAX;
  priority_queue<pair<int,int>,vector<pair<int,int>>,oder>pq;
   pq.push({s,0});

   while(!pq.empty())
   {
    pair<int,int>curr=pq.top();
    pq.pop();

    if(isvisted[curr.first])
      continue;

    isvisted[curr.first]=true;
    cout<<curr.first<<" "<<curr.second<<endl;
    ans+=curr.second;

    for(int i=0;i<vec[curr.first].size();i++)
    {
        pair<int,int>next=vec[curr.first][i];

        if(isvisted[next.first])
          continue;
        if(next.second<dis[next.first])
        {
          dis[next.first]=next.second;
          pq.push(next);
        }
    }

   }
   cout<<ans<<endl;

}

int main() {
  Speed();
   int n,e;
   cin>>n>>e;

   for(int i=0;i<e;i++)
   {
    int u,v,w;
    cin>>u>>v>>w;
     vec[u].push_back({v,w});
   }
   prims(1);

  return 0;
}



