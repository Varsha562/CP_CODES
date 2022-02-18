class AutocompleteSystem {
public:
    //trie+hashmap+pq
    struct trie{
        struct trie* children[27];
        map<string,int>m;
    };
    static bool comp(pair<int,string>&p1,pair<int,string>&p2)
    {
       if(p1.first==p2.first)
       {
           return p1.second>p2.second;
       }
        return p1.first<p2.first;
    }
    string str;
    struct trie* create(void)
    {
        struct trie* new_node=new trie();
        for(int i=0;i<27;i++)
        {
            new_node->children[i]=NULL;
        }
        return new_node;
    }
    struct trie* x=create();
    struct trie* search_str=x;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        str="";
        for(int i=0;i<sentences.size();i++)
        {
            struct trie* curr=x;
            if(curr->m.find(sentences[i])==curr->m.end())
            {
            for(int j=0;j<sentences[i].size();j++)
            {
                curr->m[sentences[i]]=times[i];
                if(sentences[i][j]==' ' && curr->children[0]==NULL)
                {
                   curr->children[0]=create();
                }
                else
                if(sentences[i][j]!=' '  && curr->children[(int)sentences[i][j]-96]==NULL)
                {
                   curr->children[(int)sentences[i][j]-96]=create();
                }
                curr=(sentences[i][j]==' ') ?  curr->children[0] : curr->children[(int)sentences[i][j]-96];
            }
            curr->m[sentences[i]]=times[i];
            }
            else
            {
                for(int j=0;j<sentences[i].size();j++)
                {
                    curr->m[sentences[i]]+=times[i];
                    curr=(sentences[i][j]==' ') ?  curr->children[0] : curr->children[(int)sentences[i][j]-96];
                }
                curr->m[sentences[i]]+=times[i];
            }
        }
    }
    
    vector<string> input(char c) {
        vector<string>res;
        if(c=='#')
        {
            struct trie* curr=x;
            if(curr->m.find(str)==curr->m.end())
            {
               for(int i=0;i<str.size();i++)
               {
                   curr->m[str]=1;
                   //cout<<curr->m.size()<<"a\n";
                   curr=(str[i]!=' ') ? curr->children[str[i]-96] : curr->children[0];
               }
                curr->m[str]=1;
                //cout<<curr->m.size()<<"a\n";
            }
            else
            {
               for(int i=0;i<str.size();i++)
               {
                   curr->m[str]++;
                   //cout<<curr->m.size()<<"b\n";
                   curr=(str[i]!=' ') ? curr->children[str[i]-96] : curr->children[0];
               }
                curr->m[str]++;
                //cout<<curr->m.size()<<"b\n";
            }
            str="";
            search_str=x;
            return res;
        }
        str+=c;
        if(c==' ')
        {
            if(search_str->children[0]==NULL)
            {
               search_str->children[0]=create();
            }
            search_str=search_str->children[0];
            vector<pair<int,string>>v;
            for(auto ch: search_str->m)
            {
                //cout<<x.first<<"\n";
                v.push_back({ch.second,ch.first});
            }
            sort(v.begin(),v.end(),comp);
            if(!v.empty())
            {
                res.push_back(v.back().second);
                v.pop_back();
            }
            if(!v.empty())
            {
                res.push_back(v.back().second);
                v.pop_back();
            }
            if(!v.empty())
            {
                res.push_back(v.back().second);
                v.pop_back();
            }
            return res;
        }
        else
        {
            if(search_str->children[(int)c-96]==NULL)
            {
               search_str->children[(int)c-96]=create();
            }
            search_str=search_str->children[(int)c-96];
            vector<pair<int,string>>v;
            for(auto ch: search_str->m)
            {
                //cout<<x.first<<"\n";
                v.push_back({ch.second,ch.first});
            }
            sort(v.begin(),v.end(),comp);
            if(!v.empty())
            {
                res.push_back(v.back().second);
                v.pop_back();
            }
            if(!v.empty())
            {
                res.push_back(v.back().second);
                v.pop_back();
            }
            if(!v.empty())
            {
                res.push_back(v.back().second);
                v.pop_back();
            }
            return res;
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
