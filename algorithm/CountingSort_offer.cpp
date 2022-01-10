#include "common.h"
/* 计算排序 */

/* 
它的工作过程分为三个步骤：

计算每个数出现了几次；
求出每个数出现次数的 前缀和；
利用出现次数的前缀和，从右至左计算每个数的排名。
 */
void CountingSort(VI &nums)
{
    int minVal = INT_MAX, maxVal = INT_MIN;
    /* 找出最大最小值，确定数的范围 */
    for (int num: nums) {
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }
    /* 根据数的范围确定需要计数的数的空间 */
    vector<int> cnts(maxVal - minVal + 1, 0);
    for (int num: nums) {
        cnts[num - minVal]++;
    }
    
    int i = 0;
    for (int num = 0; num <= maxVal - minVal; ++num) {
        while (cnts[num] > 0) {
            nums[i++] = num + minVal;
            cnts[num]--;
        }
    }
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

void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void msort(VI &nums) {
    CountingSort(nums);
}
