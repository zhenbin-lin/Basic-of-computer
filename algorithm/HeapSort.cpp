#include "common.h"



using VI = vector<int>;



void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/* 
iParent(i) = (i - 1) / 2;
iLeftChild(i) = 2 * i + 1;
iRightChild(i) = 2 * i + 2;
 */
void sift_down(VI &nums, int start, int end) {
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end) {
        /* 比较两个子节点，选择大的那一个 */
        if (child + 1 <= end && nums[child] < nums[child + 1]) ++child;
        /* 与父节点进行比较 */
        if (nums[parent] >= nums[child]) {
            return;
        }
        /* 交换父子节点，并向下继续 */
        swap(nums[parent], nums[child]);
        parent = child;
        child = parent * 2 + 1;
    }
}

void HeapSort(VI &nums)
{
    int n = nums.size();
    /* n - 1为最后一个节点 */
    /* parent = (i - 1) / 2 */
    /* 从最后一个节点的父节点开始 sift down 以完成堆化 (heapify) */
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) sift_down(nums, i, n - 1);

    /* 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕 */
    for (int i = (n - 1); i >= 0; --i) {
        swap(nums[0], nums[i]);
        sift_down(nums, 0, i - 1);
    }
}


void msort(VI &nums) {
    HeapSort(nums);
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
