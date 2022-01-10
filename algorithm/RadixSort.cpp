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
它的工作原理是将待排序的元素拆分为 K 个关键字（比较两个元素时，先比较第一关键字，如果相同再比较第二关键字……），
然后先对第 K  关键字进行稳定排序，再对第 K - 1 关键字进行稳定排序，
再对第 K - 2 关键字进行稳定排序……最后对第一关键字进行稳定排序，
这样就完成了对整个待排序序列的稳定排序。
 */
void RadixSort(VI &nums)
{
    vector<vector<int>> Radixs(10);
    int maxVal = *max_element(nums.begin(), nums.end());
    int base = 1;
    while (maxVal > 0) {
        base *= 10; 
        maxVal /= 10;
    }

    for(int num : nums) {
        Radixs[num / base] =
    }
}


void msort(VI &nums) {
    RadixSort(nums);
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
