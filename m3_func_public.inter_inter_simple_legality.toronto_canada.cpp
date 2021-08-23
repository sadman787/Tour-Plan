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
    TEST(find_path_between_intersections_simple_legality) {
        std::vector<unsigned> path;
        
        path = find_path_between_intersections(5100, 5101, 0.00000000000000000);
        CHECK(path_is_legal(5100, 5101, path));
        
        path = find_path_between_intersections(13222, 23746, 0.00000000000000000);
        CHECK(path_is_legal(13222, 23746, path));
        
        path = find_path_between_intersections(25937, 24777, 0.00000000000000000);
        CHECK(path_is_legal(25937, 24777, path));
        
        path = find_path_between_intersections(31204, 31203, 0.00000000000000000);
        CHECK(path_is_legal(31204, 31203, path));
        
        path = find_path_between_intersections(36012, 66455, 0.00000000000000000);
        CHECK(path_is_legal(36012, 66455, path));
        
        path = find_path_between_intersections(50444, 49782, 0.00000000000000000);
        CHECK(path_is_legal(50444, 49782, path));
        
        path = find_path_between_intersections(50814, 68574, 0.00000000000000000);
        CHECK(path_is_legal(50814, 68574, path));
        
        path = find_path_between_intersections(53232, 53250, 0.00000000000000000);
        CHECK(path_is_legal(53232, 53250, path));
        
        path = find_path_between_intersections(57720, 57747, 0.00000000000000000);
        CHECK(path_is_legal(57720, 57747, path));
        
        path = find_path_between_intersections(27925, 62494, 0.00000000000000000);
        CHECK(path_is_legal(27925, 62494, path));
        
        path = find_path_between_intersections(63326, 93138, 0.00000000000000000);
        CHECK(path_is_legal(63326, 93138, path));
        
        path = find_path_between_intersections(64448, 64449, 0.00000000000000000);
        CHECK(path_is_legal(64448, 64449, path));
        
        path = find_path_between_intersections(65709, 65672, 0.00000000000000000);
        CHECK(path_is_legal(65709, 65672, path));
        
        path = find_path_between_intersections(34406, 34409, 0.00000000000000000);
        CHECK(path_is_legal(34406, 34409, path));
        
        path = find_path_between_intersections(71692, 11626, 0.00000000000000000);
        CHECK(path_is_legal(71692, 11626, path));
        
        path = find_path_between_intersections(33188, 73114, 0.00000000000000000);
        CHECK(path_is_legal(33188, 73114, path));
        
        path = find_path_between_intersections(26296, 74002, 0.00000000000000000);
        CHECK(path_is_legal(26296, 74002, path));
        
        path = find_path_between_intersections(69186, 32340, 0.00000000000000000);
        CHECK(path_is_legal(69186, 32340, path));
        
        path = find_path_between_intersections(82598, 82590, 0.00000000000000000);
        CHECK(path_is_legal(82598, 82590, path));
        
        path = find_path_between_intersections(83507, 83509, 0.00000000000000000);
        CHECK(path_is_legal(83507, 83509, path));
        
        path = find_path_between_intersections(86217, 89186, 0.00000000000000000);
        CHECK(path_is_legal(86217, 89186, path));
        
        path = find_path_between_intersections(86592, 86591, 0.00000000000000000);
        CHECK(path_is_legal(86592, 86591, path));
        
        path = find_path_between_intersections(19278, 87490, 0.00000000000000000);
        CHECK(path_is_legal(19278, 87490, path));
        
        path = find_path_between_intersections(9, 13445, 0.00000000000000000);
        CHECK(path_is_legal(9, 13445, path));
        
        path = find_path_between_intersections(89779, 89785, 0.00000000000000000);
        CHECK(path_is_legal(89779, 89785, path));
        
        path = find_path_between_intersections(90809, 90810, 0.00000000000000000);
        CHECK(path_is_legal(90809, 90810, path));
        
        path = find_path_between_intersections(63858, 63857, 0.00000000000000000);
        CHECK(path_is_legal(63858, 63857, path));
        
        path = find_path_between_intersections(94321, 98486, 0.00000000000000000);
        CHECK(path_is_legal(94321, 98486, path));
        
        path = find_path_between_intersections(106035, 89025, 0.00000000000000000);
        CHECK(path_is_legal(106035, 89025, path));
        
        path = find_path_between_intersections(106719, 106723, 0.00000000000000000);
        CHECK(path_is_legal(106719, 106723, path));
        
    } //find_path_between_intersections_simple_legality

    TEST(find_path_between_intersections_simple_optimality) {
        std::vector<unsigned> path;
        path = find_path_between_intersections(5100, 5101, 0.00000000000000000);
        CHECK(path_is_legal(5100, 5101, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 14.77362895876531113);
        
        path = find_path_between_intersections(13222, 23746, 0.00000000000000000);
        CHECK(path_is_legal(13222, 23746, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 24.43654849664330442);
        
        path = find_path_between_intersections(25937, 24777, 0.00000000000000000);
        CHECK(path_is_legal(25937, 24777, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 8.57824635194903706);
        
        path = find_path_between_intersections(31204, 31203, 0.00000000000000000);
        CHECK(path_is_legal(31204, 31203, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6.70541914204923017);
        
        path = find_path_between_intersections(36012, 66455, 0.00000000000000000);
        CHECK(path_is_legal(36012, 66455, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 26.56293224763040328);
        
        path = find_path_between_intersections(50444, 49782, 0.00000000000000000);
        CHECK(path_is_legal(50444, 49782, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 28.47874257550629551);
        
        path = find_path_between_intersections(50814, 68574, 0.00000000000000000);
        CHECK(path_is_legal(50814, 68574, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5.49448024634639953);
        
        path = find_path_between_intersections(53232, 53250, 0.00000000000000000);
        CHECK(path_is_legal(53232, 53250, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 33.39387888253683201);
        
        path = find_path_between_intersections(57720, 57747, 0.00000000000000000);
        CHECK(path_is_legal(57720, 57747, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 0.74490910971583346);
        
        path = find_path_between_intersections(27925, 62494, 0.00000000000000000);
        CHECK(path_is_legal(27925, 62494, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 8.73487587986469016);
        
        path = find_path_between_intersections(63326, 93138, 0.00000000000000000);
        CHECK(path_is_legal(63326, 93138, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.13441946730466459);
        
        path = find_path_between_intersections(64448, 64449, 0.00000000000000000);
        CHECK(path_is_legal(64448, 64449, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.01370940302279666);
        
        path = find_path_between_intersections(65709, 65672, 0.00000000000000000);
        CHECK(path_is_legal(65709, 65672, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 48.33413457815498759);
        
        path = find_path_between_intersections(34406, 34409, 0.00000000000000000);
        CHECK(path_is_legal(34406, 34409, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5.42797123876484555);
        
        path = find_path_between_intersections(71692, 11626, 0.00000000000000000);
        CHECK(path_is_legal(71692, 11626, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 23.63816397242758782);
        
        path = find_path_between_intersections(33188, 73114, 0.00000000000000000);
        CHECK(path_is_legal(33188, 73114, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.34273136276358529);
        
        path = find_path_between_intersections(26296, 74002, 0.00000000000000000);
        CHECK(path_is_legal(26296, 74002, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.15003066223536621);
        
        path = find_path_between_intersections(69186, 32340, 0.00000000000000000);
        CHECK(path_is_legal(69186, 32340, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 9.40755340156452213);
        
        path = find_path_between_intersections(82598, 82590, 0.00000000000000000);
        CHECK(path_is_legal(82598, 82590, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.44521266809096716);
        
        path = find_path_between_intersections(83507, 83509, 0.00000000000000000);
        CHECK(path_is_legal(83507, 83509, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 11.32856851633632900);
        
        path = find_path_between_intersections(86217, 89186, 0.00000000000000000);
        CHECK(path_is_legal(86217, 89186, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4.24556877328201132);
        
        path = find_path_between_intersections(86592, 86591, 0.00000000000000000);
        CHECK(path_is_legal(86592, 86591, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.18468382732186317);
        
        path = find_path_between_intersections(19278, 87490, 0.00000000000000000);
        CHECK(path_is_legal(19278, 87490, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 10.19777893366977217);
        
        path = find_path_between_intersections(9, 13445, 0.00000000000000000);
        CHECK(path_is_legal(9, 13445, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 15.13158731681028790);
        
        path = find_path_between_intersections(89779, 89785, 0.00000000000000000);
        CHECK(path_is_legal(89779, 89785, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4.92635148155003399);
        
        path = find_path_between_intersections(90809, 90810, 0.00000000000000000);
        CHECK(path_is_legal(90809, 90810, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1.21283768460279284);
        
        path = find_path_between_intersections(63858, 63857, 0.00000000000000000);
        CHECK(path_is_legal(63858, 63857, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.44393942696772504);
        
        path = find_path_between_intersections(94321, 98486, 0.00000000000000000);
        CHECK(path_is_legal(94321, 98486, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 10.60383850801276040);
        
        path = find_path_between_intersections(106035, 89025, 0.00000000000000000);
        CHECK(path_is_legal(106035, 89025, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2.30158047065706439);
        
        path = find_path_between_intersections(106719, 106723, 0.00000000000000000);
        CHECK(path_is_legal(106719, 106723, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6.15483342767940034);
        
    } //find_path_between_intersections_simple_optimality

} //inter_inter_simple_path_func_public

