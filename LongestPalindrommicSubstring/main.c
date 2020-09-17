class Solution {
    bool is_palindromic(string s)
    {
        int len = s.size();
        int len_2 = len / 2;
        for (int cnt = 0; cnt < len_2; ++cnt)
        {
            if (s[cnt] != s[len - cnt - 1])
            {
                //std::cout << s << " is NOT palindromic " << std::endl;
                return false;
            }
        }
        //std::cout << s << " is palindromic " << std::endl;
        return true;
    }
public:
    string longestPalindrome(string s) {        
        
        if (is_palindromic(s))
        {
            return s;
        }
                
        string res = "";
        string found = "";
        auto it = s.begin();
        
        auto f_begin = s.begin();
        
        for (; it < s.end(); ++it)
        {
            //std::cout << "found " << found << std::endl;
            //std::cout << "next char " << *it << std::endl;

            found.push_back(*it);

            //std::cout << found << std::endl;
            
            //std::cout << "begin " << found.front() << std::endl;
            //std::cout << "end " << found.back() << std::endl;

            
            if (f_begin > s.begin())
            {
                //std::cout << "beyond " << *(f_begin - 1) << std::endl;
                
                found.insert(found.begin(), *(f_begin - 1));
                
                if (is_palindromic(found) == false)
                {
                    found.erase(found.begin());
                }
                else
                {
                    f_begin--;
                }
            }
            
            while(is_palindromic(found) == false)
            {
                found.erase(found.begin());
                f_begin++;
            } 
            //std::cout << "found " << found << std::endl;
            if (found.size() > res.size())
            {
                res = found;
            }
            //std::cout << "-------" << std::endl;
        }

        if (found.size() > res.size())
        {
            res = found;
        }
        
    
        
        return res;
    }
};