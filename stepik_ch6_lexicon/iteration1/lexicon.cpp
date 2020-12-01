#include "lexicon.hpp"
#include <algorithm>

bool Lexicon::find(std::string word)
{
    return std::find(ll.begin(), ll.end(), word) != ll.end();
}

void Lexicon::insert(std::string word)
{
    if (!find(word))
    {
        ll.push_back(word);
    }
}

void Lexicon::remove(std::string word)
{
    ll.remove(word);
}

int Lexicon::size(){
    return ll.size();
}