class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
a.push_back(nums[0]);//when i have declared the vector without the size, i cannot initialize any index with value, we have to push the value !!!
    for(int i=1;i<nums.size();i++)
    a.push_back(nums[i]+a[i-1]);
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        return a[right];

        return a[right]-a[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */