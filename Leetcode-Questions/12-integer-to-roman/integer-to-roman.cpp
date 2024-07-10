class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int a, b, c, d;

        a = num / 1000;
        b = (num % 1000) / 100;
        c = (num % 100) / 10;
        d = num % 10;

        // Process thousands place
        for (int i = 0; i < a; i++) {
            roman += "M";
        }

        // Process hundreds place
        if (b == 9) {
            roman += "CM";
        } else if (b >= 5) {
            roman += "D";
            for (int i = 0; i < b - 5; i++) {
                roman += "C";
            }
        } else if (b == 4) {
            roman += "CD";
        } else {
            for (int i = 0; i < b; i++) {
                roman += "C";
            }
        }

        // Process tens place
        if (c == 9) {
            roman += "XC";
        } else if (c >= 5) {
            roman += "L";
            for (int i = 0; i < c - 5; i++) {
                roman += "X";
            }
        } else if (c == 4) {
            roman += "XL";
        } else {
            for (int i = 0; i < c; i++) {
                roman += "X";
            }
        }

        // Process ones place
        if (d == 9) {
            roman += "IX";
        } else if (d >= 5) {
            roman += "V";
            for (int i = 0; i < d - 5; i++) {
                roman += "I";
            }
        } else if (d == 4) {
            roman += "IV";
        } else {
            for (int i = 0; i < d; i++) {
                roman += "I";
            }
        }

        return roman;
    }
};
