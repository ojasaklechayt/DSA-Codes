class Solution {
public:
    string countAndSay(int n) {
        string st = "1";
        int i = 1;
        while(i<n){
            st = rle(st);
            i++;
        }

        return st;
    }

private:
    string rle(string st){
        string result = "";
        int count = 1;
        for(int i=1; i<st.size(); i++){
            if(st[i] == st[i-1]){
                ++count;
            } else {
                result+=to_string(count)+st[i-1];
                count=1;
            }
        }

        result+=to_string(count)+st.back();
        return result;
    }
};