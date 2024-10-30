class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> umap;  

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});  
    }
    
    string get(string key, int timestamp) {
        if (umap.find(key) == umap.end()) {
            return ""; 
        }

        vector<pair<int, string>>& entries = umap[key];
        
        int left = 0;
        int right = entries.size() - 1;
        string result = "";
        
        while (left <= right) {
            int middle = (right + left) / 2;
            if (entries[middle].first <= timestamp) {
                result = entries[middle].second;  
                left = middle + 1;  
            } else {
                right = middle - 1; 
            }
        }

        return result;  
    }
};
