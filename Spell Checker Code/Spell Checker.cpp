#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#include <ctime>

using namespace std;

/* ================= UTIL ================= */
string toLowerCase(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

/* ================= TRIE ================= */
struct TrieNode {
    bool isEnd;
    TrieNode* child[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    void collectWords(TrieNode* node, string current, vector<string>& result) {
        if (!node) return;

        if (node->isEnd)
            result.push_back(current);

        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                char nextChar = 'a' + i;
                collectWords(node->child[i], current + nextChar, result);
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insertWord(string word) {
        word = toLowerCase(word);
        TrieNode* cur = root;
        for (char c : word) {
            if (c < 'a' || c > 'z') continue;
            int idx = c - 'a';
            if (!cur->child[idx])
                cur->child[idx] = new TrieNode();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }

    bool searchWord(string word) {
        word = toLowerCase(word);
        TrieNode* cur = root;
        for (char c : word) {
            if (c < 'a' || c > 'z') return false;
            int idx = c - 'a';
            if (!cur->child[idx])
                return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }

    vector<string> getAllWords() {
        vector<string> result;
        collectWords(root, "", result);
        sort(result.begin(), result.end());
        return result;
    }

    vector<string> autoComplete(string prefix) {
        prefix = toLowerCase(prefix);
        TrieNode* cur = root;
        for (char c : prefix) {
            if (c < 'a' || c > 'z') return {};
            int idx = c - 'a';
            if (!cur->child[idx])
                return {};
            cur = cur->child[idx];
        }

        vector<string> result;
        collectWords(cur, prefix, result);
        return result;
    }
};

/* ================= MAIN ================= */
int main() {
    srand(time(0));

    Trie trie;
    map<string,int> wordFrequency;

    vector<string> words = {
        "hello","world","computer","science","program","programming",
        "language","algorithm","data","structure","tree","graph",
        "stack","queue","array","string","integer","float","double",
        "boolean","class","object","function","variable","constant",
        "loop","condition","compile","execute","memory","pointer",
        "reference","dynamic","static","virtual","template","library",
        "debug","error","exception","input","output","file","stream"
    };

    for (auto& w : words)
        trie.insertWord(w);

    int choice;
    string lastWord;
    bool hasWord = false;

    while (true) {
        cout << "\n=================================\n";
        cout << "       SMART SPELL CHECKER \n";
        cout << "=================================\n";
        cout << "1. Check word\n";
        cout << "2. Auto-complete\n";
        cout << "3. Add new word\n";
        cout << "4. Show all dictionary words\n";
        cout << "5. Show statistics\n";
        cout << "6. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter word: ";
            cin >> lastWord;
            lastWord = toLowerCase(lastWord);
            hasWord = true;
            wordFrequency[lastWord]++;

            if (trie.searchWord(lastWord))
                cout << "✅ Correct spelling!\n";
            else
                cout << "❌ Misspelled!\n";
        }

        else if (choice == 2) {
            string prefix;
            cout << "Enter prefix: ";
            cin >> prefix;

            vector<string> results = trie.autoComplete(prefix);

            if (results.empty())
                cout << "No words found.\n";
            else {
                cout << "Auto-complete results:\n";
                for (auto& r : results)
                    cout << "- " << r << "\n";
            }
        }

        else if (choice == 3) {
            string newWord;
            cout << "Enter new word: ";
            cin >> newWord;
            newWord = toLowerCase(newWord);

            trie.insertWord(newWord);
            cout << "Word added successfully ✅\n";
        }

        else if (choice == 4) {
            vector<string> allWords = trie.getAllWords();

            cout << "\nDictionary Words (" 
                 << allWords.size() << " words):\n";

            for (auto& w : allWords)
                cout << "- " << w << "\n";
        }

        else if (choice == 5) {
            cout << "\nSearch statistics:\n";
            for (auto& p : wordFrequency)
                cout << p.first << " : "
                     << p.second << " times\n";
        }

        else if (choice == 6) {
            cout << "Exit program 👋\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}