#include <bits/stdc++.h>
using namespace std;

/*
 * 线段树
 * 一种平衡二叉树
 * 通过二叉树的回溯来以O(logn)的时间复杂度来求和
 * 需要有4n的空间来存放
 * 单点修改版本
 * 
 * 建树：
 *  通过给定的起点和终点来进行二叉树的划分，当抵达最底层时（当前的start=end），赋值并回溯，继续赋值父节点，根节点即是所有元素之和
 * 修改：
 *  通过检测目标所在的是左子节点还是右子节点来进行向下搜索（类似DFS），完成后回溯更新父节点
 * 查询：
 *  将所有完全包含的数相加即可得到，如果一个数已经完全包含就不需要再向下了，直接返回，减少计算次数
 * */


// 以下函数代码由AI生成
/// 线段树节点结构体
struct SegmentTreeNode {
    int start;  // 节点对应区间的起始位置
    int end;    // 节点对应区间的结束位置
    int value;  // 节点对应区间的值
    SegmentTreeNode* left;  // 左子节点指针
    SegmentTreeNode* right; // 右子节点指针
};

/// 创建线段树
SegmentTreeNode* createSegmentTree(int start, int end, const vector<int>& nums) {
    if (start > end) {  // 条件错误，创建失败
        return nullptr;
    }

    // 新建节点
    SegmentTreeNode* node = new SegmentTreeNode;
    node->start = start;
    node->end = end;
    node->left = nullptr;
    node->right = nullptr;

    // 如果已经到了最底层，就直接赋值返回
    if (start == end) {
        node->value = nums[start];
        return node;
    }

    // 二叉树，往下建立左右两个儿子
    int const mid = (start + end) / 2;
    node->left = createSegmentTree(start, mid, nums);
    node->right = createSegmentTree(mid + 1, end, nums);

    // 回溯
    node->value = node->left->value + node->right->value;
    return node;
}

/// 更新线段树节点的值
void updateSegmentTree(SegmentTreeNode* node, int index, int newValue) {
    if (node == nullptr || index < node->start || index > node->end) {  // 如果不符合条件直接返回
        return;
    }

    // 如果找到了最下面的目标值
    if (node->start == node->end && node->start == index) {
        node->value = newValue;
        return;
    }

    // 向下寻找
    int const mid = (node->start + node->end) / 2;
    if (index <= mid) { // 查找左右两个孩子节点
        updateSegmentTree(node->left, index, newValue);
    } else {
        updateSegmentTree(node->right, index, newValue);
    }

    // 找到后回溯到这里，再重新计算当前节点的值
    node->value = node->left->value + node->right->value;
}

/// 查询线段树节点的值之和
int querySegmentTree(SegmentTreeNode* node, int start, int end) {
    if (node == nullptr || start > node->end || end < node->start) {    // 如果不满足条件，返回
        return 0;
    }

    // 找到完全包含的数，再往下也是浪费时间，直接整个返回
    if (start <= node->start && end >= node->end) {
        return node->value;
    }

    // 继续向两个子节点分头寻找
    int const mid = (node->start + node->end) / 2;  // 貌似没有用
    int const leftSum = querySegmentTree(node->left, start, end);
    int const rightSum = querySegmentTree(node->right, start, end);
    return leftSum + rightSum;
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    vector<int> a = {1, 1, 2, 3};
    auto tree = createSegmentTree(0, 3, a);
    cout << querySegmentTree(tree, 0, 3) << '\n';
    updateSegmentTree(tree, 0, 4);
    cout << querySegmentTree(tree, 0, 3) << '\n';

    return 0;
}