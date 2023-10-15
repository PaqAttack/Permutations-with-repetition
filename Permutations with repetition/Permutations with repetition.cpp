// Permutations with repetition.cpp
//

#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main()
{
    // create a map (set-type data structure)
    std::map<char, int> word_map;
    std::map<char, int>::iterator itr;

    // pick a word to look at
    std::string word = "MISSISSIPPI";
    int word_len = word.size();

    // set up variables to hold the final data
    std::string top = std::to_string(word_len).append("!");
    std::string bottom;

    // iterate over the word and place characters in the map retaining quanity of each one.
    for (int i = 0; i < word.size(); i++) {
        word_map[word.at(i)]++;
    }

    // first part of output
    std::cout << "For the " << word_len << " letter word " << word << ", there are:\n";

    // This iterates through the map to displays the process similar to Participation activity 5.8.1
    for (itr = word_map.begin(); itr != word_map.end(); ++itr) {
        // word_len is repurposed from here down to show the remaining number of positions 
        // available (or complement).
        std::cout << word_len << "!/" << itr->second << "! choices to place \"" << itr->first << "\"s\n";

        // This prepares data for the final combined formula. Its just a bit simpler to collect 
        // it here rather than iterate through the array again to get it.
        bottom = bottom + "(" + std::to_string(itr->second) + "!)";

        // Reduce the number of available positions for the next iteration.
        word_len -= itr->second;
    }

    // generate output.
    std::cout << "\nThis gives you (" << top << ")";

    // This handles situations where there are no repetitions. We cant be dividing by 0 in here!
    if (bottom.size() > 0) {
        std::cout << " / " << bottom;
    }
    std::cout << " ways to scramble " << word << ".\n\n";

}

