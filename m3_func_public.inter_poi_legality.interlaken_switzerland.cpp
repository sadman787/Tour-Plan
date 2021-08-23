#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_poi_path_func_public) {
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
    TEST(find_path_to_point_of_interest_functionality) {
        std::vector<unsigned> path;
        std::vector<unsigned> valid_end_intersections;
        double path_cost;
        
        valid_end_intersections = {1047};
        path = find_path_to_point_of_interest(117, "Interlaken Ost", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(117, valid_end_intersections, path));
        CHECK(path_cost <= 208.14763090820909497);
        
        valid_end_intersections = {934};
        path = find_path_to_point_of_interest(338, "Simply Sushi", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(338, valid_end_intersections, path));
        CHECK(path_cost <= 114.56744169802249189);
        
        valid_end_intersections = {462};
        path = find_path_to_point_of_interest(362, "Kita Kunterbunt", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(362, valid_end_intersections, path));
        CHECK(path_cost <= 366.64658929571112367);
        
        valid_end_intersections = {371};
        path = find_path_to_point_of_interest(478, "Ruedi Rüssel", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(478, valid_end_intersections, path));
        CHECK(path_cost <= 374.43439234626123380);
        
        valid_end_intersections = {320, 1143};
        path = find_path_to_point_of_interest(483, "Agrola", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(483, valid_end_intersections, path));
        CHECK(path_cost <= 301.21485304833697683);
        
        valid_end_intersections = {1137, 1136, 1636, 1250, 1140};
        path = find_path_to_point_of_interest(570, "Oeltrans", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(570, valid_end_intersections, path));
        CHECK(path_cost <= 463.45926400146521473);
        
        valid_end_intersections = {1147};
        path = find_path_to_point_of_interest(590, "Buddy's Pub", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(590, valid_end_intersections, path));
        CHECK(path_cost <= 291.57956910219382962);
        
        valid_end_intersections = {1137, 1136, 1636, 1250, 1140};
        path = find_path_to_point_of_interest(703, "Oeltrans", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(703, valid_end_intersections, path));
        CHECK(path_cost <= 287.62419515185894170);
        
        valid_end_intersections = {1078, 1079, 1086};
        path = find_path_to_point_of_interest(776, "Stedtlizentrum", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(776, valid_end_intersections, path));
        CHECK(path_cost <= 219.90183112653778608);
        
        valid_end_intersections = {1316};
        path = find_path_to_point_of_interest(321, "Kino Rex", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(321, valid_end_intersections, path));
        CHECK(path_cost <= 310.23124570377422060);
        
        valid_end_intersections = {803};
        path = find_path_to_point_of_interest(964, "Casino Interlaken", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(964, valid_end_intersections, path));
        CHECK(path_cost <= 219.09267995046570832);
        
        valid_end_intersections = {129, 789};
        path = find_path_to_point_of_interest(281, "Raiffeisenbank Jungfrau", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(281, valid_end_intersections, path));
        CHECK(path_cost <= 348.60570749025060877);
        
        valid_end_intersections = {1078, 1079, 1086};
        path = find_path_to_point_of_interest(787, "Stedtlizentrum", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(787, valid_end_intersections, path));
        CHECK(path_cost <= 630.09422123795684456);
        
        valid_end_intersections = {1518};
        path = find_path_to_point_of_interest(1098, "Bamboo", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1098, valid_end_intersections, path));
        CHECK(path_cost <= 481.73560708154082022);
        
        valid_end_intersections = {1137, 1136, 1636, 1250, 1140};
        path = find_path_to_point_of_interest(1119, "Oeltrans", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1119, valid_end_intersections, path));
        CHECK(path_cost <= 291.48260842053088027);
        
        valid_end_intersections = {233};
        path = find_path_to_point_of_interest(1145, "PizPaz", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1145, valid_end_intersections, path));
        CHECK(path_cost <= 149.82303317177718327);
        
        valid_end_intersections = {408};
        path = find_path_to_point_of_interest(1154, "Swisscom", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1154, valid_end_intersections, path));
        CHECK(path_cost <= 207.78271951998851819);
        
        valid_end_intersections = {828};
        path = find_path_to_point_of_interest(1209, "Niederried", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1209, valid_end_intersections, path));
        CHECK(path_cost <= 607.01191857989806522);
        
        valid_end_intersections = {1031};
        path = find_path_to_point_of_interest(351, "Bödeli Bibliothek", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(351, valid_end_intersections, path));
        CHECK(path_cost <= 604.57062041461460922);
        
        valid_end_intersections = {363};
        path = find_path_to_point_of_interest(1302, "Steakhouse Steinbock", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1302, valid_end_intersections, path));
        CHECK(path_cost <= 202.70336822886679329);
        
        valid_end_intersections = {926};
        path = find_path_to_point_of_interest(1279, "Maiezyt", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1279, valid_end_intersections, path));
        CHECK(path_cost <= 548.49616409780901449);
        
        valid_end_intersections = {399};
        path = find_path_to_point_of_interest(1585, "Touristinfo Ringgenberg", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1585, valid_end_intersections, path));
        CHECK(path_cost <= 484.42511143028707465);
        
        valid_end_intersections = {479};
        path = find_path_to_point_of_interest(59, "Wilderswil", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(59, valid_end_intersections, path));
        CHECK(path_cost <= 271.86546102897921173);
        
        valid_end_intersections = {304};
        path = find_path_to_point_of_interest(1629, "Kindertagesstätte Alpenstrasse", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1629, valid_end_intersections, path));
        CHECK(path_cost <= 251.53601530831406308);
        
        valid_end_intersections = {1078, 1079, 1086};
        path = find_path_to_point_of_interest(125, "Stedtlizentrum", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(125, valid_end_intersections, path));
        CHECK(path_cost <= 300.11126832810589349);
        
        valid_end_intersections = {1137, 1136, 1636, 1250, 1140};
        path = find_path_to_point_of_interest(1117, "Oeltrans", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1117, valid_end_intersections, path));
        CHECK(path_cost <= 265.97916041405363785);
        
        valid_end_intersections = {938};
        path = find_path_to_point_of_interest(1617, "McDonald's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1617, valid_end_intersections, path));
        CHECK(path_cost <= 385.51147234523199359);
        
        valid_end_intersections = {792};
        path = find_path_to_point_of_interest(10, "Private Parking for Ula's Holiday Apartments", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(10, valid_end_intersections, path));
        CHECK(path_cost <= 522.73724272799745449);
        
        valid_end_intersections = {388};
        path = find_path_to_point_of_interest(1682, "Raiffeisenbank", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1682, valid_end_intersections, path));
        CHECK(path_cost <= 541.14470777845360772);
        
        valid_end_intersections = {284};
        path = find_path_to_point_of_interest(1719, "Mobility Interlaken West", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(1719, valid_end_intersections, path));
        CHECK(path_cost <= 618.83547554050835515);
        
    } //find_path_to_point_of_interest_functionality

} //inter_poi_path_func_public

