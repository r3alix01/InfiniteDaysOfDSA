#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> splitWords(string sentence) {
        string temp;
        vector<string> arr;
        stringstream ss(sentence); // convert sentence to words

        // taking each word and putting it into a vector.
        while (ss >> temp) {
            arr.push_back(temp);
        }

        return arr;
    }

    // tc : O(3n)
    // not the very optimal code.
    // since it is of "easy" category so not bothering much.
    bool wordPattern(string pattern, string s) {
        int patlen = pattern.size();

        vector<string> words = splitWords(s);
        // since each char must associate with each word so diff len then return false.
        if (words.size() != patlen)
            return false;

        unordered_map<char, string> map;
        unordered_map<string, char> map2;

        // char -> word.
        for (int i = 0; i < words.size(); i++) {
            char key = pattern[i];
            string word = words[i];

            auto it = map.find(key);
            // if it does not exists.
            if (it == map.end()) {
                map[key] = word;
            } else {
                // if the key already exists.
                if (it->second != word)
                    return false;
            }
        }

        // word -> char
        for (int i = 0; i < words.size(); i++) {
            string key = words[i];
            char val = pattern[i];

            auto it = map2.find(key);
            // if it does not exists.
            if (it == map2.end()) {
                map2[key] = val;
            } else {
                // if the key already exists.
                if (it->second != val)
                    return false;
            }
        }
        // if there are all words the same then also using the two map concept helps.
        /*
        example:
        a b b a
        dog dog dog dog

        In map 1:
        a -> dog
        b -> dog

        In map 2:
        dog -> a/b

        which is handled. but simply using the one map does not work in this case.
        */
        if (map.size() != map2.size())
            return false;
        return true;
    }
};

int main() {
    Solution mySolution;
    string pattern = "abba";
    string s = "dog dog dog dog";
    cout << mySolution.wordPattern(pattern, s) << endl;
}