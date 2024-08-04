void splitarray(int index, int k, vector<vector<int>> current, vector<vector<vector<int>>> result, vector<int> nums)
{
    
    if(index == nums.size()){
        if(k==0) result.push_back(current);
        return;
    }
    
    for(int i=0; i<current.size(); i++){
        current[i].push_back(nums[index]);
        splitarray(index+1, k, current, result);
        current[i].pop_back(nums[index]);
    }
    
    if(k>0){
        current.push_back({nums[index]});
        splitarray(index+1, k-1, current, result);
        current.pop_back();
    }
}

vector<vector<vector<int>>>  splitted(vector<int>& nums, k)
{
    vector<vector<vector<int>>> result;
    vector<vector<int>> current;
    splitarray(0, k, nums, current, result, nums);
    return result;
}
