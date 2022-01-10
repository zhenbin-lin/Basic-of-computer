#include "common.h"
/* 快速排序算法 */

using VI = vector<int>;



void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/* 
    1. 快速排序在每次分割的过程中，需要 1 个空间存储基准值。
        而快速排序的大概需要 logN次的分割处理，所以占用空间也是 logN 个
    2. 为不稳定排序算法
    3. 最坏情况下为 升序和降序 为O(n*n)
 */
void Quicksort(VI &nums, int start, int end)
{
    if (start < end) {
        int base = nums[start];
        int left = start, right = end;
        while (left < right) {
            while (left < right && nums[right] >= base) --right;
            nums[left] = nums[right];
            while (left < right && nums[left] <= base) ++left;
            nums[right] = nums[left];
        }
        nums[left] = base;
        // printInts(nums);
        Quicksort(nums, start, left - 1);
        Quicksort(nums, left + 1, end);
    }
}


void msort(VI &nums) {
    Quicksort(nums, 0, nums.size() - 1);
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
