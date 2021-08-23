#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_path_perf_hard_public) {
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
    TEST_FIXTURE(MapFixture, find_path_between_intersections_perf_hard) {
        //Verify Functionality
        std::vector<unsigned> path;
        path = find_path_between_intersections(3880, 89039, 15.00000000000000000);
        CHECK(path_is_legal(3880, 89039, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1077.87294946711267585);
        
        path = find_path_between_intersections(16687, 63241, 0.00000000000000000);
        CHECK(path_is_legal(16687, 63241, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1288.27007038493616164);
        
        path = find_path_between_intersections(16781, 17877, 15.00000000000000000);
        CHECK(path_is_legal(16781, 17877, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1132.75227401682013806);
        
        path = find_path_between_intersections(17843, 43552, 0.00000000000000000);
        CHECK(path_is_legal(17843, 43552, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1402.23648547544985377);
        
        path = find_path_between_intersections(21097, 107926, 0.00000000000000000);
        CHECK(path_is_legal(21097, 107926, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1307.76918418503396424);
        
        path = find_path_between_intersections(31758, 52913, 0.00000000000000000);
        CHECK(path_is_legal(31758, 52913, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1429.01490758259524227);
        
        path = find_path_between_intersections(31900, 40658, 15.00000000000000000);
        CHECK(path_is_legal(31900, 40658, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1389.90244531190978705);
        
        path = find_path_between_intersections(34031, 28008, 0.00000000000000000);
        CHECK(path_is_legal(34031, 28008, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1550.83025597099663173);
        
        path = find_path_between_intersections(35114, 79808, 15.00000000000000000);
        CHECK(path_is_legal(35114, 79808, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1748.85271365264293308);
        
        path = find_path_between_intersections(37326, 35810, 15.00000000000000000);
        CHECK(path_is_legal(37326, 35810, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2311.83924455696478617);
        
        path = find_path_between_intersections(39083, 32357, 0.00000000000000000);
        CHECK(path_is_legal(39083, 32357, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 238.87007388962905452);
        
        path = find_path_between_intersections(41608, 13340, 0.00000000000000000);
        CHECK(path_is_legal(41608, 13340, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 736.39438654873367796);
        
        path = find_path_between_intersections(46576, 4937, 0.00000000000000000);
        CHECK(path_is_legal(46576, 4937, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1625.81526908912451290);
        
        path = find_path_between_intersections(49014, 100911, 0.00000000000000000);
        CHECK(path_is_legal(49014, 100911, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1544.90200926748002530);
        
        path = find_path_between_intersections(66870, 85726, 0.00000000000000000);
        CHECK(path_is_legal(66870, 85726, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1068.49854281737998463);
        
        path = find_path_between_intersections(71040, 3202, 15.00000000000000000);
        CHECK(path_is_legal(71040, 3202, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 857.49966728926619908);
        
        path = find_path_between_intersections(13792, 99910, 15.00000000000000000);
        CHECK(path_is_legal(13792, 99910, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2509.42101936447124899);
        
        path = find_path_between_intersections(72220, 11730, 0.00000000000000000);
        CHECK(path_is_legal(72220, 11730, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1055.74673377742283265);
        
        path = find_path_between_intersections(74017, 97865, 0.00000000000000000);
        CHECK(path_is_legal(74017, 97865, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1845.95828150656507205);
        
        path = find_path_between_intersections(4068, 29989, 15.00000000000000000);
        CHECK(path_is_legal(4068, 29989, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 690.59113994211952559);
        
        path = find_path_between_intersections(81109, 78267, 15.00000000000000000);
        CHECK(path_is_legal(81109, 78267, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2929.01503824021301625);
        
        path = find_path_between_intersections(41044, 90328, 0.00000000000000000);
        CHECK(path_is_legal(41044, 90328, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1647.50559886327891945);
        
        path = find_path_between_intersections(87944, 42501, 15.00000000000000000);
        CHECK(path_is_legal(87944, 42501, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1765.82335308418305431);
        
        path = find_path_between_intersections(88019, 102690, 0.00000000000000000);
        CHECK(path_is_legal(88019, 102690, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 637.71019311772386118);
        
        path = find_path_between_intersections(91349, 35313, 15.00000000000000000);
        CHECK(path_is_legal(91349, 35313, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2612.61601777495434362);
        
        path = find_path_between_intersections(92813, 71115, 0.00000000000000000);
        CHECK(path_is_legal(92813, 71115, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2342.99201540622743778);
        
        path = find_path_between_intersections(95586, 24974, 15.00000000000000000);
        CHECK(path_is_legal(95586, 24974, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1021.58914577299492521);
        
        path = find_path_between_intersections(82419, 67889, 0.00000000000000000);
        CHECK(path_is_legal(82419, 67889, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1017.89856402543398417);
        
        path = find_path_between_intersections(2931, 104669, 15.00000000000000000);
        CHECK(path_is_legal(2931, 104669, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1371.42132514167724366);
        
        path = find_path_between_intersections(106121, 78335, 15.00000000000000000);
        CHECK(path_is_legal(106121, 78335, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2191.48920143601071686);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids1;
        std::vector<unsigned> intersection_ids2;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 475; i++) {
            intersection_ids1.push_back(rand_intersection(rng));
            intersection_ids2.push_back(rand_intersection(rng));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(22878);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 475; i++) {
                result = find_path_between_intersections(intersection_ids1[i], intersection_ids2[i], turn_penalties[i]);
            }
        }
    } //find_path_between_intersections_perf_hard

} //inter_inter_path_perf_hard_public

