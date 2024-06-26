class Solution {
public:
    string simplifyPath(const string& path) {
        vector<string> dirs;
        for (auto i = path.begin(); i != path.end(); ) {
            i++;
            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);
            
            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                } else {
                    dirs.push_back(dir);
                }
            }
            i = j;
        }
        ostringstream os;
        if (dirs.empty()) {
            os << "/";
        } else {
            for (auto dir : dirs)
                os << "/" << dir;
        }
        return os.str();
    }
};
