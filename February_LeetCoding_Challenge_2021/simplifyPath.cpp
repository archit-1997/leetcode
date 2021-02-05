class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        vector<string> s;
        while (i < path.length()) {
            while (i < path.length() && path[i] == '/')
                i++; //begining '/'
            if (i == path.length())
                break;
            
            int start = i;
            while (i < path.length() && path[i] != '/')
                i++; 
                
            string cur = path.substr(start, i - start);
            if (cur == "..") {
                if (!s.empty())
                    s.pop_back();
            }
            else if (cur != ".")
                s.push_back(cur);
        }
        if (s.size() == 0)  return "/";
        string res = "";
        for (int i = 0; i < s.size(); i++)
            res += '/' + s[i];
        return res;
    }
};
