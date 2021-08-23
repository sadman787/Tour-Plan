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


SUITE(medium_toronto_canada_public) {
    TEST(medium_toronto_canada) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(74152, 34457), DeliveryInfo(86940, 494), DeliveryInfo(30279, 91675), DeliveryInfo(96297, 49282), DeliveryInfo(61948, 24891), DeliveryInfo(76703, 83282), DeliveryInfo(78437, 1954), DeliveryInfo(84448, 88738), DeliveryInfo(81284, 64646), DeliveryInfo(59293, 53533), DeliveryInfo(53792, 49402), DeliveryInfo(34676, 54224), DeliveryInfo(30577, 62332), DeliveryInfo(90185, 25685), DeliveryInfo(59320, 79105), DeliveryInfo(62481, 20585), DeliveryInfo(100735, 30506), DeliveryInfo(58216, 88333), DeliveryInfo(80276, 94354), DeliveryInfo(46668, 56996), DeliveryInfo(58255, 40851), DeliveryInfo(51942, 80235), DeliveryInfo(97027, 21783), DeliveryInfo(27422, 43197), DeliveryInfo(37132, 54015), DeliveryInfo(84608, 105856), DeliveryInfo(32307, 84816), DeliveryInfo(29244, 66613), DeliveryInfo(68888, 29017), DeliveryInfo(73025, 79595), DeliveryInfo(107254, 97720), DeliveryInfo(85859, 12181), DeliveryInfo(76038, 42062), DeliveryInfo(104396, 37087), DeliveryInfo(59223, 2431), DeliveryInfo(20279, 75108), DeliveryInfo(21121, 55789), DeliveryInfo(23403, 18435), DeliveryInfo(68571, 39989), DeliveryInfo(97956, 95322), DeliveryInfo(25096, 102791), DeliveryInfo(96023, 92159), DeliveryInfo(7339, 35415), DeliveryInfo(26554, 31328), DeliveryInfo(92540, 10403), DeliveryInfo(40207, 43788), DeliveryInfo(62657, 102589), DeliveryInfo(23724, 67700), DeliveryInfo(19446, 106347), DeliveryInfo(88038, 83073)};
        depots = {7, 27769, 87529, 73462, 98395};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR medium_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR medium_toronto_canada: INVALID" << std::endl;
        }
        
    } //medium_toronto_canada

} //medium_toronto_canada_public

