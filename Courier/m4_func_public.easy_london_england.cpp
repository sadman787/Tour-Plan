#include <random>
#include <iostream>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"
#include "m4.h"

#include "unit_test_util.h"
#include "courier_verify.h"

using ece297test::relative_error;
using ece297test::courier_path_is_legal;


SUITE(easy_london_england_public) {
    TEST(easy_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(88693, 230067), DeliveryInfo(74411, 52846), DeliveryInfo(165996, 80437), DeliveryInfo(409505, 213096), DeliveryInfo(348295, 71958), DeliveryInfo(13105, 270900), DeliveryInfo(342697, 78362)};
        depots = {19};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR easy_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR easy_london_england: INVALID" << std::endl;
        }
        
    } //easy_london_england

} //easy_london_england_public

