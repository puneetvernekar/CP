class WordDictionary {
    vector<WordDictionary*>dict;
    bool end;
public:
    WordDictionary():end(false) {
        dict=vector<WordDictionary*>(26,nullptr);
    }
    
    void addWord(string word) {
        WordDictionary *cur=this;
        for(char c:word)
        {
            if(cur->dict[c-'a']==nullptr)
            cur->dict[c-'a']= new WordDictionary();
            cur=cur->dict[c-'a'];
        }
        cur->end=true;
    }
    
    bool search(string word) {
        WordDictionary *cur=this;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(ch=='.')
            {
                for(auto c: cur->dict)
                {
                    if(c && c->search(word.substr(i+1)))
                    return true;
                }
                return false;
            }
            else if(cur->dict[ch-'a']==nullptr)
            return false;
            cur=cur->dict[ch-'a'];
        }
        return cur && cur->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */