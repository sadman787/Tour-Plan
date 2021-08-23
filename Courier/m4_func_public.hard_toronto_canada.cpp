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


SUITE(hard_toronto_canada_public) {
    TEST(hard_toronto_canada) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(79796, 42839), DeliveryInfo(6620, 18908), DeliveryInfo(12917, 69324), DeliveryInfo(4009, 76027), DeliveryInfo(78640, 49449), DeliveryInfo(21674, 90763), DeliveryInfo(50896, 23880), DeliveryInfo(74090, 53653), DeliveryInfo(2111, 61148), DeliveryInfo(43971, 1223), DeliveryInfo(50063, 91913), DeliveryInfo(82083, 84759), DeliveryInfo(105386, 101774), DeliveryInfo(107769, 57682), DeliveryInfo(82981, 96244), DeliveryInfo(8738, 34980), DeliveryInfo(1342, 95587), DeliveryInfo(42483, 103377), DeliveryInfo(1161, 103664), DeliveryInfo(21428, 77598), DeliveryInfo(71316, 23235), DeliveryInfo(95619, 32911), DeliveryInfo(99061, 18848), DeliveryInfo(93949, 20039), DeliveryInfo(67982, 12095), DeliveryInfo(11945, 105365), DeliveryInfo(94347, 20391), DeliveryInfo(92583, 13875), DeliveryInfo(2811, 42442), DeliveryInfo(20951, 31516), DeliveryInfo(104712, 15493), DeliveryInfo(25003, 55427), DeliveryInfo(23213, 50781), DeliveryInfo(33297, 94451), DeliveryInfo(91792, 620), DeliveryInfo(94877, 17273), DeliveryInfo(42021, 30653), DeliveryInfo(45453, 80507), DeliveryInfo(19701, 9255), DeliveryInfo(100880, 11642), DeliveryInfo(43478, 97117), DeliveryInfo(37661, 18514), DeliveryInfo(27367, 105658), DeliveryInfo(4306, 54259), DeliveryInfo(107255, 358), DeliveryInfo(90985, 90550), DeliveryInfo(105483, 54918), DeliveryInfo(52218, 24878), DeliveryInfo(64146, 14569), DeliveryInfo(96695, 6359), DeliveryInfo(77408, 7132), DeliveryInfo(475, 94272), DeliveryInfo(94111, 10286), DeliveryInfo(102213, 28393), DeliveryInfo(31031, 5428), DeliveryInfo(61407, 87201), DeliveryInfo(52502, 25739), DeliveryInfo(64678, 11041), DeliveryInfo(7230, 43223), DeliveryInfo(42470, 32197), DeliveryInfo(17541, 79209), DeliveryInfo(38249, 15541), DeliveryInfo(44546, 79051), DeliveryInfo(11121, 102845), DeliveryInfo(55855, 31136), DeliveryInfo(38533, 45203), DeliveryInfo(82603, 34501), DeliveryInfo(84243, 24909), DeliveryInfo(69588, 744), DeliveryInfo(10546, 6312), DeliveryInfo(16898, 19546), DeliveryInfo(43784, 60601), DeliveryInfo(64789, 68213), DeliveryInfo(28003, 21779), DeliveryInfo(17561, 48204), DeliveryInfo(69514, 34766), DeliveryInfo(17040, 74080), DeliveryInfo(91356, 102978), DeliveryInfo(6292, 87024), DeliveryInfo(65826, 27845), DeliveryInfo(80009, 86251), DeliveryInfo(105642, 44253), DeliveryInfo(16066, 8023), DeliveryInfo(20106, 87653), DeliveryInfo(66771, 16683), DeliveryInfo(90038, 88410), DeliveryInfo(40917, 83054), DeliveryInfo(60050, 94321), DeliveryInfo(55413, 11814), DeliveryInfo(56359, 1693), DeliveryInfo(23931, 47427), DeliveryInfo(86665, 93996), DeliveryInfo(79695, 16400), DeliveryInfo(58624, 21665), DeliveryInfo(82028, 43899), DeliveryInfo(30893, 19071), DeliveryInfo(31114, 26049), DeliveryInfo(31066, 56617), DeliveryInfo(103338, 92746), DeliveryInfo(7629, 13181)};
        depots = {8552, 38211, 92758, 39860, 100277, 17123, 6130, 40760, 5413, 47813};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_toronto_canada: INVALID" << std::endl;
        }
        
    } //hard_toronto_canada

    TEST(hard_multi_toronto_canada) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(102168, 46017), DeliveryInfo(59033, 3949), DeliveryInfo(52607, 70747), DeliveryInfo(62536, 100049), DeliveryInfo(87300, 100878), DeliveryInfo(61813, 23189), DeliveryInfo(103299, 82337), DeliveryInfo(87922, 6329), DeliveryInfo(106883, 61250), DeliveryInfo(74157, 81025), DeliveryInfo(107776, 82337), DeliveryInfo(24454, 83613), DeliveryInfo(89223, 26925), DeliveryInfo(22739, 82458), DeliveryInfo(96372, 26433), DeliveryInfo(56696, 21665), DeliveryInfo(94993, 64798), DeliveryInfo(103248, 35208), DeliveryInfo(68697, 105256), DeliveryInfo(105074, 73527), DeliveryInfo(14179, 3364), DeliveryInfo(20302, 23189), DeliveryInfo(97506, 81025), DeliveryInfo(51178, 62599), DeliveryInfo(94080, 80313), DeliveryInfo(39037, 63926), DeliveryInfo(45703, 90270), DeliveryInfo(108282, 64030), DeliveryInfo(7971, 96808), DeliveryInfo(53625, 82969), DeliveryInfo(62121, 7506), DeliveryInfo(38448, 83330), DeliveryInfo(89653, 73370), DeliveryInfo(70104, 23189), DeliveryInfo(103248, 22508), DeliveryInfo(36693, 53342), DeliveryInfo(106372, 81025), DeliveryInfo(103248, 56701), DeliveryInfo(48740, 82337), DeliveryInfo(48519, 22647), DeliveryInfo(106184, 12268), DeliveryInfo(107776, 105310), DeliveryInfo(107776, 87790), DeliveryInfo(50962, 1044), DeliveryInfo(103248, 59901), DeliveryInfo(41485, 2487), DeliveryInfo(54156, 35650), DeliveryInfo(103854, 788), DeliveryInfo(90686, 19604), DeliveryInfo(12849, 23966), DeliveryInfo(104727, 82337), DeliveryInfo(34239, 87043), DeliveryInfo(97438, 43353), DeliveryInfo(103887, 19163), DeliveryInfo(39005, 56987), DeliveryInfo(17558, 94519), DeliveryInfo(21142, 60659), DeliveryInfo(90026, 92605), DeliveryInfo(52852, 73529), DeliveryInfo(5207, 12090), DeliveryInfo(26171, 5120), DeliveryInfo(17800, 7514), DeliveryInfo(60805, 82874), DeliveryInfo(41711, 81630), DeliveryInfo(104428, 104847), DeliveryInfo(107744, 25649), DeliveryInfo(12111, 50400), DeliveryInfo(38362, 59881), DeliveryInfo(50843, 19784), DeliveryInfo(9088, 23189), DeliveryInfo(39544, 72147), DeliveryInfo(107776, 1708), DeliveryInfo(108614, 93653), DeliveryInfo(82136, 13562), DeliveryInfo(104671, 52031), DeliveryInfo(50283, 97305), DeliveryInfo(103298, 30594), DeliveryInfo(73397, 93338), DeliveryInfo(29944, 98197), DeliveryInfo(31562, 89513), DeliveryInfo(7644, 98949), DeliveryInfo(86296, 33118), DeliveryInfo(99187, 83233), DeliveryInfo(30362, 105801), DeliveryInfo(59268, 27793), DeliveryInfo(78113, 88982), DeliveryInfo(36306, 99377), DeliveryInfo(98705, 81149), DeliveryInfo(5162, 34639), DeliveryInfo(55265, 37355), DeliveryInfo(49864, 93912), DeliveryInfo(78527, 88186), DeliveryInfo(75827, 17720), DeliveryInfo(40339, 21829), DeliveryInfo(98173, 58391), DeliveryInfo(103248, 99952), DeliveryInfo(58155, 18617), DeliveryInfo(52214, 66081), DeliveryInfo(28847, 15478), DeliveryInfo(104461, 56342)};
        depots = {12, 46283, 736};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR hard_multi_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR hard_multi_toronto_canada: INVALID" << std::endl;
        }
        
    } //hard_multi_toronto_canada

} //hard_toronto_canada_public

