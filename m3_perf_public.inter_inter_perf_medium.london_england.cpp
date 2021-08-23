#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_path_perf_medium_public) {
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
    TEST_FIXTURE(MapFixture, find_path_between_intersections_perf_medium) {
        //Verify Functionality
        std::vector<unsigned> path;
        path = find_path_between_intersections(29779, 141023, 15.00000000000000000);
        CHECK(path_is_legal(29779, 141023, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1716.39023089342435924);
        
        path = find_path_between_intersections(59863, 86578, 0.00000000000000000);
        CHECK(path_is_legal(59863, 86578, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2752.49123344776580780);
        
        path = find_path_between_intersections(91463, 183244, 0.00000000000000000);
        CHECK(path_is_legal(91463, 183244, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1577.43074548608865371);
        
        path = find_path_between_intersections(100269, 395237, 15.00000000000000000);
        CHECK(path_is_legal(100269, 395237, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2788.52605924459794551);
        
        path = find_path_between_intersections(120114, 107861, 15.00000000000000000);
        CHECK(path_is_legal(120114, 107861, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2916.68659754333248202);
        
        path = find_path_between_intersections(122145, 116882, 15.00000000000000000);
        CHECK(path_is_legal(122145, 116882, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2215.10552844419953544);
        
        path = find_path_between_intersections(149130, 139979, 0.00000000000000000);
        CHECK(path_is_legal(149130, 139979, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2119.48106353290768311);
        
        path = find_path_between_intersections(160330, 419701, 0.00000000000000000);
        CHECK(path_is_legal(160330, 419701, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 473.32239600957728953);
        
        path = find_path_between_intersections(195985, 208353, 15.00000000000000000);
        CHECK(path_is_legal(195985, 208353, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3255.85250911248385819);
        
        path = find_path_between_intersections(226911, 126955, 0.00000000000000000);
        CHECK(path_is_legal(226911, 126955, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2588.43816825354861066);
        
        path = find_path_between_intersections(291458, 63868, 15.00000000000000000);
        CHECK(path_is_legal(291458, 63868, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1747.60093592864745915);
        
        path = find_path_between_intersections(293063, 98375, 0.00000000000000000);
        CHECK(path_is_legal(293063, 98375, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4205.81283488149074401);
        
        path = find_path_between_intersections(305264, 136833, 15.00000000000000000);
        CHECK(path_is_legal(305264, 136833, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2758.53309164571919609);
        
        path = find_path_between_intersections(326145, 409216, 0.00000000000000000);
        CHECK(path_is_legal(326145, 409216, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3648.38583899226068752);
        
        path = find_path_between_intersections(328780, 290510, 15.00000000000000000);
        CHECK(path_is_legal(328780, 290510, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3932.19681898938915765);
        
        path = find_path_between_intersections(332720, 118379, 0.00000000000000000);
        CHECK(path_is_legal(332720, 118379, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2791.89483867105536774);
        
        path = find_path_between_intersections(348445, 60901, 0.00000000000000000);
        CHECK(path_is_legal(348445, 60901, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 6072.88669513193690364);
        
        path = find_path_between_intersections(355532, 411446, 0.00000000000000000);
        CHECK(path_is_legal(355532, 411446, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2306.06144118679549138);
        
        path = find_path_between_intersections(362774, 398795, 0.00000000000000000);
        CHECK(path_is_legal(362774, 398795, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3511.80938032778158231);
        
        path = find_path_between_intersections(199182, 89369, 0.00000000000000000);
        CHECK(path_is_legal(199182, 89369, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2362.15208732047267404);
        
        path = find_path_between_intersections(208516, 401119, 15.00000000000000000);
        CHECK(path_is_legal(208516, 401119, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1337.45292372027029160);
        
        path = find_path_between_intersections(289331, 253023, 15.00000000000000000);
        CHECK(path_is_legal(289331, 253023, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 4265.24345260383688583);
        
        path = find_path_between_intersections(405679, 106491, 0.00000000000000000);
        CHECK(path_is_legal(405679, 106491, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4453.25576859041120770);
        
        path = find_path_between_intersections(408351, 7974, 15.00000000000000000);
        CHECK(path_is_legal(408351, 7974, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3608.53744136156956301);
        
        path = find_path_between_intersections(116465, 273676, 15.00000000000000000);
        CHECK(path_is_legal(116465, 273676, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3630.95683363747366457);
        
        path = find_path_between_intersections(413075, 90868, 0.00000000000000000);
        CHECK(path_is_legal(413075, 90868, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2733.64162186665498666);
        
        path = find_path_between_intersections(196052, 356368, 0.00000000000000000);
        CHECK(path_is_legal(196052, 356368, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3628.20196145637919471);
        
        path = find_path_between_intersections(411538, 268904, 15.00000000000000000);
        CHECK(path_is_legal(411538, 268904, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3499.31786809304185226);
        
        path = find_path_between_intersections(424782, 308019, 15.00000000000000000);
        CHECK(path_is_legal(424782, 308019, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3536.20129012817005787);
        
        path = find_path_between_intersections(312885, 37466, 0.00000000000000000);
        CHECK(path_is_legal(312885, 37466, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 915.81030773948896240);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids1;
        std::vector<unsigned> intersection_ids2;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 40; i++) {
            intersection_ids1.push_back(rand_intersection(rng));
            intersection_ids2.push_back(rand_intersection(rng));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(17804);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 40; i++) {
                result = find_path_between_intersections(intersection_ids1[i], intersection_ids2[i], turn_penalties[i]);
            }
        }
    } //find_path_between_intersections_perf_medium

} //inter_inter_path_perf_medium_public

