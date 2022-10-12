

/*                                                          In The Name Of Allah                                                                            */
/*                                                       Author: Ibrahim Adnan Tanim                                                                         */

#include <bits/stdc++.h>
using namespace std;

#define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


class store
{
public:
    int u,v,w;
};

class compare
{
public:
    bool operator()(const store &a,const store &b)
    {
        if(a.w>b.w)
            return true;
        else
            return false;
    }
};

priority_queue<store,vector<store>,compare> pq;

int parent[100];
int _rank[100];
 // suppose number of edges=100;
void init()
{
    for(int i=0;i<100;i++){
        parent[i]=i;

        _rank[i]=1;
    }
}

int find(int par)
{
    if(parent[par]==par)
        return par;

    return parent[par]=find(parent[par]);
}

void Union(int x1,int y1)
{
    if(find(x1)!=find(y1))
    {
       int par1=find(x1);
       int par2=find(y1);

       if(_rank[par1]>=_rank[par2])
       {
          parent[par2]=par1;
          _rank[par1]+=_rank[par2];
          _rank[par2]=0;
       }
       else
       {
         parent[par1]=par2;
         _rank[par2]+=_rank[par1];
         _rank[par1]=0;
       }
    }
}



void test_case()
{
   init();
   int n,m;
   cin>>n>>m; // n->nodes and m->edges

   for(int i=0;i<m;i++)
   {
      int x,y,z;
      cin>>x>>y>>z;

      store obj;
      obj.u=x;
      obj.v=y;
      obj.w=z;

     pq.push(obj);

   }
  int ans=0;
    while(!pq.empty())
    {
       store obj1=pq.top();
       pq.pop();

       if(find(obj1.u)!=find(obj1.v))
       {

        Union(obj1.u,obj1.v);
        ans+=obj1.w;
       }
    }

 


 cout<<ans<<endl;
}

int32_t main()
{
   Speed();
    
    test_case();

}


/*
Input-----
 7 10
1 3 1
1 2 2
1 6 3
3 4 2
6 7 5
4 7 3
2 5 6
5 7 4
2 6 1
3 6 3
ans=13
*/

