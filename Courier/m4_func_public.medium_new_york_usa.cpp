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


SUITE(medium_new_york_usa_public) {
    TEST(medium_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(116751, 664), DeliveryInfo(128948, 16358), DeliveryInfo(129316, 66180), DeliveryInfo(103003, 53701), DeliveryInfo(105332, 111839), DeliveryInfo(92083, 57961), DeliveryInfo(102110, 119165), DeliveryInfo(131543, 86813), DeliveryInfo(137765, 107746), DeliveryInfo(109156, 66342), DeliveryInfo(46566, 24756), DeliveryInfo(121108, 76539), DeliveryInfo(83905, 18684), DeliveryInfo(135276, 27644), DeliveryInfo(113405, 58802), DeliveryInfo(78178, 118622), DeliveryInfo(106229, 29253), DeliveryInfo(62670, 13970), DeliveryInfo(69752, 54858), DeliveryInfo(53994, 58009), DeliveryInfo(118225, 142153), DeliveryInfo(36824, 33426), DeliveryInfo(43385, 113899), DeliveryInfo(72236, 56485), DeliveryInfo(92509, 111557), DeliveryInfo(140192, 38966), DeliveryInfo(98065, 95009), DeliveryInfo(39272, 131227), DeliveryInfo(130297, 123109), DeliveryInfo(9856, 3265), DeliveryInfo(79529, 72537), DeliveryInfo(34493, 100862), DeliveryInfo(31428, 89454), DeliveryInfo(78230, 128006), DeliveryInfo(144031, 47559), DeliveryInfo(41062, 30007), DeliveryInfo(26114, 106887), DeliveryInfo(27233, 123759), DeliveryInfo(35659, 42071), DeliveryInfo(124272, 71889), DeliveryInfo(49864, 72816), DeliveryInfo(46272, 83705), DeliveryInfo(142812, 90914), DeliveryInfo(99578, 126707), DeliveryInfo(113619, 74919), DeliveryInfo(79624, 40966), DeliveryInfo(84141, 49804), DeliveryInfo(40662, 138036), DeliveryInfo(107801, 66315), DeliveryInfo(31859, 2625)};
        depots = {9, 37291, 117542, 98651, 132133, 83190, 79661, 28363, 115300, 33701};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR medium_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR medium_new_york_usa: INVALID" << std::endl;
        }
        
    } //medium_new_york_usa

} //medium_new_york_usa_public

