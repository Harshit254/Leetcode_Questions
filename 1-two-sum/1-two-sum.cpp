class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>b;
        long long int i=0;
        long long int j=0;
    
        for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] == target - nums[i]) {
                b.push_back(i);
                b.push_back(j);
            }
        }
    }
        return b;
    }
//     vector<int> twoSum(vector<int>& nums, int target) {
//     unordered_map<int, int> cache;
//     for (int index = 0; index < nums.size(); index++) {
//         const auto combination = cache.find(target - nums[index]);
//         if (combination != cache.end()) {
//             return {combination->second, index};
//         }

//         cache.insert({nums[index], index});
//     }

//     return {};

};