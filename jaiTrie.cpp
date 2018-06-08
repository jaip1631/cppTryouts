#include "jaiTrie.h"
#include <stack>

TrieNode::TrieNode() : endsHere(false), arr(ALPHABETS, NULL)
{
}

TrieNode::~TrieNode()
{
    for(int i = 0; i < arr.size(); i++)
        delete arr[i];
}

Trie::Trie() : root(NULL)
{
}

Trie::~Trie()
{
    deleteDictionary();
}

void Trie::deleteDictionaryUtil(TrieNode *&cur)
{
    for(int i = 0; i < ALPHABETS; i++)
    {
        if(cur->arr[i])
        {
            deleteDictionaryUtil(cur->arr[i]);
        }
    }

    delete cur;
    cur = NULL;
}

void Trie::deleteDictionary()
{
    if(root == NULL)
        return;

    deleteDictionaryUtil(root);
}

bool TrieNode::isEmpty()
{
    if(endsHere == true)
        return false;

    for(int i = 0; i < ALPHABETS; i++)
        if(arr[i] != NULL)
            return false;
    
    return true;
}

void Trie::addWord(const string &str)
{
    if(root == NULL)
        root = new TrieNode();
    
    TrieNode *cur = root;

    for(int i = 0; i < str.size(); i++)
    {
        if(!cur->arr[str[i]-'A'])
            cur->arr[str[i]-'A'] = new TrieNode();
        cur = cur->arr[str[i]-'A'];
    }
    cur->endsHere = true;
}

bool Trie::prefixExists(const string &str)
{
    if(str.empty())
        return true;
    
    TrieNode *cur = root;

    for(int i = 0; cur != NULL && i < str.size(); i++)
    {
        cur = cur->arr[str[i]-'A'];
    }
    if(cur == NULL)
        return false;

    return true;
}

bool Trie::wordExists(const string &str)
{
    if(str.empty())
        return true;
    
    TrieNode *cur = root;

    for(int i = 0; cur != NULL && i < str.size(); i++)
    {
        cur = cur->arr[str[i]-'A'];
    }
    if(cur == NULL)
        return false;

    return cur->endsHere;
}

bool Trie::deleteWord(const string &str)
{
    // if(!wordExists)
    //     return false;
    
    if(root == NULL)
        return false;
    
    stack<TrieNode **> wordStack;
    wordStack.push(&root);
    TrieNode *cur = root, **topTrieNode = NULL;
    
    for(int i = 0; cur != NULL && i < str.size(); i++)
    {
        wordStack.push(&(cur->arr[str[i]-'A']));
        cur = cur->arr[str[i]-'A'];
    }
    if(cur == NULL)
        return false;

    topTrieNode = wordStack.top();

    if((*topTrieNode)->endsHere == false)
        return false;

    (*topTrieNode)->endsHere = false;
    while((*topTrieNode)->isEmpty())
    {
        delete (*topTrieNode);
        (*topTrieNode) = NULL;
        wordStack.pop();
        topTrieNode = wordStack.top();
    }

    return true;
}

bool Trie::deleteWordRecUtil(const string &str, int i, TrieNode *&cur)
{
    if(cur == NULL)
        return false;
    
    bool deleted = true;
    if(i < str.size())
        deleted = deleteWordRecUtil(str, i+1, cur->arr[str[i]-'A']);

    if(i == str.size())
    {
        if(cur->endsHere == false)
            return false;
        cur->endsHere = false;
    }
    
    if(cur->isEmpty())
    {
        delete cur;
        cur = NULL;
    }
    return deleted;
}

bool Trie::deleteWordRec(const string &str)
{
    // if(!wordExists)
    //     return false;
    
    if(root == NULL)
        return false;
    
    return deleteWordRecUtil(str, 0, root);
}

void Trie::getWords(TrieNode * cur, vector<string> &words, string &curWord)
{
    if(cur == NULL)
        return;
    
    if(cur->endsHere)
        words.push_back(curWord);

    for(int i = 0; i < ALPHABETS; i++)
    {
        if(cur->arr[i])
        {
            curWord.push_back(i+'A');
            getWords(cur->arr[i], words, curWord);
            curWord.pop_back();
        }
    }
}

vector<string> Trie::getTrieWords()
{
    vector<string> words;
    string curWord;
    
    getWords(root, words, curWord);

    return words;
}
