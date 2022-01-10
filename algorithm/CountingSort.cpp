#include "common.h"
/* 插入排序算法 */

using VI = vector<int>;



void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/* 
它的工作过程分为三个步骤：

计算每个数出现了几次；
求出每个数出现次数的 前缀和；
利用出现次数的前缀和，从右至左计算每个数的排名。
 */
void CountingSort(VI &nums)
{
    vector<int> temp = nums;
    int n = nums.size();
    vector<int> cnt(*max_element(nums.begin(), nums.end()) + 1);

    for (int num : nums) {
        cnt[num]++;
    }
    for (int i = 1; i < cnt.size(); ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        nums[--cnt[temp[i]]] = temp[i];
    }
}


void msort(VI &nums) {
    CountingSort(nums);
}


int main()
{
    VI nums = {3, 5, 90, 2, 5, 76, 43, 21, 11};
    cout << "before: ";
    printInts(nums);
    msort(nums);
    cout << "after: ";
    printInts(nums);
    return 0;
}
