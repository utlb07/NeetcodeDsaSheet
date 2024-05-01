class Solution {
public:
    string reversePrefix(string word, char ch) {
        int id=-1;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]==ch)
            {
                id=i;
                break;
            }
        }
        if(id==-1)
        {
            return word;
        }
        else{
        reverse(word.begin(),word.begin()+id+1);
        return word;
        }
    }
};