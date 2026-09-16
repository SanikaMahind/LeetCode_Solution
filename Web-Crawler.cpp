#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
private:
    std::string getHostName(const std::string& url) {
        size_t start = 7;
        size_t end = url.find('/', start);
        if (end == std::string::npos) {
            return url.substr(start);
        }
        return url.substr(start, end - start);
    }

public:
    std::vector<std::string> crawl(std::string startUrl, HtmlParser htmlParser) {
        std::string targetHost = getHostName(startUrl);
        
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;
        
        q.push(startUrl);
        visited.insert(startUrl);
        
        while (!q.empty()) {
            std::string currentUrl = q.front();
            q.pop();
          
            std::vector<std::string> neighbors = htmlParser.getUrls(currentUrl);
            
            for (const std::string& neighbor : neighbors) {
            
                if (getHostName(neighbor) == targetHost && !visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        return std::vector<std::string>(visited.begin(), visited.end());
    }
};
