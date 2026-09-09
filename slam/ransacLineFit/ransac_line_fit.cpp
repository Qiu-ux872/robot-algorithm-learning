/****************************
* 本程序演示了 RANSAC(RANdom SAmple Consensus) 算法在二维直线拟合中的应用
* 纯 C++ 实现，不依赖任何第三方库
* 思想：从含有大量外点(outlier)的数据中，通过反复随机采样一小部分数据来估计模型
*       (这里是直线 y = ax + b)，再统计支持该模型的内点(inlier)数量，
*       保留内点最多的那个模型，最后用所有内点做最小二乘精化。
****************************/

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
  double x;
  double y;
};

// 直线的斜截式模型
struct Line {
  double a = 0.0;  // 斜率
  double b = 0.0;  // 截距
};

// 由两个点确定一条直线，返回 false 表示退化（两点几乎重合导致斜率为无穷）
bool lineFromTwoPoints(const Point &p1, const Point &p2, Line &line) {
  if (fabs(p2.x - p1.x) < 1e-9) return false;
  line.a = (p2.y - p1.y) / (p2.x - p1.x);
  line.b = p1.y - line.a * p1.x;
  return true;
}

// 点到直线的垂直距离
double pointLineDistance(const Point &p, const Line &line) {
  return fabs(line.a * p.x - p.y + line.b) / sqrt(line.a * line.a + 1.0);
}

// 用全部内点做最小二乘拟合，进一步精化模型（对 a, b 求偏导令其为零）
Line leastSquaresFit(const vector<Point> &inliers) {
  Line best;
  size_t n = inliers.size();
  if (n < 2) return best;

  double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
  for (const auto &p : inliers) {
    sumX += p.x;
    sumY += p.y;
    sumXY += p.x * p.y;
    sumXX += p.x * p.x;
  }
  double denom = n * sumXX - sumX * sumX;
  if (fabs(denom) < 1e-9) return best;

  best.a = (n * sumXY - sumX * sumY) / denom;
  best.b = (sumY - best.a * sumX) / n;
  return best;
}

// RANSAC 主线
Line ransac(const vector<Point> &pts, double threshold,
            int maxIter, double desiredRatio) {
  // 随机数：用于均匀地抽取两个点
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<size_t> pick(0, pts.size() - 1);

  Line bestModel;
  int bestInliers = 0;

  int iter = 0;
  for (; iter < maxIter; ++iter) {
    // 1. 随机采样两个点（两点确定一条直线）
    size_t i = pick(gen);
    size_t j = pick(gen);
    if (i == j) continue;

    Line cand;
    if (!lineFromTwoPoints(pts[i], pts[j], cand)) continue;

    // 2. 统计与该候选直线距离小于阈值的点的个数（即内点数）
    int nInliers = 0;
    for (const auto &p : pts)
      if (pointLineDistance(p, cand) < threshold) ++nInliers;

    // 3. 保留内点最多的模型
    if (nInliers > bestInliers) {
      bestInliers = nInliers;
      bestModel = cand;

      // 4. 若内点比例已足够高，可以提前结束迭代
      if (static_cast<double>(nInliers) / pts.size() > desiredRatio) break;
    }
  }

  cout << "RANSAC 实际迭代次数: " << iter + 1
       << " (最大 " << maxIter << "), 最佳内点数: " << bestInliers << endl;

  // 5. 收集所有内点，用最小二乘精化模型（只用内点，避免外点干扰）
  vector<Point> inliers;
  for (const auto &p : pts)
    if (pointLineDistance(p, bestModel) < threshold) inliers.push_back(p);
  bestModel = leastSquaresFit(inliers);

  return bestModel;
}

int main() {
  // ---------- 1. 生成模拟数据：内点贴着直线 y = 0.5x + 1.0，外加高斯噪声 ----------
  const double gtA = 0.5, gtB = 1.0;  // 真实直线参数
  const int nInliers = 80, nOutliers = 40;

  random_device rd;
  mt19937 gen(rd());
  normal_distribution<double> gauss(0.0, 0.3);      // 内点噪声
  uniform_real_distribution<double> uni(-10.0, 10.0); // 外点随机散落

  vector<Point> pts;
  pts.reserve(nInliers + nOutliers);
  for (int k = 0; k < nInliers; ++k) {
    double x = uni(gen);
    pts.push_back({x, gtA * x + gtB + gauss(gen)});
  }
  for (int k = 0; k < nOutliers; ++k) {
    double x = uni(gen), y = uni(gen);
    if (fabs(y - (gtA * x + gtB)) < 1.5) ++k;  // 尽量让外点离真线远些，更有区分度
    pts.push_back({x, y});
  }
  cout << "生成数据: 内点 " << nInliers << " 个, 外点 " << nOutliers << " 个" << endl;

  // ---------- 2. 直接最小二乘（会受外点严重干扰，作为对照） ----------
  Line naive = leastSquaresFit(pts);
  cout << "\n[对照] 全量最小二乘:   a = " << naive.a << ", b = " << naive.b << endl;

  // ---------- 3. RANSAC 拟合 ----------
  double threshold = 0.6;  // 距离阈值：点到直线距离小于它即视为内点
  int maxIter = 100;
  double desiredRatio = 0.8;  // 内点比例达到该值时提前收敛
  Line robust = ransac(pts, threshold, maxIter, desiredRatio);

  cout << "[RANSAC] 直线:       a = " << robust.a << ", b = " << robust.b << endl;
  cout << "[真值]   直线:       a = " << gtA << ", b = " << gtB << endl;
  cout << "\n对比可见：全量最小二乘被外点带偏，RANSAC 能鲁棒地找回真实直线。" << endl;

  return 0;
}
