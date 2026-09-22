#include "reprojection.hpp"

std::optional<Eigen::Vector2d> projectPoint(
    const Eigen::Vector3d& Pw,
    const Eigen::Matrix3d& K,
    const Eigen::Matrix3d& R,
    const Eigen::Vector3d& t
) {
    Eigen::Vector3d Pc = R * Pw + t;

    if (Pc.z() <= 0.1
) {
        return std::nullopt;
    }

    double x = Pc.x() / Pc.z();
    double y = Pc.y() / Pc.z();

    double u = K(0, 0) * x + K(0, 2);
    double v = K(1, 1) * y + K(1, 2);

    return Eigen::Vector2d(u, v);
}
