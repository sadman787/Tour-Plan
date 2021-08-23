#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_path_func_public) {
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
    TEST(find_path_between_intersections_legality) {
        std::vector<unsigned> path;
        
        path = find_path_between_intersections(0, 589, 0.00000000000000000);
        CHECK(path_is_legal(0, 589, path));
        
        path = find_path_between_intersections(103, 1025, 0.00000000000000000);
        CHECK(path_is_legal(103, 1025, path));
        
        path = find_path_between_intersections(89, 1688, 0.00000000000000000);
        CHECK(path_is_legal(89, 1688, path));
        
        path = find_path_between_intersections(496, 1329, 15.00000000000000000);
        CHECK(path_is_legal(496, 1329, path));
        
        path = find_path_between_intersections(534, 1136, 15.00000000000000000);
        CHECK(path_is_legal(534, 1136, path));
        
        path = find_path_between_intersections(570, 412, 0.00000000000000000);
        CHECK(path_is_legal(570, 412, path));
        
        path = find_path_between_intersections(582, 1257, 15.00000000000000000);
        CHECK(path_is_legal(582, 1257, path));
        
        path = find_path_between_intersections(637, 81, 0.00000000000000000);
        CHECK(path_is_legal(637, 81, path));
        
        path = find_path_between_intersections(640, 649, 15.00000000000000000);
        CHECK(path_is_legal(640, 649, path));
        
        path = find_path_between_intersections(690, 658, 15.00000000000000000);
        CHECK(path_is_legal(690, 658, path));
        
        path = find_path_between_intersections(702, 981, 0.00000000000000000);
        CHECK(path_is_legal(702, 981, path));
        
        path = find_path_between_intersections(758, 1263, 15.00000000000000000);
        CHECK(path_is_legal(758, 1263, path));
        
        path = find_path_between_intersections(808, 548, 15.00000000000000000);
        CHECK(path_is_legal(808, 548, path));
        
        path = find_path_between_intersections(405, 103, 0.00000000000000000);
        CHECK(path_is_legal(405, 103, path));
        
        path = find_path_between_intersections(620, 418, 0.00000000000000000);
        CHECK(path_is_legal(620, 418, path));
        
        path = find_path_between_intersections(1008, 275, 15.00000000000000000);
        CHECK(path_is_legal(1008, 275, path));
        
        path = find_path_between_intersections(1087, 305, 0.00000000000000000);
        CHECK(path_is_legal(1087, 305, path));
        
        path = find_path_between_intersections(1101, 1679, 15.00000000000000000);
        CHECK(path_is_legal(1101, 1679, path));
        
        path = find_path_between_intersections(1141, 748, 0.00000000000000000);
        CHECK(path_is_legal(1141, 748, path));
        
        path = find_path_between_intersections(1291, 1141, 0.00000000000000000);
        CHECK(path_is_legal(1291, 1141, path));
        
        path = find_path_between_intersections(1309, 1122, 15.00000000000000000);
        CHECK(path_is_legal(1309, 1122, path));
        
        path = find_path_between_intersections(1311, 306, 15.00000000000000000);
        CHECK(path_is_legal(1311, 306, path));
        
        path = find_path_between_intersections(1036, 1060, 0.00000000000000000);
        CHECK(path_is_legal(1036, 1060, path));
        
        path = find_path_between_intersections(1050, 1466, 0.00000000000000000);
        CHECK(path_is_legal(1050, 1466, path));
        
        path = find_path_between_intersections(1550, 210, 15.00000000000000000);
        CHECK(path_is_legal(1550, 210, path));
        
        path = find_path_between_intersections(1568, 1501, 0.00000000000000000);
        CHECK(path_is_legal(1568, 1501, path));
        
        path = find_path_between_intersections(877, 1698, 0.00000000000000000);
        CHECK(path_is_legal(877, 1698, path));
        
        path = find_path_between_intersections(1658, 444, 15.00000000000000000);
        CHECK(path_is_legal(1658, 444, path));
        
        path = find_path_between_intersections(1510, 1314, 0.00000000000000000);
        CHECK(path_is_legal(1510, 1314, path));
        
        path = find_path_between_intersections(1680, 158, 15.00000000000000000);
        CHECK(path_is_legal(1680, 158, path));
        
    } //find_path_between_intersections_legality

    TEST(find_path_between_intersections_optimality) {
        std::vector<unsigned> path;
        path = find_path_between_intersections(0, 589, 0.00000000000000000);
        CHECK(path_is_legal(0, 589, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 176.04758212437866405);
        
        path = find_path_between_intersections(103, 1025, 0.00000000000000000);
        CHECK(path_is_legal(103, 1025, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 312.46671284522000178);
        
        path = find_path_between_intersections(89, 1688, 0.00000000000000000);
        CHECK(path_is_legal(89, 1688, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 288.37367034502619845);
        
        path = find_path_between_intersections(496, 1329, 15.00000000000000000);
        CHECK(path_is_legal(496, 1329, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 473.29223115450753312);
        
        path = find_path_between_intersections(534, 1136, 15.00000000000000000);
        CHECK(path_is_legal(534, 1136, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 469.88430178859613306);
        
        path = find_path_between_intersections(570, 412, 0.00000000000000000);
        CHECK(path_is_legal(570, 412, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 251.70033956909844619);
        
        path = find_path_between_intersections(582, 1257, 15.00000000000000000);
        CHECK(path_is_legal(582, 1257, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 629.74146848571137980);
        
        path = find_path_between_intersections(637, 81, 0.00000000000000000);
        CHECK(path_is_legal(637, 81, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 251.57190324374113288);
        
        path = find_path_between_intersections(640, 649, 15.00000000000000000);
        CHECK(path_is_legal(640, 649, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 263.12327169610568944);
        
        path = find_path_between_intersections(690, 658, 15.00000000000000000);
        CHECK(path_is_legal(690, 658, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 378.55994881658210716);
        
        path = find_path_between_intersections(702, 981, 0.00000000000000000);
        CHECK(path_is_legal(702, 981, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 197.52858843520897381);
        
        path = find_path_between_intersections(758, 1263, 15.00000000000000000);
        CHECK(path_is_legal(758, 1263, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 517.96800792230317256);
        
        path = find_path_between_intersections(808, 548, 15.00000000000000000);
        CHECK(path_is_legal(808, 548, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 150.51020625515883467);
        
        path = find_path_between_intersections(405, 103, 0.00000000000000000);
        CHECK(path_is_legal(405, 103, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 373.74278813252647069);
        
        path = find_path_between_intersections(620, 418, 0.00000000000000000);
        CHECK(path_is_legal(620, 418, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 94.58352910269611868);
        
        path = find_path_between_intersections(1008, 275, 15.00000000000000000);
        CHECK(path_is_legal(1008, 275, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 734.21114432479271272);
        
        path = find_path_between_intersections(1087, 305, 0.00000000000000000);
        CHECK(path_is_legal(1087, 305, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 232.05216292478516493);
        
        path = find_path_between_intersections(1101, 1679, 15.00000000000000000);
        CHECK(path_is_legal(1101, 1679, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 294.13925134390609628);
        
        path = find_path_between_intersections(1141, 748, 0.00000000000000000);
        CHECK(path_is_legal(1141, 748, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 118.46665453886328123);
        
        path = find_path_between_intersections(1291, 1141, 0.00000000000000000);
        CHECK(path_is_legal(1291, 1141, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 295.82274331369882248);
        
        path = find_path_between_intersections(1309, 1122, 15.00000000000000000);
        CHECK(path_is_legal(1309, 1122, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 408.67456373045638429);
        
        path = find_path_between_intersections(1311, 306, 15.00000000000000000);
        CHECK(path_is_legal(1311, 306, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 237.55010078848246735);
        
        path = find_path_between_intersections(1036, 1060, 0.00000000000000000);
        CHECK(path_is_legal(1036, 1060, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 187.27344042579284178);
        
        path = find_path_between_intersections(1050, 1466, 0.00000000000000000);
        CHECK(path_is_legal(1050, 1466, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 166.85895170964596446);
        
        path = find_path_between_intersections(1550, 210, 15.00000000000000000);
        CHECK(path_is_legal(1550, 210, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 66.79527098106851213);
        
        path = find_path_between_intersections(1568, 1501, 0.00000000000000000);
        CHECK(path_is_legal(1568, 1501, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 430.90567142957064561);
        
        path = find_path_between_intersections(877, 1698, 0.00000000000000000);
        CHECK(path_is_legal(877, 1698, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 554.49403131584529092);
        
        path = find_path_between_intersections(1658, 444, 15.00000000000000000);
        CHECK(path_is_legal(1658, 444, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 165.55948126154950728);
        
        path = find_path_between_intersections(1510, 1314, 0.00000000000000000);
        CHECK(path_is_legal(1510, 1314, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 29.89433188865661606);
        
        path = find_path_between_intersections(1680, 158, 15.00000000000000000);
        CHECK(path_is_legal(1680, 158, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 345.65597656842442120);
        
    } //find_path_between_intersections_optimality

} //inter_inter_path_func_public

