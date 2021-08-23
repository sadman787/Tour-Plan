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


SUITE(extreme_toronto_canada_public) {
    TEST(extreme_toronto_canada) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(70831, 51733), DeliveryInfo(64614, 49104), DeliveryInfo(86395, 90198), DeliveryInfo(68915, 1748), DeliveryInfo(77817, 36464), DeliveryInfo(7906, 86992), DeliveryInfo(85195, 97964), DeliveryInfo(24366, 11113), DeliveryInfo(62657, 72429), DeliveryInfo(44826, 33045), DeliveryInfo(6566, 86491), DeliveryInfo(91850, 60035), DeliveryInfo(36280, 57275), DeliveryInfo(97481, 1195), DeliveryInfo(68300, 60860), DeliveryInfo(77791, 15128), DeliveryInfo(69739, 8078), DeliveryInfo(68385, 108770), DeliveryInfo(75459, 100013), DeliveryInfo(67285, 100826), DeliveryInfo(16103, 47349), DeliveryInfo(44690, 30333), DeliveryInfo(989, 81045), DeliveryInfo(95265, 10843), DeliveryInfo(15804, 90041), DeliveryInfo(66262, 30923), DeliveryInfo(69352, 11124), DeliveryInfo(39741, 80709), DeliveryInfo(107067, 9155), DeliveryInfo(9727, 87561), DeliveryInfo(14679, 69801), DeliveryInfo(49350, 45035), DeliveryInfo(46806, 39996), DeliveryInfo(22340, 50841), DeliveryInfo(83735, 29110), DeliveryInfo(84125, 35208), DeliveryInfo(27827, 94577), DeliveryInfo(99880, 45391), DeliveryInfo(51371, 56818), DeliveryInfo(108031, 19488), DeliveryInfo(41567, 48318), DeliveryInfo(2266, 5702), DeliveryInfo(82273, 58171), DeliveryInfo(105662, 92219), DeliveryInfo(71511, 93073), DeliveryInfo(76398, 49443), DeliveryInfo(44689, 105495), DeliveryInfo(20806, 49666), DeliveryInfo(74292, 43619), DeliveryInfo(99932, 46063), DeliveryInfo(67216, 82420), DeliveryInfo(83186, 45317), DeliveryInfo(76221, 39119), DeliveryInfo(23822, 101787), DeliveryInfo(30252, 47210), DeliveryInfo(21261, 30777), DeliveryInfo(32640, 60454), DeliveryInfo(5132, 5321), DeliveryInfo(36493, 6120), DeliveryInfo(57286, 100769), DeliveryInfo(96376, 26250), DeliveryInfo(51728, 103554), DeliveryInfo(40558, 39484), DeliveryInfo(2725, 55441), DeliveryInfo(74490, 26052), DeliveryInfo(39219, 29203), DeliveryInfo(81784, 3342), DeliveryInfo(9007, 54902), DeliveryInfo(74175, 27755), DeliveryInfo(21235, 22648), DeliveryInfo(53109, 15924), DeliveryInfo(4863, 44723), DeliveryInfo(37191, 76062), DeliveryInfo(88341, 85383), DeliveryInfo(94683, 55071), DeliveryInfo(36870, 22371), DeliveryInfo(27010, 53986), DeliveryInfo(4562, 6641), DeliveryInfo(54939, 83587), DeliveryInfo(56452, 69532), DeliveryInfo(98765, 72206), DeliveryInfo(57705, 18710), DeliveryInfo(93630, 76760), DeliveryInfo(75607, 23835), DeliveryInfo(50531, 62871), DeliveryInfo(87576, 103929), DeliveryInfo(75119, 104926), DeliveryInfo(28917, 94863), DeliveryInfo(48014, 79421), DeliveryInfo(67807, 70881), DeliveryInfo(36713, 40596), DeliveryInfo(60356, 107976), DeliveryInfo(61155, 49594), DeliveryInfo(5404, 68375), DeliveryInfo(86324, 87156), DeliveryInfo(58034, 43156), DeliveryInfo(26541, 93050), DeliveryInfo(49782, 56269), DeliveryInfo(98805, 88285), DeliveryInfo(96318, 57406), DeliveryInfo(3909, 1063), DeliveryInfo(106669, 38602), DeliveryInfo(60559, 39417), DeliveryInfo(32310, 77756), DeliveryInfo(43215, 79559), DeliveryInfo(2719, 85706), DeliveryInfo(44546, 50836), DeliveryInfo(103884, 51061), DeliveryInfo(33352, 97894), DeliveryInfo(13982, 53927), DeliveryInfo(39136, 83642), DeliveryInfo(16454, 16407), DeliveryInfo(107566, 10186), DeliveryInfo(55738, 29559), DeliveryInfo(20433, 64640), DeliveryInfo(51018, 47704), DeliveryInfo(83418, 20963), DeliveryInfo(46690, 88588), DeliveryInfo(79849, 202), DeliveryInfo(74264, 55481), DeliveryInfo(86580, 46058), DeliveryInfo(41171, 66137), DeliveryInfo(75263, 31994), DeliveryInfo(9586, 45923), DeliveryInfo(103834, 69443), DeliveryInfo(50331, 53154), DeliveryInfo(60773, 99528), DeliveryInfo(55406, 19758), DeliveryInfo(6145, 89729), DeliveryInfo(108448, 58740), DeliveryInfo(81702, 13838), DeliveryInfo(103362, 31397), DeliveryInfo(54844, 92286), DeliveryInfo(43567, 69760), DeliveryInfo(79978, 86281), DeliveryInfo(22727, 51589), DeliveryInfo(80415, 31898), DeliveryInfo(94398, 36759), DeliveryInfo(85643, 11886), DeliveryInfo(99530, 91160), DeliveryInfo(24362, 91302), DeliveryInfo(61012, 103837), DeliveryInfo(65021, 32757), DeliveryInfo(51692, 101825), DeliveryInfo(98287, 68477), DeliveryInfo(61805, 90143), DeliveryInfo(92611, 90642), DeliveryInfo(89383, 26267), DeliveryInfo(107584, 16088), DeliveryInfo(26525, 77272), DeliveryInfo(82828, 107683), DeliveryInfo(47068, 107059), DeliveryInfo(41357, 87541), DeliveryInfo(1224, 69355), DeliveryInfo(25809, 18541), DeliveryInfo(98564, 427), DeliveryInfo(68616, 101140), DeliveryInfo(41462, 75845), DeliveryInfo(84210, 94998), DeliveryInfo(47770, 5933), DeliveryInfo(74323, 20719), DeliveryInfo(96722, 88605), DeliveryInfo(98608, 101900), DeliveryInfo(16936, 27083), DeliveryInfo(47448, 39881), DeliveryInfo(74333, 43454), DeliveryInfo(18735, 66274), DeliveryInfo(51610, 59328), DeliveryInfo(7572, 44358), DeliveryInfo(96967, 76061), DeliveryInfo(20466, 30814), DeliveryInfo(78564, 5062), DeliveryInfo(102853, 7788), DeliveryInfo(47378, 8940), DeliveryInfo(4738, 45674)};
        depots = {14, 55539, 66199, 38064, 87930, 15037, 9781, 42243, 62859, 50192, 58489, 39444, 53709, 93336, 60037, 7650, 28282, 105649, 38892, 87051};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_toronto_canada: INVALID" << std::endl;
        }
        
    } //extreme_toronto_canada

    TEST(extreme_multi_toronto_canada) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(79455, 73885), DeliveryInfo(14430, 10485), DeliveryInfo(79455, 99841), DeliveryInfo(108559, 26485), DeliveryInfo(38749, 65506), DeliveryInfo(20835, 87067), DeliveryInfo(84376, 107360), DeliveryInfo(42725, 29784), DeliveryInfo(32762, 75186), DeliveryInfo(34213, 39393), DeliveryInfo(69426, 107360), DeliveryInfo(55325, 28231), DeliveryInfo(33647, 31763), DeliveryInfo(68294, 15356), DeliveryInfo(70155, 24347), DeliveryInfo(28514, 55990), DeliveryInfo(46387, 88018), DeliveryInfo(37630, 15626), DeliveryInfo(86263, 58035), DeliveryInfo(82461, 20408), DeliveryInfo(91578, 24347), DeliveryInfo(107158, 42714), DeliveryInfo(35313, 7843), DeliveryInfo(17403, 47053), DeliveryInfo(77278, 63670), DeliveryInfo(37630, 93854), DeliveryInfo(33647, 107676), DeliveryInfo(37995, 30867), DeliveryInfo(71720, 73392), DeliveryInfo(4875, 89987), DeliveryInfo(57530, 37233), DeliveryInfo(71726, 50174), DeliveryInfo(47045, 15356), DeliveryInfo(97081, 15356), DeliveryInfo(34213, 67172), DeliveryInfo(80829, 63670), DeliveryInfo(103400, 101884), DeliveryInfo(107667, 64172), DeliveryInfo(57530, 83862), DeliveryInfo(26535, 101729), DeliveryInfo(578, 4701), DeliveryInfo(82, 2027), DeliveryInfo(20059, 51404), DeliveryInfo(43367, 54326), DeliveryInfo(37995, 97563), DeliveryInfo(6469, 102816), DeliveryInfo(106029, 42732), DeliveryInfo(36836, 106282), DeliveryInfo(71616, 12665), DeliveryInfo(17189, 31763), DeliveryInfo(51160, 63670), DeliveryInfo(2030, 1781), DeliveryInfo(52135, 58035), DeliveryInfo(60829, 38153), DeliveryInfo(70329, 27322), DeliveryInfo(56687, 50174), DeliveryInfo(102644, 93854), DeliveryInfo(51160, 21629), DeliveryInfo(89837, 21123), DeliveryInfo(62814, 44061), DeliveryInfo(5485, 4477), DeliveryInfo(33647, 65506), DeliveryInfo(51160, 75466), DeliveryInfo(67195, 14706), DeliveryInfo(51160, 7843), DeliveryInfo(37995, 12665), DeliveryInfo(107053, 86249), DeliveryInfo(79455, 70851), DeliveryInfo(20490, 59387), DeliveryInfo(51160, 77914), DeliveryInfo(79455, 80541), DeliveryInfo(103954, 30634), DeliveryInfo(100065, 20408), DeliveryInfo(83317, 38615), DeliveryInfo(45974, 20321), DeliveryInfo(35313, 1899), DeliveryInfo(62038, 67929), DeliveryInfo(70710, 57250), DeliveryInfo(5225, 53901), DeliveryInfo(82993, 33449), DeliveryInfo(51160, 49192), DeliveryInfo(69411, 43920), DeliveryInfo(57530, 48581), DeliveryInfo(34213, 12965), DeliveryInfo(99394, 17430), DeliveryInfo(12367, 10485), DeliveryInfo(82993, 80188), DeliveryInfo(56284, 56652), DeliveryInfo(37630, 93854), DeliveryInfo(34213, 9757), DeliveryInfo(8831, 81670), DeliveryInfo(67383, 70107), DeliveryInfo(66198, 105775), DeliveryInfo(72195, 20160), DeliveryInfo(51160, 4165), DeliveryInfo(52135, 84657), DeliveryInfo(51724, 59909), DeliveryInfo(34213, 33857), DeliveryInfo(22254, 96331), DeliveryInfo(2996, 24081), DeliveryInfo(19118, 53115), DeliveryInfo(79455, 30052), DeliveryInfo(40790, 107605), DeliveryInfo(79455, 63670), DeliveryInfo(62255, 36331), DeliveryInfo(99394, 63670), DeliveryInfo(61183, 67293), DeliveryInfo(107158, 65506), DeliveryInfo(92100, 30634), DeliveryInfo(61789, 5972), DeliveryInfo(87640, 7843), DeliveryInfo(69768, 80701), DeliveryInfo(105434, 67172), DeliveryInfo(44077, 12413), DeliveryInfo(37630, 25767), DeliveryInfo(51160, 50383), DeliveryInfo(32528, 103466), DeliveryInfo(37995, 4701), DeliveryInfo(37995, 73392), DeliveryInfo(105174, 12665), DeliveryInfo(66884, 68455), DeliveryInfo(97034, 38752), DeliveryInfo(107158, 84254), DeliveryInfo(38421, 54525), DeliveryInfo(26272, 38594), DeliveryInfo(46996, 12665), DeliveryInfo(35313, 76583), DeliveryInfo(39295, 7843), DeliveryInfo(24117, 10485), DeliveryInfo(66930, 57489), DeliveryInfo(27823, 4165), DeliveryInfo(55810, 107360), DeliveryInfo(35313, 80701), DeliveryInfo(37995, 73198), DeliveryInfo(29102, 43920), DeliveryInfo(6709, 52971), DeliveryInfo(39078, 69259), DeliveryInfo(99149, 7843), DeliveryInfo(102632, 15005), DeliveryInfo(105744, 30061), DeliveryInfo(87027, 50174), DeliveryInfo(40801, 69027), DeliveryInfo(6709, 80541), DeliveryInfo(107158, 97563), DeliveryInfo(26214, 31702), DeliveryInfo(77961, 20408), DeliveryInfo(35313, 74120), DeliveryInfo(1181, 59203), DeliveryInfo(83990, 33468), DeliveryInfo(26750, 15356), DeliveryInfo(37310, 20307), DeliveryInfo(79455, 73392), DeliveryInfo(102613, 3112), DeliveryInfo(60258, 67985), DeliveryInfo(10679, 27776), DeliveryInfo(40080, 58035), DeliveryInfo(99394, 26570), DeliveryInfo(57530, 31568), DeliveryInfo(3153, 22846), DeliveryInfo(42725, 93247), DeliveryInfo(49298, 92319), DeliveryInfo(6345, 13222), DeliveryInfo(59248, 38615), DeliveryInfo(91580, 21629), DeliveryInfo(2032, 98262), DeliveryInfo(80474, 38685), DeliveryInfo(33647, 68676), DeliveryInfo(35313, 60835), DeliveryInfo(83317, 28756), DeliveryInfo(99394, 59203), DeliveryInfo(86012, 93854), DeliveryInfo(47947, 21629), DeliveryInfo(14774, 65506), DeliveryInfo(79455, 58035), DeliveryInfo(23741, 46990), DeliveryInfo(102613, 10998), DeliveryInfo(108063, 15726), DeliveryInfo(41604, 6224), DeliveryInfo(104009, 73603), DeliveryInfo(75284, 67344), DeliveryInfo(6709, 104642), DeliveryInfo(101640, 7182), DeliveryInfo(36071, 54387), DeliveryInfo(98893, 33156), DeliveryInfo(30885, 107331), DeliveryInfo(82993, 66932), DeliveryInfo(33647, 31763), DeliveryInfo(24490, 92319), DeliveryInfo(57530, 57345), DeliveryInfo(12689, 59352), DeliveryInfo(6709, 65506), DeliveryInfo(103954, 50150), DeliveryInfo(1959, 16171), DeliveryInfo(20490, 98262), DeliveryInfo(8166, 56081), DeliveryInfo(34213, 71797), DeliveryInfo(31305, 67172), DeliveryInfo(24244, 21629), DeliveryInfo(75089, 97563), DeliveryInfo(7169, 97563), DeliveryInfo(30301, 67539), DeliveryInfo(90791, 81955), DeliveryInfo(42959, 59203), DeliveryInfo(57530, 61808), DeliveryInfo(410, 92494), DeliveryInfo(92349, 40334), DeliveryInfo(91580, 18045), DeliveryInfo(64993, 82804), DeliveryInfo(65560, 15298), DeliveryInfo(107158, 48468), DeliveryInfo(79455, 20408), DeliveryInfo(42725, 8731), DeliveryInfo(42725, 81558), DeliveryInfo(27119, 99648), DeliveryInfo(37630, 59203), DeliveryInfo(51160, 65981), DeliveryInfo(102613, 32994), DeliveryInfo(34797, 12045), DeliveryInfo(2237, 80710), DeliveryInfo(91580, 5061), DeliveryInfo(34213, 91631), DeliveryInfo(105744, 80541), DeliveryInfo(6226, 38594), DeliveryInfo(7394, 73392), DeliveryInfo(102613, 38594), DeliveryInfo(82871, 15356), DeliveryInfo(102887, 20408), DeliveryInfo(105744, 24347), DeliveryInfo(63589, 7550), DeliveryInfo(102613, 59324), DeliveryInfo(99394, 8553), DeliveryInfo(103589, 21617), DeliveryInfo(51160, 59203), DeliveryInfo(51813, 60651), DeliveryInfo(90255, 351), DeliveryInfo(37630, 37233), DeliveryInfo(102613, 74991), DeliveryInfo(71605, 38594), DeliveryInfo(37995, 10985), DeliveryInfo(99394, 7971), DeliveryInfo(12087, 73392), DeliveryInfo(5446, 11574), DeliveryInfo(52117, 107386), DeliveryInfo(35313, 21303), DeliveryInfo(71021, 79876), DeliveryInfo(57530, 67172), DeliveryInfo(79455, 12665), DeliveryInfo(50874, 70919), DeliveryInfo(102613, 31763), DeliveryInfo(34014, 66982), DeliveryInfo(6372, 98642), DeliveryInfo(1958, 10485), DeliveryInfo(52135, 29121), DeliveryInfo(52135, 31763), DeliveryInfo(54404, 12767), DeliveryInfo(34213, 6543), DeliveryInfo(3238, 13116), DeliveryInfo(99394, 89087), DeliveryInfo(102613, 43626), DeliveryInfo(97803, 59091)};
        depots = {80658, 107155, 34524, 106290, 80008};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_multi_toronto_canada: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_multi_toronto_canada: INVALID" << std::endl;
        }
        
    } //extreme_multi_toronto_canada

} //extreme_toronto_canada_public

