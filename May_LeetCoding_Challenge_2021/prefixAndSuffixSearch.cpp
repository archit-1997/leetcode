class WordFilter
{
private:
    unordered_map<string, int> hash;

public:
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            int wordSize = word.size();

            //find the prefix of each string
            for (int j = 1; j <= wordSize; j++)
            {
                string pre = word.substr(0, j);
                for (int k = 0; k < wordSize; k++)
                {
                    string suf = word.substr(k);
                    string str = pre + "|" + suf;
                    hash[str] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        string str = prefix + "|" + suffix;
        return hash[str] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */