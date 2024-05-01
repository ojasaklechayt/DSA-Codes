class Solution {
public:
    // Function to reverse the prefix of a word up to a given character 'ch'
    string reversePrefix(string word, char ch) {
        string stringlet; // This will hold the result

        // Find the first occurrence of 'ch' in 'word'
        size_t pos = word.find(ch);

        // Check if 'ch' is found in the string
        if (pos != string::npos) {
            int i = 0; // Initialize a counter 'i' to iterate over the string

            // Iterate over the string until 'ch' is found
            while (i < word.size()) {
                // If the current character is 'ch', add it to 'stringlet' and break the loop
                if (word[i] == ch) {
                    stringlet = word[i] + stringlet;
                    break;
                } else {
                    // If it's not 'ch', add the current character to the front of 'stringlet'
                    stringlet = word[i] + stringlet;
                }
                i++; // Increment the counter
            }

            // Continue adding the rest of the characters in 'word' to 'stringlet' after 'ch'
            for (int j = i + 1; j < word.size(); j++) {
                stringlet += word[j];
            }
        } else {
            // If 'ch' is not found, return the original word
            return word;
        }

        // Return the modified string with the prefix reversed
        return stringlet;
    }
};
