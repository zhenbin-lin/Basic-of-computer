#include "common.h"
/* 冒泡排序算法 */



/* 
    1. 冒泡排序的时间复杂度为O(n*n)
        最好的时间复杂度为O(n)，即全部都是有序的
    2. 为稳定排序算法
 */
using VI = vector<int>;

VI BubbleSort(VI &nums)
{
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                flag = true;
                swap(nums[i], nums[i - 1]);
            }
        }
    }
    return nums;
}

void msort(VI &nums) {
    BubbleSort(nums);
}

void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    VI nums = {3, 5, 1, 2, 90, 2, 5, 54, 76, 43, 21, 11};
    cout << "before: ";
    printInts(nums);
    msort(nums);
    cout << "after: ";
    printInts(nums);
    cout << endl;

    return 0;
}
