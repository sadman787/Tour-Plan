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
    TEST(find_path_between_intersections_legality) {
        std::vector<unsigned> path;
        
        path = find_path_between_intersections(22588, 426193, 0.00000000000000000);
        CHECK(path_is_legal(22588, 426193, path));
        
        path = find_path_between_intersections(102310, 26065, 15.00000000000000000);
        CHECK(path_is_legal(102310, 26065, path));
        
        path = find_path_between_intersections(26210, 259042, 0.00000000000000000);
        CHECK(path_is_legal(26210, 259042, path));
        
        path = find_path_between_intersections(146958, 317385, 15.00000000000000000);
        CHECK(path_is_legal(146958, 317385, path));
        
        path = find_path_between_intersections(160875, 20499, 0.00000000000000000);
        CHECK(path_is_legal(160875, 20499, path));
        
        path = find_path_between_intersections(191618, 318988, 15.00000000000000000);
        CHECK(path_is_legal(191618, 318988, path));
        
        path = find_path_between_intersections(204241, 138512, 15.00000000000000000);
        CHECK(path_is_legal(204241, 138512, path));
        
        path = find_path_between_intersections(221633, 428944, 0.00000000000000000);
        CHECK(path_is_legal(221633, 428944, path));
        
        path = find_path_between_intersections(254529, 69630, 15.00000000000000000);
        CHECK(path_is_legal(254529, 69630, path));
        
        path = find_path_between_intersections(261649, 267776, 0.00000000000000000);
        CHECK(path_is_legal(261649, 267776, path));
        
        path = find_path_between_intersections(265213, 370223, 0.00000000000000000);
        CHECK(path_is_legal(265213, 370223, path));
        
        path = find_path_between_intersections(278086, 424080, 15.00000000000000000);
        CHECK(path_is_legal(278086, 424080, path));
        
        path = find_path_between_intersections(143917, 104252, 0.00000000000000000);
        CHECK(path_is_legal(143917, 104252, path));
        
        path = find_path_between_intersections(325961, 288159, 0.00000000000000000);
        CHECK(path_is_legal(325961, 288159, path));
        
        path = find_path_between_intersections(330511, 283503, 15.00000000000000000);
        CHECK(path_is_legal(330511, 283503, path));
        
        path = find_path_between_intersections(331033, 77485, 15.00000000000000000);
        CHECK(path_is_legal(331033, 77485, path));
        
        path = find_path_between_intersections(177386, 247846, 0.00000000000000000);
        CHECK(path_is_legal(177386, 247846, path));
        
        path = find_path_between_intersections(125421, 335789, 15.00000000000000000);
        CHECK(path_is_legal(125421, 335789, path));
        
        path = find_path_between_intersections(381463, 331993, 0.00000000000000000);
        CHECK(path_is_legal(381463, 331993, path));
        
        path = find_path_between_intersections(391356, 53147, 15.00000000000000000);
        CHECK(path_is_legal(391356, 53147, path));
        
        path = find_path_between_intersections(395913, 379111, 0.00000000000000000);
        CHECK(path_is_legal(395913, 379111, path));
        
        path = find_path_between_intersections(82438, 308122, 0.00000000000000000);
        CHECK(path_is_legal(82438, 308122, path));
        
        path = find_path_between_intersections(274507, 77054, 0.00000000000000000);
        CHECK(path_is_legal(274507, 77054, path));
        
        path = find_path_between_intersections(174230, 166141, 15.00000000000000000);
        CHECK(path_is_legal(174230, 166141, path));
        
        path = find_path_between_intersections(161730, 163870, 15.00000000000000000);
        CHECK(path_is_legal(161730, 163870, path));
        
        path = find_path_between_intersections(418841, 112242, 15.00000000000000000);
        CHECK(path_is_legal(418841, 112242, path));
        
        path = find_path_between_intersections(424214, 39985, 15.00000000000000000);
        CHECK(path_is_legal(424214, 39985, path));
        
        path = find_path_between_intersections(156725, 105693, 0.00000000000000000);
        CHECK(path_is_legal(156725, 105693, path));
        
        path = find_path_between_intersections(39, 148822, 0.00000000000000000);
        CHECK(path_is_legal(39, 148822, path));
        
        path = find_path_between_intersections(288278, 188998, 0.00000000000000000);
        CHECK(path_is_legal(288278, 188998, path));
        
    } //find_path_between_intersections_legality

    TEST(find_path_between_intersections_optimality) {
        std::vector<unsigned> path;
        path = find_path_between_intersections(22588, 426193, 0.00000000000000000);
        CHECK(path_is_legal(22588, 426193, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3708.06117637256375019);
        
        path = find_path_between_intersections(102310, 26065, 15.00000000000000000);
        CHECK(path_is_legal(102310, 26065, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2090.99642788595019738);
        
        path = find_path_between_intersections(26210, 259042, 0.00000000000000000);
        CHECK(path_is_legal(26210, 259042, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4137.77326489265942655);
        
        path = find_path_between_intersections(146958, 317385, 15.00000000000000000);
        CHECK(path_is_legal(146958, 317385, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1582.73448425823426078);
        
        path = find_path_between_intersections(160875, 20499, 0.00000000000000000);
        CHECK(path_is_legal(160875, 20499, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3408.75196807684733358);
        
        path = find_path_between_intersections(191618, 318988, 15.00000000000000000);
        CHECK(path_is_legal(191618, 318988, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3654.46041545493017111);
        
        path = find_path_between_intersections(204241, 138512, 15.00000000000000000);
        CHECK(path_is_legal(204241, 138512, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3140.59579546423447027);
        
        path = find_path_between_intersections(221633, 428944, 0.00000000000000000);
        CHECK(path_is_legal(221633, 428944, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2133.44904627448840984);
        
        path = find_path_between_intersections(254529, 69630, 15.00000000000000000);
        CHECK(path_is_legal(254529, 69630, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3922.47764918305711035);
        
        path = find_path_between_intersections(261649, 267776, 0.00000000000000000);
        CHECK(path_is_legal(261649, 267776, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 5471.74271715016129747);
        
        path = find_path_between_intersections(265213, 370223, 0.00000000000000000);
        CHECK(path_is_legal(265213, 370223, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3374.45518141583715988);
        
        path = find_path_between_intersections(278086, 424080, 15.00000000000000000);
        CHECK(path_is_legal(278086, 424080, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 4175.50461052226182801);
        
        path = find_path_between_intersections(143917, 104252, 0.00000000000000000);
        CHECK(path_is_legal(143917, 104252, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2342.92490175483590065);
        
        path = find_path_between_intersections(325961, 288159, 0.00000000000000000);
        CHECK(path_is_legal(325961, 288159, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3589.84377409225589872);
        
        path = find_path_between_intersections(330511, 283503, 15.00000000000000000);
        CHECK(path_is_legal(330511, 283503, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3464.00398252420609424);
        
        path = find_path_between_intersections(331033, 77485, 15.00000000000000000);
        CHECK(path_is_legal(331033, 77485, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 5109.56051668266081833);
        
        path = find_path_between_intersections(177386, 247846, 0.00000000000000000);
        CHECK(path_is_legal(177386, 247846, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2645.01885580593534542);
        
        path = find_path_between_intersections(125421, 335789, 15.00000000000000000);
        CHECK(path_is_legal(125421, 335789, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3216.88754701082189058);
        
        path = find_path_between_intersections(381463, 331993, 0.00000000000000000);
        CHECK(path_is_legal(381463, 331993, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3156.53200666063003155);
        
        path = find_path_between_intersections(391356, 53147, 15.00000000000000000);
        CHECK(path_is_legal(391356, 53147, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2501.57321118543677585);
        
        path = find_path_between_intersections(395913, 379111, 0.00000000000000000);
        CHECK(path_is_legal(395913, 379111, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2584.25277478955149491);
        
        path = find_path_between_intersections(82438, 308122, 0.00000000000000000);
        CHECK(path_is_legal(82438, 308122, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2143.43108150722764549);
        
        path = find_path_between_intersections(274507, 77054, 0.00000000000000000);
        CHECK(path_is_legal(274507, 77054, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1478.99559873938665078);
        
        path = find_path_between_intersections(174230, 166141, 15.00000000000000000);
        CHECK(path_is_legal(174230, 166141, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 4691.05478748685254686);
        
        path = find_path_between_intersections(161730, 163870, 15.00000000000000000);
        CHECK(path_is_legal(161730, 163870, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2587.46694164032533081);
        
        path = find_path_between_intersections(418841, 112242, 15.00000000000000000);
        CHECK(path_is_legal(418841, 112242, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2015.53171574948623856);
        
        path = find_path_between_intersections(424214, 39985, 15.00000000000000000);
        CHECK(path_is_legal(424214, 39985, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1792.98665438500734126);
        
        path = find_path_between_intersections(156725, 105693, 0.00000000000000000);
        CHECK(path_is_legal(156725, 105693, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1993.59796854483988682);
        
        path = find_path_between_intersections(39, 148822, 0.00000000000000000);
        CHECK(path_is_legal(39, 148822, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3498.98518976936111358);
        
        path = find_path_between_intersections(288278, 188998, 0.00000000000000000);
        CHECK(path_is_legal(288278, 188998, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3639.67572338385025432);
        
    } //find_path_between_intersections_optimality

} //inter_inter_path_func_public

