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


SUITE(hard_new_york_usa_public) {
    TEST(hard_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(2434, 17781), DeliveryInfo(123693, 51285), DeliveryInfo(39004, 126011), DeliveryInfo(92910, 11976), DeliveryInfo(110599, 100958), DeliveryInfo(48360, 121946), DeliveryInfo(25888, 130129), DeliveryInfo(94720, 86591), DeliveryInfo(53749, 66687), DeliveryInfo(41904, 43807), DeliveryInfo(58211, 28617), DeliveryInfo(130754, 2932), DeliveryInfo(110920, 56094), DeliveryInfo(54622, 61146), DeliveryInfo(74048, 85588), DeliveryInfo(88609, 37213), DeliveryInfo(44568, 137149), DeliveryInfo(120330, 19034), DeliveryInfo(141687, 51955), DeliveryInfo(141732, 41800), DeliveryInfo(111606, 116284), DeliveryInfo(49099, 29221), DeliveryInfo(106039, 59322), DeliveryInfo(34182, 45866), DeliveryInfo(143312, 89418), DeliveryInfo(96275, 67740), DeliveryInfo(23263, 83840), DeliveryInfo(63145, 88240), DeliveryInfo(17756, 137467), DeliveryInfo(96315, 35037), DeliveryInfo(34831, 24181), DeliveryInfo(102945, 26660), DeliveryInfo(81737, 73145), DeliveryInfo(8757, 142696), DeliveryInfo(37500, 77511), DeliveryInfo(95853, 101542), DeliveryInfo(126662, 95039), DeliveryInfo(7546, 25423), DeliveryInfo(46204, 140809), DeliveryInfo(112188, 120563), DeliveryInfo(91714, 6602), DeliveryInfo(54749, 40376), DeliveryInfo(112141, 5501), DeliveryInfo(75313, 12700), DeliveryInfo(6848, 5878), DeliveryInfo(68238, 24912), DeliveryInfo(35312, 88456), DeliveryInfo(108905, 42138), DeliveryInfo(8708, 37119), DeliveryInfo(127448, 49900), DeliveryInfo(13359, 35094), DeliveryInfo(101811, 66406), DeliveryInfo(48083, 4242), DeliveryInfo(45059, 23761), DeliveryInfo(27542, 873), DeliveryInfo(54034, 99487), DeliveryInfo(25744, 118372), DeliveryInfo(116084, 25951), DeliveryInfo(127132, 24926), DeliveryInfo(55508, 135999), DeliveryInfo(142393, 96716), DeliveryInfo(86547, 86281), DeliveryInfo(106575, 54408), DeliveryInfo(87418, 2439), DeliveryInfo(49614, 112620), DeliveryInfo(139936, 115780), DeliveryInfo(46277, 85754), DeliveryInfo(110425, 71485), DeliveryInfo(21811, 96299), DeliveryInfo(64020, 115750), DeliveryInfo(85039, 70543), DeliveryInfo(89465, 1810), DeliveryInfo(132276, 19667), DeliveryInfo(52362, 67251), DeliveryInfo(102052, 56792)};
        depots = {13, 49722, 59265, 82806};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_new_york_usa: INVALID" << std::endl;
        }
        
    } //hard_new_york_usa

    TEST(hard_multi_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(105453, 107852), DeliveryInfo(101827, 134224), DeliveryInfo(17255, 120895), DeliveryInfo(56014, 67681), DeliveryInfo(130940, 139465), DeliveryInfo(28391, 35145), DeliveryInfo(12204, 111773), DeliveryInfo(81654, 125343), DeliveryInfo(104898, 51632), DeliveryInfo(40773, 3339), DeliveryInfo(72012, 23796), DeliveryInfo(144731, 143532), DeliveryInfo(120394, 84064), DeliveryInfo(52380, 82252), DeliveryInfo(6992, 110570), DeliveryInfo(140236, 98741), DeliveryInfo(83422, 53104), DeliveryInfo(138719, 142079), DeliveryInfo(48755, 111418), DeliveryInfo(119816, 70645), DeliveryInfo(38738, 87017), DeliveryInfo(142593, 124359), DeliveryInfo(54171, 110300), DeliveryInfo(23903, 139465), DeliveryInfo(118070, 52422), DeliveryInfo(132549, 5303), DeliveryInfo(78096, 141103), DeliveryInfo(131836, 64944), DeliveryInfo(6932, 51632), DeliveryInfo(68437, 16263), DeliveryInfo(79274, 111902), DeliveryInfo(42384, 71632), DeliveryInfo(94142, 145411), DeliveryInfo(129417, 141347), DeliveryInfo(68726, 108808), DeliveryInfo(98565, 40211), DeliveryInfo(117234, 69872), DeliveryInfo(83979, 126928), DeliveryInfo(126339, 91431), DeliveryInfo(27263, 76143), DeliveryInfo(65156, 139465), DeliveryInfo(55710, 1059), DeliveryInfo(79590, 117893), DeliveryInfo(32838, 20786), DeliveryInfo(130848, 125766), DeliveryInfo(127565, 4518), DeliveryInfo(133197, 6876), DeliveryInfo(117234, 110732), DeliveryInfo(23579, 116890), DeliveryInfo(8759, 135468), DeliveryInfo(19041, 51517), DeliveryInfo(99585, 119493), DeliveryInfo(140562, 140798), DeliveryInfo(10704, 131867), DeliveryInfo(61374, 144688), DeliveryInfo(76136, 137200), DeliveryInfo(92252, 139465), DeliveryInfo(30536, 47873), DeliveryInfo(117234, 34444), DeliveryInfo(49275, 61796), DeliveryInfo(145857, 51632), DeliveryInfo(117234, 16474), DeliveryInfo(104898, 70118), DeliveryInfo(74214, 32184), DeliveryInfo(72726, 51632), DeliveryInfo(70975, 102795), DeliveryInfo(140279, 96886), DeliveryInfo(67525, 80441), DeliveryInfo(139508, 109620), DeliveryInfo(138718, 30226), DeliveryInfo(104898, 18212), DeliveryInfo(142846, 47280), DeliveryInfo(140637, 139465), DeliveryInfo(68277, 10266), DeliveryInfo(121781, 31140)};
        depots = {16, 62153, 988, 66961, 122764, 138650, 84039};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_multi_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_multi_new_york_usa: INVALID" << std::endl;
        }
        
    } //hard_multi_new_york_usa

} //hard_new_york_usa_public

