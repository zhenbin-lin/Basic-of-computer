#include "common.h"
/* 快速排序算法 */
/* 
    1. 快速排序在每次分割的过程中，需要 1 个空间存储基准值。
        而快速排序的大概需要 logN次的分割处理，所以占用空间也是 logN 个
    2. 为不稳定排序算法
    3. 最坏情况下为 升序和降序 为O(n*n)
 */
int partition(VI &nums, int start, int end)
{
    /* 随机选择一个中间值 */
    int random = rand() % (end - start + 1) + start;
    /* 把中间值放在最后面 */
    swap(nums[end], nums[random]);

    /* small指向以发现的最后一个小于nums[end]的数 */
    /* 一开始没有所以指向start - 1 */
    int small = start - 1;
    /* i指向 */
    for (int i = start; i < end; ++i) {
        if (nums[i] < nums[end]) {
            small++;
            swap(nums[i], nums[small]);
        }
    }

    small++;
    swap(nums[end], nums[small]);

    return small;
}


void Quicksort(VI &nums, int start, int end)
{
    if (start < end) {
        int mid = partition(nums, start, end);
        Quicksort(nums, start, mid - 1);
        Quicksort(nums, mid + 1, end);
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

void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void msort(VI &nums) {
    Quicksort(nums, 0, nums.size() - 1);
}
