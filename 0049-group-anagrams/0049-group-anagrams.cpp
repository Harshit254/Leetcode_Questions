class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        vector<vector<string>>res;
        for(auto i:strs)
        {
            string s=i;
            sort(i.begin(),i.end());
            um[i].push_back(s);
        }
        
        for(auto i:um)
        {
            res.push_back(i.second);
        }
        return res;
        
        
//          unordered_map<string,vector<string>> un;
//     vector<vector<string>> res;
//     for(auto i:strs){
//         string original=i;
//         sort(i.begin(), i.end());
//         un[i].push_back(original);
//     }
    
//     for(auto i:un){
//         res.push_back(i.second);
//     }
//     return res;
        
    }
};