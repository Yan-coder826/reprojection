#include <iostream>
#include "reprojection.hpp"

int main() {
    Eigen::Matrix3d K;
    K << 1000, 0, 640,
          0, 1000, 360,
          0, 0, 1;

    Eigen::Matrix3d R = Eigen::Matrix3d::Identity();
    Eigen::Vector3d t(0, 0, 0);

    Eigen::Vector3d Pw(0.1, 0.1, 1.0);
    auto result = projectPoint(Pw, K, R, t);
    if (result) {
        std::cout << "Projected pixel: (" << result->x() << ", " << result->y() << ")" << std::endl;
    } else {
        std::cout << "Point is behind the camera." << std::endl;
    }

    Eigen::Vector3d Pw_behind(0, 0, -1.0);
    auto result_behind = projectPoint(Pw_behind, K, R, t);
    if (!result_behind) {
        std::cout << "Correctly handled negative depth." << std::endl;
    }

    return 0;
}
