#include <random>
#include <unittest++/UnitTest++.h>

#include "StreetsDatabaseAPI.h"
#include "m1.h"
#include "m3.h"

#include "unit_test_util.h"
#include "path_verify.h"

using ece297test::relative_error;
using ece297test::path_is_legal;


SUITE(inter_inter_path_perf_medium_public) {
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
    TEST_FIXTURE(MapFixture, find_path_to_point_of_interest_perf_medium) {
        //Verify Functionality
        std::vector<unsigned> path;
        std::vector<unsigned> valid_end_intersections;
        double path_cost;
        
        valid_end_intersections = {42447, 4202, 71582, 104447, 76222, 26389, 10514, 47886};
        path = find_path_to_point_of_interest(673, "Starbucks", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(673, valid_end_intersections, path));
        CHECK(path_cost <= 1003.13460454865651172);
        
        valid_end_intersections = {5204, 45670, 5185, 82551, 1487, 1833, 12572, 11031, 513, 6997, 63067, 97836, 4182, 727, 16674, 81174, 2259, 45089, 3340, 2292, 9236, 70897, 95463, 18670, 99114, 93480, 1078, 23113, 59300, 20194, 10869, 11016, 24460, 10077, 99992, 2955, 7359, 57768, 23035, 57420, 2142, 4320, 14601, 45640, 107820, 57809, 4756, 62134, 61721, 25555, 21033, 21437, 1219, 69668, 54322, 35151, 56405, 15076, 19848, 41888, 82161, 45499, 88579, 44755, 36643, 57025, 11621, 35124, 2277, 13491, 103732, 78869, 98642, 50657, 4297, 13280, 103325, 20697, 7374, 90859, 70714, 85313, 70080, 30545, 13547, 91, 89185, 16270, 101013, 86929, 11652, 71366, 55837, 51470, 62041, 98166, 67837, 1014, 72647, 72722, 13509, 78657, 90530, 20573, 31198, 75072, 2616, 61318, 78708, 79851, 12380, 31088, 39914, 100978, 59011, 41993, 83226, 20638, 58307, 44748, 108439, 94713, 71708, 41888, 49570, 28929, 10705, 14875, 15327, 96378, 102316, 26561, 31353, 31436, 90149, 86671, 92235, 90611, 105177, 33433, 34329, 16982, 105008, 105754, 10654, 73025, 76161, 89164, 41888, 91364, 22203, 64251, 97329, 96696, 21220, 97512, 5454, 13479, 106280, 35327, 3339, 19847, 24385, 45095, 34069, 86359, 91838, 53707, 36467, 79328, 2569, 91665, 7830, 52498, 6652, 32341, 106756, 63321, 49388, 101345, 93394, 103775, 103980, 18532, 49629, 93660};
        path = find_path_to_point_of_interest(3736, "TD Canada Trust", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(3736, valid_end_intersections, path));
        CHECK(path_cost <= 161.50228671388515522);
        
        valid_end_intersections = {95048};
        path = find_path_to_point_of_interest(7896, "Loblaw Pharmacy", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(7896, valid_end_intersections, path));
        CHECK(path_cost <= 1369.74078643584311976);
        
        valid_end_intersections = {50352};
        path = find_path_to_point_of_interest(21234, "Steeles Public Library", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(21234, valid_end_intersections, path));
        CHECK(path_cost <= 1110.98433518936985820);
        
        valid_end_intersections = {41886, 4182, 12243, 2339, 41887, 2275, 13495, 7014, 2246, 16576, 44753, 20236, 90576, 102026, 63059, 74416, 33029, 33027, 2290};
        path = find_path_to_point_of_interest(21708, "Bixi Bike Sharing", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(21708, valid_end_intersections, path));
        CHECK(path_cost <= 1036.30329917523613403);
        
        valid_end_intersections = {33018, 16695, 103014, 82104, 35700};
        path = find_path_to_point_of_interest(22087, "Alterna Savings", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(22087, valid_end_intersections, path));
        CHECK(path_cost <= 70.23052663425980313);
        
        valid_end_intersections = {85052, 72167, 16263, 11484, 87732};
        path = find_path_to_point_of_interest(30389, "Gabby's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(30389, valid_end_intersections, path));
        CHECK(path_cost <= 1285.25373082495343624);
        
        valid_end_intersections = {8874};
        path = find_path_to_point_of_interest(20222, "Pogue Mahone Irish Pub", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(20222, valid_end_intersections, path));
        CHECK(path_cost <= 87.45697275280974736);
        
        valid_end_intersections = {99983, 98776, 44741, 88, 100647, 44637};
        path = find_path_to_point_of_interest(39889, "aroma espresso bar", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(39889, valid_end_intersections, path));
        CHECK(path_cost <= 1549.66794630845697611);
        
        valid_end_intersections = {25657, 41834, 97185, 101796, 104747};
        path = find_path_to_point_of_interest(40714, "Popeye's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(40714, valid_end_intersections, path));
        CHECK(path_cost <= 1269.21511353897426488);
        
        valid_end_intersections = {96284, 3703, 30577, 39596, 26678, 28345, 19205, 35799, 92835, 21033, 41849, 74357, 59509, 86899, 79860, 30436, 100046, 28419, 103127, 94556, 69943, 52172, 75758, 28740, 74655, 60458, 108040, 60671, 80162, 56135, 77801};
        path = find_path_to_point_of_interest(45583, "Husky", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(45583, valid_end_intersections, path));
        CHECK(path_cost <= 564.17285850763369126);
        
        valid_end_intersections = {12913, 3933, 18627, 18798, 23133, 19081, 54335, 48990, 53540, 35824, 49794, 59487, 69668, 72384, 8994, 3705, 28896, 4320, 19156, 4197, 81984, 100275, 106566, 56389, 52373, 53502, 10070, 15646, 71793, 71027, 71564, 62070, 54633, 5198, 77731, 52965, 77399, 2506, 5184, 46775, 79525, 33651, 26561, 94157, 58670, 105755, 90150, 96138, 23333, 16513, 34424, 27882, 92790, 96346, 8596, 3172};
        path = find_path_to_point_of_interest(22772, "Mr. Sub", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(22772, valid_end_intersections, path));
        CHECK(path_cost <= 475.08674659694366937);
        
        valid_end_intersections = {29450};
        path = find_path_to_point_of_interest(30065, "Dr Marion Hilliard Senior Public School", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(30065, valid_end_intersections, path));
        CHECK(path_cost <= 1761.85994362162477955);
        
        valid_end_intersections = {106577};
        path = find_path_to_point_of_interest(60095, "Two Guys from Italy", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(60095, valid_end_intersections, path));
        CHECK(path_cost <= 1484.21139949633402466);
        
        valid_end_intersections = {100774, 105444, 5185, 12458, 718, 100550, 58152, 17419, 1051, 3955, 1014, 2271, 16982, 23132, 98899, 101404, 19081, 26459, 56532, 36635, 95336, 7228, 63129, 92835, 21437, 36298, 23842, 749, 56398, 19837, 16758, 36646, 85504, 99106, 1273, 71793, 27150, 103731, 33577, 98620, 24379, 6867, 10040, 91, 6861, 16222, 97865, 99358, 90569, 73350, 24563, 45674, 100978, 94112, 93349, 81128, 25725, 93140, 94713, 13280, 20232, 31108, 55867, 92435, 30989, 31437, 64642, 69786, 3633, 33434, 22151, 32066, 90578, 50517, 62040, 96035, 22508, 59185, 34721, 58665, 74521, 5458, 89809, 99298, 74729, 96829, 16762, 19422, 90111, 41495, 53494, 50353};
        path = find_path_to_point_of_interest(60596, "McDonald's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(60596, valid_end_intersections, path));
        CHECK(path_cost <= 227.66123024509982997);
        
        valid_end_intersections = {1744, 41885, 4016, 85504, 2262, 86938};
        path = find_path_to_point_of_interest(51878, "Pumpernickel's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(51878, valid_end_intersections, path));
        CHECK(path_cost <= 919.49506753919843050);
        
        valid_end_intersections = {12238, 6430, 7636, 61358, 104721, 5812, 100051, 47489, 15240, 44763, 18487, 29135, 71078, 28893, 19467, 88387, 60237, 26919, 61543, 32459, 30411, 83360, 8595, 28345, 56682, 59316, 58041, 89470, 57138, 7388, 26459, 29974, 86732, 44165, 17035, 35099, 71518, 78976, 14206, 54944, 78533, 62144, 61725, 74932, 43686, 58006, 57748, 14339, 60650, 37963, 52515, 70098, 97142, 89317, 105726, 8404, 77212, 66400, 59291, 30509, 82641, 33542, 81992, 82269, 20118, 50793, 89873, 100007, 23371, 28269, 107531, 98394, 54000, 54808, 55450, 51806, 1351, 55859, 90671, 92477, 1089, 55121, 95479, 69747, 53731, 87686, 54002, 56688, 76190, 70987, 55047, 77061, 63408, 59511, 60402, 64239, 75753, 77948, 77927, 92004, 60456, 87207, 24728, 61400, 322, 67438, 74302, 78617, 82751, 90682, 89317, 24864, 67871, 36512, 35246, 17338, 26347, 25516, 15594, 26609, 92879, 50506, 88706, 106895, 59185, 101114, 74779, 68628, 94397, 74578, 106127, 29414, 14484, 55712};
        path = find_path_to_point_of_interest(69022, "Petro-Canada", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(69022, valid_end_intersections, path));
        CHECK(path_cost <= 216.58012897213927772);
        
        valid_end_intersections = {22258};
        path = find_path_to_point_of_interest(70177, "Eden", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(70177, valid_end_intersections, path));
        CHECK(path_cost <= 716.90162505837372464);
        
        valid_end_intersections = {102025, 6339, 1606, 12751, 2376, 2324, 2290, 20025, 69682, 14820, 29104, 86232, 7765, 16975, 1014, 9244, 21369, 103429, 24460, 16462, 85315, 29210, 2954, 98707, 101446, 99962, 31614, 57675, 17010, 92414, 12581, 71793, 49815, 77452, 91245, 92502, 61261, 49579, 22702, 33213, 35826, 61521, 42735, 36000, 59406, 103939, 35151, 54004, 19844, 29581, 16757, 33014, 70058, 41887, 1451, 44754, 24760, 31089, 31857, 106573, 101979, 107521, 68572, 4309, 103323, 103248, 98622, 62004, 23686, 7225, 60370, 90042, 92175, 61318, 6724, 20730, 98946, 11442, 107221, 62041, 12338, 79040, 71545, 70909, 68931, 72646, 41218, 75682, 76109, 90534, 56109, 73344, 75072, 81689, 50236, 100978, 101900, 70747, 8233, 2272, 74435, 24813, 82898, 83204, 96009, 67794, 1387, 6056, 2242, 23123, 10854, 87690, 90, 66053, 66552, 36589, 81814, 90600, 57025, 33577, 32573, 24733, 3803, 98153, 99122, 105007, 725, 84727, 75746, 34810, 90766, 22148, 22525, 36643, 55855, 21221, 99329, 71569, 63993, 21715, 61723, 4650, 25731, 45402, 56308, 87078, 78708, 41490, 68958, 102029, 61137, 6668, 104741, 59974, 63316, 93394, 27002, 80410, 13495, 59482, 103983, 35794, 105725};
        path = find_path_to_point_of_interest(71984, "Shoppers Drug Mart", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(71984, valid_end_intersections, path));
        CHECK(path_cost <= 208.16053559715888355);
        
        valid_end_intersections = {12913, 3933, 18627, 18798, 23133, 19081, 54335, 48990, 53540, 35824, 49794, 59487, 69668, 72384, 8994, 3705, 28896, 4320, 19156, 4197, 81984, 100275, 106566, 56389, 52373, 53502, 10070, 15646, 71793, 71027, 71564, 62070, 54633, 5198, 77731, 52965, 77399, 2506, 5184, 46775, 79525, 33651, 26561, 94157, 58670, 105755, 90150, 96138, 23333, 16513, 34424, 27882, 92790, 96346, 8596, 3172};
        path = find_path_to_point_of_interest(75948, "Mr. Sub", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(75948, valid_end_intersections, path));
        CHECK(path_cost <= 507.21397617733720153);
        
        valid_end_intersections = {1101, 4137, 21477, 61237, 82968, 107838, 3305, 71835, 61317, 81796, 102490, 104557, 95694, 32540, 21473};
        path = find_path_to_point_of_interest(80378, "Pharmasave", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(80378, valid_end_intersections, path));
        CHECK(path_cost <= 1133.39572921295939523);
        
        valid_end_intersections = {3128, 1127, 87701, 1130, 9511, 7276, 7245, 8227, 91425, 16773, 16695, 20024, 20228, 1750, 16570, 71078, 8374, 88345, 1118, 97185, 103427, 18672, 59292, 99983, 24740, 18487, 98904, 41909, 9163, 28915, 57095, 80708, 88674, 107653, 61242, 61372, 3305, 105178, 105429, 77832, 43589, 36000, 36298, 54326, 61296, 97143, 104617, 16757, 2600, 44754, 28907, 19182, 5510, 1671, 60902, 70584, 26925, 68574, 4308, 82642, 29789, 44161, 7854, 91776, 86833, 61226, 71731, 54006, 90874, 18970, 1078, 23758, 108379, 3679, 64275, 4461, 88344, 70573, 1744, 20826, 14901, 12572, 14675, 333, 5702, 44066, 71262, 98900, 4318, 24452, 99720, 71027, 57995, 5812, 13135, 749, 61308, 71869, 54499, 70708, 2246, 1862, 6753, 2294, 30964, 44035, 52383, 69685, 9799, 8172, 98946, 56866, 86200, 41916, 94133, 34255, 20233, 79798, 54863, 1884, 85971, 73908, 62074, 9400, 61321, 79167, 546, 5206, 16758, 6047, 96169, 60475, 41905, 10006, 41812, 34379, 82546, 24525, 75745, 8874, 94645, 3955, 11491, 67223, 96378, 96917, 6759, 29104, 1381, 25473, 17227, 72214, 31343, 26706, 87691, 24556, 58705, 38400, 104991, 44800, 23035, 1419, 92486, 75763, 22074, 99065, 22524, 97232, 22525, 28508, 66430, 98637, 22226, 64250, 85319, 41834, 39079, 97503, 58757, 70909, 29507, 104447, 22151, 67695, 40479, 50517, 30374, 58785, 59718, 107465, 45250, 7711, 71564, 91365, 84589, 2634, 96346, 80538, 4631, 89207, 99358, 97595, 11422, 104877, 28913, 46545, 96491, 14761, 56420, 104752, 60402, 36288, 7512, 11035, 6866, 33311, 89158, 3293, 88146, 1252, 85234, 93076, 93394, 63216, 101341, 28634, 105187, 35880, 97857, 35792, 61872};
        path = find_path_to_point_of_interest(81143, "Subway", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(81143, valid_end_intersections, path));
        CHECK(path_cost <= 63.47291184868886660);
        
        valid_end_intersections = {82463, 7260, 5590, 12433, 12052, 4320, 61321, 94640, 72385, 93575, 84, 50648, 38399, 19295, 68318, 73691, 1734, 63154, 59027, 19205, 82796, 52818, 59855, 14026, 57661, 57240, 61389, 21993, 34993, 4757, 35151, 77462, 27358, 61365, 62142, 26845, 93032, 42895, 7743, 40908, 41828, 52515, 88287, 54672, 88337, 19150, 1338, 57691, 60371, 30348, 37284, 8082, 98165, 54838, 62321, 90671, 29824, 98646, 10463, 51494, 57906, 49973, 77878, 73305, 62003, 88171, 31376, 75744, 71030, 46469, 67773, 86509, 59739, 1215, 1259, 26339, 106362, 34537, 97208, 44990, 56415, 26382, 14486, 107633, 66380, 60901, 70933, 52441, 60608, 18520, 72667, 63418, 106837, 33322, 82691};
        path = find_path_to_point_of_interest(72513, "Shell", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(72513, valid_end_intersections, path));
        CHECK(path_cost <= 280.58544094605161945);
        
        valid_end_intersections = {12913};
        path = find_path_to_point_of_interest(37083, "Pulcinella Ristorante Italiano", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(37083, valid_end_intersections, path));
        CHECK(path_cost <= 1546.96752133384325134);
        
        valid_end_intersections = {100774, 105444, 5185, 12458, 718, 100550, 58152, 17419, 1051, 3955, 1014, 2271, 16982, 23132, 98899, 101404, 19081, 26459, 56532, 36635, 95336, 7228, 63129, 92835, 21437, 36298, 23842, 749, 56398, 19837, 16758, 36646, 85504, 99106, 1273, 71793, 27150, 103731, 33577, 98620, 24379, 6867, 10040, 91, 6861, 16222, 97865, 99358, 90569, 73350, 24563, 45674, 100978, 94112, 93349, 81128, 25725, 93140, 94713, 13280, 20232, 31108, 55867, 92435, 30989, 31437, 64642, 69786, 3633, 33434, 22151, 32066, 90578, 50517, 62040, 96035, 22508, 59185, 34721, 58665, 74521, 5458, 89809, 99298, 74729, 96829, 16762, 19422, 90111, 41495, 53494, 50353};
        path = find_path_to_point_of_interest(89941, "McDonald's", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(89941, valid_end_intersections, path));
        CHECK(path_cost <= 263.84591034208250449);
        
        valid_end_intersections = {38488};
        path = find_path_to_point_of_interest(7416, "Villa Madina Mediterranean Cuisine", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(7416, valid_end_intersections, path));
        CHECK(path_cost <= 1232.05024525734529561);
        
        valid_end_intersections = {12310, 97205, 94183, 7826, 45680, 61360, 4320, 28860, 81174, 6263, 9369, 81945, 12718, 18482, 71673, 2236, 6456, 16915, 99110, 23084, 25690, 32614, 32603, 38393, 81717, 39763, 10084, 94170, 81749, 45385, 57096, 43650, 89467, 59013, 60623, 107461, 82021, 23975, 35110, 69667, 78939, 87129, 97688, 4731, 35727, 93715, 67901, 35989, 36298, 79077, 37111, 61309, 41827, 52520, 9136, 68516, 41497, 3404, 71552, 429, 455, 92840, 52030, 57749, 67785, 82645, 96422, 50569, 92165, 72341, 66414, 98164, 51967, 107581, 60860, 60721, 20009, 12131, 21291, 53500, 86567, 86899, 24805, 71366, 69738, 71564, 10741, 79743, 73505, 75962, 74432, 106172, 26371, 82676, 27494, 69680, 49648, 54814, 18577, 105027, 75735, 87077, 98859, 39763, 92165, 70691, 38394, 86671, 69786, 74783, 20627, 54003, 86638, 92886, 75695, 60355, 60639, 79077, 79547, 86620, 69709, 67715, 73443, 60456, 107634, 60199, 78015, 96679, 90111, 2236, 94579, 106839, 77569};
        path = find_path_to_point_of_interest(99618, "Esso", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(99618, valid_end_intersections, path));
        CHECK(path_cost <= 279.66377522688003410);
        
        valid_end_intersections = {16762};
        path = find_path_to_point_of_interest(105322, "Salad King", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(105322, valid_end_intersections, path));
        CHECK(path_cost <= 2437.39741604481196191);
        
        valid_end_intersections = {85051};
        path = find_path_to_point_of_interest(108009, "NOW, 24 Hours", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(108009, valid_end_intersections, path));
        CHECK(path_cost <= 2484.90208432232520863);
        
        valid_end_intersections = {29543};
        path = find_path_to_point_of_interest(107062, "Airport Medical Centre", 15.00000000000000000);
        path_cost = compute_path_travel_time(path, 15.00000000000000000);
        CHECK(path_is_legal(107062, valid_end_intersections, path));
        CHECK(path_cost <= 497.64888502908002010);
        
        //Generate random inputs
        std::vector<unsigned> intersection_ids;
        std::vector<std::string> poi_names;
        std::vector<double> turn_penalties;
        for(size_t i = 0; i < 40; i++) {
            intersection_ids.push_back(rand_intersection(rng));
            poi_names.push_back(getPointOfInterestName(rand_poi(rng)));
            turn_penalties.push_back(rand_turn_penalty(rng));
        }
        {
            //Timed Test
            ECE297_TIME_CONSTRAINT(78630);
            std::vector<unsigned> result;
            for(size_t i = 0; i < 40; i++) {
                result = find_path_to_point_of_interest(intersection_ids[i], poi_names[i], turn_penalties[i]);
            }
        }
    } //find_path_to_point_of_interest_perf_medium

} //inter_inter_path_perf_medium_public

