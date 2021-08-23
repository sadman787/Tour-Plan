#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_simple_path_func_public) {
struct MapFixture {
    MapFixture() {
        rng = std::minstd_rand(4);
        rand_intersection = std::uniform_int_distribution<unsigned>(0, getNumberOfIntersections()-1);
        rand_street = std::uniform_int_distribution<unsigned>(1, getNumberOfStreets()-1);
        rand_segment = std::uniform_int_distribution<unsigned>(0, getNumberOfStreetSegments()-1);
        rand_poi = std::uniform_int_distribution<unsigned>(0, getNumberOfPointsOfInterest()-1);
        rand_lat = std::uniform_real_distribution<double>(46.650653839, 46.730262756);
        rand_lon = std::uniform_real_distribution<double>(7.667298794, 7.962547302);
        rand_turn_penalty = std::uniform_real_distribution<double>(0., 30.);
    }

    std::minstd_rand rng;
    std::uniform_int_distribution<unsigned> rand_intersection;
    std::uniform_int_distribution<unsigned> rand_street;
    std::uniform_int_distribution<unsigned> rand_segment;
    std::uniform_int_distribution<unsigned> rand_poi;
    std::uniform_real_distribution<double> rand_lat;
    std::uniform_real_distribution<double> rand_lon;
    std::uniform_real_distribution<double> rand_turn_penalty;
};
    TEST(find_path_between_intersections_simple_legality) {
        std::vector<unsigned> path;
        
        path = find_path_between_intersections(103, 104, 0.00000000000000000);
        CHECK(path_is_legal(103, 104, path));
        
        path = find_path_between_intersections(103, 54, 0.00000000000000000);
        CHECK(path_is_legal(103, 54, path));
        
        path = find_path_between_intersections(141, 297, 0.00000000000000000);
        CHECK(path_is_legal(141, 297, path));
        
        path = find_path_between_intersections(418, 419, 0.00000000000000000);
        CHECK(path_is_legal(418, 419, path));
        
        path = find_path_between_intersections(607, 606, 0.00000000000000000);
        CHECK(path_is_legal(607, 606, path));
        
        path = find_path_between_intersections(644, 645, 0.00000000000000000);
        CHECK(path_is_legal(644, 645, path));
        
        path = find_path_between_intersections(658, 665, 0.00000000000000000);
        CHECK(path_is_legal(658, 665, path));
        
        path = find_path_between_intersections(702, 703, 0.00000000000000000);
        CHECK(path_is_legal(702, 703, path));
        
        path = find_path_between_intersections(724, 499, 0.00000000000000000);
        CHECK(path_is_legal(724, 499, path));
        
        path = find_path_between_intersections(496, 725, 0.00000000000000000);
        CHECK(path_is_legal(496, 725, path));
        
        path = find_path_between_intersections(748, 564, 0.00000000000000000);
        CHECK(path_is_legal(748, 564, path));
        
        path = find_path_between_intersections(210, 53, 0.00000000000000000);
        CHECK(path_is_legal(210, 53, path));
        
        path = find_path_between_intersections(836, 857, 0.00000000000000000);
        CHECK(path_is_legal(836, 857, path));
        
        path = find_path_between_intersections(918, 719, 0.00000000000000000);
        CHECK(path_is_legal(918, 719, path));
        
        path = find_path_between_intersections(412, 1017, 0.00000000000000000);
        CHECK(path_is_legal(412, 1017, path));
        
        path = find_path_between_intersections(1220, 394, 0.00000000000000000);
        CHECK(path_is_legal(1220, 394, path));
        
        path = find_path_between_intersections(543, 517, 0.00000000000000000);
        CHECK(path_is_legal(543, 517, path));
        
        path = find_path_between_intersections(1291, 1286, 0.00000000000000000);
        CHECK(path_is_legal(1291, 1286, path));
        
        path = find_path_between_intersections(1329, 519, 0.00000000000000000);
        CHECK(path_is_legal(1329, 519, path));
        
        path = find_path_between_intersections(1378, 358, 0.00000000000000000);
        CHECK(path_is_legal(1378, 358, path));
        
        path = find_path_between_intersections(1501, 1500, 0.00000000000000000);
        CHECK(path_is_legal(1501, 1500, path));
        
        path = find_path_between_intersections(462, 461, 0.00000000000000000);
        CHECK(path_is_legal(462, 461, path));
        
        path = find_path_between_intersections(0, 1412, 0.00000000000000000);
        CHECK(path_is_legal(0, 1412, path));
        
        path = find_path_between_intersections(1629, 1533, 0.00000000000000000);
        CHECK(path_is_legal(1629, 1533, path));
        
        path = find_path_between_intersections(1507, 1633, 0.00000000000000000);
        CHECK(path_is_legal(1507, 1633, path));
        
        path = find_path_between_intersections(1146, 1379, 0.00000000000000000);
        CHECK(path_is_legal(1146, 1379, path));
        
        path = find_path_between_intersections(1510, 966, 0.00000000000000000);
        CHECK(path_is_legal(1510, 966, path));
        
        path = find_path_between_intersections(1688, 1687, 0.00000000000000000);
        CHECK(path_is_legal(1688, 1687, path));
        
        path = find_path_between_intersections(1698, 145, 0.00000000000000000);
        CHECK(path_is_legal(1698, 145, path));
        
        path = find_path_between_intersections(758, 691, 0.00000000000000000);
        CHECK(path_is_legal(758, 691, path));
        
    } //find_path_between_intersections_simple_legality

    TEST(find_path_between_intersections_simple_optimality) {
        std::vector<unsigned> path;
        path = find_path_between_intersections(103, 104, 0.00000000000000000);
        CHECK(path_is_legal(103, 104, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 25.69336157229719220);
        
        path = find_path_between_intersections(103, 54, 0.00000000000000000);
        CHECK(path_is_legal(103, 54, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 27.78911713171637743);
        
        path = find_path_between_intersections(141, 297, 0.00000000000000000);
        CHECK(path_is_legal(141, 297, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 9.24496065330763273);
        
        path = find_path_between_intersections(418, 419, 0.00000000000000000);
        CHECK(path_is_legal(418, 419, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.12100595004342019);
        
        path = find_path_between_intersections(607, 606, 0.00000000000000000);
        CHECK(path_is_legal(607, 606, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.18859295730892311);
        
        path = find_path_between_intersections(644, 645, 0.00000000000000000);
        CHECK(path_is_legal(644, 645, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 0.73912009460227202);
        
        path = find_path_between_intersections(658, 665, 0.00000000000000000);
        CHECK(path_is_legal(658, 665, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 31.68352004873833749);
        
        path = find_path_between_intersections(702, 703, 0.00000000000000000);
        CHECK(path_is_legal(702, 703, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4.43336013196311818);
        
        path = find_path_between_intersections(724, 499, 0.00000000000000000);
        CHECK(path_is_legal(724, 499, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6.69338669826130239);
        
        path = find_path_between_intersections(496, 725, 0.00000000000000000);
        CHECK(path_is_legal(496, 725, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.17252772249248505);
        
        path = find_path_between_intersections(748, 564, 0.00000000000000000);
        CHECK(path_is_legal(748, 564, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.87880009726705532);
        
        path = find_path_between_intersections(210, 53, 0.00000000000000000);
        CHECK(path_is_legal(210, 53, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.30154201638575273);
        
        path = find_path_between_intersections(836, 857, 0.00000000000000000);
        CHECK(path_is_legal(836, 857, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 11.84644239870678817);
        
        path = find_path_between_intersections(918, 719, 0.00000000000000000);
        CHECK(path_is_legal(918, 719, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 19.12350691116010637);
        
        path = find_path_between_intersections(412, 1017, 0.00000000000000000);
        CHECK(path_is_legal(412, 1017, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 30.87259807051281513);
        
        path = find_path_between_intersections(1220, 394, 0.00000000000000000);
        CHECK(path_is_legal(1220, 394, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 13.94071575380215222);
        
        path = find_path_between_intersections(543, 517, 0.00000000000000000);
        CHECK(path_is_legal(543, 517, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 22.09813374483935533);
        
        path = find_path_between_intersections(1291, 1286, 0.00000000000000000);
        CHECK(path_is_legal(1291, 1286, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 10.30276569168242240);
        
        path = find_path_between_intersections(1329, 519, 0.00000000000000000);
        CHECK(path_is_legal(1329, 519, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 13.30951272438761279);
        
        path = find_path_between_intersections(1378, 358, 0.00000000000000000);
        CHECK(path_is_legal(1378, 358, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.69151408689932792);
        
        path = find_path_between_intersections(1501, 1500, 0.00000000000000000);
        CHECK(path_is_legal(1501, 1500, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.70245083565795285);
        
        path = find_path_between_intersections(462, 461, 0.00000000000000000);
        CHECK(path_is_legal(462, 461, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4.54148036273994116);
        
        path = find_path_between_intersections(0, 1412, 0.00000000000000000);
        CHECK(path_is_legal(0, 1412, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 14.19422116297794290);
        
        path = find_path_between_intersections(1629, 1533, 0.00000000000000000);
        CHECK(path_is_legal(1629, 1533, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 30.12106601591016997);
        
        path = find_path_between_intersections(1507, 1633, 0.00000000000000000);
        CHECK(path_is_legal(1507, 1633, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.45739991891922793);
        
        path = find_path_between_intersections(1146, 1379, 0.00000000000000000);
        CHECK(path_is_legal(1146, 1379, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.03058221212988732);
        
        path = find_path_between_intersections(1510, 966, 0.00000000000000000);
        CHECK(path_is_legal(1510, 966, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.57866851887993143);
        
        path = find_path_between_intersections(1688, 1687, 0.00000000000000000);
        CHECK(path_is_legal(1688, 1687, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.32971510667543136);
        
        path = find_path_between_intersections(1698, 145, 0.00000000000000000);
        CHECK(path_is_legal(1698, 145, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 8.48393702234746705);
        
        path = find_path_between_intersections(758, 691, 0.00000000000000000);
        CHECK(path_is_legal(758, 691, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 16.38587484818824791);
        
    } //find_path_between_intersections_simple_optimality

} //inter_inter_simple_path_func_public

