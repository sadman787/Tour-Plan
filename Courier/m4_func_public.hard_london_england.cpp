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


SUITE(hard_london_england_public) {
    TEST(hard_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(20499, 330511), DeliveryInfo(331993, 318988), DeliveryInfo(160875, 288159), DeliveryInfo(156725, 317385), DeliveryInfo(247846, 204241), DeliveryInfo(82438, 166141), DeliveryInfo(308122, 325961), DeliveryInfo(379111, 391356), DeliveryInfo(143917, 174230), DeliveryInfo(104252, 125421), DeliveryInfo(259042, 69630), DeliveryInfo(177386, 335789), DeliveryInfo(188998, 331033), DeliveryInfo(274507, 254529), DeliveryInfo(148822, 161730), DeliveryInfo(265213, 191618), DeliveryInfo(105693, 53147), DeliveryInfo(267776, 39985), DeliveryInfo(426193, 77054), DeliveryInfo(428944, 26065), DeliveryInfo(370223, 424214), DeliveryInfo(395913, 77485), DeliveryInfo(26210, 146958), DeliveryInfo(22588, 112242), DeliveryInfo(381463, 418841), DeliveryInfo(288278, 102310), DeliveryInfo(261649, 138512), DeliveryInfo(221633, 163870)};
        depots = {39};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_london_england: INVALID" << std::endl;
        }
        
    } //hard_london_england

    TEST(hard_multi_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(367443, 237274), DeliveryInfo(367443, 32038), DeliveryInfo(244397, 415198), DeliveryInfo(217674, 378142), DeliveryInfo(350891, 202107), DeliveryInfo(414991, 396731), DeliveryInfo(426793, 427549), DeliveryInfo(56992, 251355), DeliveryInfo(167654, 98289), DeliveryInfo(212434, 51648), DeliveryInfo(367443, 315631), DeliveryInfo(137622, 304777), DeliveryInfo(20929, 156777), DeliveryInfo(2959, 20749), DeliveryInfo(195907, 420936), DeliveryInfo(367443, 419737), DeliveryInfo(398670, 183698), DeliveryInfo(276118, 394595), DeliveryInfo(313967, 391914), DeliveryInfo(251536, 36528), DeliveryInfo(433190, 436561), DeliveryInfo(360348, 195018), DeliveryInfo(115947, 204837), DeliveryInfo(222130, 298065), DeliveryInfo(419868, 70575), DeliveryInfo(364502, 298065), DeliveryInfo(126861, 233747), DeliveryInfo(353392, 298065)};
        depots = {49, 186028};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_multi_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_multi_london_england: INVALID" << std::endl;
        }
        
    } //hard_multi_london_england

} //hard_london_england_public

