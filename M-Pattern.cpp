#include<iostream>
using namespace std;
int main()
{
int i,j,k,l,n;
cin>>n;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(j<=i)
cout<<"\t"<<j;
else
cout<<" \t";
}
for(k=n-1;k>i;k--)
{
cout<<" \t";
}
l=i;
if(l==n)
{
l=l-1;
while(l>0)
{
cout<<"\t"<<l;
l--;
}
}
else if(l<n)
{
while(l>0)
{
cout<<"\t"<<l;
l--;
}
}
cout<<endl;
}
}