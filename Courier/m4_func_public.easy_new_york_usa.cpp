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


SUITE(easy_new_york_usa_public) {
    TEST(easy_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(124565, 121231), DeliveryInfo(86864, 27374), DeliveryInfo(24041, 100847), DeliveryInfo(48157, 32010), DeliveryInfo(134940, 81971), DeliveryInfo(66138, 84725), DeliveryInfo(26181, 34119), DeliveryInfo(117398, 23138), DeliveryInfo(136817, 29105), DeliveryInfo(116367, 79773), DeliveryInfo(3424, 56094), DeliveryInfo(4378, 12944), DeliveryInfo(17656, 143959), DeliveryInfo(90509, 90184), DeliveryInfo(136424, 27017), DeliveryInfo(104666, 65377), DeliveryInfo(110117, 127546), DeliveryInfo(116802, 115613), DeliveryInfo(55460, 55299), DeliveryInfo(118950, 85965), DeliveryInfo(26874, 4354), DeliveryInfo(71196, 126381), DeliveryInfo(44732, 24549), DeliveryInfo(76866, 53019), DeliveryInfo(144749, 20952)};
        depots = {6, 24861, 29632, 114496};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR easy_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR easy_new_york_usa: INVALID" << std::endl;
        }
        
    } //easy_new_york_usa

} //easy_new_york_usa_public

