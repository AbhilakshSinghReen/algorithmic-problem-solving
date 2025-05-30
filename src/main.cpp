#include <iostream>

#include "data_structures/trie.h"

using namespace std;

int main() {
    Trie trie = Trie();

    trie.insert("hello");
    trie.insert("goodbye");
    trie.insert("goodday");

    cout << trie.search("hello") << "    [1] \n";
    cout << trie.search("bye") << "    [2] \n";
    cout << trie.startsWith("hel") << "    [3] \n";

    cout << "Delete success: " << trie.deleteWord("hello") << "    [3] \n";
    cout << "Delete success: " << trie.deleteWord("doesnotexist") << "    [4] \n";
    cout << trie.search("hello") << "    [5] \n";
    cout << trie.startsWith("hel") << "    [6] \n";

    cout << trie.search("good") << "    [7] \n";
    cout << trie.search("goodbye") << "    [7.1] \n";
    cout << trie.startsWith("go") << "    [8] \n";
    cout << "Delete success: " << trie.deleteWord("goodbye") << "    [9] \n";

    trie.insert("cplusplus");
    cout << trie.search("cpluscplusplus") << "    [10] \n";
    cout << trie.search("cplusplus") << "    [11] \n";
    cout << trie.search("cplusplu") << "    [12] \n";
    cout << trie.startsWith("cplusplusp") << "    [13] \n";

    return 0;
}
