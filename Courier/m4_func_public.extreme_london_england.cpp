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


SUITE(extreme_london_england_public) {
    TEST(extreme_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(213465, 200094), DeliveryInfo(59002, 321463), DeliveryInfo(169790, 320943), DeliveryInfo(39315, 220437), DeliveryInfo(349892, 207769), DeliveryInfo(342430, 276994), DeliveryInfo(30437, 306362), DeliveryInfo(116228, 3976), DeliveryInfo(323219, 38530), DeliveryInfo(173700, 207439), DeliveryInfo(152996, 10929), DeliveryInfo(30748, 148195), DeliveryInfo(192987, 97938), DeliveryInfo(375153, 299401), DeliveryInfo(245805, 63523), DeliveryInfo(259709, 206482), DeliveryInfo(353422, 435891), DeliveryInfo(235088, 198355), DeliveryInfo(270168, 15714), DeliveryInfo(242595, 284696), DeliveryInfo(334355, 19547), DeliveryInfo(261345, 245231), DeliveryInfo(215876, 328719), DeliveryInfo(252656, 97922), DeliveryInfo(201742, 190713), DeliveryInfo(266079, 278752), DeliveryInfo(243409, 298139), DeliveryInfo(156322, 149487), DeliveryInfo(401665, 202299), DeliveryInfo(158540, 434218), DeliveryInfo(223234, 417347), DeliveryInfo(64723, 338129), DeliveryInfo(241313, 387137), DeliveryInfo(163020, 83628), DeliveryInfo(432418, 413406), DeliveryInfo(336561, 20627), DeliveryInfo(60442, 352002), DeliveryInfo(287428, 66136), DeliveryInfo(113676, 175115), DeliveryInfo(179046, 298495), DeliveryInfo(39098, 188132), DeliveryInfo(424643, 417548), DeliveryInfo(372239, 430343)};
        depots = {59};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_london_england: INVALID" << std::endl;
        }
        
    } //extreme_london_england

    TEST(extreme_multi_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(34879, 389264), DeliveryInfo(291829, 231525), DeliveryInfo(129725, 383125), DeliveryInfo(195441, 389264), DeliveryInfo(89516, 394484), DeliveryInfo(89516, 76650), DeliveryInfo(89516, 310581), DeliveryInfo(286772, 17241), DeliveryInfo(394891, 31461), DeliveryInfo(66940, 347829), DeliveryInfo(343938, 41336), DeliveryInfo(89516, 130528), DeliveryInfo(343938, 83342), DeliveryInfo(422492, 66208), DeliveryInfo(135963, 409382), DeliveryInfo(143440, 49854), DeliveryInfo(64254, 293818), DeliveryInfo(36527, 138649), DeliveryInfo(242272, 96989), DeliveryInfo(219488, 257177), DeliveryInfo(343938, 83342), DeliveryInfo(335283, 31461), DeliveryInfo(89516, 272137), DeliveryInfo(150084, 187224), DeliveryInfo(116559, 394484), DeliveryInfo(25457, 17241), DeliveryInfo(143440, 147035), DeliveryInfo(105571, 114243), DeliveryInfo(69656, 138649), DeliveryInfo(343938, 17241), DeliveryInfo(360534, 394484), DeliveryInfo(105571, 23238), DeliveryInfo(343938, 257177), DeliveryInfo(89516, 257177), DeliveryInfo(274269, 24644), DeliveryInfo(105571, 69040), DeliveryInfo(89516, 83342), DeliveryInfo(403738, 118970), DeliveryInfo(400133, 158490), DeliveryInfo(86129, 158490), DeliveryInfo(231240, 121008), DeliveryInfo(59697, 259279), DeliveryInfo(2586, 158490), DeliveryInfo(152228, 158490), DeliveryInfo(260440, 76650), DeliveryInfo(264388, 234780), DeliveryInfo(62758, 318743), DeliveryInfo(143440, 390891), DeliveryInfo(254647, 286103), DeliveryInfo(143440, 155660), DeliveryInfo(89516, 138649), DeliveryInfo(33082, 247326), DeliveryInfo(249835, 314504), DeliveryInfo(429827, 362691), DeliveryInfo(343938, 158490), DeliveryInfo(89516, 343518), DeliveryInfo(179361, 204300), DeliveryInfo(354374, 310032), DeliveryInfo(143440, 168741), DeliveryInfo(336040, 40447), DeliveryInfo(343938, 394685), DeliveryInfo(143440, 17241), DeliveryInfo(319729, 394484), DeliveryInfo(143440, 17241), DeliveryInfo(143440, 25775), DeliveryInfo(11296, 338914)};
        depots = {68};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_multi_london_england: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_multi_london_england: INVALID" << std::endl;
        }
        
    } //extreme_multi_london_england

} //extreme_london_england_public

