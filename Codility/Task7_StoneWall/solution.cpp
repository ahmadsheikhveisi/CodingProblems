// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> blks(1,H[0]);
    int height = H[0];
    int blks_num = 1;

    for (auto it = H.begin() + 1; it < H.end(); ++it)
    {
        //std::cout << " req " << *it << " h " << height << " blk_num " << blks_num << " blks ";
        if (*it == height)
        {
            // just skip
        }
        else if (*it > height)
        {
            blks.push_back(*it - height);
            blks_num++;
            height = *it;
        }
        else // requested height is less than current height
        {
            bool found = false;
            while ((blks.empty() == false) && found == false)
            {
                //pickup last block
                int last_blk = blks.back();
                blks.pop_back();
                height = height - last_blk;
                if (*it > height)
                {
                    blks.push_back(*it - height);
                    blks_num++;
                    found = true;
                    height = *it;
                }
                else if (*it == height)
                {
                    found = true;
                    height = *it;
                }
            }
            if (found == false)
            {
                blks.push_back(*it);
                blks_num++;
            }
        }
        /*
        for (auto blk : blks)
        {
            std::cout << blk << " ";
        }
        std::cout << "new height " << height << " blks_num " << blks_num;
        std::cout << std::endl;
        */
        
    }

    return blks_num;
}

