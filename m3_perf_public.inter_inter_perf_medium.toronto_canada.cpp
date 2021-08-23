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
    TEST_FIXTURE(MapFixture, find_path_between_intersections_perf_medium) {
        //Verify Functionality
        std::vector<unsigned> path;
        path = find_path_between_intersections(9991, 66058, 15.00000000000000000);
        CHECK(path_is_legal(9991, 66058, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1508.13950651630875655);
        
        path = find_path_between_intersections(10547, 17086, 0.00000000000000000);
        CHECK(path_is_legal(10547, 17086, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1792.99749944258019241);
        
        path = find_path_between_intersections(13994, 60116, 0.00000000000000000);
        CHECK(path_is_legal(13994, 60116, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1001.40320309372657448);
        
        path = find_path_between_intersections(17292, 94562, 0.00000000000000000);
        CHECK(path_is_legal(17292, 94562, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 804.94316350241683722);
        
        path = find_path_between_intersections(18670, 78048, 15.00000000000000000);
        CHECK(path_is_legal(18670, 78048, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1259.51698329585633473);
        
        path = find_path_between_intersections(22179, 1011, 15.00000000000000000);
        CHECK(path_is_legal(22179, 1011, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 300.76928851899998563);
        
        path = find_path_between_intersections(23787, 7385, 0.00000000000000000);
        CHECK(path_is_legal(23787, 7385, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1380.28221879970760710);
        
        path = find_path_between_intersections(29426, 61756, 15.00000000000000000);
        CHECK(path_is_legal(29426, 61756, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1774.13853165878367690);
        
        path = find_path_between_intersections(33160, 99714, 0.00000000000000000);
        CHECK(path_is_legal(33160, 99714, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1131.63381923815359187);
        
        path = find_path_between_intersections(33635, 102573, 15.00000000000000000);
        CHECK(path_is_legal(33635, 102573, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1881.32776223148539430);
        
        path = find_path_between_intersections(34612, 104025, 15.00000000000000000);
        CHECK(path_is_legal(34612, 104025, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1715.37776484050209547);
        
        path = find_path_between_intersections(34914, 7218, 0.00000000000000000);
        CHECK(path_is_legal(34914, 7218, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1580.12218103871236963);
        
        path = find_path_between_intersections(43153, 17710, 0.00000000000000000);
        CHECK(path_is_legal(43153, 17710, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1779.31818986762073109);
        
        path = find_path_between_intersections(46021, 85697, 0.00000000000000000);
        CHECK(path_is_legal(46021, 85697, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 905.88984065764407205);
        
        path = find_path_between_intersections(53243, 48641, 15.00000000000000000);
        CHECK(path_is_legal(53243, 48641, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1048.43343566112957888);
        
        path = find_path_between_intersections(31993, 58311, 15.00000000000000000);
        CHECK(path_is_legal(31993, 58311, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1810.60128512575306559);
        
        path = find_path_between_intersections(59420, 32039, 0.00000000000000000);
        CHECK(path_is_legal(59420, 32039, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 947.42977090821545971);
        
        path = find_path_between_intersections(23467, 87768, 0.00000000000000000);
        CHECK(path_is_legal(23467, 87768, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 918.60412216580868972);
        
        path = find_path_between_intersections(46238, 16774, 15.00000000000000000);
        CHECK(path_is_legal(46238, 16774, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 2227.67318523146695952);
        
        path = find_path_between_intersections(65645, 74209, 15.00000000000000000);
        CHECK(path_is_legal(65645, 74209, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 919.48759101689324780);
        
        path = find_path_between_intersections(68801, 34636, 0.00000000000000000);
        CHECK(path_is_legal(68801, 34636, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1320.27992571703975955);
        
        path = find_path_between_intersections(72095, 70229, 15.00000000000000000);
        CHECK(path_is_legal(72095, 70229, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1635.94642494017534773);
        
        path = find_path_between_intersections(72666, 92849, 0.00000000000000000);
        CHECK(path_is_legal(72666, 92849, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 959.32888933352080585);
        
        path = find_path_between_intersections(79447, 84379, 0.00000000000000000);
        CHECK(path_is_legal(79447, 84379, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 2360.36658186867589393);
        
        path = find_path_between_intersections(31825, 30029, 15.00000000000000000);
        CHECK(path_is_legal(31825, 30029, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1278.76625923074152524);
        
        path = find_path_between_intersections(89254, 23175, 0.00000000000000000);
        CHECK(path_is_legal(89254, 23175, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1223.75257324748349674);
        
        path = find_path_between_intersections(92348, 63761, 15.00000000000000000);
        CHECK(path_is_legal(92348, 63761, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 929.48354740974104971);
        
        path = find_path_between_intersections(4534, 65229, 0.00000000000000000);
        CHECK(path_is_legal(4534, 65229, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 1164.06762691703966084);
        
        path = find_path_between_intersections(97675, 60455, 15.00000000000000000);
        CHECK(path_is_legal(97675, 60455, path));
        CHECK(compute_path_travel_time(path, 15.00000000000000000) <= 1563.43312030873426011);
        
        path = find_path_between_intersections(99435, 95720, 0.00000000000000000);
        CHECK(path_is_legal(99435, 95720, path));
        CHECK(compute_path_travel_time(path, 0.00000000000000000) <= 560.55396128154166036);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids1;
        std::vector<unsigned> intersection_ids2;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 150; i++) {
            intersection_ids1.push_back(rand_intersection(rng));
            intersection_ids2.push_back(rand_intersection(rng));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(13558);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 150; i++) {
                result = find_path_between_intersections(intersection_ids1[i], intersection_ids2[i], turn_penalties[i]);
            }
        }
    } //find_path_between_intersections_perf_medium

} //inter_inter_path_perf_medium_public

