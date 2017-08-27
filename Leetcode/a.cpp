#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int INF = 0x3f3f3f3f;

bool checkPossibility(vector<int> &nums)
{
    if (nums.size() == 1)
        return true;
    int cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            if (i == 0 || i + 1 == nums.size() - 1)
                cnt++;
            else
            {
                if (nums[i - 1] >= nums[i + 1])
                    nums[i + 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                cnt++;
            }
        if (cnt > 1)
            break;
    }
    if (cnt == 1 || cnt == 0)
        return true;
    else
        return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    vector<int> nums = {1, 2, 3};
    checkPossibility(nums);
    return 0;
}
