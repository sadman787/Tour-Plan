#include <random>
#include <iostream>
#include <string>
#include <unittest++/UnitTest++.h>

#include "unit_test_util.h"

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

extern void set_disable_event_loop (bool new_setting);

std::string map_name = "/cad2/ece297s/public/maps/saint-helena.streets.bin";

int main(int argc, char** argv) {
    //Disable interactive graphics
    set_disable_event_loop(true);

    bool load_success = load_map(map_name);

    if(!load_success) {
        std::cout << "ERROR: Could not load map file: '" << map_name << "'!";
        std::cout << " Subsequent tests will likely fail." << std::endl;
        //Don't abort tests, since we still want to show that all
        //tests fail.
    }

    //Run the unit tests
    int num_failures = UnitTest::RunAllTests();

    close_map();

    return num_failures;
}

struct MapFixture {
    MapFixture() {
        rng = std::minstd_rand(0);
        rand_intersection = std::uniform_int_distribution<unsigned>(0, getNumberOfIntersections()-1);
        rand_street = std::uniform_int_distribution<unsigned>(1, getNumberOfStreets()-1);
        rand_segment = std::uniform_int_distribution<unsigned>(0, getNumberOfStreetSegments()-1);
        rand_poi = std::uniform_int_distribution<unsigned>(0, getNumberOfPointsOfInterest()-1);
        rand_lat = std::uniform_real_distribution<float>(-16.00203, -7.925433);
        rand_lon = std::uniform_real_distribution<float>(-14.41355, -5.649098);
        rand_turn_penalty = std::uniform_real_distribution<float>(0., 30.);
    }

    std::minstd_rand rng;
    std::uniform_int_distribution<unsigned> rand_intersection;
    std::uniform_int_distribution<unsigned> rand_street;
    std::uniform_int_distribution<unsigned> rand_segment;
    std::uniform_int_distribution<unsigned> rand_poi;
    std::uniform_real_distribution<float> rand_lat;
    std::uniform_real_distribution<float> rand_lon;
    std::uniform_real_distribution<float> rand_turn_penalty;
};

TEST_FIXTURE(MapFixture, valgrind_exercise) {

    for(size_t i = 0; i < 10; i++) {

        unsigned source = rand_intersection(rng);
        unsigned destination = rand_intersection(rng);
        float turn_penalty = rand_turn_penalty(rng);


        std::vector<unsigned> path = find_path_between_intersections(source, destination, turn_penalty);

        double path_cost = compute_path_travel_time(path, turn_penalty);

        std::string poi_name = getPointOfInterestName(rand_poi(rng));

        std::vector<unsigned> poi_path = find_path_to_point_of_interest(source, poi_name, turn_penalty);

        double poi_path_cost = path_cost = compute_path_travel_time(poi_path, turn_penalty);

    }

};
