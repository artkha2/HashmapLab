#include <string>
#include <iostream>
#include <unordered_map>
#include <cctype>  // for converting to lowercase and removing whitespace
#include <vector>
#include <cassert>

using namespace std;
using Map = unordered_map<char, int>;

bool can_create_note(string note, vector<string> articles){
    Map note_chars, article_chars;
    
    // Create a character frequency map for the note
    for(char c : note){
        if (!isspace(c)) {
            c = tolower(c);
            note_chars[c]++;
        }
    }

    // Create a character frequency map for the articles
    for(const string& str : articles){
        for(char c : str){
            if (!isspace(c)) {
                c = tolower(c);
                article_chars[c]++;
            }
        }
    }

    // Compare the 2 frequency maps
    // If there are fewer instances of that character available in articles than needed for the note, return false
    for (const auto& [ch, count] : note_chars) {
        if (article_chars[ch] < count) {
            return false;
        }
    }

    return true;
}

// Test cases
void run_tests() {
    // Format: note, articles, expected_result

    assert(can_create_note("a", {"a"}) == true);
    assert(can_create_note("a", {"ab"}) == true);
    assert(can_create_note("a", {"a", "b"}) == true);
    assert(can_create_note("abc", {"a", "b", "c"}) == true);
    assert(can_create_note("The bird is red!", {"I write a lot.", "To and fro.", "Here be deadly dragons!"}) == true);

    assert(can_create_note("a", {"b"}) == false);
    assert(can_create_note("a", {"bc"}) == false);
    assert(can_create_note("a", {"b", "c"}) == false);
    assert(can_create_note("abc", {"a", "b", "d"}) == false);
    assert(can_create_note("The bird is red", {"I write a lot.", "To and fro."}) == false);
    assert(can_create_note("The bird is red!", {"I write a lot.", "To and fro.", "Here be deadly dragons"}) == false);

    cout << "All test cases passed!" << endl;
}

int main() {
    run_tests();
    return 0;
}




