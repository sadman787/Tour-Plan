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


SUITE(medium_london_england_public) {
    TEST(medium_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(198567, 356036), DeliveryInfo(164196, 270642), DeliveryInfo(413154, 312607), DeliveryInfo(82742, 320326), DeliveryInfo(55924, 223329), DeliveryInfo(284370, 41131), DeliveryInfo(272114, 292114), DeliveryInfo(125922, 173483), DeliveryInfo(116630, 198486), DeliveryInfo(392772, 227943), DeliveryInfo(89814, 54282), DeliveryInfo(370422, 9523), DeliveryInfo(355045, 434947), DeliveryInfo(259838, 150965)};
        depots = {122615, 87557, 217945, 74097, 250535, 217109, 383133, 425476, 149069, 267743, 379245, 7857, 368474, 333900, 198082, 334742, 173626, 340909, 301888, 356671};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR medium_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR medium_london_england: INVALID" << std::endl;
        }
        
    } //medium_london_england

} //medium_london_england_public

