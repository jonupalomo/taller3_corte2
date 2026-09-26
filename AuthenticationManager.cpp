#include <unordered_map>
#include <string>

using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> tokens;
public:
    AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {  
    }

    void generate(string tokenId, int currentTime){
        tokens[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId) && tokens[tokenId] > currentTime){
            tokens[tokenId] = currentTime + timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (const auto& pair : tokens){
            if(pair.second > currentTime){
                count++;
            }
        }
        return count;
    }
};