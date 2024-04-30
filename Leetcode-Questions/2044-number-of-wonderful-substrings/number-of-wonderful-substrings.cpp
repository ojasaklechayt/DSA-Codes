// Initial Code 

// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         vector<string> substrings = getAllString(word);
//         long long count = 0;

//         for (const string& substring : substrings) {
//             if (wonderful(substring)) {
//                 count++;
//             }
//         }

//         return count;
//     }

// private:
//     vector<string> getAllString(string word) {
//         vector<string> substrings;
//         for (int i = 0; i < word.size(); i++) {
//             for (int j = i; j < word.size(); j++) {
//                 substrings.push_back(word.substr(i, j - i + 1));
//             }
//         }
//         return substrings;
//     }

//     bool wonderful(string substring) {
//         unordered_map<char, int> freq;
//         for (char c : substring) {
//             freq[c]++;
//         }

//         int oddCount = 0;
//         for (auto it : freq) {
//             if (it.second % 2 != 0) {
//                 oddCount++;
//             }
//         }

//         if (oddCount <= 1) {
//             return true;
//         }

//         return false;
//     }
// };

// Improved Code

// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         return getAllString(word, 0);
//     }

// private:
//     long long getAllString(string word, long long count) {
//         for (int i = 0; i < word.size(); i++) {
//             for (int j = i; j < word.size(); j++) {
//                 if(wonderful(word.substr(i, j - i + 1))){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//     bool wonderful(string substring) {
//         unordered_map<char, int> freq;
//         for (char c : substring) {
//             freq[c]++;
//         }

//         int oddCount = 0;
//         for (auto it : freq) {
//             if (it.second % 2 != 0) {
//                 oddCount++;
//             }
//         }

//         if (oddCount <= 1) {
//             return true;
//         }

//         return false;
//     }
// };


// Further Improved Code
// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         // Initialize a counter to keep track of the number of "wonderful" substrings
//         long long count = 0;

//         // Outer loop iterates over each character in the string
//         for(int i=0; i<word.size(); i++){
//             // For each character, initialize a new frequency map and an oddCount variable
//             unordered_map<char,int> freq;
//             int oddCount = 0;

//             // Inner loop iterates from the current character to the end of the string
//             for(int j=i; j<word.size(); j++){
//                 // As the inner loop iterates, it updates the frequency map
//                 freq[word[j]]++;

//                 // If the frequency of the current character is even, decrement oddCount
//                 // This is because the character's frequency was odd before incrementing it
//                 if(freq[word[j]]%2==0){
//                     oddCount--;
//                 } else {
//                     // If the frequency of the current character is odd, increment oddCount
//                     // This is because the character's frequency was even before incrementing it
//                     oddCount++;
//                 }

//                 // If oddCount is less than or equal to 1, increment count
//                 // This is because a "wonderful" string can contain at most one character with an odd frequency
//                 if(oddCount<=1){
//                     count++;
//                 }
//             }
//         }

//         // Return the total count of "wonderful" substrings
//         return count;
//     }
// };


// Most Optimised Solution
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0);
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;

        for (char ch : word) {
            int charIndex = ch - 'a';
            prefixXor ^= 1 << charIndex;
            result += count[prefixXor];
            for (int i = 0; i < 10; i++) {
                result += count[prefixXor ^ (1 << i)];
            }
            count[prefixXor]++;
        }

        return result;
    }
};