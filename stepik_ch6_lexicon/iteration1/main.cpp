#include <iostream>
#include "lexicon.hpp"
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    string filename = "..\\wordlist.10000.txt"; // 10000 words
    // string filename = "..\\engmix.txt"; // 84099 words
    // string filename = "..\\words_alphas.txt"; // 370103 words
    int N = 10000; // αριθμός αναζητήσεων, διαγραφών

    if (argc == 3)
    {
        filename = argv[1];
        N = atoi(argv[2]);
    }

    vector<string> words; // για την επιλογή τυχαίων λέξεων
    auto start = std::chrono::high_resolution_clock::now();

    //1. ανάγνωση λέξεων
    Lexicon lexicon;
    std::ifstream infile(filename);
    if (infile.fail())
    {
        cout << "File named " << filename << " did not open successfully." << endl;
    }
    string s;
    int c = 0;
    while (infile >> s)
    {
        words.push_back(s);
        lexicon.insert(s);
        c++;
    }
    cout << "INSERT: #words= " << c << endl;
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = finish - start;
    std::cout << "Time passed: " << duration.count() << std::endl;

    //τυχαία επιλογή N λέξεων
    auto rng = std::default_random_engine{};
    std::shuffle(begin(words), end(words), rng);
    words.resize(N);
    for (size_t i = 0; i < words.size(); i++)
    {
        if (i % 2 == 0)
            std::shuffle(begin(words[i]), end(words[i]), rng);
    }

    //2.  αναζήτηση N λέξεων
    start = std::chrono::high_resolution_clock::now();
    int successes = 0;
    int fails = 0;
    for (int i = 0; i < N; i++)
    {
        if (lexicon.find(words[i]))
            successes++;
        else
            fails++;
    }
    std::cout << "FIND: SUCCESSES=" << successes << " FAILS=" << fails << std::endl;
    finish = std::chrono::high_resolution_clock::now();
    duration = finish - start;
    std::cout << "Time passed: " << duration.count() << std::endl;

    // 3. Ν διαγραφές
    start = std::chrono::high_resolution_clock::now();
    for (string s : words)
    {
        lexicon.remove(s);
    }
    std::cout << "REMOVE: #remaining words=" << lexicon.size() << std::endl;
    finish = std::chrono::high_resolution_clock::now();
    duration = finish - start;
    std::cout << "Time passed: " << duration.count() << std::endl;
}