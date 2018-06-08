#include <iostream>
#include <string>
#include <vector>
using namespace std;


#define ALPHABETS 127

class TrieNode
{
public:
    bool endsHere;
    vector<TrieNode *> arr;
    bool isEmpty();
    TrieNode();
    ~TrieNode();
};

class Trie
{
private:
    TrieNode * root;
    bool deleteWordRecUtil(const string &str, int i, TrieNode * &cur);
    void deleteDictionaryUtil(TrieNode *&cur);
    void getWords(TrieNode *cur, vector<string> &words, string &curWord);
public:
    Trie();
    ~Trie();
    void deleteDictionary();
    bool prefixExists(const string &str);
    bool wordExists(const string &str);
    void addWord(const string &str);
    bool deleteWord(const string &str);
    bool deleteWordRec(const string &str);
    vector<string> getTrieWords();
};