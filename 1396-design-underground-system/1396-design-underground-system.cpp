class UndergroundSystem {
public:
    map<int,pair<string,int>>in;  //{id,<station,time>}
    map<string,pair<int,int>>path; //{st1-st2,<difference,count>}
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto x=in[id];
        string full_path=x.first+"-"+stationName;
        path[full_path].first+=t-x.second;
        path[full_path].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string full_path=startStation+"-"+endStation;
        auto x=path[full_path];
        return (double) x.first/x.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */