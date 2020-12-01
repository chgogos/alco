# A Lexicon ADT

ADT operations

* find
* insert
* remove

## Data

* [wordlist.10000](https://www.mit.edu/~ecprice/wordlist.10000) 10000 words
* [http://www.gwicks.net/dictionaries.htm](./engmix.txt) 84099 words
* [english-words](https://github.com/dwyl/english-words)
  * [words_alpha.txt](https://github.com/dwyl/english-words/blob/master/words_alpha.txt) 370103 words


## Using a linked list

* [lexicon.hpp](./iteration1/lexicon.hpp)
* [lexicon.cpp](./iteration1/lexicon.cpp)
* [main.cpp](./iteration1/main.cpp)

Μεταγλώττιση

    $ cd iteration1
    $ g++ lexicon.cpp main.cpp -o lexicon -std=c++17 -Wall

Εκτέλεση

    $ lexicon.exe ../wordlist.10000.txt 5000
    INSERT: #words= 10000
    Time passed: 0.728024
    FIND: SUCCESSES=2687 FAILS=2313
    Time passed: 0.537
    REMOVE: #remaining words=7334
    Time passed: 0.573018


    $ lexicon.exe ../engmix.txt 5000
    INSERT: #words= 84099
    Time passed: 53.37
    FIND: SUCCESSES=2529 FAILS=2471
    Time passed: 4.92
    REMOVE: #remaining words=81570
    Time passed: 5.81903


    $ lexicon.exe ../words_alpha.txt 50000
    INSERT: #words= 370103
    Time passed: 1686.31
    FIND: SUCCESSES=25179 FAILS=24821
    Time passed: 365.318
    REMOVE: #remaining words=344932
    Time passed: 443.286