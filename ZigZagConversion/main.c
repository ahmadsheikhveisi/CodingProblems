class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.size())
        {
            return s;
        }
        if (numRows <= 1)
        {
            return s;
        }
        int cnt = 1;
        int row = 0;
        int cln = 1;
        int nex = (2*numRows - 2) * cln;
        while (nex < s.size())
        {
            //std::cout << nex << std::endl;
            char temp = s[nex];
            s.erase(s.begin()+nex);
            s.insert(s.begin()+cnt, temp);
            ++cln;
            ++cnt;
            nex = (2*numRows - 2) * cln;
            //std::cout << s << std::endl;
        }
        ++row;
        //std::cout << s << std::endl;
        int ordered = cnt;
        
        ++cnt;
        
        while (row < numRows - 1)
        {
            cln = 1;
            nex = (2*numRows - 2*(row+1)) * cln + ordered;
            //std::cout << "R+++ " << nex << std::endl;
            while (nex < s.size())
            {
                
                char temp = s[nex];
                s.erase(s.begin()+nex);
                s.insert(s.begin()+cnt, temp);
                
                //std::cout << "f " << nex << " " << temp << " " << cln << " " << row << " " << ordered << std::endl;
                ++cnt;
                //std::cout << s << std::endl;
                
                if (nex + 1 < s.size())
                {
                    nex++;
                    temp = s[nex];
                    s.erase(s.begin()+nex);
                    s.insert(s.begin()+cnt, temp);
                    //std::cout << nex << " " << temp << std::endl;
                    ++cnt;
                    //std::cout << s << std::endl;
                }
                
                ++cln; 
                nex = (2*numRows - 2*(row+1)) * cln + ordered + cln - 1;               
            }
            
            ordered = cnt;
            
            cnt++;
            row++;
        }
        //std::cout << "----------------" << std::endl;
        return s;
    }
};
