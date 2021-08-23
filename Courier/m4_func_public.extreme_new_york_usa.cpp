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


SUITE(extreme_new_york_usa_public) {
    TEST(extreme_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(50564, 99439), DeliveryInfo(107510, 133245), DeliveryInfo(87970, 87000), DeliveryInfo(7063, 86643), DeliveryInfo(47501, 23024), DeliveryInfo(57005, 110701), DeliveryInfo(81752, 116636), DeliveryInfo(113936, 27409), DeliveryInfo(94528, 144788), DeliveryInfo(30020, 30120), DeliveryInfo(33600, 119792), DeliveryInfo(133062, 44364), DeliveryInfo(89501, 128388), DeliveryInfo(103972, 140847), DeliveryInfo(36074, 94549), DeliveryInfo(124522, 60546), DeliveryInfo(19751, 64603), DeliveryInfo(14539, 40926), DeliveryInfo(88653, 132788), DeliveryInfo(104178, 45846), DeliveryInfo(76389, 24232), DeliveryInfo(79775, 128266), DeliveryInfo(102258, 33870), DeliveryInfo(137631, 40484), DeliveryInfo(101283, 133200), DeliveryInfo(135115, 65690), DeliveryInfo(142403, 33789), DeliveryInfo(66342, 93039), DeliveryInfo(109409, 85383), DeliveryInfo(46598, 42706), DeliveryInfo(121009, 97906), DeliveryInfo(114111, 105683), DeliveryInfo(46626, 129314), DeliveryInfo(122769, 60489), DeliveryInfo(129948, 109472), DeliveryInfo(8911, 123777), DeliveryInfo(47940, 20749), DeliveryInfo(48682, 79117), DeliveryInfo(44696, 63355), DeliveryInfo(95336, 63127), DeliveryInfo(35673, 137538), DeliveryInfo(23755, 110230), DeliveryInfo(94277, 124455), DeliveryInfo(127765, 143214), DeliveryInfo(103109, 14656), DeliveryInfo(120363, 127115), DeliveryInfo(130516, 121129), DeliveryInfo(137215, 7913), DeliveryInfo(92717, 90161), DeliveryInfo(34156, 35288), DeliveryInfo(144945, 62445), DeliveryInfo(40308, 10162), DeliveryInfo(97412, 141700), DeliveryInfo(97980, 80007), DeliveryInfo(139790, 138463), DeliveryInfo(19768, 55516), DeliveryInfo(67241, 69316), DeliveryInfo(99529, 40314), DeliveryInfo(125506, 71367), DeliveryInfo(45663, 113900), DeliveryInfo(82226, 82685), DeliveryInfo(7990, 20046), DeliveryInfo(119776, 84121), DeliveryInfo(26664, 102933), DeliveryInfo(42114, 64451), DeliveryInfo(111513, 58714), DeliveryInfo(3658, 133523), DeliveryInfo(121095, 136039), DeliveryInfo(13846, 128500), DeliveryInfo(145319, 42041), DeliveryInfo(5029, 120327), DeliveryInfo(133716, 81025), DeliveryInfo(52615, 143790), DeliveryInfo(91069, 103297), DeliveryInfo(95306, 92900), DeliveryInfo(107972, 44677), DeliveryInfo(66182, 31118), DeliveryInfo(9644, 49084), DeliveryInfo(49141, 128436), DeliveryInfo(19608, 45652), DeliveryInfo(59138, 89420), DeliveryInfo(30606, 77677), DeliveryInfo(15110, 116988), DeliveryInfo(88738, 79345), DeliveryInfo(5272, 31202), DeliveryInfo(21246, 112793), DeliveryInfo(20088, 94806), DeliveryInfo(44293, 136157), DeliveryInfo(15938, 43432), DeliveryInfo(80544, 13871), DeliveryInfo(37706, 53775), DeliveryInfo(143293, 141311), DeliveryInfo(20126, 75995), DeliveryInfo(187, 45710), DeliveryInfo(52726, 51304), DeliveryInfo(61128, 72081), DeliveryInfo(50478, 132368), DeliveryInfo(145223, 46506), DeliveryInfo(63676, 30183), DeliveryInfo(107926, 89265), DeliveryInfo(23813, 105984), DeliveryInfo(58300, 61515), DeliveryInfo(129693, 75131), DeliveryInfo(107251, 134837), DeliveryInfo(66795, 51471), DeliveryInfo(103744, 111341), DeliveryInfo(103954, 113723), DeliveryInfo(122217, 63908), DeliveryInfo(92140, 116422), DeliveryInfo(23780, 56284), DeliveryInfo(137821, 98661), DeliveryInfo(4297, 141257), DeliveryInfo(29992, 63616), DeliveryInfo(121730, 29827), DeliveryInfo(87756, 66801), DeliveryInfo(116032, 54105), DeliveryInfo(13831, 27354), DeliveryInfo(127202, 62522), DeliveryInfo(48707, 86870), DeliveryInfo(84179, 142814), DeliveryInfo(70330, 23626), DeliveryInfo(75003, 141213), DeliveryInfo(144638, 120588), DeliveryInfo(9295, 64107), DeliveryInfo(65496, 143966), DeliveryInfo(141466, 112927), DeliveryInfo(19433, 70421), DeliveryInfo(17394, 131001)};
        depots = {56782};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_new_york_usa: INVALID" << std::endl;
        }
        
    } //extreme_new_york_usa

    TEST(extreme_multi_new_york_usa) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        float turn_penalty;
        std::vector<unsigned> result_path;
        bool is_legal;
        
        deliveries = {DeliveryInfo(63880, 27769), DeliveryInfo(122377, 122330), DeliveryInfo(37214, 114433), DeliveryInfo(139469, 79556), DeliveryInfo(40241, 114364), DeliveryInfo(2277, 4047), DeliveryInfo(129435, 94027), DeliveryInfo(95837, 55403), DeliveryInfo(108518, 68504), DeliveryInfo(63880, 62206), DeliveryInfo(26862, 58758), DeliveryInfo(133572, 114364), DeliveryInfo(95001, 22808), DeliveryInfo(63880, 80057), DeliveryInfo(58311, 22725), DeliveryInfo(12526, 58758), DeliveryInfo(11088, 72602), DeliveryInfo(63880, 114433), DeliveryInfo(30260, 58169), DeliveryInfo(52923, 56240), DeliveryInfo(76258, 104686), DeliveryInfo(14009, 121917), DeliveryInfo(88447, 41102), DeliveryInfo(11346, 46298), DeliveryInfo(8076, 9969), DeliveryInfo(103909, 12449), DeliveryInfo(144894, 57956), DeliveryInfo(14009, 12757), DeliveryInfo(122763, 107935), DeliveryInfo(59579, 103273), DeliveryInfo(46995, 58758), DeliveryInfo(94718, 70785), DeliveryInfo(139469, 93678), DeliveryInfo(108383, 40045), DeliveryInfo(14009, 79164), DeliveryInfo(28983, 106077), DeliveryInfo(128688, 136385), DeliveryInfo(11088, 25036), DeliveryInfo(67291, 67523), DeliveryInfo(18613, 58758), DeliveryInfo(120680, 104575), DeliveryInfo(20896, 111456), DeliveryInfo(65665, 6567), DeliveryInfo(53691, 57083), DeliveryInfo(59242, 68504), DeliveryInfo(2277, 133053), DeliveryInfo(116134, 24785), DeliveryInfo(139469, 9969), DeliveryInfo(77693, 60488), DeliveryInfo(52328, 104575), DeliveryInfo(68261, 96349), DeliveryInfo(107911, 39276), DeliveryInfo(89096, 64618), DeliveryInfo(116440, 79164), DeliveryInfo(83261, 111526), DeliveryInfo(57995, 57956), DeliveryInfo(64297, 40045), DeliveryInfo(19476, 123215), DeliveryInfo(110006, 146163), DeliveryInfo(108810, 114364), DeliveryInfo(3545, 137222), DeliveryInfo(5446, 17462), DeliveryInfo(26862, 76259), DeliveryInfo(132734, 122330), DeliveryInfo(32900, 114433), DeliveryInfo(2155, 9969), DeliveryInfo(85756, 135777), DeliveryInfo(20596, 94027), DeliveryInfo(14009, 68504), DeliveryInfo(41130, 73936), DeliveryInfo(57995, 71217), DeliveryInfo(73848, 4961), DeliveryInfo(26862, 14834), DeliveryInfo(37223, 28861), DeliveryInfo(122314, 54476), DeliveryInfo(7548, 16762), DeliveryInfo(142598, 65439), DeliveryInfo(14009, 66618), DeliveryInfo(23373, 15414), DeliveryInfo(50204, 133813), DeliveryInfo(35213, 119029), DeliveryInfo(77503, 132052), DeliveryInfo(2277, 131392), DeliveryInfo(63880, 79164), DeliveryInfo(139469, 111634), DeliveryInfo(57995, 3687), DeliveryInfo(10776, 11374), DeliveryInfo(62732, 102078), DeliveryInfo(122377, 78251), DeliveryInfo(52771, 120369), DeliveryInfo(125279, 57956), DeliveryInfo(57995, 111389), DeliveryInfo(120191, 106817), DeliveryInfo(30260, 71217), DeliveryInfo(33945, 78904), DeliveryInfo(139469, 79164), DeliveryInfo(135969, 104575), DeliveryInfo(5528, 66350), DeliveryInfo(58498, 79164), DeliveryInfo(18613, 101476), DeliveryInfo(95677, 38052), DeliveryInfo(143258, 13076), DeliveryInfo(116587, 45157), DeliveryInfo(122361, 29082), DeliveryInfo(17935, 57083), DeliveryInfo(63880, 126815), DeliveryInfo(11088, 110612), DeliveryInfo(114426, 9969), DeliveryInfo(20896, 110851), DeliveryInfo(57995, 26647), DeliveryInfo(63880, 66350), DeliveryInfo(93342, 7747), DeliveryInfo(146110, 135777), DeliveryInfo(1466, 129213), DeliveryInfo(11088, 90085), DeliveryInfo(63880, 66350), DeliveryInfo(66259, 81602), DeliveryInfo(18613, 32775), DeliveryInfo(15607, 75472), DeliveryInfo(139469, 8011), DeliveryInfo(6779, 93711), DeliveryInfo(101365, 65568), DeliveryInfo(139469, 124884), DeliveryInfo(120513, 83260), DeliveryInfo(24213, 15558), DeliveryInfo(52328, 126815), DeliveryInfo(59583, 53341), DeliveryInfo(123648, 104575), DeliveryInfo(69195, 55968), DeliveryInfo(92141, 40045), DeliveryInfo(72834, 139882), DeliveryInfo(26862, 86612), DeliveryInfo(11088, 108320), DeliveryInfo(125022, 45969), DeliveryInfo(18613, 107935), DeliveryInfo(85319, 139882), DeliveryInfo(26862, 3154), DeliveryInfo(52328, 69814), DeliveryInfo(11088, 64312), DeliveryInfo(20896, 136385), DeliveryInfo(30260, 6606), DeliveryInfo(133861, 135777), DeliveryInfo(124046, 16447), DeliveryInfo(3439, 139882), DeliveryInfo(17935, 57083), DeliveryInfo(11088, 14117), DeliveryInfo(18613, 38163), DeliveryInfo(63880, 68504), DeliveryInfo(49998, 139997), DeliveryInfo(18613, 83213), DeliveryInfo(57126, 68504), DeliveryInfo(95001, 114364), DeliveryInfo(109398, 8949), DeliveryInfo(26862, 117912), DeliveryInfo(38253, 121917), DeliveryInfo(126580, 57956), DeliveryInfo(57995, 70608), DeliveryInfo(41974, 135777), DeliveryInfo(92864, 17349), DeliveryInfo(47403, 145130), DeliveryInfo(34355, 57956), DeliveryInfo(7548, 71217), DeliveryInfo(141323, 13572), DeliveryInfo(26862, 104575), DeliveryInfo(11123, 115070), DeliveryInfo(30260, 51333), DeliveryInfo(116134, 1117), DeliveryInfo(45077, 117599), DeliveryInfo(57995, 78), DeliveryInfo(54077, 9969), DeliveryInfo(7548, 100999), DeliveryInfo(67758, 101023), DeliveryInfo(63880, 2441), DeliveryInfo(57995, 122330), DeliveryInfo(139469, 135777), DeliveryInfo(67593, 40045), DeliveryInfo(105397, 10548), DeliveryInfo(82158, 87462), DeliveryInfo(50671, 20926), DeliveryInfo(50844, 94027), DeliveryInfo(53252, 112299), DeliveryInfo(33577, 122330), DeliveryInfo(107892, 22194), DeliveryInfo(139469, 65030), DeliveryInfo(56645, 56508), DeliveryInfo(14009, 57083), DeliveryInfo(8733, 40045), DeliveryInfo(2723, 4560), DeliveryInfo(76984, 106817), DeliveryInfo(87431, 47250), DeliveryInfo(64676, 58758), DeliveryInfo(2277, 139704)};
        depots = {144690, 121666};
        turn_penalty = 15;
        {
        	ECE297_TIME_CONSTRAINT(30000);
        	
        	result_path = traveling_courier(deliveries, depots, turn_penalty);
        }
        
        is_legal = courier_path_is_legal(deliveries, depots, result_path);
        CHECK(is_legal);
        
        if(is_legal) {
        	double path_cost = compute_path_travel_time(result_path, turn_penalty);
        	std::cout << "QoR extreme_multi_new_york_usa: " << path_cost << std::endl;
        } else {
        	std::cout << "QoR extreme_multi_new_york_usa: INVALID" << std::endl;
        }
        
    } //extreme_multi_new_york_usa

} //extreme_new_york_usa_public

