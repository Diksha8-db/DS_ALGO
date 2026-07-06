class TimeMap {
public:
    unordered_map<string,unordered_map<int,vector<string>>> mpp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp].push_back(value);
        return;
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end()){
            return "";
        }
        int seen = 0;
        for(const auto& [time,_] : mpp[key]){
            if(time <= timestamp){
                seen = max(seen,time);
            }
        }

        return seen == 0 ? "" : mpp[key][seen].back();
    }
};
