#include <stack>
#include <algorithm>

using std::stack;
using std::sort;
// ============================================================
// Algorithm of Graham

class Point {
public:
	int x, y;
	friend bool operator < (const Point &a, const Point &b) {
		// 按与x轴夹角由小到大排序, 夹角相同按长度排
		int cmp = a.x * b.y - b.x * a.y;
		if (cmp == 0) return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
		if (cmp > 0) return true;
		return false;
	}
};

bool leftq(Point &a, Point &b, Point &c) {
	// 判断C点是否在ab的左侧
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) >= 0;
}

void getConvexHell(Point arr[], int n, stack<Point> &sta) {
	// arr[]代表点集，n为集合中点的个数，用栈sta存储凸包
	if (!sta.empty()) sta.pop();		// 清空栈

	sort(arr, arr + n);

	Point base = arr[0];				// base 代表纵坐标最小的点
	for (int i = 1; i < n; ++i) {
		if (arr[i].y < base.y) base = arr[i];
	}


	sta.push(base), sta.push(arr[1]);
	for (int i = 2; i < n - 1;) {
		// 连接base和栈顶的那个点，得到直线L, 看当前点是在直线 L 的右边还是左边
		if (leftq(base, sta.top(), arr[i])) {
			// 如果在直线上, 或者在直线的左边, 当前点是凸包上的点, 把它压入栈
			sta.push(arr[i]);

			// 检查当前的点是不是最后一个, 是最后一个的话就结束, 否则判断下一个点
			if (i == n - 1) break;
			else ++i;
		} else {
			// 如果在直线的右边, 则栈顶的那个元素不是凸包上的点, 把栈顶元素出栈
			// 重复判断当前点
			sta.pop();
		}

	}
}
// ============================================================
