#include <list>
#include <string>

class Lexicon
{
    std::list<std::string> ll;

public:
    void read_corpus(std::string fn);
    bool find(std::string word);
    void insert(std::string word);
    void remove(std::string word);
    int size();
    std::list<std::string> &get_data();
};