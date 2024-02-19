class Solution {
public:
    string simplifyPath(string path) {
        string dir = "";
        queue<string> q;
        vector<string> v;
        
        for(int i = 0; i < path.length(); i++)
        {
            if(path[i] == '/')
            {
                if(dir != "")
                {
                    q.push(dir);
                }
                dir = "";
            }
            else
            {
                dir += path[i];
            }
        }
        
        int index = 0;
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            
            if(cur == "..")
            {
                if(index == 0) continue;
                index--;
            }
            else if(cur == ".")
            {
                continue;
            }
            else
            {
                if(v.size() == index) v.push_back(cur);
                else v[index] = cur;
                index++;
            }

            cout << cur << ", " << index << "\n";
        }
        if(dir != "")
        {
            if(dir == "..") index--;
            else if(dir != ".")
            {
                if(v.size() == index) v.push_back(dir);
                else v[index] = dir;
                index++;
            }
        }
        dir = "";
        for(int i = 0; i < index; i++)
        {
            dir += "/" + v[i];
        }
        if(dir == "") return "/";
        
        return dir;
    }
};