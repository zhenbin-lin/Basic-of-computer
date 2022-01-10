#include "common.h"
/* 
工作原理
桶排序按下列步骤进行：

1. 设置一个定量的数组当作空桶；  ==> 可以使用最大元素除以基数来得到桶的个数
2. 遍历序列，并将元素一个个放到对应的桶中；
3. 对每个不是空的桶进行排序；
4. 从不是空的桶里把元素再放回原来的序列中。
 */

using VI = vector<int>;


void printInts(const VI &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}


void insertSort(VI & nums) {
    vector<int> temp = nums;
    for (int i = 1; i < temp.size(); ++i) {
        int key = temp[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}


void BucketSort(VI &nums)
{
    int n = nums.size();
    int bucket_size = *max_element(nums.begin(), nums.end()) / n + 1;
    vector<vector<int>> buckets(bucket_size);
    
    for (int num : nums) {
        buckets[num / n].push_back(num);
    }

    int i = 0;
    for (VI &bucket : buckets) {
        insertSort(bucket);
        for (int j = 0; j < bucket.size() && i < n; ++j) {
            nums[i++] = bucket[j];
        }
        printInts(nums);
    }
}


void msort(VI &nums) {
    BucketSort(nums);
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
