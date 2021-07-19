#include<bits/stdc++.h>
using namespace std;
struct trie{
  trie* children[26];
  bool isendofword=true;
};
trie* createnode(void)
{
 trie* newnode=new trie();
 for(int i=0;i<26;i++)
 newnode->children[i]=NULL;
 newnode->isendofword=false;
 return newnode;
}
void insert(trie* root,string s)
{
    trie* curr=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(curr->children[index]==NULL)
        curr->children[index]=createnode();
        curr=curr->children[index];
    }
    curr->isendofword=true;
}
bool search(trie* root,string s)
{
    bool flag=0;
    trie* curr=root;
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        if(curr->children[index]!=NULL)
        curr=curr->children[index];
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    return false;
   return (curr->isendofword);
}
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    trie* root = createnode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}
