#pragma once

namespace ece297test {

    bool path_is_legal(const unsigned start_intersection, const unsigned end_intersection, const std::vector<unsigned>& path);

    bool path_is_legal(const unsigned start_intersection, const std::vector<unsigned>& end_intersections, const std::vector<unsigned>& path);
}

