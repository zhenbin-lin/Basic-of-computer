#include "common.h"
/* 希尔排序 */

using VI = vector<int>;



void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/* 
希尔排序中相等数据可能会交换位置，所以希尔排序是不稳定的算法。

直接插入排序和希尔排序的比较:

    直接插入排序是稳定的；而希尔排序是不稳定的。

    直接插入排序更适合于原始记录基本有序的集合。

    希尔排序的比较次数和移动次数都要比直接插入排序少，当N越大时，效果越明显。

    希尔排序的比较次数和移动次数都要比直接插入排序少，当N越大时，效果越明显。

直接插入排序也适用于链式存储结构；希尔排序不适用于链式结构。
 */
void ShellsSort(VI &nums)
{
    int gap = nums.size() / 2;
    while (gap >= 1) {
        for (int i = gap; i < nums.size(); ++i) {
            int j = 0;
            int temp = nums[i];
            for (j = i - gap; j >= 0 && nums[j] > temp ; j -= gap) {
                nums[j + gap] = nums[j];
            }
            nums[j + gap] = temp;
        }
        printInts(nums);
        gap /= 2;
    }
}


void msort(VI &nums) {
    ShellsSort(nums);
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
