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
    1. 当数据正序时，执行效率最好，每次插入都不用移动前面的元素，时间复杂度为O(N)。
       当数据反序时，执行效率最差，每次插入都要前面的元素后移，时间复杂度为O(N^2)。

    2. 直接插入排序的过程中，不需要改变相等数值元素的位置，所以它是稳定的算法。

    3. 因为在一个有序序列中查找一个插入位置，以保证有序序列的序列不变，
       所以可以使用二分查找，减少元素比较次数提高效率。
 */
void InsertionSort(VI &nums)
{
    vector<int> temp = nums;
    for (int i = 1; i < temp.size(); ++i) {
        int key = temp[i];
        int j = i - 1;
        /* 往后挪 */
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}


void msort(VI &nums) {
    InsertionSort(nums);
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
