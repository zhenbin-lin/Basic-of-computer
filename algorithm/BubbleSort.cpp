#include "common.h"
/* 冒泡排序算法 */



/* 
    1. 冒泡排序的时间复杂度为O(n*n)
        最好的时间复杂度为O(n)，即全部都是有序的
    2. 为稳定排序算法
 */

VI BubbleSort(VI &nums)
{
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i < nums.size(); ++i) {
            /* 前一个大于后一个交换顺序 */
            if (nums[i - 1] > nums[i]) {
                flag = true;
                swap(nums[i], nums[i - 1]);
            }
        }
    }
    return nums;
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

void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void msort(VI &nums) {
    BubbleSort(nums);
}
