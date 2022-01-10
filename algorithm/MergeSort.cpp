#include "common.h"




/* [ll, rr) */
void MergeSort(VI &nums, int ll, int rr)
{
    if (rr - ll <= 1) return;
    int mid = ((rr - ll) >> 1) + ll;
    /* 拆分，分治 */
    MergeSort(nums, ll, mid);
    MergeSort(nums, mid, rr);
    VI temp(rr - ll);
    int p1 = ll, p2 = mid, p3 = 0;
    /* 合并 */
    while (p3 < rr - ll) {
        if (p1 >= mid) {
            temp[p3++] = nums[p2++];
        } else if (p2 >= rr) {
            temp[p3++] = nums[p1++];
        } else {
            temp[p3++] = nums[p2] < nums[p1] ? nums[p2++] : nums[p1++];
        }
    }

    for (int i = 0, j = ll; j < rr; ++j, ++i) {
        nums[j] = temp[i]; 
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
    MergeSort(nums, 0, nums.size());
}

