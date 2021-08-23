#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_path_perf_very_hard_public) {
struct MapFixture {
    MapFixture() {
        rng = std::minstd_rand(4);
        rand_intersection = std::uniform_int_distribution<unsigned>(0, getNumberOfIntersections()-1);
        rand_street = std::uniform_int_distribution<unsigned>(1, getNumberOfStreets()-1);
        rand_segment = std::uniform_int_distribution<unsigned>(0, getNumberOfStreetSegments()-1);
        rand_poi = std::uniform_int_distribution<unsigned>(0, getNumberOfPointsOfInterest()-1);
        rand_lat = std::uniform_real_distribution<double>(50.941036224, 51.983997345);
        rand_lon = std::uniform_real_distribution<double>(-1.114988804, 0.894998193);
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
    TEST_FIXTURE(MapFixture, find_path_to_point_of_interest_perf_very_hard) {
        //Verify Functionality
        std::vector<unsigned> path;
        std::vector<unsigned> valid_end_intersections;
        double path_cost;
        
        valid_end_intersections = {33210, 34022, 128141, 272809, 34081, 395601, 337061, 425721, 92412, 35274, 18269, 407650, 49551, 1301, 33536, 153427, 435814, 125493, 211453, 418119, 1311};
        path = find_path_to_point_of_interest(28985, "EAT", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(28985, valid_end_intersections, path));
        CHECK(path_cost <= 2525.06683850779518252);
        
        valid_end_intersections = {125493, 291134, 264497, 33750, 33271, 3572, 290037, 366891, 33086, 370889, 278722, 45725, 33793, 10161, 34240, 227719, 384187, 109357, 158621, 25714, 33959, 34940, 33671, 60746, 316361, 340078, 123009, 34318, 2738, 309102, 83601, 30829, 257162, 125491, 285916, 381327, 381331, 20247, 198323, 95363, 20244, 290193, 383640, 381326, 381315, 310804, 383627, 383634, 383641, 383680, 383630, 322836, 173418, 196656, 69391, 69422, 191806, 69396, 69436, 192697, 191793, 154921, 121623, 121622, 121621, 272048, 122952, 88732, 119791, 88732, 79002, 272053, 154912, 79000, 371119, 79004, 78985, 78984, 196658, 88729, 300634, 338173, 154894, 154894, 36535, 372288, 378783, 383662, 383646, 383646, 372287, 317146, 383658, 120735, 36526, 299943, 36523, 264009, 264007, 383347, 23796, 383349, 20260, 53457, 309173, 270279, 104713, 241484, 300497, 106837, 6206, 107146, 125760, 293349, 31371, 325544, 67225, 385235, 36317, 38495, 106864, 125523, 122183, 122181, 309084, 309084, 281386, 335505, 76506, 76458, 60761, 72375, 254089, 120727, 280410, 72374, 192702, 72370, 72287, 274771, 279892, 72274, 184232, 227177, 231630, 184228, 192601, 10393, 352664, 280285, 231621, 279898, 76590, 291368, 76585, 192832, 62895, 120207, 62895, 289755, 52781, 120314, 52784, 62870, 231635, 192635, 88686, 88698, 88696, 88696, 259698, 69388, 69389, 405911, 152345, 152345, 69412, 69400, 152343, 69416, 69438, 191786, 121629, 191789, 69432, 313540, 88675, 88674, 37366, 124268, 124268, 311199, 37367, 323212, 88673, 401533, 88679, 137510, 123602, 121205, 119599, 123598, 124244, 152329, 150496, 191714, 191717, 191715, 90163, 122921, 309847, 123588, 122606, 122603, 19918, 123584, 33952, 33951, 119956, 110139, 125515, 98338, 104797, 104659, 104668, 347058, 105207, 106877, 105429, 24862, 141956, 286218, 34274, 33082, 106713, 64449, 64445, 35231, 35216, 18266, 18268, 35226, 33582, 33759, 364527, 364543, 33869, 17574, 64228, 35273, 33902, 33882, 33881, 33882, 314538, 264765, 109354, 109354, 278721, 36307, 33521, 33901, 33901, 33902, 33901, 32997, 32993, 33336, 33511, 158680, 382880, 16327, 20349, 16329, 16332, 123747, 123746, 327762, 92119, 30659, 30648, 18290, 34548, 293539, 290188, 290189, 5232, 296986, 140608, 296980, 218724, 6176, 121756, 163107, 320385, 3458, 111578, 226976, 148795, 247124, 247256, 273395, 163961, 415115, 124211, 183513, 44866, 39961, 34037, 252004, 34083, 368294, 370318, 370312, 25656, 370312, 274678, 314313, 34509, 321224, 33857, 2727, 40293, 383093, 38195, 260700, 274334, 34773, 34780, 34897, 34894, 34898, 34892, 34612, 19819, 34771, 3747, 34759, 34757, 34753, 34754, 33974, 33983, 397131, 33980, 353075, 34029, 34039, 34028, 34039, 48436, 25699, 246982, 264563, 25647, 34596, 239271, 296428, 34594, 33482, 33482, 214575, 296426, 294480, 214572, 335283, 34522, 34522, 34502, 294480, 34526, 34530, 34529, 45712, 16618, 33516, 16606, 33530, 33948, 12167, 52614, 52614, 16729, 16723, 381993, 272946, 43829, 382802, 348514, 5841, 4454, 4670, 5841, 348518, 123051, 110808, 67139, 121139, 153670, 9621, 5928, 120976, 9540, 9618, 9606, 296422, 5913, 9624, 10194, 10163, 296435, 10195, 33799, 34316, 34315, 34311, 33798, 33792, 34346, 200788, 12180, 12179, 34347, 331341, 109332, 5356, 4673, 4673, 185161, 9608, 9607, 33640, 33599, 33598, 34940, 5989, 4676, 224585, 120496, 53462, 53455, 124761, 127778, 35277, 247987, 247984, 124768, 410927, 226759, 374926, 82460, 125886, 52682, 55223, 124842, 52692, 55221, 55224, 55219, 34103, 33708, 226496, 75443, 33701, 226493, 33705, 272102, 281920, 226515, 427233, 33668, 366916, 33711, 33712, 427227, 33670, 283582, 225309, 369580, 283582, 159826, 370884, 370888, 318604, 370889, 370890, 250920, 369634, 324726, 250917, 369738, 159843, 159845, 369608, 369608, 3300, 2730, 273212, 158409, 370652, 370653, 415942, 34152, 245234, 34155, 369600, 369600, 34381, 318607, 370664, 360685, 360685, 2739, 360684, 2740, 382779, 382788, 382779, 161109, 158407, 312490, 60762, 120999, 124262, 124262, 121008, 34396, 33799};
        path = find_path_to_point_of_interest(38006, "Motorcycle parking", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(38006, valid_end_intersections, path));
        CHECK(path_cost <= 1033.25891676656624441);
        
        valid_end_intersections = {86927};
        path = find_path_to_point_of_interest(59903, "Nam An", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(59903, valid_end_intersections, path));
        CHECK(path_cost <= 3202.74664160226529930);
        
        valid_end_intersections = {264169};
        path = find_path_to_point_of_interest(61161, "Jenn Che", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(61161, valid_end_intersections, path));
        CHECK(path_cost <= 3976.34517252784235097);
        
        valid_end_intersections = {89210, 34806, 20656, 26805, 291139, 201749, 141729, 31428, 99347, 272704, 243720, 145493, 380034, 307210, 120562, 80655, 110306, 22445, 72019, 63027, 171567, 203462};
        path = find_path_to_point_of_interest(72464, "Prince of Wales", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(72464, valid_end_intersections, path));
        CHECK(path_cost <= 1336.45471962820442968);
        
        valid_end_intersections = {75482};
        path = find_path_to_point_of_interest(113746, "Windham Nursery School", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(113746, valid_end_intersections, path));
        CHECK(path_cost <= 4530.05551742031002505);
        
        valid_end_intersections = {427505};
        path = find_path_to_point_of_interest(39445, "The Buddha Bar", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(39445, valid_end_intersections, path));
        CHECK(path_cost <= 2770.21539113139715482);
        
        valid_end_intersections = {153735, 80527, 194014, 85409, 135500, 423168, 69766};
        path = find_path_to_point_of_interest(140335, "The Five Bells", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(140335, valid_end_intersections, path));
        CHECK(path_cost <= 1814.80477493905732445);
        
        valid_end_intersections = {33523, 18271, 34775, 214574, 364529, 369624, 409926};
        path = find_path_to_point_of_interest(147984, "Abokado", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(147984, valid_end_intersections, path));
        CHECK(path_cost <= 1495.19546960064462837);
        
        valid_end_intersections = {25013, 56640, 356477, 191084};
        path = find_path_to_point_of_interest(156368, "Wahaca", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(156368, valid_end_intersections, path));
        CHECK(path_cost <= 1155.55943023577901840);
        
        valid_end_intersections = {285957};
        path = find_path_to_point_of_interest(159183, "Paster Pharmacy", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(159183, valid_end_intersections, path));
        CHECK(path_cost <= 3163.53217266743877190);
        
        valid_end_intersections = {357452};
        path = find_path_to_point_of_interest(199055, "Shell Burgh heath", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(199055, valid_end_intersections, path));
        CHECK(path_cost <= 2139.85920182617883256);
        
        valid_end_intersections = {397469, 296278};
        path = find_path_to_point_of_interest(32740, "Sagar", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(32740, valid_end_intersections, path));
        CHECK(path_cost <= 2069.50530113627701212);
        
        valid_end_intersections = {7522};
        path = find_path_to_point_of_interest(204045, "Sally's Cafe", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(204045, valid_end_intersections, path));
        CHECK(path_cost <= 2283.34843635149263719);
        
        valid_end_intersections = {19801, 45802, 35244, 424127};
        path = find_path_to_point_of_interest(205741, "The Forge", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(205741, valid_end_intersections, path));
        CHECK(path_cost <= 2914.67846408886089193);
        
        valid_end_intersections = {420479};
        path = find_path_to_point_of_interest(221087, "Mark Hall Specialist Sports College", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(221087, valid_end_intersections, path));
        CHECK(path_cost <= 4981.25067203658818471);
        
        valid_end_intersections = {32645};
        path = find_path_to_point_of_interest(214008, "Curry Leaf East", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(214008, valid_end_intersections, path));
        CHECK(path_cost <= 3119.68027710436535926);
        
        valid_end_intersections = {8129};
        path = find_path_to_point_of_interest(236966, "Blagrave Street", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(236966, valid_end_intersections, path));
        CHECK(path_cost <= 3192.68845615206782895);
        
        valid_end_intersections = {26708, 337536, 78371, 122944, 424647, 343115, 208748, 47494, 324343};
        path = find_path_to_point_of_interest(284149, "Vue", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(284149, valid_end_intersections, path));
        CHECK(path_cost <= 2295.85681138917516364);
        
        valid_end_intersections = {1310};
        path = find_path_to_point_of_interest(292071, "Barcelona", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(292071, valid_end_intersections, path));
        CHECK(path_cost <= 3159.69058309982483479);
        
        valid_end_intersections = {100995};
        path = find_path_to_point_of_interest(154423, "Shenstone School", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(154423, valid_end_intersections, path));
        CHECK(path_cost <= 1488.23217166048016225);
        
        valid_end_intersections = {145613, 342398, 11812};
        path = find_path_to_point_of_interest(305792, "The Surgery", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(305792, valid_end_intersections, path));
        CHECK(path_cost <= 3850.72849911344246721);
        
        valid_end_intersections = {3742, 32277, 291515, 164, 209539, 18921, 46809, 31073, 110123};
        path = find_path_to_point_of_interest(319327, "Dental Surgery", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(319327, valid_end_intersections, path));
        CHECK(path_cost <= 1313.13944522096767287);
        
        valid_end_intersections = {76765, 55257, 351409, 150328, 286355, 121389, 262503, 233810, 125431, 231762};
        path = find_path_to_point_of_interest(373544, "The New Inn", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(373544, valid_end_intersections, path));
        CHECK(path_cost <= 944.22534823554747163);
        
        valid_end_intersections = {40188, 206829, 191051, 160824, 308945, 4693, 89981, 57506, 193422, 159933, 327334, 253551, 71711, 34485, 268437, 148584, 302810, 11672, 367676, 358770, 383098, 125746};
        path = find_path_to_point_of_interest(386481, "The Rising Sun", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(386481, valid_end_intersections, path));
        CHECK(path_cost <= 546.70419967305554110);
        
        valid_end_intersections = {26604};
        path = find_path_to_point_of_interest(389719, "A Baía", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(389719, valid_end_intersections, path));
        CHECK(path_cost <= 2214.57142272726150622);
        
        valid_end_intersections = {51424, 245556, 105579};
        path = find_path_to_point_of_interest(405145, "The British Queen", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(405145, valid_end_intersections, path));
        CHECK(path_cost <= 2274.26503283315651061);
        
        valid_end_intersections = {350553};
        path = find_path_to_point_of_interest(231528, "Lodge Farm Park", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(231528, valid_end_intersections, path));
        CHECK(path_cost <= 1088.72959843963258209);
        
        valid_end_intersections = {396508, 20401, 315473, 37801, 202066};
        path = find_path_to_point_of_interest(190666, "Royal British Legion", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(190666, valid_end_intersections, path));
        CHECK(path_cost <= 2122.92777390124228987);
        
        valid_end_intersections = {79970, 26708, 412356};
        path = find_path_to_point_of_interest(423756, "Imperial China", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(423756, valid_end_intersections, path));
        CHECK(path_cost <= 2878.89722502698487006);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids;
        std::vector<std::string> poi_names;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 100; i++) {
            intersection_ids.push_back(rand_intersection(rng));
            poi_names.push_back(getPointOfInterestName(rand_poi(rng)));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(22385);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 100; i++) {
                result = find_path_to_point_of_interest(intersection_ids[i], poi_names[i], turn_penalties[i]);
            }
        }
    } //find_path_to_point_of_interest_perf_very_hard

} //inter_inter_path_perf_very_hard_public

