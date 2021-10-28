class Solution {
public:
string optimalDivision(vector& nums) {
string s;
int n = nums.size();
if(n==1)
{
s = to_string(nums[0]);
return s;
}
if(n==2)
{
s += to_string(nums[0]);
s+='/';
s+= to_string(nums[1]);
return s;
}
for(int i=0;i<n;i++)
{
if(i==1) s += '(' ;
s += to_string(nums[i]);
if(i<n-1) s += '/';
}
s += ')';
return s;
}
};