#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    struct node*next;
}*h[100010];
int col[100010];
void node(int v,int u)
{
    struct node*p=(struct node*)malloc(sizeof(struct node));
    p->u=u;
    p->next=h[v];
    h[v]=p;
}
void dfs(int x,int flag)
{

    struct node*p;
    for( p=h[x]; p!=NULL; p=p->next)
    {
       int u=p->u;
       if(col[u]==-1)
       {
           col[u]=flag;
           dfs(u,!flag);
       }
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(col,-1,sizeof(col));
        for(int i=0;i<100010;i++)
        {
            h[i]=NULL;
        }
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            node(a,b);
            node(b,a);
        }
        dfs(1,0);
      
       long long ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0)
            {
                ans1++;
            }
            if(vis[i]==1)
                ans2++;
        }
        printf("%lld\n",(ans1*ans2)-n+1);
    }
}