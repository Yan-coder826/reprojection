#pragma once

#include <Eigen/Dense>
#include <optional>

std::optional<Eigen::Vector2d> projectPoint(
    const Eigen::Vector3d& Pw,
    const Eigen::Matrix3d& K,
    const Eigen::Matrix3d& R,
    const Eigen::Vector3d& t
);
