#include <list>
#include <string>

class Lexicon
{
    std::list<std::string> ll;
public:
    bool find(std::string word);
    void insert(std::string word);
    void remove(std::string word);
    int size();
};