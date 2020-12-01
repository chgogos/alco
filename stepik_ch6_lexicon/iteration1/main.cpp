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

    //1. ανάγνωση λέξεων
    auto start = std::chrono::high_resolution_clock::now();
    Lexicon lexicon;
    lexicon.read_corpus(filename);
    cout << "READ FILE: #words=" << lexicon.size() << endl;
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = finish - start;
    std::cout << "Time passed: " << duration.count() << " seconds" << std::endl;
    std::cout << "##########################################################" << std::endl;

    //2. τυχαία επιλογή N λέξεων
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Create set of " << N << " values for find/remove/insert" << std::endl;
    vector<string> words(std::begin(lexicon.get_data()), std::end(lexicon.get_data())); // για την επιλογή τυχαίων λέξεων
    auto rng = std::default_random_engine{};
    std::shuffle(begin(words), end(words), rng);
    words.resize(N);
    for (size_t i = 0; i < words.size(); i++)
    {
        if (i % 2 == 0)
        {
            std::shuffle(begin(words[i]), end(words[i]), rng);
        }
    }
    finish = std::chrono::high_resolution_clock::now();
    duration = finish - start;
    std::cout << "Time passed: " << duration.count() << " seconds" << std::endl;
    std::cout << "##########################################################" << std::endl;

    //3.  αναζήτηση N λέξεων (find)
    start = std::chrono::high_resolution_clock::now();
    int successes = 0;
    int fails = 0;
    for (int i = 0; i < N; i++)
    {
        if (lexicon.find(words[i]))
        {
            successes++;
        }
        else
        {
            fails++;
        }
    }
    std::cout << "FIND: SUCCESSES=" << successes << " FAILS=" << fails << std::endl;
    finish = std::chrono::high_resolution_clock::now();
    duration = finish - start;
    std::cout << "Time passed: " << duration.count() << " seconds" << std::endl;
    std::cout << "##########################################################" << std::endl;

    // 4. Ν διαγραφές (remove)
    start = std::chrono::high_resolution_clock::now();
    for (string s : words)
    {
        lexicon.remove(s);
    }
    std::cout << "REMOVE: #words in lexicon=" << lexicon.size() << std::endl;
    finish = std::chrono::high_resolution_clock::now();
    duration = finish - start;
    std::cout << "Time passed: " << duration.count() << " seconds" << std::endl;
    std::cout << "##########################################################" << std::endl;

    // 5. Ν εισαγωγές (insert)
    start = std::chrono::high_resolution_clock::now();
    for (string s : words)
    {
        lexicon.insert(s);
    }
    std::cout << "INSERT: #words in lexicon=" << lexicon.size() << std::endl;
    finish = std::chrono::high_resolution_clock::now();
    duration = finish - start;
    std::cout << "Time passed: " << duration.count() << " seconds" << std::endl;
}