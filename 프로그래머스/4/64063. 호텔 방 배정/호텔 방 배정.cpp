#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> parent;
    
    function<long long(long long)> findRoom = [&](long long room) -> long long{
        if(parent.find(room) == parent.end())
        {
            parent[room] = room+1;
            return room;
        }
        
        return parent[room] = findRoom(parent[room]);
    };
    
    for(auto& room : room_number)
    {
        answer.push_back(findRoom(room));
    }
    
    return answer;
}