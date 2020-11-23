struct trie{
    trie* next[26];
    bool isword;
    trie()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
        isword=false;
    }
};
​
class trieNode{
    trie dummy;
    trie* root;
    public:
    trieNode()
    {
        root=new trie();
    }
    void insert(string s)
    {
        trie* curr=root;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(curr->next[s[i]-'a']==NULL)
            {
                curr->next[s[i]-'a']=new trie();
            }
            curr=curr->next[s[i]-'a'];
        }
        curr->isword=true;
    }
    bool isPrefix(string s)
    {
        trie* curr=root;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(curr->next[s[i]-'a']==NULL)
                return false;
            if(curr->next[s[i]-'a']->isword==false)
                return false;
            curr=curr->next[s[i]-'a'];
        }
        return true;
    }
};
​
class Solution {
public:
    string longestWord(vector<string>& words) {
     
        trieNode* t=new trieNode();
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            t->insert(words[i]);
        }
        
        int length=0;
        string str="";
        
        for(int i=0;i<n;i++)
        {
