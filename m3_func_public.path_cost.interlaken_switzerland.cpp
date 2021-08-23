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
        rand_lat = std::uniform_real_distribution<double>(46.650653839, 46.730262756);
        rand_lon = std::uniform_real_distribution<double>(7.667298794, 7.962547302);
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
        
        path = {1952, 1953, 1954, 1955, 1956, 76, 77, 1529};
        turn_penalty = 0.00000000000000000;
        expected = 29.86446602706181608;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {928, 199, 200, 201, 1797, 989, 990, 991, 2026, 55, 202, 203, 204, 205, 54, 1522, 1510, 1509, 1508, 1519, 151, 2084, 1377, 1823, 961, 1330, 1976, 1524, 1525, 1076, 1077, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1879};
        turn_penalty = 10.72199757501731554;
        expected = 140.30198019148892286;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1073, 1081, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1879, 1239, 2035, 2034, 960, 455, 2036, 383, 381, 1896, 635};
        turn_penalty = 7.92470683533765108;
        expected = 157.97183488442280463;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {0, 1, 1891, 2066, 48, 47, 46, 51, 2067, 1010, 528, 45, 1890, 43, 2097, 2094, 2095, 2105};
        turn_penalty = 0.00000000000000000;
        expected = 175.87170220368304285;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {589, 588, 587, 617, 616, 615, 596, 583, 1763, 1762, 194, 715, 716, 1931, 1926, 197, 198, 288, 570, 569, 562, 472, 688, 558, 559, 556, 684, 473, 577, 144, 891, 890, 889};
        turn_penalty = 0.00000000000000000;
        expected = 197.33124796594560735;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {56, 2053, 1389, 2099, 2100, 44, 1739, 2106, 706, 1758, 1443, 1442, 154, 78, 1929, 42, 720, 75, 170, 1888, 1889, 1968, 1764, 1765, 1624, 1625, 1626, 1612, 1611, 1617, 1616};
        turn_penalty = 12.86716044314528418;
        expected = 200.33395383427915704;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1922, 1919, 1920, 1921, 355, 1912, 1911, 1910, 1909, 1908, 1291, 1290, 1126, 1125, 879};
        turn_penalty = 29.15722898780660799;
        expected = 207.02299540445056891;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {576, 1332, 1970, 1969, 563, 565, 566, 685, 567, 568, 687, 1759, 256, 257, 195, 196, 1927, 74, 1889, 1888, 170, 75, 714, 194, 1762, 1763, 583, 584, 585, 586, 920, 921, 386, 387, 388, 389, 390, 541, 542, 543, 544, 545};
        turn_penalty = 4.11236351442220283;
        expected = 308.74356696684958479;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {528, 45, 1890, 43, 2097, 2094, 2095, 2105, 475, 2108, 2109, 2112, 706, 1758, 1443, 1442, 154, 78, 1929, 42, 1942, 194, 1762, 1763, 583, 584, 585, 586, 536};
        turn_penalty = 32.80671457076476116;
        expected = 319.08725729667378346;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {269, 268, 199, 200, 201, 1797, 989, 990, 991, 2026, 55, 202, 203, 204, 205, 54, 1522, 1510, 1509, 1508, 1519, 151, 2084, 1377, 1823, 961, 1330, 1976, 1524, 1525, 1076, 1077, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1879, 1239, 2035, 2034, 960, 455, 2036, 383, 382, 2033, 769, 513, 512, 511, 399, 400, 401, 402, 403, 404, 535, 534, 533, 532};
        turn_penalty = 3.90960681914189401;
        expected = 333.59272218232138130;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1537, 1538, 1239, 330, 331, 332, 2048, 2049, 1511, 2050, 2100, 44, 1739, 2106, 477, 478, 2107, 475, 2104, 476, 2093, 2098, 43, 1890, 45, 528, 1010, 2067, 51, 52, 726, 727, 728, 1893, 982};
        turn_penalty = 38.07595966077786898;
        expected = 339.39018398101376306;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {525, 520, 521, 522, 523, 2062, 2057, 396, 38, 2046, 2047, 56, 2053, 1389, 2051, 1511, 2049, 2048, 332, 331, 330, 1239, 1538, 1537, 1536, 1535, 1534, 1533, 1532, 1531, 1530, 1313, 1312, 835};
        turn_penalty = 44.11521863240028551;
        expected = 339.55100819339241980;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1278, 1271, 1270, 378, 379, 1259, 164, 163, 162, 161, 160, 289, 702, 701, 700, 292, 291, 290, 28, 29, 251, 252, 249, 1028, 893, 725, 891, 892, 267, 1969, 1970, 1332, 576, 1842, 1589, 882, 883, 1579, 1581, 1843, 1844, 1845, 1580, 814, 813, 101, 732, 241, 237, 1856, 1857, 1855, 869, 914, 915, 916, 1997, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 1527, 1526, 1076, 1077, 1221, 1222, 1080, 1075};
        turn_penalty = 2.68072293181142607;
        expected = 343.78021507400461587;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1337, 273, 1203, 1202, 1201, 1200, 1199, 272, 271, 449, 448, 1540, 1315, 270, 1325, 1324, 1323, 1322, 25, 1078, 1406};
        turn_penalty = 43.34477103046508972;
        expected = 350.25776397606273349;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1807, 1801, 729, 1236, 1894, 1893, 728, 727, 730, 50, 2067, 1010, 528, 45, 1890, 43, 2097, 2094, 2095, 2105, 475, 2108, 2109, 2113, 2111, 2110, 2103, 2100, 2099, 2051, 1511, 2049, 2048, 332, 331, 330, 1239, 1538, 1537, 1536, 1535, 1534, 1533, 1532, 1531, 1530, 1529, 77, 76, 1956, 1955, 1954, 1953, 1952, 1951, 1997, 113};
        turn_penalty = 17.26744121680091126;
        expected = 351.87000985240285900;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {400, 399, 511, 512, 513, 769, 2033, 382, 383, 2036, 455, 960, 2034, 2035, 1239, 1879, 1231, 1230, 1229, 1228, 1227, 1226, 1225, 1224, 1223, 1222, 1221, 1077, 191, 1527, 1528, 1331, 961, 1823, 1377, 2083, 1509, 1510, 1522, 54, 205, 204, 203, 202, 55, 2026, 991, 990, 989, 1797, 201, 200, 199, 928, 900, 899, 898, 897, 878, 877, 423, 424, 425, 1875, 1876, 1341};
        turn_penalty = 5.46601715552688994;
        expected = 352.94557838076354983;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {534, 533, 532, 531, 530, 529, 920, 586, 585, 584, 583, 1763, 1762, 194, 714, 75, 170, 1888, 1889, 1968, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771, 1772, 1773, 1774, 879, 880, 1915, 1914, 1913, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 102, 89, 90, 374};
        turn_penalty = 25.16084927376740765;
        expected = 382.32418003719573107;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1029, 422, 421, 420, 1876, 1875, 425, 424, 423, 877, 878, 897, 898, 899, 900, 928, 199, 200, 201, 1797, 989, 990, 991, 2026, 55, 202, 203, 204, 205, 54, 1522, 1510, 1509, 1508, 1519, 151, 2084, 1377, 1823, 961, 1330, 1980, 1986, 1982};
        turn_penalty = 29.50603330874932340;
        expected = 394.89365869027301414;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {78, 1929, 1925, 1931, 1926, 197, 198, 288, 570, 569, 562, 472, 688, 558, 559, 556, 686, 557, 733, 555, 762, 970, 971, 560, 159, 735, 736, 737, 738, 739, 740, 741, 763, 764, 765, 766, 767, 768, 742, 743, 744, 745, 746, 747, 954, 953, 952, 951};
        turn_penalty = 43.83224127580765384;
        expected = 399.81902626612600216;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {23, 22, 21, 20, 19, 18, 17, 16, 507, 506, 505, 1874, 1873, 1872, 1871, 1870, 1869, 1868, 1892, 1891, 2066, 48, 47, 46, 51, 2067, 1010, 528, 45, 1890, 43, 2097, 2094, 2095, 2105, 475, 2108, 2109, 2112, 706, 1758, 1443, 1442, 154, 78, 1929, 42, 720, 75, 170, 1888, 1889, 1968, 1764};
        turn_penalty = 31.34028327739956765;
        expected = 464.19261087783098674;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {798, 734, 1782, 1781, 1780, 1792, 1791, 1790, 1796, 1795, 760, 759, 758, 757, 756, 755, 754, 753, 752, 751, 750, 749, 748, 747, 746, 745, 744, 743, 742, 768, 767, 766, 765, 764, 763, 741, 740, 739, 738, 737, 736, 735, 159, 560, 971, 970, 762, 761, 1970, 1969, 267, 887, 888, 889, 724, 893, 1028, 249, 252, 251, 29, 28, 290, 291, 292, 700, 701, 702, 289, 160, 161, 162, 163, 164, 165, 166, 1163, 308, 307, 1152, 1194};
        turn_penalty = 6.71398457277002869;
        expected = 481.33329105847275287;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1393, 1390, 1373, 1372, 1371, 278, 759, 758, 757, 756, 755, 754, 753, 752, 751, 750, 749, 748, 747, 746, 745, 744, 743, 742, 768, 767, 766, 765, 764, 763, 741, 740, 739, 738, 737, 736, 735, 159, 560, 971, 970, 762, 555, 733, 575, 564, 265, 266, 685, 567, 568, 687, 1759, 256, 257, 195, 196, 1927, 169, 1937, 1938, 1761, 153, 1441, 114, 461, 218, 2096, 2095, 2105, 475};
        turn_penalty = 13.71927624544100688;
        expected = 488.71754574509037639;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1016, 1132, 1133, 1134, 800, 799, 160, 289, 702, 701, 700, 292, 291, 290, 28, 29, 251, 252, 249, 1028, 893, 725, 891, 144, 561, 555, 762, 970, 971, 560, 159, 735, 736, 737, 738, 739, 740};
        turn_penalty = 31.07746946120639464;
        expected = 494.91362481003756102;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {693, 398, 397, 937, 319, 318, 694, 695, 696, 1651, 1652, 1653, 1654, 2069, 2070, 2071, 1467, 1481, 1472, 1479, 1468, 1474, 1473, 1476, 1477, 1475, 1650, 1480, 1466, 1482, 1469, 1483, 1485, 1478, 1471, 1484, 1470, 2020, 2115, 2116, 2117, 468, 1040, 1041, 1378, 2021, 2022, 2068, 417, 418, 491, 492, 493};
        turn_penalty = 0.90258765451972178;
        expected = 504.27317127614213632;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {503, 502, 319, 318, 694, 695, 696, 1651, 1652, 1653, 1654, 2069, 2070, 2071, 1467, 1481, 1472, 1479, 1468, 1474, 1473, 1476, 1477, 1475, 1650, 1480, 1466, 1482, 1469, 1483, 1485, 1478, 1471, 1484, 1470, 2020, 2115, 2116, 2117, 468, 1040, 1041, 1378, 2021, 2022, 2068, 1197, 1198, 183, 903, 902, 901, 1203, 1202, 1201, 856, 857, 858, 2025, 282, 1397};
        turn_penalty = 7.66876581015625014;
        expected = 602.14799478996496873;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {470, 1165, 1166, 1760, 634, 1726, 1725, 287, 1763, 1762, 194, 714, 75, 170, 717, 41, 1937, 1938, 1761, 153, 1441, 114, 461, 218, 2093, 2098, 43, 1890, 45, 528, 1010, 2067, 51, 52, 726, 727, 728, 1893, 1894, 1236, 1237, 1238, 1813, 808, 809, 464, 465, 466, 467, 1233, 1234, 1235};
        turn_penalty = 14.24546986562031847;
        expected = 608.83061581984804889;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {931, 1499, 1497, 1498, 694, 695, 696, 1651, 1652, 1653, 1654, 2069, 2070, 2071, 1467, 1481, 1472, 1479, 1468, 1474, 1473, 1476, 1477, 1475, 1650, 1480, 1466, 1482, 1469, 1483, 1485, 1478, 1471, 1484, 1470, 2020, 2115, 2116, 2117, 468, 1040, 1041, 1378, 2021, 2022, 2068, 1197, 1198, 183, 689, 690, 877, 878, 897, 898, 899, 900, 928, 199, 200, 201, 1797, 989, 990, 991, 2026, 55, 202, 203, 204, 205, 54, 1522, 1510, 1509, 1508, 1519, 151, 2084, 1377, 1823, 961, 1330, 1976, 1524, 1525, 1076, 1077, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1879, 330, 331, 332, 2048, 2063};
        turn_penalty = 7.96910429139791976;
        expected = 663.97340239747018131;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {952, 953, 954, 747, 746, 745, 744, 743, 742, 768, 767, 766, 765, 764, 763, 741, 740, 739, 738, 737, 736, 735, 159, 560, 971, 970, 762, 555, 733, 575, 564, 265, 266, 685, 567, 568, 687, 1759, 256, 257, 195, 196, 1927, 74, 1889, 1888, 170, 75, 714, 194, 1762, 1763, 583, 584, 585, 586, 920, 921, 386, 387, 388, 389, 390, 391, 910, 911, 1705, 1706, 392, 680, 681, 682, 683, 606, 607, 2054, 827};
        turn_penalty = 27.22910222223687171;
        expected = 676.17778146822513463;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {1646, 1645, 1644, 927, 926, 925, 798, 734, 1782, 1781, 1780, 1792, 1791, 1790, 1796, 1795, 760, 759, 758, 757, 756, 755, 754, 753, 752, 751, 750, 749, 748, 747, 746, 745, 744, 743, 742, 768, 767, 766, 765, 764, 763, 741, 740, 739, 738, 737, 736, 735, 159, 560, 971, 970, 762, 555, 733, 575, 564, 265, 266, 685, 567, 568, 687, 1759, 256, 257, 195, 196, 1927, 74, 1968, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771, 1772, 1773, 1774, 879, 880, 1915, 1914, 1913, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 88, 87, 86, 85, 84, 1558, 1559};
        turn_penalty = 31.68914896056834252;
        expected = 738.38088499870298165;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
        path = {273, 1203, 1202, 1201, 1200, 1199, 272, 271, 449, 448, 1540, 1315, 270, 1325, 1324, 1323, 1322, 1328, 1327, 1326, 150, 1861, 1860, 1859, 1858, 1830, 1321, 1320, 1319, 1318, 992, 216, 1428, 1429, 1430, 1431, 1432, 1491, 1492, 1493, 1494, 32, 33, 34, 35, 36, 1841, 120, 123, 124, 125, 126, 127, 128, 1295, 1296, 133, 1284, 1751, 1752};
        turn_penalty = 38.78946586502576110;
        expected = 855.36806969410804413;
        actual = compute_path_travel_time(path, turn_penalty);
        CHECK(relative_error(expected, actual) < 0.001000000);
        
    } //compute_path_travel_time

} //path_cost_public

