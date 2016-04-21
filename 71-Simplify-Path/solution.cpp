class Solution {
public:
    string simplifyPath(string path) {
        list<string> path_struct(0);
        bool end = false;
        for (int i = 0, l = 0; !end; i++)
            if (path[i] == '/' || !path[i]) {
                end = !path[i];
                path[i] = '\0';
                if (l < i) {
                    string folder_name = &path[l];
                    if (folder_name == "..") {
                        if (!path_struct.empty())
                            path_struct.pop_back();
                    } else if (folder_name != ".")
                        path_struct.push_back(folder_name);
                }
                l = i + 1;
            }
        if (path_struct.empty())
            return "/";
        string result("");
        for (auto &s: path_struct)
            result += "/" + s;
        return result;
    }
};