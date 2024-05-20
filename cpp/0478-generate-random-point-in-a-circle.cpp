#include <cmath>
#include <numbers>
#include <random>
#include <vector>

using namespace std;

class Solution {
public:
  Solution(double radius, double x_center, double y_center)
      : radius_square{radius * radius}, x_center{x_center}, y_center{y_center} {
  }

  vector<double> randPoint() {
    uniform_real_distribution<double> dist_phi(0.0,
                                               2.0 * numbers::pi_v<double>);
    uniform_real_distribution<double> dist_r(0.0, radius_square);

    double phi = dist_phi(gen);
    double r = sqrt(dist_r(gen));

    return {x_center + r * cos(phi), y_center + r * sin(phi)};
  }

private:
  double x_center{};
  double y_center{};
  double radius_square{};
  mt19937 gen{random_device{}()};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
