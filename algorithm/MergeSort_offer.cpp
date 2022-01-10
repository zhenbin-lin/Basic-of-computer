#include "common.h"




/* [ll, rr) */
void MergeSort_Circulation(VI &nums)
{
    int n = nums.size();
    vector<int> src = nums;
    vector<int> dst(n);

    /* segment片段长度 */
    for (int seg = 1; seg < n; seg += seg) {
        for (int start = 0; start < n; start += seg * 2) {
            /* 划分区间 */
            /* 细节在于 [start, end) */
            int mid = min(n, start + seg);
            int end = min(n, start + seg * 2);
            int i = start, j = mid, k = start;
            /* 进行并归 */
            while (i < mid || j < end) {
                if (j >= end || (i < mid && src[i] < src[j])) {
                    dst[k++] = src[i++];
                } else {
                    dst[k++] = src[j++];
                }
            }
        }
        swap(dst, src);
    }
    nums = src;
}

void MergeSort_Recursion(VI &src, VI& dst, int start, int end)
{
    if (start + 1 >= end) return;
    int mid = ((end - start) >> 1) + start; 

    MergeSort_Recursion(dst, src, start, mid);
    MergeSort_Recursion(dst, src, mid, end);

    int i = start, j = mid, k = start;
    /* 进行并归 */
    while (i < mid || j < end) {
        if (j >= end || (i < mid && src[i] < src[j])) {
            dst[k++] = src[i++];
        } else {
            dst[k++] = src[j++];
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
    // MergeSort_Circulation(nums);
    vector<int> dst = nums;
    MergeSort_Recursion(nums, dst, 0, nums.size());
    nums = dst;
}

