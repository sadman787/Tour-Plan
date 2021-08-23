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


SUITE(simple_legality_new_york_usa_public) {
    TEST(simple_legality_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        std::vector<unsigned> result_path;
        float turn_penalty;
        
        deliveries = {DeliveryInfo(74805, 128152), DeliveryInfo(145468, 106162)};
        depots = {86530};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(result_path.empty());
        
        deliveries = {DeliveryInfo(98827, 140269), DeliveryInfo(2660, 63196), DeliveryInfo(78162, 42171), DeliveryInfo(137148, 85912), DeliveryInfo(55265, 85419)};
        depots = {3385, 6921, 55244};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(137435, 54608), DeliveryInfo(89304, 44517), DeliveryInfo(86240, 94261), DeliveryInfo(13621, 120264), DeliveryInfo(69560, 114433)};
        depots = {19506, 28786, 55617};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(12274, 26509), DeliveryInfo(90152, 84662)};
        depots = {32688, 114079};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(20826, 137686), DeliveryInfo(123308, 30239), DeliveryInfo(139961, 57655), DeliveryInfo(123308, 137686), DeliveryInfo(107183, 137686), DeliveryInfo(102095, 26644), DeliveryInfo(102095, 30239), DeliveryInfo(102095, 26172), DeliveryInfo(102095, 30239)};
        depots = {36434, 93268, 67449};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(10142, 15303), DeliveryInfo(28036, 102149), DeliveryInfo(103288, 102149), DeliveryInfo(145306, 102149), DeliveryInfo(145306, 133200), DeliveryInfo(43675, 133200), DeliveryInfo(43675, 123871), DeliveryInfo(43675, 133200), DeliveryInfo(43675, 69990)};
        depots = {43961, 37384, 37801};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(18828, 25513), DeliveryInfo(64582, 5452), DeliveryInfo(73702, 68329)};
        depots = {48950, 66629, 11142};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(57806, 115456)};
        depots = {45092, 75270};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(110306, 126010), DeliveryInfo(97437, 5334), DeliveryInfo(75580, 121419), DeliveryInfo(143748, 59405), DeliveryInfo(90496, 59405), DeliveryInfo(107467, 132100), DeliveryInfo(133905, 126010), DeliveryInfo(27461, 126010)};
        depots = {44921, 33012, 119367};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(24602, 114637), DeliveryInfo(80120, 130644), DeliveryInfo(132636, 106295), DeliveryInfo(109004, 47001), DeliveryInfo(120024, 21231)};
        depots = {71969, 47146, 98785};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(139406, 5000), DeliveryInfo(46434, 122096), DeliveryInfo(103394, 48238), DeliveryInfo(64337, 122096), DeliveryInfo(107459, 52922), DeliveryInfo(142949, 48238), DeliveryInfo(29696, 48238), DeliveryInfo(7231, 128593)};
        depots = {78180, 26134, 76222};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(9751, 121730), DeliveryInfo(56981, 27901), DeliveryInfo(24179, 140126)};
        depots = {84644, 98546, 13655};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(30980, 107680), DeliveryInfo(31503, 81848), DeliveryInfo(84521, 24460), DeliveryInfo(110051, 26107), DeliveryInfo(115521, 62259)};
        depots = {107617, 34672, 7396};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(60226, 132867), DeliveryInfo(145061, 84358), DeliveryInfo(23963, 102114)};
        depots = {108077, 45921, 64153};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(13090, 81921), DeliveryInfo(85114, 118347)};
        depots = {108691};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(70834, 32532), DeliveryInfo(70834, 30140), DeliveryInfo(16812, 88380), DeliveryInfo(70834, 83543), DeliveryInfo(35674, 97168), DeliveryInfo(24871, 102038), DeliveryInfo(107460, 1060), DeliveryInfo(107460, 68049)};
        depots = {79033, 6228, 80398};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(121106, 114085), DeliveryInfo(77851, 115871), DeliveryInfo(77851, 85568), DeliveryInfo(133399, 114556), DeliveryInfo(1375, 22354), DeliveryInfo(116128, 83627), DeliveryInfo(77851, 139233), DeliveryInfo(121106, 21570)};
        depots = {110092, 101248, 46640};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(71979, 112979), DeliveryInfo(10476, 28047)};
        depots = {87646, 123517};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(141502, 27730)};
        depots = {130341};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(24078, 125426)};
        depots = {131792, 140563};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(34502, 117229), DeliveryInfo(44369, 9303), DeliveryInfo(140990, 143640), DeliveryInfo(134118, 8216), DeliveryInfo(32484, 143640), DeliveryInfo(89728, 9303), DeliveryInfo(65574, 9303), DeliveryInfo(63788, 143820)};
        depots = {133241, 45320, 115996};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(12430, 87909)};
        depots = {3};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(136866, 60615)};
        depots = {132568, 42982};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(69368, 98734), DeliveryInfo(18708, 65752), DeliveryInfo(80425, 59795), DeliveryInfo(58657, 90388), DeliveryInfo(30426, 108836)};
        depots = {48465, 52329, 44447};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(56890, 37643), DeliveryInfo(63531, 79882), DeliveryInfo(26791, 112291), DeliveryInfo(26791, 37643), DeliveryInfo(20655, 79882), DeliveryInfo(56890, 79882), DeliveryInfo(26791, 89254), DeliveryInfo(119733, 28726), DeliveryInfo(26791, 37643)};
        depots = {57680, 36772, 67911};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(35464, 59326), DeliveryInfo(95647, 107537), DeliveryInfo(137444, 61146), DeliveryInfo(87164, 134539), DeliveryInfo(132132, 17023)};
        depots = {140932, 142109, 96354};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(43432, 62282), DeliveryInfo(131494, 95459)};
        depots = {141305};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(58183, 38433)};
        depots = {75282};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(86602, 13687), DeliveryInfo(89098, 63190)};
        depots = {100743, 79565};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(39721, 28937), DeliveryInfo(98332, 22060), DeliveryInfo(98332, 37279), DeliveryInfo(90964, 89765), DeliveryInfo(90964, 85914), DeliveryInfo(98332, 116794), DeliveryInfo(86695, 131078), DeliveryInfo(39540, 57943)};
        depots = {144842, 16601, 127275};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
    } //simple_legality_new_york_usa

} //simple_legality_new_york_usa_public

