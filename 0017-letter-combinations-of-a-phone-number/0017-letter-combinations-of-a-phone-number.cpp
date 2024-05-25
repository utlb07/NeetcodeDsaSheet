
  class Solution {
public:
    vector<string> answer;
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};



    void recursionTree(string digits, string & temp, int index) {
        if (index == digits.size()) {
            answer.push_back(temp);
            return;
        }

        string curr_value = keypad[digits[index]- '0'];
        for (int i = 0; i < curr_value.size(); i++) {
            temp.push_back(curr_value[i]);
            recursionTree(digits, temp, index+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        
        string temp;
        recursionTree(digits, temp, 0);
        return answer;
    }
  };