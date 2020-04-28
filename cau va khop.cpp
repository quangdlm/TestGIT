#include <bits/stdc++.h>
using namespace std;

ifstream fi("input.txt");
ofstream fo("output.txt");
struct mg
{
    int spt=0;
    int dnoi[10000];
};
vector <long long> number,low,parent;
vector <mg> mangbd;
vector <long long> dinhdau,sodr;
long long n,m,cnt=0,demlt=0;

void nhap()
{
    fi>>n>>m;
    number.resize(n+2,0);
    low.resize(n+2,n+2);
    parent.resize(n+2);
    mangbd.resize(n+2);
    dinhdau.resize(n+2,false);
    sodr.resize(n+2);
    int x,y;
    for (int i=1;i<=m;i++)
    {
        fi>>x>>y;
        mangbd[x].spt++;
        mangbd[y].spt++;
        mangbd[x].dnoi[mangbd[x].spt]=y;
        mangbd[y].dnoi[mangbd[y].spt]=x;
    }
}

long long cauvskhop(long long x)
{
    if (number[x]==0)
    {
        cnt++;number[x]=cnt;low[x]=number[x];
        for (int i=1;i<=mangbd[x].spt;++i)
            {
                if (mangbd[x].dnoi[i]==dinhdau[demlt]) sodr[demlt]++;
                if (number[mangbd[x].dnoi[i]]==0)
                {
                    parent[mangbd[x].dnoi[i]]=number[x];
                    low[x]=min(low[x],cauvskhop(mangbd[x].dnoi[i]));
                } else low[x]=min(low[x],number[mangbd[x].dnoi[i]]);
            }
    }
    else return low[x];
    return low[x];
}

void xuly()
{
    low[1]=1;
    for (int i=1;i<=n;i++)
        if (number[i]==0)
        {
            demlt++;sodr[demlt]=1;
            dinhdau[demlt]=i;
            cauvskhop(i);
        }
}

void xuat()
{
    cout<<"Cau: "<<endl;
    for (int i=2;i<=n;i++)
        if ((parent[parent[i]]==0)||(low[i]>number[parent[i]]))
            cout<<parent[i]<<" "<<i<<endl;
    cout<<"Khop: \n";
    for (int i=2;i<=n;i++)
        if (low[i]>=number[parent[i]]) printf("%d\n",parent[i]);
    for (int x=1;x<=n;x++)
        cout<<low[x]<<" "<<number[x]<<" "<<parent[x]<<endl;

}

main()
{
    nhap();
    xuly();
    xuat();
}
