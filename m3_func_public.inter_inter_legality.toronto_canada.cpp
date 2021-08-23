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
        rand_lat = std::uniform_real_distribution<double>(43.479999542, 43.919979095);
        rand_lon = std::uniform_real_distribution<double>(-79.789978027, -79.000007629);
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
        
        path = find_path_between_intersections(20510, 76659, 0.00000000000000000);
        CHECK(path_is_legal(20510, 76659, path));
        
        path = find_path_between_intersections(25454, 6484, 15.00000000000000000);
        CHECK(path_is_legal(25454, 6484, path));
        
        path = find_path_between_intersections(6521, 64448, 0.00000000000000000);
        CHECK(path_is_legal(6521, 64448, path));
        
        path = find_path_between_intersections(31204, 83543, 15.00000000000000000);
        CHECK(path_is_legal(31204, 83543, path));
        
        path = find_path_between_intersections(35806, 25937, 0.00000000000000000);
        CHECK(path_is_legal(35806, 25937, path));
        
        path = find_path_between_intersections(38992, 26296, 0.00000000000000000);
        CHECK(path_is_legal(38992, 26296, path));
        
        path = find_path_between_intersections(40025, 5100, 0.00000000000000000);
        CHECK(path_is_legal(40025, 5100, path));
        
        path = find_path_between_intersections(40237, 40770, 15.00000000000000000);
        CHECK(path_is_legal(40237, 40770, path));
        
        path = find_path_between_intersections(44133, 61663, 0.00000000000000000);
        CHECK(path_is_legal(44133, 61663, path));
        
        path = find_path_between_intersections(47674, 79363, 15.00000000000000000);
        CHECK(path_is_legal(47674, 79363, path));
        
        path = find_path_between_intersections(50814, 34461, 15.00000000000000000);
        CHECK(path_is_legal(50814, 34461, path));
        
        path = find_path_between_intersections(55141, 106719, 0.00000000000000000);
        CHECK(path_is_legal(55141, 106719, path));
        
        path = find_path_between_intersections(65097, 66621, 0.00000000000000000);
        CHECK(path_is_legal(65097, 66621, path));
        
        path = find_path_between_intersections(65984, 92110, 0.00000000000000000);
        CHECK(path_is_legal(65984, 92110, path));
        
        path = find_path_between_intersections(68296, 19170, 0.00000000000000000);
        CHECK(path_is_legal(68296, 19170, path));
        
        path = find_path_between_intersections(69186, 105509, 15.00000000000000000);
        CHECK(path_is_legal(69186, 105509, path));
        
        path = find_path_between_intersections(71722, 47022, 0.00000000000000000);
        CHECK(path_is_legal(71722, 47022, path));
        
        path = find_path_between_intersections(81098, 71692, 0.00000000000000000);
        CHECK(path_is_legal(81098, 71692, path));
        
        path = find_path_between_intersections(82359, 19278, 15.00000000000000000);
        CHECK(path_is_legal(82359, 19278, path));
        
        path = find_path_between_intersections(9, 37026, 0.00000000000000000);
        CHECK(path_is_legal(9, 37026, path));
        
        path = find_path_between_intersections(63326, 17323, 15.00000000000000000);
        CHECK(path_is_legal(63326, 17323, path));
        
        path = find_path_between_intersections(43347, 41335, 15.00000000000000000);
        CHECK(path_is_legal(43347, 41335, path));
        
        path = find_path_between_intersections(82230, 70534, 15.00000000000000000);
        CHECK(path_is_legal(82230, 70534, path));
        
        path = find_path_between_intersections(94906, 82598, 0.00000000000000000);
        CHECK(path_is_legal(94906, 82598, path));
        
        path = find_path_between_intersections(97367, 13222, 15.00000000000000000);
        CHECK(path_is_legal(97367, 13222, path));
        
        path = find_path_between_intersections(98501, 94321, 0.00000000000000000);
        CHECK(path_is_legal(98501, 94321, path));
        
        path = find_path_between_intersections(36562, 78964, 15.00000000000000000);
        CHECK(path_is_legal(36562, 78964, path));
        
        path = find_path_between_intersections(104205, 27925, 15.00000000000000000);
        CHECK(path_is_legal(104205, 27925, path));
        
        path = find_path_between_intersections(5619, 106035, 0.00000000000000000);
        CHECK(path_is_legal(5619, 106035, path));
        
        path = find_path_between_intersections(105542, 9948, 15.00000000000000000);
        CHECK(path_is_legal(105542, 9948, path));
        
    } //find_path_between_intersections_legality

    TEST(find_path_between_intersections_optimality) {
        std::vector<unsigned> path;
        path = find_path_between_intersections(20510, 76659, 0.00000000000000000);
        CHECK(path_is_legal(20510, 76659, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1349.26085003037064780);
        
        path = find_path_between_intersections(25454, 6484, 15.00000000000000000);
        CHECK(path_is_legal(25454, 6484, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 671.49284765610127579);
        
        path = find_path_between_intersections(6521, 64448, 0.00000000000000000);
        CHECK(path_is_legal(6521, 64448, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 733.48680433282027025);
        
        path = find_path_between_intersections(31204, 83543, 15.00000000000000000);
        CHECK(path_is_legal(31204, 83543, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2530.20198875657524695);
        
        path = find_path_between_intersections(35806, 25937, 0.00000000000000000);
        CHECK(path_is_legal(35806, 25937, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2456.32479501058605820);
        
        path = find_path_between_intersections(38992, 26296, 0.00000000000000000);
        CHECK(path_is_legal(38992, 26296, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 831.79445104476553752);
        
        path = find_path_between_intersections(40025, 5100, 0.00000000000000000);
        CHECK(path_is_legal(40025, 5100, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1674.97045398580280562);
        
        path = find_path_between_intersections(40237, 40770, 15.00000000000000000);
        CHECK(path_is_legal(40237, 40770, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 211.71014008555803798);
        
        path = find_path_between_intersections(44133, 61663, 0.00000000000000000);
        CHECK(path_is_legal(44133, 61663, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1813.57214168313703340);
        
        path = find_path_between_intersections(47674, 79363, 15.00000000000000000);
        CHECK(path_is_legal(47674, 79363, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1004.14016659595279179);
        
        path = find_path_between_intersections(50814, 34461, 15.00000000000000000);
        CHECK(path_is_legal(50814, 34461, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2020.17082894758232214);
        
        path = find_path_between_intersections(55141, 106719, 0.00000000000000000);
        CHECK(path_is_legal(55141, 106719, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1818.96001385856061461);
        
        path = find_path_between_intersections(65097, 66621, 0.00000000000000000);
        CHECK(path_is_legal(65097, 66621, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 566.24575934012489142);
        
        path = find_path_between_intersections(65984, 92110, 0.00000000000000000);
        CHECK(path_is_legal(65984, 92110, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 563.28499967118602854);
        
        path = find_path_between_intersections(68296, 19170, 0.00000000000000000);
        CHECK(path_is_legal(68296, 19170, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1314.98429130271460963);
        
        path = find_path_between_intersections(69186, 105509, 15.00000000000000000);
        CHECK(path_is_legal(69186, 105509, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2227.68403736206846588);
        
        path = find_path_between_intersections(71722, 47022, 0.00000000000000000);
        CHECK(path_is_legal(71722, 47022, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2109.71577363680626149);
        
        path = find_path_between_intersections(81098, 71692, 0.00000000000000000);
        CHECK(path_is_legal(81098, 71692, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 589.08023131039556120);
        
        path = find_path_between_intersections(82359, 19278, 15.00000000000000000);
        CHECK(path_is_legal(82359, 19278, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1177.72673753896469862);
        
        path = find_path_between_intersections(9, 37026, 0.00000000000000000);
        CHECK(path_is_legal(9, 37026, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1788.70796324029083735);
        
        path = find_path_between_intersections(63326, 17323, 15.00000000000000000);
        CHECK(path_is_legal(63326, 17323, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1813.26996109788592548);
        
        path = find_path_between_intersections(43347, 41335, 15.00000000000000000);
        CHECK(path_is_legal(43347, 41335, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 953.12140383964037937);
        
        path = find_path_between_intersections(82230, 70534, 15.00000000000000000);
        CHECK(path_is_legal(82230, 70534, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1216.30868071390591467);
        
        path = find_path_between_intersections(94906, 82598, 0.00000000000000000);
        CHECK(path_is_legal(94906, 82598, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1725.37531949114986674);
        
        path = find_path_between_intersections(97367, 13222, 15.00000000000000000);
        CHECK(path_is_legal(97367, 13222, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2165.17305072148610634);
        
        path = find_path_between_intersections(98501, 94321, 0.00000000000000000);
        CHECK(path_is_legal(98501, 94321, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.72894808941914135);
        
        path = find_path_between_intersections(36562, 78964, 15.00000000000000000);
        CHECK(path_is_legal(36562, 78964, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2642.39065170988214959);
        
        path = find_path_between_intersections(104205, 27925, 15.00000000000000000);
        CHECK(path_is_legal(104205, 27925, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 391.95503702589377326);
        
        path = find_path_between_intersections(5619, 106035, 0.00000000000000000);
        CHECK(path_is_legal(5619, 106035, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1709.35130477509073899);
        
        path = find_path_between_intersections(105542, 9948, 15.00000000000000000);
        CHECK(path_is_legal(105542, 9948, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 796.25321840686842734);
        
    } //find_path_between_intersections_optimality

} //inter_inter_path_func_public

