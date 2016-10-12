#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums_copy(nums);
        sort(nums_copy.begin(), nums_copy.end());
        vector<int>::iterator it1 = nums_copy.begin(), it2 = nums_copy.end() - 1;
        while(*it1 + *it2 != target && it1 <= it2)
        {
            if(*it1 + *it2 > target)
                --it2;
            else
                ++it1;
        }
        if(*it1 + *it2 == target)
        {
            vector<int>::iterator it3 = find(nums.begin(), nums.end(), *it1),
                it4 = find(nums.begin(), nums.end(), *it2);
                if(it4 == it3)
                    it4 = find(it3 + 1, nums.end(), *it2);
            vector<int> ans = {it3-nums.begin(), it4-nums.begin()};
            return ans;
        }
        else
        {
            cerr << "there is no answer!" << endl;
            exit(1);
        }
}

int main()
{
	vector<int> vi = {3, 2, 4};
	vector<int> ans(twoSum(vi, 6));
	for(const auto &i:ans)
		cout << i << '\t';
	cout << endl;
	return 0;
}