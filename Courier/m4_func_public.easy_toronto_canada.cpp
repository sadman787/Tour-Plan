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


SUITE(easy_toronto_canada_public) {
    TEST(easy_toronto_canada) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(64685, 77941), DeliveryInfo(101590, 3242), DeliveryInfo(2550, 75097), DeliveryInfo(100485, 23837), DeliveryInfo(87422, 61041), DeliveryInfo(107789, 86093), DeliveryInfo(3260, 25407), DeliveryInfo(33310, 15602), DeliveryInfo(67398, 21673), DeliveryInfo(22066, 59404), DeliveryInfo(86654, 41771), DeliveryInfo(20012, 20118), DeliveryInfo(101883, 41179), DeliveryInfo(41299, 107201), DeliveryInfo(13148, 88578), DeliveryInfo(49250, 20385), DeliveryInfo(35861, 48683), DeliveryInfo(19496, 64015), DeliveryInfo(92759, 94111), DeliveryInfo(85261, 63091), DeliveryInfo(82000, 67157), DeliveryInfo(53017, 90276), DeliveryInfo(17903, 94979), DeliveryInfo(86978, 18281), DeliveryInfo(57239, 39482)};
        depots = {4, 18513};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR easy_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR easy_toronto_canada: INVALID" << std::endl;
        }
        
    } //easy_toronto_canada

} //easy_toronto_canada_public

