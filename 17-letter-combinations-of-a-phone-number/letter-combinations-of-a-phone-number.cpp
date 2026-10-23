
class Solution {
private:
    void solve(int index, string output, string mapping[],
               string digits, vector<string>& ans) {

        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(index + 1, output, mapping, digits, ans);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.length() == 0) {
            return ans;
        }

        string output = "";
        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, output, mapping, digits, ans);

        return ans;
    }
};
