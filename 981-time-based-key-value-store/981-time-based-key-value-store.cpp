class TimeMap {
public:
    unordered_map<string ,vector<pair<int,string>>>mp;

TimeMap() {    
}

void set(string key, string value, int timestamp) {
    
    mp[key].push_back({timestamp,value});
    
}

string get(string key, int timestamp) {
    string s="";
 
    
  if(mp.find(key)!=mp.end()){
      vector<pair<int,string>>&v=mp[key];
      
     //binary search on this vector
    
     int i=0,j=v.size()-1;
      
    if(timestamp<v[i].first)return "";
      if(timestamp>=v[j].first)return v[j].second;
      
     while(i<=j){
         int mid=i+(j-i)/2;
         
       if(v[mid].first==timestamp){
           s=v[mid].second;
           break;
       }
         
       else if(v[mid].first<timestamp){
           s=v[mid].second;
           i=mid+1;
       }
        else{
            j=mid-1;
        }
         
     }
       
  }  
    
    
    
  return s;  
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */