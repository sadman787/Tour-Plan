#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_path_perf_basic_public) {
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
    TEST_FIXTURE(MapFixture, find_path_to_point_of_interest_perf_basic) {
        //Verify Functionality
        std::vector<unsigned> path;
        std::vector<unsigned> valid_end_intersections;
        double path_cost;
        
        valid_end_intersections = {88977};
        path = find_path_to_point_of_interest(40537, "The White Rabbit", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(40537, valid_end_intersections, path));
        CHECK(path_cost <= 3406.79685361415795342);
        
        valid_end_intersections = {343050, 406991, 36679};
        path = find_path_to_point_of_interest(67337, "Co-operative", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(67337, valid_end_intersections, path));
        CHECK(path_cost <= 1319.40222806310862325);
        
        valid_end_intersections = {363905, 106690, 158873};
        path = find_path_to_point_of_interest(85911, "Church Street", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(85911, valid_end_intersections, path));
        CHECK(path_cost <= 2331.43995060633824323);
        
        valid_end_intersections = {109823};
        path = find_path_to_point_of_interest(87776, "Tapping the Admiral", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(87776, valid_end_intersections, path));
        CHECK(path_cost <= 3158.13689639396761777);
        
        valid_end_intersections = {92411, 182830, 321240, 44005, 302938, 301694, 56039, 217336, 300680, 1141, 254958, 242903, 157376, 11730, 157382, 178161, 407942, 296275, 273389, 129514, 223422, 22581, 22167, 415744, 386447, 23448, 279886, 154684, 357446, 11257, 89975, 296137, 279361, 26928, 120314, 76471, 33605, 34729, 274771, 235299, 202486, 425721, 293536, 340258, 393320, 3474, 265387, 188664, 409341, 298781, 419062, 431031, 305770, 124320, 29951, 239270, 313491, 356154, 314527, 35367, 158026, 35233, 301809, 8132, 30747, 102687, 146820, 381757, 89405, 230677, 329944, 60445, 91165, 33486, 22473, 117546, 358470, 120999, 350523, 35375, 340865, 39449, 395044, 314343, 34024, 393794, 393321, 418122, 354373, 328598, 41143, 84676, 34977, 48324, 386926, 126242, 117079, 430236, 24571, 412917, 18270, 347780, 417460, 61965, 23072, 411462, 404814, 35274, 29184, 158455, 296432, 78371, 198769, 183309, 394468, 20027, 195484, 142896, 9855, 224517, 9857, 139583, 8134, 435232, 291155, 412064, 214566, 82969, 292373, 146425, 95101, 33228, 33430, 34827, 357936, 201410, 20350, 31080, 349602, 55955, 327823, 89466, 278803};
        path = find_path_to_point_of_interest(120844, "Starbucks", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(120844, valid_end_intersections, path));
        CHECK(path_cost <= 301.42809801411596027);
        
        valid_end_intersections = {125493, 291134, 264497, 33750, 33271, 3572, 290037, 366891, 33086, 370889, 278722, 45725, 33793, 10161, 34240, 227719, 384187, 109357, 158621, 25714, 33959, 34940, 33671, 60746, 316361, 340078, 123009, 34318, 2738, 309102, 83601, 30829, 257162, 125491, 285916, 381327, 381331, 20247, 198323, 95363, 20244, 290193, 383640, 381326, 381315, 310804, 383627, 383634, 383641, 383680, 383630, 322836, 173418, 196656, 69391, 69422, 191806, 69396, 69436, 192697, 191793, 154921, 121623, 121622, 121621, 272048, 122952, 88732, 119791, 88732, 79002, 272053, 154912, 79000, 371119, 79004, 78985, 78984, 196658, 88729, 300634, 338173, 154894, 154894, 36535, 372288, 378783, 383662, 383646, 383646, 372287, 317146, 383658, 120735, 36526, 299943, 36523, 264009, 264007, 383347, 23796, 383349, 20260, 53457, 309173, 270279, 104713, 241484, 300497, 106837, 6206, 107146, 125760, 293349, 31371, 325544, 67225, 385235, 36317, 38495, 106864, 125523, 122183, 122181, 309084, 309084, 281386, 335505, 76506, 76458, 60761, 72375, 254089, 120727, 280410, 72374, 192702, 72370, 72287, 274771, 279892, 72274, 184232, 227177, 231630, 184228, 192601, 10393, 352664, 280285, 231621, 279898, 76590, 291368, 76585, 192832, 62895, 120207, 62895, 289755, 52781, 120314, 52784, 62870, 231635, 192635, 88686, 88698, 88696, 88696, 259698, 69388, 69389, 405911, 152345, 152345, 69412, 69400, 152343, 69416, 69438, 191786, 121629, 191789, 69432, 313540, 88675, 88674, 37366, 124268, 124268, 311199, 37367, 323212, 88673, 401533, 88679, 137510, 123602, 121205, 119599, 123598, 124244, 152329, 150496, 191714, 191717, 191715, 90163, 122921, 309847, 123588, 122606, 122603, 19918, 123584, 33952, 33951, 119956, 110139, 125515, 98338, 104797, 104659, 104668, 347058, 105207, 106877, 105429, 24862, 141956, 286218, 34274, 33082, 106713, 64449, 64445, 35231, 35216, 18266, 18268, 35226, 33582, 33759, 364527, 364543, 33869, 17574, 64228, 35273, 33902, 33882, 33881, 33882, 314538, 264765, 109354, 109354, 278721, 36307, 33521, 33901, 33901, 33902, 33901, 32997, 32993, 33336, 33511, 158680, 382880, 16327, 20349, 16329, 16332, 123747, 123746, 327762, 92119, 30659, 30648, 18290, 34548, 293539, 290188, 290189, 5232, 296986, 140608, 296980, 218724, 6176, 121756, 163107, 320385, 3458, 111578, 226976, 148795, 247124, 247256, 273395, 163961, 415115, 124211, 183513, 44866, 39961, 34037, 252004, 34083, 368294, 370318, 370312, 25656, 370312, 274678, 314313, 34509, 321224, 33857, 2727, 40293, 383093, 38195, 260700, 274334, 34773, 34780, 34897, 34894, 34898, 34892, 34612, 19819, 34771, 3747, 34759, 34757, 34753, 34754, 33974, 33983, 397131, 33980, 353075, 34029, 34039, 34028, 34039, 48436, 25699, 246982, 264563, 25647, 34596, 239271, 296428, 34594, 33482, 33482, 214575, 296426, 294480, 214572, 335283, 34522, 34522, 34502, 294480, 34526, 34530, 34529, 45712, 16618, 33516, 16606, 33530, 33948, 12167, 52614, 52614, 16729, 16723, 381993, 272946, 43829, 382802, 348514, 5841, 4454, 4670, 5841, 348518, 123051, 110808, 67139, 121139, 153670, 9621, 5928, 120976, 9540, 9618, 9606, 296422, 5913, 9624, 10194, 10163, 296435, 10195, 33799, 34316, 34315, 34311, 33798, 33792, 34346, 200788, 12180, 12179, 34347, 331341, 109332, 5356, 4673, 4673, 185161, 9608, 9607, 33640, 33599, 33598, 34940, 5989, 4676, 224585, 120496, 53462, 53455, 124761, 127778, 35277, 247987, 247984, 124768, 410927, 226759, 374926, 82460, 125886, 52682, 55223, 124842, 52692, 55221, 55224, 55219, 34103, 33708, 226496, 75443, 33701, 226493, 33705, 272102, 281920, 226515, 427233, 33668, 366916, 33711, 33712, 427227, 33670, 283582, 225309, 369580, 283582, 159826, 370884, 370888, 318604, 370889, 370890, 250920, 369634, 324726, 250917, 369738, 159843, 159845, 369608, 369608, 3300, 2730, 273212, 158409, 370652, 370653, 415942, 34152, 245234, 34155, 369600, 369600, 34381, 318607, 370664, 360685, 360685, 2739, 360684, 2740, 382779, 382788, 382779, 161109, 158407, 312490, 60762, 120999, 124262, 124262, 121008, 34396, 33799};
        path = find_path_to_point_of_interest(147568, "Motorcycle parking", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(147568, valid_end_intersections, path));
        CHECK(path_cost <= 3471.41846673280724644);
        
        valid_end_intersections = {219053, 201727, 53739, 226144, 338801, 259688, 362837, 255766, 95, 325556, 41730};
        path = find_path_to_point_of_interest(153473, "The Three Horseshoes", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(153473, valid_end_intersections, path));
        CHECK(path_cost <= 3503.12217767835772975);
        
        valid_end_intersections = {368293};
        path = find_path_to_point_of_interest(188958, "Wasabi Sushi", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(188958, valid_end_intersections, path));
        CHECK(path_cost <= 2398.58542833160072405);
        
        valid_end_intersections = {68913, 198107, 27390, 227296, 424980};
        path = find_path_to_point_of_interest(203815, "The Station", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(203815, valid_end_intersections, path));
        CHECK(path_cost <= 393.01973663707508422);
        
        valid_end_intersections = {696};
        path = find_path_to_point_of_interest(147115, "St Mary at Finchley", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(147115, valid_end_intersections, path));
        CHECK(path_cost <= 1759.09157691796008294);
        
        valid_end_intersections = {400978};
        path = find_path_to_point_of_interest(223851, "Camberley Infant and Nursery School", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(223851, valid_end_intersections, path));
        CHECK(path_cost <= 3656.24995365910626788);
        
        valid_end_intersections = {296272};
        path = find_path_to_point_of_interest(223979, "Terriors", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(223979, valid_end_intersections, path));
        CHECK(path_cost <= 2686.82806359219284786);
        
        valid_end_intersections = {436586, 33458, 109332};
        path = find_path_to_point_of_interest(272726, "subway", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(272726, valid_end_intersections, path));
        CHECK(path_cost <= 1870.13019076020714238);
        
        valid_end_intersections = {125493, 291134, 264497, 33750, 33271, 3572, 290037, 366891, 33086, 370889, 278722, 45725, 33793, 10161, 34240, 227719, 384187, 109357, 158621, 25714, 33959, 34940, 33671, 60746, 316361, 340078, 123009, 34318, 2738, 309102, 83601, 30829, 257162, 125491, 285916, 381327, 381331, 20247, 198323, 95363, 20244, 290193, 383640, 381326, 381315, 310804, 383627, 383634, 383641, 383680, 383630, 322836, 173418, 196656, 69391, 69422, 191806, 69396, 69436, 192697, 191793, 154921, 121623, 121622, 121621, 272048, 122952, 88732, 119791, 88732, 79002, 272053, 154912, 79000, 371119, 79004, 78985, 78984, 196658, 88729, 300634, 338173, 154894, 154894, 36535, 372288, 378783, 383662, 383646, 383646, 372287, 317146, 383658, 120735, 36526, 299943, 36523, 264009, 264007, 383347, 23796, 383349, 20260, 53457, 309173, 270279, 104713, 241484, 300497, 106837, 6206, 107146, 125760, 293349, 31371, 325544, 67225, 385235, 36317, 38495, 106864, 125523, 122183, 122181, 309084, 309084, 281386, 335505, 76506, 76458, 60761, 72375, 254089, 120727, 280410, 72374, 192702, 72370, 72287, 274771, 279892, 72274, 184232, 227177, 231630, 184228, 192601, 10393, 352664, 280285, 231621, 279898, 76590, 291368, 76585, 192832, 62895, 120207, 62895, 289755, 52781, 120314, 52784, 62870, 231635, 192635, 88686, 88698, 88696, 88696, 259698, 69388, 69389, 405911, 152345, 152345, 69412, 69400, 152343, 69416, 69438, 191786, 121629, 191789, 69432, 313540, 88675, 88674, 37366, 124268, 124268, 311199, 37367, 323212, 88673, 401533, 88679, 137510, 123602, 121205, 119599, 123598, 124244, 152329, 150496, 191714, 191717, 191715, 90163, 122921, 309847, 123588, 122606, 122603, 19918, 123584, 33952, 33951, 119956, 110139, 125515, 98338, 104797, 104659, 104668, 347058, 105207, 106877, 105429, 24862, 141956, 286218, 34274, 33082, 106713, 64449, 64445, 35231, 35216, 18266, 18268, 35226, 33582, 33759, 364527, 364543, 33869, 17574, 64228, 35273, 33902, 33882, 33881, 33882, 314538, 264765, 109354, 109354, 278721, 36307, 33521, 33901, 33901, 33902, 33901, 32997, 32993, 33336, 33511, 158680, 382880, 16327, 20349, 16329, 16332, 123747, 123746, 327762, 92119, 30659, 30648, 18290, 34548, 293539, 290188, 290189, 5232, 296986, 140608, 296980, 218724, 6176, 121756, 163107, 320385, 3458, 111578, 226976, 148795, 247124, 247256, 273395, 163961, 415115, 124211, 183513, 44866, 39961, 34037, 252004, 34083, 368294, 370318, 370312, 25656, 370312, 274678, 314313, 34509, 321224, 33857, 2727, 40293, 383093, 38195, 260700, 274334, 34773, 34780, 34897, 34894, 34898, 34892, 34612, 19819, 34771, 3747, 34759, 34757, 34753, 34754, 33974, 33983, 397131, 33980, 353075, 34029, 34039, 34028, 34039, 48436, 25699, 246982, 264563, 25647, 34596, 239271, 296428, 34594, 33482, 33482, 214575, 296426, 294480, 214572, 335283, 34522, 34522, 34502, 294480, 34526, 34530, 34529, 45712, 16618, 33516, 16606, 33530, 33948, 12167, 52614, 52614, 16729, 16723, 381993, 272946, 43829, 382802, 348514, 5841, 4454, 4670, 5841, 348518, 123051, 110808, 67139, 121139, 153670, 9621, 5928, 120976, 9540, 9618, 9606, 296422, 5913, 9624, 10194, 10163, 296435, 10195, 33799, 34316, 34315, 34311, 33798, 33792, 34346, 200788, 12180, 12179, 34347, 331341, 109332, 5356, 4673, 4673, 185161, 9608, 9607, 33640, 33599, 33598, 34940, 5989, 4676, 224585, 120496, 53462, 53455, 124761, 127778, 35277, 247987, 247984, 124768, 410927, 226759, 374926, 82460, 125886, 52682, 55223, 124842, 52692, 55221, 55224, 55219, 34103, 33708, 226496, 75443, 33701, 226493, 33705, 272102, 281920, 226515, 427233, 33668, 366916, 33711, 33712, 427227, 33670, 283582, 225309, 369580, 283582, 159826, 370884, 370888, 318604, 370889, 370890, 250920, 369634, 324726, 250917, 369738, 159843, 159845, 369608, 369608, 3300, 2730, 273212, 158409, 370652, 370653, 415942, 34152, 245234, 34155, 369600, 369600, 34381, 318607, 370664, 360685, 360685, 2739, 360684, 2740, 382779, 382788, 382779, 161109, 158407, 312490, 60762, 120999, 124262, 124262, 121008, 34396, 33799};
        path = find_path_to_point_of_interest(278086, "Motorcycle parking", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(278086, valid_end_intersections, path));
        CHECK(path_cost <= 1996.38984592464908019);
        
        valid_end_intersections = {315594};
        path = find_path_to_point_of_interest(278485, "The Greenstreet Pharmacy", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(278485, valid_end_intersections, path));
        CHECK(path_cost <= 5580.60133586468236899);
        
        valid_end_intersections = {87156};
        path = find_path_to_point_of_interest(298097, "Elm Court Fountain", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(298097, valid_end_intersections, path));
        CHECK(path_cost <= 3791.16409103759497157);
        
        valid_end_intersections = {316108};
        path = find_path_to_point_of_interest(319059, "Tollington", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(319059, valid_end_intersections, path));
        CHECK(path_cost <= 2652.40976695387644213);
        
        valid_end_intersections = {411785, 31826, 284265};
        path = find_path_to_point_of_interest(358664, "Delice de France", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(358664, valid_end_intersections, path));
        CHECK(path_cost <= 3698.98184545495769271);
        
        valid_end_intersections = {125493, 291134, 264497, 33750, 33271, 3572, 290037, 366891, 33086, 370889, 278722, 45725, 33793, 10161, 34240, 227719, 384187, 109357, 158621, 25714, 33959, 34940, 33671, 60746, 316361, 340078, 123009, 34318, 2738, 309102, 83601, 30829, 257162, 125491, 285916, 381327, 381331, 20247, 198323, 95363, 20244, 290193, 383640, 381326, 381315, 310804, 383627, 383634, 383641, 383680, 383630, 322836, 173418, 196656, 69391, 69422, 191806, 69396, 69436, 192697, 191793, 154921, 121623, 121622, 121621, 272048, 122952, 88732, 119791, 88732, 79002, 272053, 154912, 79000, 371119, 79004, 78985, 78984, 196658, 88729, 300634, 338173, 154894, 154894, 36535, 372288, 378783, 383662, 383646, 383646, 372287, 317146, 383658, 120735, 36526, 299943, 36523, 264009, 264007, 383347, 23796, 383349, 20260, 53457, 309173, 270279, 104713, 241484, 300497, 106837, 6206, 107146, 125760, 293349, 31371, 325544, 67225, 385235, 36317, 38495, 106864, 125523, 122183, 122181, 309084, 309084, 281386, 335505, 76506, 76458, 60761, 72375, 254089, 120727, 280410, 72374, 192702, 72370, 72287, 274771, 279892, 72274, 184232, 227177, 231630, 184228, 192601, 10393, 352664, 280285, 231621, 279898, 76590, 291368, 76585, 192832, 62895, 120207, 62895, 289755, 52781, 120314, 52784, 62870, 231635, 192635, 88686, 88698, 88696, 88696, 259698, 69388, 69389, 405911, 152345, 152345, 69412, 69400, 152343, 69416, 69438, 191786, 121629, 191789, 69432, 313540, 88675, 88674, 37366, 124268, 124268, 311199, 37367, 323212, 88673, 401533, 88679, 137510, 123602, 121205, 119599, 123598, 124244, 152329, 150496, 191714, 191717, 191715, 90163, 122921, 309847, 123588, 122606, 122603, 19918, 123584, 33952, 33951, 119956, 110139, 125515, 98338, 104797, 104659, 104668, 347058, 105207, 106877, 105429, 24862, 141956, 286218, 34274, 33082, 106713, 64449, 64445, 35231, 35216, 18266, 18268, 35226, 33582, 33759, 364527, 364543, 33869, 17574, 64228, 35273, 33902, 33882, 33881, 33882, 314538, 264765, 109354, 109354, 278721, 36307, 33521, 33901, 33901, 33902, 33901, 32997, 32993, 33336, 33511, 158680, 382880, 16327, 20349, 16329, 16332, 123747, 123746, 327762, 92119, 30659, 30648, 18290, 34548, 293539, 290188, 290189, 5232, 296986, 140608, 296980, 218724, 6176, 121756, 163107, 320385, 3458, 111578, 226976, 148795, 247124, 247256, 273395, 163961, 415115, 124211, 183513, 44866, 39961, 34037, 252004, 34083, 368294, 370318, 370312, 25656, 370312, 274678, 314313, 34509, 321224, 33857, 2727, 40293, 383093, 38195, 260700, 274334, 34773, 34780, 34897, 34894, 34898, 34892, 34612, 19819, 34771, 3747, 34759, 34757, 34753, 34754, 33974, 33983, 397131, 33980, 353075, 34029, 34039, 34028, 34039, 48436, 25699, 246982, 264563, 25647, 34596, 239271, 296428, 34594, 33482, 33482, 214575, 296426, 294480, 214572, 335283, 34522, 34522, 34502, 294480, 34526, 34530, 34529, 45712, 16618, 33516, 16606, 33530, 33948, 12167, 52614, 52614, 16729, 16723, 381993, 272946, 43829, 382802, 348514, 5841, 4454, 4670, 5841, 348518, 123051, 110808, 67139, 121139, 153670, 9621, 5928, 120976, 9540, 9618, 9606, 296422, 5913, 9624, 10194, 10163, 296435, 10195, 33799, 34316, 34315, 34311, 33798, 33792, 34346, 200788, 12180, 12179, 34347, 331341, 109332, 5356, 4673, 4673, 185161, 9608, 9607, 33640, 33599, 33598, 34940, 5989, 4676, 224585, 120496, 53462, 53455, 124761, 127778, 35277, 247987, 247984, 124768, 410927, 226759, 374926, 82460, 125886, 52682, 55223, 124842, 52692, 55221, 55224, 55219, 34103, 33708, 226496, 75443, 33701, 226493, 33705, 272102, 281920, 226515, 427233, 33668, 366916, 33711, 33712, 427227, 33670, 283582, 225309, 369580, 283582, 159826, 370884, 370888, 318604, 370889, 370890, 250920, 369634, 324726, 250917, 369738, 159843, 159845, 369608, 369608, 3300, 2730, 273212, 158409, 370652, 370653, 415942, 34152, 245234, 34155, 369600, 369600, 34381, 318607, 370664, 360685, 360685, 2739, 360684, 2740, 382779, 382788, 382779, 161109, 158407, 312490, 60762, 120999, 124262, 124262, 121008, 34396, 33799};
        path = find_path_to_point_of_interest(364270, "Motorcycle parking", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(364270, valid_end_intersections, path));
        CHECK(path_cost <= 1454.33077138217959146);
        
        valid_end_intersections = {119385, 62936, 141974, 272459, 179455, 270143, 194403, 424756, 224399, 261089, 352573, 420765, 305979, 137927, 19752, 416420, 13854};
        path = find_path_to_point_of_interest(366700, "Morrisons", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(366700, valid_end_intersections, path));
        CHECK(path_cost <= 1024.07917278151467144);
        
        valid_end_intersections = {183309};
        path = find_path_to_point_of_interest(374268, "Bupa Dental Care", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(374268, valid_end_intersections, path));
        CHECK(path_cost <= 3508.79509725287607580);
        
        valid_end_intersections = {11628};
        path = find_path_to_point_of_interest(392957, "Quattro", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(392957, valid_end_intersections, path));
        CHECK(path_cost <= 2602.46331568312962190);
        
        valid_end_intersections = {79028};
        path = find_path_to_point_of_interest(294514, "Da Mario", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(294514, valid_end_intersections, path));
        CHECK(path_cost <= 3358.92410791395968772);
        
        valid_end_intersections = {170430, 170463};
        path = find_path_to_point_of_interest(354296, "Co-op Pharmacy", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(354296, valid_end_intersections, path));
        CHECK(path_cost <= 4455.97895358424011647);
        
        valid_end_intersections = {33210, 34022, 128141, 272809, 34081, 395601, 337061, 425721, 92412, 35274, 18269, 407650, 49551, 1301, 33536, 153427, 435814, 125493, 211453, 418119, 1311};
        path = find_path_to_point_of_interest(408138, "EAT", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(408138, valid_end_intersections, path));
        CHECK(path_cost <= 4666.94963987085247936);
        
        valid_end_intersections = {150000};
        path = find_path_to_point_of_interest(412373, "St. Augustine Catholic Primary School", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(412373, valid_end_intersections, path));
        CHECK(path_cost <= 4026.08420161419644501);
        
        valid_end_intersections = {16327};
        path = find_path_to_point_of_interest(374639, "Goodmans City", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(374639, valid_end_intersections, path));
        CHECK(path_cost <= 3333.27296459424405839);
        
        valid_end_intersections = {188372, 84147, 334894, 394078, 49731, 8134};
        path = find_path_to_point_of_interest(264711, "The Slug and Lettuce", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(264711, valid_end_intersections, path));
        CHECK(path_cost <= 2183.65304479508404256);
        
        valid_end_intersections = {105898, 247139, 188034, 179491, 23523, 123076, 404762, 384293, 128141, 301694, 77212, 92632, 35420, 202486, 326808, 416395, 49719, 245390, 34580, 274267, 33724, 333891, 4614, 258026, 746, 258778, 3085, 14922, 22237, 419728, 119657, 96340, 286609, 266982, 177621, 417866, 102492, 107767, 96105, 304623, 290266, 291345, 293531, 88010, 76211, 265459, 412427, 421145, 140365, 65633, 76443, 420184, 183340, 75441, 294074, 54406, 181988, 1178, 410539, 396118, 193092, 410608, 393266, 340259, 13965, 243538, 427460, 122381, 114324, 283770, 125099, 411117, 114975, 320916, 136129, 369847, 368013, 211335, 331188, 38839, 21807, 55281, 102687, 13080, 335113, 203380, 230677, 247974, 393394, 33986, 287218, 235813, 257151, 198924, 110774, 123797, 312200, 155333, 363031, 52120, 143801, 213543, 60675, 118335, 215580, 107161, 226039, 406694, 395908, 166357, 145577, 364707, 413014, 150176, 416733, 263006, 321880, 29184, 364522, 426289, 158456, 314841, 414316, 394828, 33811, 430205, 236512, 337535, 374647, 124389, 408116, 114373, 131810};
        path = find_path_to_point_of_interest(198759, "McDonald's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(198759, valid_end_intersections, path));
        CHECK(path_cost <= 1082.10904151011618524);
        
        valid_end_intersections = {300533, 256914, 89269, 119547, 424715, 337403, 175177, 62182, 296630, 23075, 317753, 84515, 173273, 312900, 38881, 22549, 16289, 45660, 81400, 155519, 279929, 90492, 394658, 376010, 394288, 45325, 279366, 209541, 199279, 214839, 291827, 281409, 117410, 67050, 215258, 97514, 33506, 268594, 323346, 406560, 162977, 313504, 1490, 77838, 311516, 387108, 74164, 333010, 397220, 312036, 21518, 416365, 283126};
        path = find_path_to_point_of_interest(169984, "BP", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(169984, valid_end_intersections, path));
        CHECK(path_cost <= 959.80703486939478353);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids;
        std::vector<std::string> poi_names;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 10; i++) {
            intersection_ids.push_back(rand_intersection(rng));
            poi_names.push_back(getPointOfInterestName(rand_poi(rng)));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(72841);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 10; i++) {
                result = find_path_to_point_of_interest(intersection_ids[i], poi_names[i], turn_penalties[i]);
            }
        }
    } //find_path_to_point_of_interest_perf_basic

} //inter_inter_path_perf_basic_public
