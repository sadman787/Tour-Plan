#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(path_cost_public) {
struct MapFixture {
    MapFixture() {
        rng = std::minstd_rand(4);
        rand_intersection = std::uniform_int_distribution<unsigned>(0, getNumberOfIntersections()-1);
        rand_street = std::uniform_int_distribution<unsigned>(1, getNumberOfStreets()-1);
        rand_segment = std::uniform_int_distribution<unsigned>(0, getNumberOfStreetSegments()-1);
        rand_poi = std::uniform_int_distribution<unsigned>(0, getNumberOfPointsOfInterest()-1);
        rand_lat = std::uniform_real_distribution<double>(43.479999542, 43.919979095);
        rand_lon = std::uniform_real_distribution<double>(-79.789978027, -79.000007629);
        rand_turn_penalty = std::uniform_real_distribution<double>(0., 30.);
    }

    std::minstd_rand rng;
    std::uniform_int_distribution<unsigned> rand_intersection;
    std::uniform_int_distribution<unsigned> rand_street;
    std::uniform_int_distribution<unsigned> rand_segment;
    std::uniform_int_distribution<unsigned> rand_poi;
    std::uniform_real_distribution<double> rand_lat;
    std::uniform_real_distribution<double> rand_lon;
    std::uniform_real_distribution<double> rand_turn_penalty;
};
    TEST(compute_path_travel_time) {
        std::vector<unsigned> path;
        double turn_penalty;
        double expected;
        double actual;
        
        path = {132941, 124882, 136925, 132920};
        turn_penalty = 31.68914896056834252;
        expected = 79.09153204215472499;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {41519, 41507, 81532, 81533, 81534, 42114, 42115, 42116, 42117, 42118, 42119, 42120, 81932};
        turn_penalty = 32.80671457076476116;
        expected = 267.72548985370656283;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {27049, 8446, 17946, 17947, 17948, 17949, 17950, 21251, 142871, 142872, 114704, 114705, 114706, 114707, 114708, 21071, 29780, 29781, 138965, 138966, 138967, 141756, 141757, 141758};
        turn_penalty = 38.78946586502576110;
        expected = 361.62939841990817058;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {145575, 145574, 145585, 145580, 51781, 51782, 51783, 58043, 58039, 58040, 58034, 26872, 26871, 59775, 59766, 59762, 59728, 59729, 59780, 59749, 59727, 59731, 59758, 59756, 59755, 59767, 59732, 59740, 59737, 59753, 59736, 59741, 59746, 59771, 59730, 59772, 59773, 59776, 59747, 59751, 59790, 59791, 106040, 106041, 106042, 155177, 155178, 106051, 106037, 106038, 106039, 70198, 70194, 70195, 27303, 27302, 27304, 70192, 70191, 70190, 70189, 70186, 70184};
        turn_penalty = 29.15722898780660799;
        expected = 404.87791324845761665;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {100838, 100840, 90028, 90036, 90026, 90056, 90055, 90053, 90057, 130950, 130949, 130948, 130947, 130959, 130960, 130956, 130955, 22778, 139210, 139211, 130946, 139207, 27332, 130958, 125000, 125004, 47193, 47194, 114607, 124959, 124960, 28713, 28714, 112792, 22599, 22598, 22596, 22597, 22620, 111820, 97344, 5096, 94624, 94625, 94626, 111827, 111828, 111829, 111830, 773, 774, 5118, 138454, 126341, 138455, 126336, 126337, 121086, 68495, 68496, 111833, 10842, 10822, 86147};
        turn_penalty = 2.68072293181142607;
        expected = 620.66038727979230316;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {104644, 104643, 104642, 104619, 104596, 115194, 115191, 26240, 26241, 99357, 114542, 114543, 114555, 114556, 114557, 121076, 121077, 121078, 114560, 102953, 29090, 114566, 29091, 114077, 114663, 23253, 17473, 103715, 23251, 23252, 26097, 43994, 43995, 103527, 103528, 103529, 103530, 103531, 103532, 103533, 103534, 103535, 103536, 103537, 91104, 26098, 23362, 100911, 26093, 26094, 26095, 26096, 26086, 29094, 17474, 29093, 87032, 87031, 87030, 87029, 87028, 87027, 87026, 87025, 87024, 87023, 87022, 87021, 87020, 87019, 87018, 87017, 87016};
        turn_penalty = 43.34477103046508972;
        expected = 643.21159029840703170;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {75414, 75415, 75416, 75417, 75418, 75419, 75420, 75421, 75463, 75464, 75465, 75468, 75467, 75579, 153452, 153461, 153457, 153456, 153458, 120656, 120657, 120658, 120659, 120660, 153446, 153447, 153448, 153445, 115090, 115091, 115092, 115093, 115094, 115095, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 104432, 114769, 114770, 114771, 129173, 114767, 114768, 7771, 7772, 129243, 129244, 7773, 7774, 7775, 7776, 7777, 146516, 146518, 95481, 77660, 77654, 77658, 77657, 139072, 77564, 77567, 77555, 77551, 77549};
        turn_penalty = 38.07595966077786898;
        expected = 799.90972562761146492;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {124826, 124825, 124824, 124823, 124822, 124821, 24793, 95027, 95028, 134620, 92228, 92252, 92238, 92226, 92297, 92285, 92243, 92231, 92304, 92291, 92309, 92241, 92283, 92222, 92302, 92301, 92275, 150439, 92281, 92250, 92296, 120128, 120127, 88423, 88422, 88421, 88420, 9556, 19959, 127727, 88402, 88403, 88405, 88406, 127724, 127725, 127726, 19963, 134605, 134606, 134607, 134608, 134609, 134610, 134611, 134612, 134604, 113529, 113530, 126665, 126664, 132689, 132688, 132687, 132686, 132685, 132684, 132683, 42647};
        turn_penalty = 4.11236351442220283;
        expected = 908.55224062143975061;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {39894, 39895, 39889, 39881, 39882, 39883, 39884, 39885, 39886, 39876, 39877, 39878, 143606, 96571, 39916, 88426, 149292, 88425, 88440, 88441, 88442, 88443, 88444, 82275, 82276, 135065, 135066, 135069, 9947, 9948, 41232, 41231, 41230, 41240, 41242, 41241, 34040, 34041, 101352, 101349, 528, 97341, 97342, 97343, 26903, 26904, 28043, 90280, 90277, 28035, 28036, 28037, 28038, 28039, 28040, 28041, 28042, 25753, 133833, 133834, 25755, 25756, 25829, 25830, 25831, 25832, 25833, 25767};
        turn_penalty = 10.72199757501731554;
        expected = 916.73942936518267288;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1486, 1487, 154905, 154906, 154907, 154908, 154909, 154910, 154911, 4361, 151744, 151745, 148848, 148842, 148843, 148844, 148845, 148846, 148847, 32804, 32805, 7796, 32830, 32831, 32832, 32833, 19408, 139891, 139892, 139893, 149286, 149285, 149278, 149279, 149280, 149281, 149282, 149283, 149284, 27995, 27996, 27997, 16048, 16049, 86404, 16050, 16051, 16052, 16053, 16054, 152019, 152018, 152009, 152010, 152011, 152012, 152013, 152014, 152015, 152016, 152017, 133941, 110079, 110078, 133940, 145447, 133928, 133929, 133930, 133931, 133932, 133933, 133934, 133935, 133936, 133937, 133938, 133939, 151364, 151365, 87352, 87353, 143709, 87350, 87351, 87354, 135898, 135899, 39836, 39837, 39834, 113326, 39835, 135900, 98630, 98631, 126625, 112866, 112864, 112865, 152155, 152156, 152157, 152158, 152159, 135938, 135939, 148781, 125625, 125626, 84001, 145222, 145223, 145224, 126768, 126769, 126764, 126765, 126766, 126767, 154923, 154924, 154922, 154925, 154926, 154927, 147782, 84002, 10697, 10698, 86897, 84896, 86898, 84897, 84898, 84899, 84900, 84901, 84902, 112060, 112061, 112062, 45741, 45742, 136584, 70778, 70776, 70777, 99007, 39832, 39831, 3790, 86773, 39830, 113605, 113603, 113608, 112381, 112380, 112379, 125533, 125532, 125531};
        turn_penalty = 31.34028327739956765;
        expected = 1007.31721714986383631;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {30295, 36277, 36276, 102647, 102648, 102649, 126866, 126863, 34745, 34906, 34907, 36264, 36265, 149900, 135908, 20283, 20266, 14525, 14524, 998, 999, 126877, 126878, 113502, 994, 995, 996, 136906, 20788, 20789, 95344, 95388, 95372, 95361, 95320, 95349, 95384, 95356, 24500, 24501, 157266, 36261, 96269, 96270, 96271, 96272, 96273, 147019, 147020, 146966, 146967, 146968, 128629, 36236, 147046, 147048, 125559, 7820, 7814, 36225, 36228, 35408, 35409, 113328, 36216, 36217, 156893, 156892, 156372, 36213, 134274, 141635, 156714, 154083, 154082, 139312, 139313, 139314, 123731, 123732, 123733, 123734, 123735, 123736, 123737};
        turn_penalty = 43.83224127580765384;
        expected = 1041.72984280102059529;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {2610, 2609, 146669, 146670, 88743, 88744, 88733, 88753, 131953, 2615, 2616, 113981, 83712, 83713, 138596, 113980, 126639, 153410, 14296, 14295, 153407, 153408, 139845, 152776, 152777, 104055, 104048, 650, 651, 652, 104024, 104019, 104021, 114264, 113982, 104007, 9499, 9498, 9506, 9507, 104006, 104004, 104015, 104016, 104012, 9380, 9381, 103657, 111630, 103653, 103654, 103655, 103656, 111729, 111617, 622, 111611, 103850, 107329, 95032, 95030, 20202, 107327, 103772, 103773, 103801, 103821, 103805, 103806, 103807, 103808, 103809, 103683, 103679, 103682, 103672, 103673, 103674, 103675, 103676, 103677, 103678, 107271, 107272, 61036, 52347, 51587, 61052, 61026, 49952, 52402, 51920, 51919, 129785};
        turn_penalty = 12.86716044314528418;
        expected = 1171.36697113889499633;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {110921, 74030, 74014, 74025, 74029, 74028, 74027, 74019, 74024, 74012, 74008, 74001, 74009, 136408, 74000, 73999, 73998, 73984, 73990, 73983, 73982, 73980, 73979, 26106, 26105, 73976, 73975, 73970, 73973, 140574, 140573, 140572, 68032, 68031, 68025, 50684, 48624, 68027, 146109, 146108, 146107, 146106, 146105, 146104, 103481, 103484, 147787, 58062, 58061, 58060, 58059, 58058, 58057, 58056, 58055, 58051, 58053, 143273, 143272, 143271, 143268, 143269, 142138, 142137, 35099, 58078, 58079, 58077, 143242, 143243, 58081, 58074, 1057, 1058, 32547, 148990, 148991, 86815, 98311, 86817, 86818, 86819, 98279, 98290, 98293, 98294, 98295, 98296, 98297, 98298, 98299, 98300, 98301, 98302, 98303, 98304, 98305, 98306, 22724, 22725, 22726, 22727, 22728, 102756, 102757, 102760, 102761, 102762, 102764, 102744, 22729, 22730, 22731, 22732, 22733, 22734, 22735, 22736, 113293, 108101, 108095, 108096, 86113, 86114, 86123, 86126, 86127, 86109, 147456, 137307, 103107, 103108, 103109, 103110, 118243, 118244, 118240, 118241, 143942, 118238, 118239, 143938, 123996, 123995, 123994, 118399, 147941, 35171, 118412, 118410, 118398, 155248, 155249, 61879, 61878, 61874, 61877, 61872, 61871, 61863, 61864, 61867, 61870, 61869, 61865, 61868, 61855, 61854, 61853, 61852, 61851, 61850, 61849, 61848, 116172, 116171, 116167, 116166, 116165, 116182, 116181, 116180, 148731, 116198, 116199, 56522, 56521, 56518, 84409, 84408, 84407, 84406, 84405, 84410, 85550, 85551, 85552, 85544, 85545, 85540, 85530, 107367, 97838, 97837, 97836, 97844, 97834, 56343};
        turn_penalty = 31.07746946120639464;
        expected = 1229.86897136406810205;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {82002, 82001, 82000, 41981, 150036, 94228, 94237, 41609, 41608, 41607, 41606, 41605, 41604, 41603, 41602, 41601, 41600, 41599, 41598, 41597, 41596, 41595, 41594, 41593, 41592, 41591, 89755, 96253, 96254, 96255, 96256, 96257, 96258, 96259, 96260, 96261, 13678, 13679, 13680, 13681, 13682, 13683, 13684, 13685, 13686, 13724, 13730, 13731, 13732, 13733, 13708, 13709, 13710, 13711, 13712, 13713, 13714, 154407, 154408, 154409, 154410, 138600, 138601, 138616, 53881, 53882, 53883, 53884, 53885, 53886, 53887, 150885, 150886, 29221, 150877, 150878, 150879, 150799, 150864, 150865, 150866, 29222, 29223, 29224, 29225, 29226, 132717, 132718, 132719, 29228, 132727, 132726, 126053, 126054, 126051, 126052, 28888, 28889, 126058, 114636, 136485, 27073, 27074, 13715, 21205, 125981, 29106, 29105, 29104, 29103, 29102, 114074, 114075, 5658, 5723, 5722, 635, 5740, 5739, 123963, 136753, 136752, 28571, 28572, 28575};
        turn_penalty = 25.16084927376740765;
        expected = 1503.86972425984208712;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {109756, 45780, 45781, 134510, 13225, 13222, 91316, 44161, 13230, 13226, 13227, 13234, 13233, 13231, 151830, 13242, 13241, 13235, 13236, 13237, 13243, 13246, 13247, 13252, 13248, 13249, 13258, 13257, 13253, 13254, 27693, 27692, 3935, 155727, 8081, 8082, 102655, 112763, 112761, 112762, 88453, 88451, 88452, 82851, 82852, 34734, 34735, 34736, 13735, 13734, 34100, 34101, 138597, 138598, 114725, 101348, 34051, 34052, 131563, 131564, 41235, 41236, 41237, 135064, 135067, 135068, 82270, 82271, 82272, 82273, 82274, 88439, 88445, 39920, 88427, 88428, 88429, 96567, 96568, 96563, 96564, 96565, 96572, 96571, 96570, 97924, 97925, 97926, 97927, 97928, 97929, 97930, 97931, 97932, 98027, 97983, 98075, 97902, 98000, 97883, 97963, 97985, 98069, 97860, 97867, 98057, 97888, 98003, 97950, 97915, 97847, 97872, 97873, 97874, 97875, 97876, 97877, 98030, 97937, 97909, 74640, 75023, 75022, 74669, 74668, 74667, 74666, 37373, 37372, 37371, 37378};
        turn_penalty = 13.71927624544100688;
        expected = 1559.02566734360243572;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {74372, 74789, 74790, 74791, 74792, 120797, 120796, 9624, 9623, 9622, 9621, 9620, 9619, 9618, 9617, 9616, 115010, 115011, 115012, 115013, 24628, 24629, 24630, 151946, 115009, 151941, 143607, 143608, 143609, 24159, 97959, 97960, 97961, 97962, 98061, 96570, 96571, 39916, 88426, 149292, 88425, 88440, 88441, 88442, 88443, 88444, 82275, 82276, 135065, 135066, 135069, 135070, 41239, 41238, 82837, 34049, 34050, 82838, 82839, 82840, 82841, 34098, 34099, 82842, 13736, 13737, 82843, 82844, 82845, 82846, 82847, 34733, 82849, 82850, 82848, 82853, 82854, 82856, 82855, 88449, 88450, 82857, 82858, 112759, 3933, 8083, 8084, 109814, 109815, 128676, 27697, 27695, 27696, 27691, 27692, 27693, 13255, 13256, 13257, 13258, 13250, 82266, 82265, 82264, 82263, 64098, 64177, 64398, 82262, 64317, 91315, 146725, 146724, 85958, 64320, 64059, 64245};
        turn_penalty = 27.22910222223687171;
        expected = 1581.93245049405049940;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {20580, 20582, 20583, 130121, 130120, 17156, 17155, 17154, 130119, 130118, 17125, 17124, 155712, 125254, 125253, 125252, 125251, 125250, 128828, 128827, 128826, 128825, 128824, 128823, 128822, 128821, 128820, 128819, 128818, 7842, 5281, 5282, 138948, 138947, 29586, 137290, 137291, 125107, 137289, 5290, 39238, 118053, 39242, 39243, 143259, 39223, 39224, 39225, 140559, 129208, 82202, 82203, 82196, 82195, 82194, 101365, 82180, 140550, 140553, 140555, 140552, 9217, 28831, 111927, 28829, 28830, 111932, 102553, 124060, 127723, 11306, 11307, 111937, 111938, 111940, 23453, 23454, 127735, 127736, 127734, 644, 101355, 23484, 23485, 101358, 101359, 101360, 28468, 28469, 28478, 28472, 111962, 84433, 84424, 111963, 111968, 111969, 12330, 84442, 84443, 111984, 111985, 5737, 13590, 13597, 13600, 13598, 13599, 5735, 5736, 5660, 5725, 5724, 5726, 5727, 5707, 5706, 5699, 123959, 484, 485, 486, 125021, 125022, 10888, 10894, 29650, 29651, 22633, 22629, 8113, 22608, 22609, 22573, 22574, 22584, 22583, 1439, 112795, 28715, 28716, 124999, 28117, 17748, 28144, 28119, 28145, 28146, 28147, 28148, 28149, 28150, 28151, 41807, 41806, 41819, 41820};
        turn_penalty = 3.90960681914189401;
        expected = 1669.78161693926176667;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {97294, 97293, 97292, 97291, 97290, 97289, 97288, 97277, 97276, 116191, 116192, 116193, 56319, 56320, 56327, 56328, 56329, 56330, 56331, 142076, 12669, 111796, 111797, 111785, 111786, 111787, 111788, 103384, 16194, 16193, 8272, 124052, 124053, 124054, 645, 123655, 9538, 9539, 39239, 39240, 39241, 39242, 39243, 143259, 39223, 39224, 39225, 140559, 129208, 82202, 82203, 82196, 82195, 82194, 101365, 82180, 140550, 140553, 140555, 140552, 9217, 28831, 111927, 28829, 28830, 111932, 102553, 124060, 127723, 11306, 11307, 111937, 111938, 111940, 23453, 23454, 127735, 127736, 127734, 644, 101355, 23484, 23485, 1742, 119813, 20391, 20392, 119819, 101378, 119817, 10342, 10341, 120823, 119818, 119814, 101379, 3237, 119826, 119842, 16516, 16517, 16518, 3238, 1004, 124706, 124707, 124708, 656, 157824, 157825, 157828, 19961, 19962, 127727, 88402, 88403, 88405, 88406, 127724, 127725, 127726, 19963, 134605, 134606, 134607, 134608, 133841, 133866, 133865, 92643, 92642, 92641, 92640};
        turn_penalty = 6.71398457277002869;
        expected = 1692.07031468504146687;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {116841, 156676, 72663, 72664, 122749, 122750, 122751, 122752, 155263, 36154, 122860, 122861, 122862, 155204, 155205, 119801, 106119, 106121, 121379, 62347, 121066, 121069, 121068, 113373, 117895, 18873, 18872, 138312, 128464, 140340, 140341, 140342, 88131, 88130, 127268, 127269, 127270, 36218, 36219, 112478, 88321, 139379, 7818, 7819, 150752, 112481, 126875, 85139, 85132, 85133, 85134, 85135, 85136, 85137, 85138, 24531, 24532, 24505, 24506, 129823, 34737, 150753, 150754, 24508, 24507, 117018, 1759, 117023, 117028, 3242, 3241, 3271, 16512, 16515, 91142, 16511, 16521, 16522, 101369, 101370, 10343, 10344, 10345, 136443, 136444, 29671, 20393, 20394, 28438, 28439, 28454, 28451, 97503, 111944, 111943, 111942, 28479, 28480, 86103, 86104, 111951, 29666, 111950, 29668, 10988, 10989, 85185, 85179, 85180, 85181, 85182, 136451, 136453, 136454, 136558, 136559, 136560, 136561, 85176, 85183, 136191, 136190, 85723, 85744, 85743, 85742, 85741, 85740, 85739, 85738, 85737, 85736, 85735, 85734, 16510, 16509, 143032, 143031, 85733, 127074, 127075, 16555};
        turn_penalty = 7.96910429139791976;
        expected = 1698.02587810989939499;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {125909, 125910, 125911, 147057, 147056, 147055, 147061, 74110, 74109, 74105, 74107, 13030, 119034, 118972, 74228, 74229, 74227, 74234, 74235, 74236, 74237, 74220, 74219, 74221, 121933, 121934, 121935, 121936, 149239, 149240, 149241, 149242, 149236, 149237, 149238, 149235, 99309, 99310, 99315, 99311, 99312, 99313, 99314, 98717, 58122, 58125, 58123, 58138, 58140, 58142, 98720, 98714, 98715, 132607, 132608, 132609, 132610, 132611, 132612, 132613, 132614, 139081, 139082, 132570, 132571, 132573, 132572, 132574, 132575, 132576, 132600, 132601, 132577, 132578, 132579, 132580, 132581, 132582, 132583, 132584, 132585, 132586, 132587, 132588, 132589, 132590, 132591, 132592, 132593, 132594, 132595, 132596, 132597, 132598, 132599, 157314, 157310, 157311, 157315, 157309, 14558, 155586, 155587, 155588, 6335, 140559, 129208, 82202, 82203, 82196, 82195, 82194, 101365, 82180, 140550, 140553, 140555, 140552, 9217, 28831, 111927, 28829, 28830, 111932, 102553, 124060, 127723, 11306, 11307, 111937, 111938, 111940, 23453, 23454, 127735, 127736, 127734, 644, 101355, 23484, 23485, 101358, 101359, 101360, 28468, 28469, 28478, 28472, 111962, 84433, 84424, 111963, 111968, 111969, 12330, 84442, 84443, 111984, 111985, 5737, 13590, 13597, 13600, 13598, 13599, 123962, 5738, 636, 637, 123951, 639, 640, 115443, 115440, 86129, 641, 3853, 30047, 30048, 112082, 30049, 3854, 112080, 112081, 55936, 55939, 7203, 24697, 24696, 24672, 24671, 112095, 24204, 23921, 7236, 112093, 112094, 113501, 23265, 87637, 23261, 11389, 53711, 23248, 23247, 87638, 103591};
        turn_penalty = 0.00000000000000000;
        expected = 1723.65158735748218533;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {109322, 109321, 109311, 46322, 46321, 46320, 46319, 45739, 45738, 45737, 45736, 45742, 136584, 70778, 70776, 70777, 99007, 39832, 39831, 3790, 86773, 39830, 113605, 113603, 113608, 112381, 112380, 112379, 112378, 112377, 112376, 112372, 112371, 111639, 86583, 112373, 112361, 112362, 112363, 112364, 112365, 112366, 112367, 112368, 112369, 112370, 135483, 123310, 123311, 136427, 136424, 136423, 86584, 14557, 14556, 14555, 14554, 14553, 14552, 14551, 14550, 14549, 14548, 14547, 6330, 157457, 157459, 143248, 143251, 6331, 156835, 156834, 39225, 140559, 129208, 82202, 82203, 82196, 82195, 82194, 101365, 82180, 140550, 140553, 140555, 140552, 9217, 28831, 111927, 28829, 28830, 111932, 102553, 124060, 127723, 11306, 11307, 111937, 111938, 111940, 23453, 23454, 127735, 127736, 127734, 644, 101355, 23484, 23485, 101358, 101359, 101360, 28468, 28469, 28478, 17925, 111959, 17930, 30240, 30241, 17933, 100983, 21126, 17945, 17944, 67296, 47598, 47597, 47596, 47595, 154582, 154581, 154580, 154584, 154583, 30474, 30473, 30472, 30471, 63987, 63986, 64000, 63993, 63994, 63992, 63996, 63990, 64001, 63980, 63979, 63971, 63969, 63991, 63988, 63989, 63999, 63998, 63207, 157098, 63356, 63373, 63390, 63299, 63300, 63301, 63302, 63303, 63304, 63361, 63228, 63392, 63347, 63320, 63236, 63316, 63413, 63254, 63222, 63387, 63264, 63332, 63372, 63334, 63285, 63368, 63234, 31402, 31403, 27690, 13261, 13262, 82258, 82255, 82256, 128674, 128675, 128676, 27697, 3936, 155727, 8081};
        turn_penalty = 17.26744121680091126;
        expected = 1760.63287051858742416;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {113977, 113978, 62281, 62282, 62283, 62304, 62305, 14220, 14221, 14222, 14223, 14192, 14193, 61811, 61812, 111804, 111803, 111798, 111785, 111786, 111787, 111788, 103384, 16194, 16193, 8272, 124052, 124053, 124054, 645, 123655, 9538, 9539, 39239, 39240, 39241, 39242, 39243, 143259, 39223, 39224, 39225, 140559, 129208, 82202, 82203, 82196, 82195, 82194, 101365, 82180, 140550, 140553, 140555, 140552, 9217, 28831, 111927, 28829, 28830, 111932, 102553, 124060, 127723, 11306, 11307, 111937, 111938, 111940, 23453, 23454, 127735, 127736, 127734, 644, 101355, 23484, 23485, 101358, 101359, 101360, 28468, 28469, 28478, 28472, 111962, 84433, 84424, 111963, 111968, 111969, 12330, 84442, 84443, 111984, 111985, 5737, 13590, 13597, 13600, 13598, 13599, 123962, 5738, 636, 637, 123951, 639, 26049, 112793, 115442, 115441, 86128, 524, 97347, 97348, 30377, 30376, 523, 30033, 113538, 113539, 134082, 116899, 116900, 116901, 129020, 126443, 442, 443, 444, 90685, 90686, 153482, 153483, 26728, 126444, 607, 137005, 137004, 97902, 98000, 97883, 97963, 97985, 98069, 97860, 97867, 98057, 97888, 98003, 97950, 97915, 97988, 75033, 74968, 74967, 117966};
        turn_penalty = 0.00000000000000000;
        expected = 1786.92095877862175257;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {46101, 46100, 46099, 46098, 46097, 46096, 46095, 46094, 46093, 88076, 115224, 131734, 115220, 53557, 53732, 89834, 89835, 84252, 84253, 84254, 84255, 84256, 525, 526, 138634, 138635, 25945, 25946, 25952, 25953, 25954, 25955, 25956, 110383, 110375, 110373, 110371, 110382, 110370, 110369, 110353, 110363, 110367, 110358, 110360, 110350, 110352, 110338, 110341, 110342, 110351, 119938, 119939, 110337, 110343, 110344, 89807, 89808, 89804, 89810, 89813, 89817, 89814, 137218, 137196, 137197, 137198, 137199, 137200, 137216, 137217, 138021, 138022, 138023, 138024, 138025, 137310, 137309, 48336, 14264, 14263, 14260, 82856, 82855, 88449, 88450, 82857, 82858, 112759, 112760, 102656, 82834, 82835, 36332, 36333, 91548, 91549, 12437, 12438, 82859, 82860, 82861, 82862, 82863, 82864, 101373, 3260, 3259, 102662, 128461, 128462, 126082, 126079, 126080, 126081, 126873, 126874, 24503, 24504, 24523, 24524, 24525, 24526, 24527, 24528, 24529, 24530, 85140, 85141, 112480, 7816, 7817, 139378, 129063, 112479, 129064, 88319, 88320, 36220, 36221, 36222, 36223, 88136, 88127, 88128, 88129, 139483, 18871, 18874, 121063, 113372, 121770, 121071, 121070, 121067, 62349, 62350, 19323, 59881, 59882, 59876, 59879, 36152, 146040, 36146, 129076, 59884, 70151, 70153, 70155, 70073, 70072, 70071, 70026, 70027};
        turn_penalty = 0.00000000000000000;
        expected = 1811.76029672278036742;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {61637, 61646, 61645, 61642, 84129, 84128, 61806, 61805, 61798, 61792, 61794, 61795, 142075, 142074, 142073, 142072, 142071, 111229, 111228, 138296, 138297, 2629, 14223, 14192, 14193, 61811, 61812, 111804, 111803, 111798, 111785, 111786, 111787, 111788, 103384, 16194, 16193, 8272, 124052, 124053, 124054, 645, 123655, 9538, 9539, 39239, 39240, 39241, 39242, 39243, 143259, 39223, 39224, 39225, 140559, 129208, 82202, 82203, 82196, 82195, 82194, 101365, 82180, 140550, 140553, 140555, 140552, 9217, 28831, 111927, 28829, 28830, 111932, 102553, 124060, 127723, 11306, 11307, 111937, 111938, 111940, 23453, 23454, 127735, 127736, 127734, 644, 101355, 23484, 23485, 101358, 101359, 101360, 28468, 28469, 28478, 28472, 111962, 84433, 84424, 111963, 111968, 111969, 12330, 84442, 84443, 111984, 111985, 5737, 13590, 13597, 13600, 13598, 13599, 123962, 5738, 636, 637, 123951, 639, 640, 115443, 115440, 86129, 641, 123984, 30386, 30385, 30034, 30035, 30036, 126443, 442, 443, 444, 90685, 90686, 153482, 153483, 26728, 126444, 607, 137005, 137004, 97902, 98000, 97883, 97963, 98077, 97857, 98092, 38830, 38833, 38834, 38835, 38836, 38837, 38841, 38842, 38843, 38844, 38846, 37339, 37340, 37341, 38875, 38876};
        turn_penalty = 0.90258765451972178;
        expected = 1815.58589670041078534;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {100636, 100637, 86218, 32361, 32360, 32359, 32358, 32357, 32356, 32355, 32354, 32353, 32352, 32351, 118321, 118320, 118316, 118313, 118318, 118314, 118319, 118317, 32318, 32319, 32320, 32321, 32322, 32323, 32324, 32325, 32143, 32144, 32145, 32146, 32147, 32148, 32149, 32150, 32151, 32152, 32153, 32154, 67479, 153073, 153075, 32873, 153123, 153124, 151526, 86271, 86272, 86273, 86274, 86275, 86276, 86277, 86278, 86279, 55920, 55919, 55838, 55836, 55837, 36644, 36643, 36642, 36641, 36640, 36639, 36638, 67778, 67777, 67775, 67773, 30823, 30822, 30821, 30820, 16454, 153145, 153146, 153142, 67418, 67419, 67420, 67421, 66300, 66299, 66298, 66297, 66296, 66295, 66282, 66288, 66292, 66293, 66294, 130575, 130576, 130577, 130578, 130579, 67786, 67820, 67821, 85187, 85188, 67783, 150858, 150859, 67787, 67788, 67789, 150861, 67792, 67793, 67794, 67795, 67796, 67797, 67798, 67799, 67800, 67801, 67802, 67803, 67804, 67805, 67806, 67807, 67808, 67809, 67810, 67811, 67812, 67813, 66023, 150847, 150848, 66031, 66032, 66021, 66020, 66025, 66043, 16480, 16479, 16478, 16477, 16476, 16475, 16481, 16482, 127740, 16491, 111955, 23459, 23460, 111939, 101357, 114902, 9263, 111924, 111923, 111925, 101376, 111926, 28823, 28824, 28836, 28837, 6339, 6340, 140551, 140556, 140554, 82181, 140549, 82185, 82186, 82187, 82208, 82209, 113975, 113976, 39231, 39232, 39233, 39234, 39235, 153429, 153430, 39246, 16184, 9544, 9545, 9546, 123654, 0, 1, 16196, 8273, 103386, 111779, 111780, 646, 111789, 111790, 111791, 61817, 61818, 14185, 14186, 14187, 14216, 14214, 14215, 62310, 62311, 62312, 62288, 62289, 113997, 113998, 647, 648, 83714, 83715, 138596, 113980, 126639, 153410, 14296, 14295, 153407, 153408, 139845, 152776, 152777, 104055, 104048, 650, 651, 652, 104024, 104019, 104021, 114264, 113982, 104007, 9499, 9498, 9506, 9507, 104006, 104004, 104015, 104016, 104012, 9380, 9381, 103657, 111634, 143266, 143267, 143264, 143265, 18408, 35234, 35235, 111738, 111737, 111736, 111735, 111740, 111741, 100784, 100781, 100785, 157523, 157524, 103931, 103933, 103934, 103935, 103929, 35280, 35281, 35282, 108764, 98531, 98529, 52620, 49096};
        turn_penalty = 7.92470683533765108;
        expected = 2243.57096548856952722;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {39514, 39533, 39524, 39518, 39474, 75645, 75646, 75647, 75648, 1411, 659, 149294, 126335, 26720, 26723, 26724, 26725, 126441, 126442, 26726, 26727, 90680, 90681, 90682, 90683, 90684, 445, 129027, 129028, 129029, 129030, 129031, 129021, 30020, 30021, 30039, 30040, 480, 30380, 30381, 30382, 123982, 123983, 115439, 115438, 26046, 482, 115286, 115326, 114805, 123950, 483, 123947, 5709, 5708, 5699, 123959, 484, 485, 486, 125021, 125022, 10888, 10894, 29650, 29651, 22633, 22629, 8112, 22611, 22610, 22575, 22578, 119622, 119623, 97350, 97344, 5096, 94624, 135849, 5119, 152104, 151927, 68493, 68494, 768, 19267, 135941, 136527, 14029, 14028, 19253, 19254, 19261, 19262, 111835, 19248, 19247, 12234, 12239, 111834, 68485, 68486, 9531, 767, 40145, 40146, 40147, 40148, 40149, 11838, 156209, 151925, 156210, 151961, 32312, 107223, 107224, 112734, 107225, 123653, 107222, 27351, 373, 12208, 146716, 136981, 146715, 146707, 146708, 146712, 146713, 389, 146080, 146081, 25728, 25731, 146720, 25737, 25738, 25739, 11172, 11171, 11170, 11169, 11168, 11167, 11166, 11165, 11164, 11163, 18442, 18441, 18440, 110131, 110122, 110121, 110120};
        turn_penalty = 7.66876581015625014;
        expected = 2261.36836639455850673;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {41286, 41285, 41284, 41283, 41282, 41278, 28047, 28048, 28049, 28050, 28051, 110303, 110302, 110301, 146622, 146623, 146624, 146620, 146621, 146615, 146616, 146617, 146618, 146619, 150826, 150828, 150829, 150830, 146397, 146398, 146399, 146400, 146401, 146402, 146403, 146404, 146405, 114715, 114716, 114717, 114718, 114719, 114720, 114713, 114714, 26956, 26952, 26953, 26954, 26955, 136954, 136956, 136957, 136958, 136959, 136960, 129365, 129366, 129367, 129368, 129369, 129370, 129371, 129372, 129373, 129374, 26942, 26943, 26944, 46987, 87493, 87492, 7226, 123983, 115439, 115438, 26046, 482, 115287, 123973, 29232, 29233, 114664, 114665, 29096, 29097, 133879, 133884, 114790, 114791, 114792, 114793, 5665, 123964, 156363, 65342, 65341, 65332, 65331, 65334, 65357, 65356, 65355, 65344, 65353, 65349, 30273, 30272, 127910, 139153, 127909, 139154, 108203, 108202, 108200, 5651, 12286, 30274, 67779, 67776, 136458, 67766, 67772, 16470, 16469, 16468, 16467, 16466, 16465, 16458, 136455, 136456, 132503, 132504, 132505, 132502, 36645, 36646, 128529, 128532, 16463, 16462, 16461, 16459, 136466, 86975, 86974, 136468, 16785, 16784, 16783, 16782, 16778, 16779, 16780, 16781, 136469, 35085, 35084, 86094, 86093, 86092, 86091, 86090, 86089, 86088, 86087, 86086, 86085, 86084, 86083, 86082, 86081, 86080, 86079, 86078, 86077, 86076, 86075, 86074, 137468, 116963, 116962, 116961, 116960, 116959, 116958, 84098, 84097, 84096, 84095, 84094, 84093, 84092, 8560, 8561, 8562, 8563, 8564, 8565, 8566, 8567, 149356, 149357, 149358, 149359, 149360, 4281, 4282};
        turn_penalty = 44.11521863240028551;
        expected = 2368.85484803638883022;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {30983, 30982, 30981, 30980, 30979, 30978, 12497, 12496, 24622, 24623, 75622, 75623, 75624, 75625, 120794, 120795, 115010, 115011, 115012, 115013, 24628, 24629, 24630, 151946, 115009, 151941, 143607, 143608, 143609, 24159, 97959, 97960, 97961, 97962, 98061, 96570, 96571, 39916, 88426, 149292, 88425, 88440, 88441, 88442, 88443, 88444, 82275, 82276, 135065, 135066, 135069, 135070, 41239, 41238, 82837, 34049, 34050, 82838, 82839, 82840, 82841, 34098, 34099, 82842, 13736, 13737, 82843, 82844, 82845, 82846, 82847, 34733, 82849, 82850, 82848, 82853, 82854, 82856, 82855, 88449, 88450, 82857, 82858, 112759, 112760, 102656, 82834, 82835, 36332, 36333, 91548, 91549, 12437, 12438, 82859, 82860, 82861, 82862, 82863, 82864, 101373, 3260, 3259, 102662, 128461, 128462, 126082, 126079, 126080, 126081, 126873, 126874, 24503, 24504, 24523, 24524, 24525, 24526, 24527, 24528, 24529, 24530, 85140, 85141, 112480, 7816, 7817, 139378, 129063, 112479, 129064, 88319, 88320, 36220, 36221, 36222, 36223, 88136, 88127, 88128, 88129, 139483, 18871, 18874, 1779, 18889, 18888, 117899, 117900, 122443, 122445, 122451, 122449, 97804, 97803, 97802, 97792, 97818, 97805, 122599, 122598, 122600, 122601, 145409, 122596, 122686, 122685, 122684, 122683, 143352, 143353, 156681, 156682, 156925, 156924, 156923, 156922, 156921, 156920, 156919, 110951, 110950, 110949, 110953, 110954, 150595, 122695, 122694, 122693, 156770, 156771, 104288, 104289, 104282, 104298, 123266, 123267, 123718, 105698, 105702, 105703, 105704, 105705, 105706, 105707, 105708, 105709, 105710, 130158, 130159, 105287, 105288, 105289, 105323};
        turn_penalty = 5.46601715552688994;
        expected = 2436.40233368602821429;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {81208, 81209, 81210, 76993, 76976, 103960, 103961, 103962, 103963, 103964, 103965, 102947, 102948, 102949, 104436, 104468, 104469, 104470, 104471, 102957, 23655, 112124, 112123, 102942, 112120, 112118, 112122, 81050, 81051, 112116, 102951, 112108, 112109, 115623, 112103, 23260, 23258, 23259, 112097, 23920, 23919, 112098, 24670, 24694, 24698, 24695, 24692, 7211, 55940, 55935, 3858, 30050, 30043, 30044, 30032, 135915, 638, 115437, 115435, 115436, 115605, 633, 634, 635, 5740, 5739, 123963, 136753, 136752, 28571, 28572, 28575, 28576, 135041, 629, 630, 643, 111979, 84448, 84436, 111982, 111978, 111964, 111967, 84430, 84426, 111965, 111966, 28470, 28471, 111961, 28460, 28461, 28455, 28456, 146249, 146250, 101356, 111945, 23478, 23479, 111947, 111946, 6323, 127732, 127733, 111954, 111955, 23459, 23460, 111939, 101357, 114902, 9263, 111924, 111923, 111925, 101376, 111926, 28823, 28824, 28836, 28837, 6339, 6340, 140551, 140556, 140554, 82181, 140549, 82185, 82186, 82187, 82208, 82209, 113975, 113976, 39231, 39232, 39233, 39234, 39235, 153429, 153430, 39246, 16184, 9544, 9545, 9546, 123654, 0, 1, 16196, 8273, 103386, 111779, 111780, 646, 111789, 111790, 111791, 61817, 61818, 14185, 14186, 2630, 111805, 138419, 14210, 14211, 14212, 2625, 155825, 124123, 124124, 124125, 111229, 142071, 142072, 142073, 142074, 142075, 61796, 61802, 61797, 61807, 61808, 61809, 155485, 61732, 61744, 61743, 148327, 148411, 148410};
        turn_penalty = 29.50603330874932340;
        expected = 2457.06104114014897277;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {136937, 136936, 136948, 136931, 19104, 124898, 124895, 132920, 132938, 132939, 136926, 132945, 132944, 124892, 124914, 124908, 124909, 132858, 132859, 132861, 124920, 124919, 124929, 124931, 124924, 23663, 23662, 124927, 124930, 124925, 1442, 8109, 124928, 47197, 33820, 27928, 27929, 30186, 30187, 136528, 47198, 102594, 102592, 125001, 125005, 22785, 22784, 125000, 125004, 47193, 47194, 114607, 124959, 124960, 28713, 28714, 8107, 22582, 22581, 22577, 22576, 22612, 22614, 511, 22632, 29637, 29652, 29653, 29654, 10895, 512, 134072, 8115, 114700, 124056, 5733, 114799, 5747, 5746, 5734, 5666, 5667, 53880, 13285, 13286, 13287, 106968, 106969, 13607, 13608, 13609, 130543, 155729, 135544, 13288, 13284, 126142, 126143, 126144, 126145, 13281, 130201, 130202, 130203, 130204, 27465, 27466, 27467, 114691, 114692, 114693, 114694, 114695, 114696, 13280, 29850, 29851, 13270, 131731, 48355, 48356, 131732, 131733, 31399, 31400, 31401, 31402, 31403, 27690, 13261, 13262, 82258, 82255, 82256, 128674, 13264, 82835, 36332, 36333, 91548, 91549, 12437, 12438, 82859, 82860, 82861, 82862, 82863, 82864, 101373, 3260, 3259, 102662, 128461, 128462, 126082, 126079, 126080, 126081, 126873, 126874, 24503, 24504, 24523, 24524, 24525, 24526, 24527, 24528, 24529, 24530, 85140, 85141, 7802, 110919, 147891, 126879, 126880, 150755, 147756, 125922, 125923, 35100, 147755, 97033, 97034, 101000, 97029, 97030, 126695, 126696, 126686, 126687, 126688, 126689, 126690, 126691, 126692, 126705, 152415, 126697, 126698, 126699, 126700, 126701, 126702, 126703, 126704, 97162, 97122, 97123, 97124, 97125, 97126};
        turn_penalty = 14.24546986562031847;
        expected = 2611.92376529218699943;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
    } //compute_path_travel_time

} //path_cost_public

