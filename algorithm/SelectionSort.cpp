#include "common.h"
/* 选择排序算法 */
/*
3.2 时间复杂度

简单选择排序的比较次数与序列的初始排序无关。 
假设待排序的序列有 N 个元素，则比较次数总是N (N - 1) / 2。
简单排序的时间复杂度为O(N^2)。

空间复杂度
简单选择排序需要占用1个临时空间，用于保存最小值得索引。

选择排序是一种不稳定的排序算法。

 */
void SelectionSort(VI &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[idx]) {
                idx = j;
            }
        }
        swap(nums[i], nums[idx]);
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
    cout << endl;

    return 0;
}

void msort(VI &nums) {
    SelectionSort(nums);
}



void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
