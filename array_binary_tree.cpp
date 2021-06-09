//Array implementation
#include<bits/stdc++.h>
using namespace std;
int tree[10];
void root(int key)
{
 if(tree[0]=='\0')
 tree[0]=key;
 else
 cout<<"root exists"<<"\n";
}
void left(int key,int parent)
{
  if(tree[parent]=='\0')
  cout<<"parent does not exist\n";
  else
  tree[parent*2+1]=key;
}
void right(int key,int parent)
{
    if(tree[parent]=='\0')
    cout<<"parent does not exist\n";
    else
    tree[parent*2+2]=key;
}
int main()
{
    root(20);
    //insert_left('B',0);
    right(13, 0);
    left(14, 1);
    right(15, 1);
    right(16, 2);
    for(int i=0;i<10;i++)
    cout<<tree[i]<<" ";
    cout<<"\n";
    return 0;
}
