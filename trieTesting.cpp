#include <iostream>
#include "jaiTrie.h"
using namespace std;



int main(int argc, char const *argv[])
{
    Trie dictionary;

    dictionary.printDictionary();

    dictionary.addWord("JAI");
    dictionary.addWord("JAYANTI");
    dictionary.addWord("JAYAN");
    dictionary.addWord("JAY");
    dictionary.addWord("JAIGAN");
    dictionary.addWord("PRAKASH");
    
    dictionary.printDictionary();

    string findWord = "JAI";
    if(dictionary.wordExists(findWord))
        cout<<findWord<<" exists"<<endl;
    
    dictionary.printDictionary();
    findWord = "JAIG";
    if(dictionary.wordExists(findWord))
        cout<<findWord<<" exists"<<endl;
    else
        cout<<findWord<<" do not exists"<<endl;
    
    
    dictionary.printDictionary();
    findWord = "ABS";
    if(dictionary.wordExists(findWord))
        cout<<findWord<<" exists"<<endl;
    else
        cout<<findWord<<" do not exists"<<endl;
    
    
    dictionary.printDictionary();
    findWord = "JAYANTI";
    if(dictionary.deleteWord(findWord))
        cout<<findWord<<" deleted"<<endl;
    else
        cout<<findWord<<" not deleted"<<endl;

    dictionary.printDictionary();
    
    findWord = "JAY";
    if(dictionary.deleteWordRec(findWord))
        cout<<findWord<<" deleted"<<endl;
    else
        cout<<findWord<<" not deleted"<<endl;
    dictionary.printDictionary();

    findWord = "JAY";
    if(dictionary.deleteWordRec(findWord))
        cout<<findWord<<" deleted"<<endl;
    else
        cout<<findWord<<" not deleted"<<endl;
    dictionary.printDictionary();

    // findWord = "JAYAN";
    // if(dictionary.deleteWordRec(findWord))
    //     cout<<findWord<<" deleted"<<endl;
    // else
    //     cout<<findWord<<" not deleted"<<endl;
    // dictionary.printDictionary();

    // findWord = "PRAKASH";
    // if(dictionary.deleteWordRec(findWord))
    //     cout<<findWord<<" deleted"<<endl;
    // else
    //     cout<<findWord<<" not deleted"<<endl;
    // dictionary.printDictionary();

    // findWord = "JAI";
    // if(dictionary.deleteWordRec(findWord))
    //     cout<<findWord<<" deleted"<<endl;
    // else
    //     cout<<findWord<<" not deleted"<<endl;
    // dictionary.printDictionary();

    // findWord = "JAIGAN";
    // if(dictionary.deleteWordRec(findWord))
    //     cout<<findWord<<" deleted"<<endl;
    // else
    //     cout<<findWord<<" not deleted"<<endl;
    // dictionary.printDictionary();

    dictionary.deleteDictionary();
    dictionary.printDictionary();
    return 0;
}