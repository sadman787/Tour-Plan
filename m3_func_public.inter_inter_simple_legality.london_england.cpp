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
        rand_lat = std::uniform_real_distribution<double>(50.941036224, 51.983997345);
        rand_lon = std::uniform_real_distribution<double>(-1.114988804, 0.894998193);
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
        
        path = find_path_between_intersections(8776, 8777, 0.00000000000000000);
        CHECK(path_is_legal(8776, 8777, path));
        
        path = find_path_between_intersections(26210, 26211, 0.00000000000000000);
        CHECK(path_is_legal(26210, 26211, path));
        
        path = find_path_between_intersections(38014, 38015, 0.00000000000000000);
        CHECK(path_is_legal(38014, 38015, path));
        
        path = find_path_between_intersections(39985, 403566, 0.00000000000000000);
        CHECK(path_is_legal(39985, 403566, path));
        
        path = find_path_between_intersections(112242, 111487, 0.00000000000000000);
        CHECK(path_is_legal(112242, 111487, path));
        
        path = find_path_between_intersections(156725, 123997, 0.00000000000000000);
        CHECK(path_is_legal(156725, 123997, path));
        
        path = find_path_between_intersections(167896, 36650, 0.00000000000000000);
        CHECK(path_is_legal(167896, 36650, path));
        
        path = find_path_between_intersections(174230, 431059, 0.00000000000000000);
        CHECK(path_is_legal(174230, 431059, path));
        
        path = find_path_between_intersections(26065, 148887, 0.00000000000000000);
        CHECK(path_is_legal(26065, 148887, path));
        
        path = find_path_between_intersections(22588, 193241, 0.00000000000000000);
        CHECK(path_is_legal(22588, 193241, path));
        
        path = find_path_between_intersections(201287, 401413, 0.00000000000000000);
        CHECK(path_is_legal(201287, 401413, path));
        
        path = find_path_between_intersections(244645, 244656, 0.00000000000000000);
        CHECK(path_is_legal(244645, 244656, path));
        
        path = find_path_between_intersections(250941, 125320, 0.00000000000000000);
        CHECK(path_is_legal(250941, 125320, path));
        
        path = find_path_between_intersections(264756, 264755, 0.00000000000000000);
        CHECK(path_is_legal(264756, 264755, path));
        
        path = find_path_between_intersections(288231, 287582, 0.00000000000000000);
        CHECK(path_is_legal(288231, 287582, path));
        
        path = find_path_between_intersections(143917, 143918, 0.00000000000000000);
        CHECK(path_is_legal(143917, 143918, path));
        
        path = find_path_between_intersections(304730, 304729, 0.00000000000000000);
        CHECK(path_is_legal(304730, 304729, path));
        
        path = find_path_between_intersections(305450, 305446, 0.00000000000000000);
        CHECK(path_is_legal(305450, 305446, path));
        
        path = find_path_between_intersections(7286, 10713, 0.00000000000000000);
        CHECK(path_is_legal(7286, 10713, path));
        
        path = find_path_between_intersections(325961, 325960, 0.00000000000000000);
        CHECK(path_is_legal(325961, 325960, path));
        
        path = find_path_between_intersections(308122, 17849, 0.00000000000000000);
        CHECK(path_is_legal(308122, 17849, path));
        
        path = find_path_between_intersections(177386, 334654, 0.00000000000000000);
        CHECK(path_is_legal(177386, 334654, path));
        
        path = find_path_between_intersections(360158, 360153, 0.00000000000000000);
        CHECK(path_is_legal(360158, 360153, path));
        
        path = find_path_between_intersections(379111, 3785, 0.00000000000000000);
        CHECK(path_is_legal(379111, 3785, path));
        
        path = find_path_between_intersections(381463, 381466, 0.00000000000000000);
        CHECK(path_is_legal(381463, 381466, path));
        
        path = find_path_between_intersections(74565, 407865, 0.00000000000000000);
        CHECK(path_is_legal(74565, 407865, path));
        
        path = find_path_between_intersections(302174, 6321, 0.00000000000000000);
        CHECK(path_is_legal(302174, 6321, path));
        
        path = find_path_between_intersections(421453, 421452, 0.00000000000000000);
        CHECK(path_is_legal(421453, 421452, path));
        
        path = find_path_between_intersections(428944, 288824, 0.00000000000000000);
        CHECK(path_is_legal(428944, 288824, path));
        
        path = find_path_between_intersections(39, 4789, 0.00000000000000000);
        CHECK(path_is_legal(39, 4789, path));
        
    } //find_path_between_intersections_simple_legality

    TEST(find_path_between_intersections_simple_optimality) {
        std::vector<unsigned> path;
        path = find_path_between_intersections(8776, 8777, 0.00000000000000000);
        CHECK(path_is_legal(8776, 8777, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.10979919020618256);
        
        path = find_path_between_intersections(26210, 26211, 0.00000000000000000);
        CHECK(path_is_legal(26210, 26211, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 12.33818856155166088);
        
        path = find_path_between_intersections(38014, 38015, 0.00000000000000000);
        CHECK(path_is_legal(38014, 38015, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.09488626336134875);
        
        path = find_path_between_intersections(39985, 403566, 0.00000000000000000);
        CHECK(path_is_legal(39985, 403566, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.72115221570278365);
        
        path = find_path_between_intersections(112242, 111487, 0.00000000000000000);
        CHECK(path_is_legal(112242, 111487, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 30.97530376279389586);
        
        path = find_path_between_intersections(156725, 123997, 0.00000000000000000);
        CHECK(path_is_legal(156725, 123997, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 27.76641371053962359);
        
        path = find_path_between_intersections(167896, 36650, 0.00000000000000000);
        CHECK(path_is_legal(167896, 36650, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.52591487691695349);
        
        path = find_path_between_intersections(174230, 431059, 0.00000000000000000);
        CHECK(path_is_legal(174230, 431059, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 9.66877398421102008);
        
        path = find_path_between_intersections(26065, 148887, 0.00000000000000000);
        CHECK(path_is_legal(26065, 148887, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 8.41933906734627335);
        
        path = find_path_between_intersections(22588, 193241, 0.00000000000000000);
        CHECK(path_is_legal(22588, 193241, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.65806895585923897);
        
        path = find_path_between_intersections(201287, 401413, 0.00000000000000000);
        CHECK(path_is_legal(201287, 401413, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 16.27271297561394903);
        
        path = find_path_between_intersections(244645, 244656, 0.00000000000000000);
        CHECK(path_is_legal(244645, 244656, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3.34231314932798718);
        
        path = find_path_between_intersections(250941, 125320, 0.00000000000000000);
        CHECK(path_is_legal(250941, 125320, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6.73137472855404706);
        
        path = find_path_between_intersections(264756, 264755, 0.00000000000000000);
        CHECK(path_is_legal(264756, 264755, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5.64009626509810236);
        
        path = find_path_between_intersections(288231, 287582, 0.00000000000000000);
        CHECK(path_is_legal(288231, 287582, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.52488221599824492);
        
        path = find_path_between_intersections(143917, 143918, 0.00000000000000000);
        CHECK(path_is_legal(143917, 143918, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 7.94347871555818585);
        
        path = find_path_between_intersections(304730, 304729, 0.00000000000000000);
        CHECK(path_is_legal(304730, 304729, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5.48165958139791520);
        
        path = find_path_between_intersections(305450, 305446, 0.00000000000000000);
        CHECK(path_is_legal(305450, 305446, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 21.05135664084323821);
        
        path = find_path_between_intersections(7286, 10713, 0.00000000000000000);
        CHECK(path_is_legal(7286, 10713, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.80453995744547946);
        
        path = find_path_between_intersections(325961, 325960, 0.00000000000000000);
        CHECK(path_is_legal(325961, 325960, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.03681234482629514);
        
        path = find_path_between_intersections(308122, 17849, 0.00000000000000000);
        CHECK(path_is_legal(308122, 17849, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 10.36354904198981686);
        
        path = find_path_between_intersections(177386, 334654, 0.00000000000000000);
        CHECK(path_is_legal(177386, 334654, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.84322576251495374);
        
        path = find_path_between_intersections(360158, 360153, 0.00000000000000000);
        CHECK(path_is_legal(360158, 360153, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 14.81661921122492664);
        
        path = find_path_between_intersections(379111, 3785, 0.00000000000000000);
        CHECK(path_is_legal(379111, 3785, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4.31145116121094141);
        
        path = find_path_between_intersections(381463, 381466, 0.00000000000000000);
        CHECK(path_is_legal(381463, 381466, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 40.02991875473772154);
        
        path = find_path_between_intersections(74565, 407865, 0.00000000000000000);
        CHECK(path_is_legal(74565, 407865, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5.29121628078450623);
        
        path = find_path_between_intersections(302174, 6321, 0.00000000000000000);
        CHECK(path_is_legal(302174, 6321, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.37209736447025765);
        
        path = find_path_between_intersections(421453, 421452, 0.00000000000000000);
        CHECK(path_is_legal(421453, 421452, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6.17504780843449286);
        
        path = find_path_between_intersections(428944, 288824, 0.00000000000000000);
        CHECK(path_is_legal(428944, 288824, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5.68260929918877000);
        
        path = find_path_between_intersections(39, 4789, 0.00000000000000000);
        CHECK(path_is_legal(39, 4789, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6.83020785371774686);
        
    } //find_path_between_intersections_simple_optimality

} //inter_inter_simple_path_func_public

