

/*                                                          In The Name Of Allah                                                                            */
/*                                                       Author: Ibrahim Adnan Tanim                                                                         */

#include <bits/stdc++.h>
using namespace std;

#define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//suppose there are 100 nodes

int parent[100];
int _rank[100];

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

   Union(1,2);  
    Union(3,4);
    Union(5,6);
    Union(7,8);
    Union(1,8);
    Union(3,5);

  for(int i=1;i<9;i++)
  {
    cout<<i<<" parent -> "<<parent[i]<<" rank -> "<<_rank[i]<<endl;
  }
 
}

int32_t main()
{
   Speed();
    
  test_case();

}

