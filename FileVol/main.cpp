/* COPYRIGHT
 *
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

const std::string_view music{"music"};
const std::string_view images{"images"};
const std::string_view movies{"movies"};
const std::string_view other{"other"};
const std::vector<std::string_view> allfiletypes{music,
    images, movies, other};

const std::unordered_map<std::string_view, std::string_view> ext_map {
    {"mp3", music}, {"acc", music}, {"flac", music}, {"jpg", images},
    {"bmp", images}, {"gif", images}, {"mp4", movies}, {"avi", movies},
    {"mkv", movies}
};

std::vector<std::string_view> split(std::string_view str, char sep) {
    size_t cnt{0};
    size_t last_cnt{0};
    std::vector<std::string_view> res;
    while ((cnt = str.find(sep, last_cnt)) != std::string_view::npos) {
        res.push_back(str.substr(last_cnt, cnt - last_cnt));
        last_cnt = ++cnt;
    }
    if (last_cnt != str.size()) {
        res.push_back(str.substr(last_cnt));
    }
    return res;
}

std::string solution(std::string_view str) {
    std::unordered_map<std::string_view, size_t> files_vol;
    for (auto filetype : allfiletypes) {
        files_vol[filetype] = 0;
    }
    auto str_lines = split(str, '\n');
    for (auto& file : str_lines) {
        auto file_splited_by_space = split(file, ' ');
        auto file_name = file_splited_by_space[0];
        size_t file_size = std::atoi(file_splited_by_space[1].data());
        auto extention = file_name.substr(file_name.rfind('.') + 1);
        auto file_type = ext_map.find(extention);
        if (file_type != ext_map.end()) {
            files_vol[file_type->second] += file_size;
        } else {
            files_vol[other] += file_size;
        }
    }

    std::string res;
    for (auto file_type : allfiletypes) {
        std::stringstream sstr;
        sstr << file_type << " " << files_vol[file_type] <<
            "b\n";
        res += sstr.str();
    }
    res.erase(res.size() - 1);
    return res;
}


int main() {
    std::cout << solution("my.song.mp3 11b\n"
       "greatSong.flac 1000b\n"
       "not3.txt 5b\n"
       "video.mp4 200b\n"
       "game.exe 100b\n"
        "mov!e.mkv 10000b");
    return 0;
}

