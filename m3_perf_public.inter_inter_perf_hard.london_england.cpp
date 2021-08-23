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
    TEST_FIXTURE(MapFixture, find_path_between_intersections_perf_hard) {
        //Verify Functionality
        std::vector<unsigned> path;
        path = find_path_between_intersections(517, 50641, 15.00000000000000000);
        CHECK(path_is_legal(517, 50641, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1974.28961351431257754);
        
        path = find_path_between_intersections(28985, 303079, 15.00000000000000000);
        CHECK(path_is_legal(28985, 303079, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3233.73608060706555989);
        
        path = find_path_between_intersections(36243, 204969, 15.00000000000000000);
        CHECK(path_is_legal(36243, 204969, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2060.18795285184614841);
        
        path = find_path_between_intersections(47166, 219153, 15.00000000000000000);
        CHECK(path_is_legal(47166, 219153, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3702.20803980594018867);
        
        path = find_path_between_intersections(54523, 51688, 0.00000000000000000);
        CHECK(path_is_legal(54523, 51688, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3899.10033511162600917);
        
        path = find_path_between_intersections(72383, 185823, 0.00000000000000000);
        CHECK(path_is_legal(72383, 185823, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2342.54242317591751998);
        
        path = find_path_between_intersections(102144, 314711, 15.00000000000000000);
        CHECK(path_is_legal(102144, 314711, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2162.00884134438683759);
        
        path = find_path_between_intersections(126525, 226544, 0.00000000000000000);
        CHECK(path_is_legal(126525, 226544, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1754.45509802214451156);
        
        path = find_path_between_intersections(138847, 410681, 0.00000000000000000);
        CHECK(path_is_legal(138847, 410681, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 765.21039597985861747);
        
        path = find_path_between_intersections(147984, 408754, 0.00000000000000000);
        CHECK(path_is_legal(147984, 408754, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3675.50124784543322676);
        
        path = find_path_between_intersections(165265, 186899, 15.00000000000000000);
        CHECK(path_is_legal(165265, 186899, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3883.77541810475213424);
        
        path = find_path_between_intersections(203467, 365263, 0.00000000000000000);
        CHECK(path_is_legal(203467, 365263, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1219.80623363277504723);
        
        path = find_path_between_intersections(210307, 233932, 15.00000000000000000);
        CHECK(path_is_legal(210307, 233932, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 4473.75438743329868885);
        
        path = find_path_between_intersections(192863, 3528, 0.00000000000000000);
        CHECK(path_is_legal(192863, 3528, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3037.22329540465625541);
        
        path = find_path_between_intersections(256625, 179693, 15.00000000000000000);
        CHECK(path_is_legal(256625, 179693, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2816.18697185417659057);
        
        path = find_path_between_intersections(261731, 280802, 15.00000000000000000);
        CHECK(path_is_legal(261731, 280802, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 5911.71339350371636101);
        
        path = find_path_between_intersections(282934, 351736, 0.00000000000000000);
        CHECK(path_is_legal(282934, 351736, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2021.48272650152443930);
        
        path = find_path_between_intersections(290753, 201290, 0.00000000000000000);
        CHECK(path_is_legal(290753, 201290, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4997.29231411156160902);
        
        path = find_path_between_intersections(295638, 169385, 0.00000000000000000);
        CHECK(path_is_legal(295638, 169385, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 746.83291331996053941);
        
        path = find_path_between_intersections(298744, 25131, 0.00000000000000000);
        CHECK(path_is_legal(298744, 25131, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1882.38773458013110940);
        
        path = find_path_between_intersections(311174, 122071, 0.00000000000000000);
        CHECK(path_is_legal(311174, 122071, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3151.63907040224967204);
        
        path = find_path_between_intersections(314809, 132573, 0.00000000000000000);
        CHECK(path_is_legal(314809, 132573, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2218.61873961303717806);
        
        path = find_path_between_intersections(324901, 317303, 15.00000000000000000);
        CHECK(path_is_legal(324901, 317303, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 4162.28543501082367584);
        
        path = find_path_between_intersections(194186, 6997, 15.00000000000000000);
        CHECK(path_is_legal(194186, 6997, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 4276.74696929694437131);
        
        path = find_path_between_intersections(349238, 272572, 0.00000000000000000);
        CHECK(path_is_legal(349238, 272572, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3481.36605693008823437);
        
        path = find_path_between_intersections(357593, 143594, 15.00000000000000000);
        CHECK(path_is_legal(357593, 143594, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3213.49108934534206128);
        
        path = find_path_between_intersections(385344, 357415, 0.00000000000000000);
        CHECK(path_is_legal(385344, 357415, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 3554.96627694443714063);
        
        path = find_path_between_intersections(361115, 402964, 15.00000000000000000);
        CHECK(path_is_legal(361115, 402964, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 3446.59318677440705869);
        
        path = find_path_between_intersections(269134, 189054, 15.00000000000000000);
        CHECK(path_is_legal(269134, 189054, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2685.27815404717603087);
        
        path = find_path_between_intersections(238235, 233913, 0.00000000000000000);
        CHECK(path_is_legal(238235, 233913, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 4824.02823258445732790);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids1;
        std::vector<unsigned> intersection_ids2;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 100; i++) {
            intersection_ids1.push_back(rand_intersection(rng));
            intersection_ids2.push_back(rand_intersection(rng));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(22787);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 100; i++) {
                result = find_path_between_intersections(intersection_ids1[i], intersection_ids2[i], turn_penalties[i]);
            }
        }
    } //find_path_between_intersections_perf_hard

} //inter_inter_path_perf_hard_public

