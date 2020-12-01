#include <iostream>
#include "lexicon.hpp"
#include <algorithm>
#include <fstream>

void Lexicon::read_corpus(std::string fn)
{
    std::ifstream infile(fn);
    if (infile.fail())
    {
        std::cerr << "File named " << fn << " did not open successfully." << std::endl;
        exit(-1);
    }
    std::string s;
    while (infile >> s)
    {
        ll.emplace_back(s);
    }
}

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

int Lexicon::size()
{
    return ll.size();
}

std::list<std::string> &Lexicon::get_data()
{
    return ll;
}