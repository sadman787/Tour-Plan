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


SUITE(simple_legality_london_england_public) {
    TEST(simple_legality_london_england) {
        std::vector<DeliveryInfo> deliveries;
        std::vector<unsigned> depots;
        std::vector<unsigned> result_path;
        float turn_penalty;
        
        deliveries = {DeliveryInfo(37205, 263120)};
        depots = {9};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(62334, 412105), DeliveryInfo(369072, 90509), DeliveryInfo(418914, 172565), DeliveryInfo(369072, 412105), DeliveryInfo(320808, 412105), DeliveryInfo(305578, 79748), DeliveryInfo(305578, 90509), DeliveryInfo(305578, 78336), DeliveryInfo(305578, 90509)};
        depots = {109050, 279160, 201880};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(36739, 79346), DeliveryInfo(269834, 253401)};
        depots = {97839, 341447};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(30357, 45804), DeliveryInfo(83915, 305741), DeliveryInfo(309150, 305741), DeliveryInfo(434912, 305741), DeliveryInfo(434912, 398678), DeliveryInfo(130724, 398678), DeliveryInfo(130724, 370756), DeliveryInfo(130724, 398678), DeliveryInfo(130724, 209487)};
        depots = {131581, 111893, 113141};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(330154, 377157), DeliveryInfo(291638, 15967), DeliveryInfo(226218, 363416), DeliveryInfo(430248, 177806), DeliveryInfo(270862, 177806), DeliveryInfo(321658, 395386), DeliveryInfo(400788, 377157), DeliveryInfo(82195, 377157)};
        depots = {134454, 98809, 357276};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(173019, 345568)};
        depots = {134964, 225290};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(207626, 295518), DeliveryInfo(55994, 196802), DeliveryInfo(240717, 178971), DeliveryInfo(175564, 270537), DeliveryInfo(91067, 325756)};
        depots = {145060, 156626, 133033};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(56354, 76362), DeliveryInfo(193298, 16320), DeliveryInfo(220595, 204516)};
        depots = {146512, 199426, 33349};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(73637, 343119), DeliveryInfo(239806, 391028), DeliveryInfo(396991, 318149), DeliveryInfo(326257, 140677), DeliveryInfo(359241, 63548)};
        depots = {215409, 141111, 295673};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(174147, 115033)};
        depots = {225326};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(417252, 14965), DeliveryInfo(138981, 365443), DeliveryInfo(309467, 144381), DeliveryInfo(192566, 365443), DeliveryInfo(321635, 158399), DeliveryInfo(427859, 144381), DeliveryInfo(88883, 144381), DeliveryInfo(21644, 384888)};
        depots = {233999, 78221, 228140};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(212011, 97371), DeliveryInfo(212011, 90214), DeliveryInfo(50321, 264527), DeliveryInfo(212011, 250051), DeliveryInfo(106775, 290831), DeliveryInfo(74443, 305409), DeliveryInfo(321636, 3174), DeliveryInfo(321636, 203677)};
        depots = {236554, 18641, 240639};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(29185, 364347), DeliveryInfo(170548, 83511), DeliveryInfo(72369, 419409)};
        depots = {253346, 294956, 40871};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(215440, 338157), DeliveryInfo(31355, 83947)};
        depots = {262331, 369695};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(92726, 322295), DeliveryInfo(94292, 244979), DeliveryInfo(252979, 73210), DeliveryInfo(329392, 78142), DeliveryInfo(345765, 186347)};
        depots = {322105, 103778, 22137};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(180262, 397682), DeliveryInfo(434180, 252490), DeliveryInfo(71723, 305636)};
        depots = {323484, 137447, 192014};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(39181, 245197), DeliveryInfo(254753, 354223)};
        depots = {325322};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(423526, 82998)};
        depots = {390122};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(72069, 375410)};
        depots = {394464, 420716};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(409651, 181426)};
        depots = {396787, 128650};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(103268, 350877), DeliveryInfo(132801, 27845), DeliveryInfo(421995, 429925), DeliveryInfo(401426, 24593), DeliveryInfo(97228, 429925), DeliveryInfo(268562, 27845), DeliveryInfo(196267, 27845), DeliveryInfo(190923, 430464)};
        depots = {398800, 135646, 347184};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(362481, 341466), DeliveryInfo(233016, 346812), DeliveryInfo(233016, 256112), DeliveryInfo(399275, 342877), DeliveryInfo(4116, 66908), DeliveryInfo(347579, 250304), DeliveryInfo(233016, 416734), DeliveryInfo(362481, 64561)};
        depots = {329515, 303043, 139599};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(223898, 383569), DeliveryInfo(435396, 317752)};
        depots = {258992};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(106147, 177568), DeliveryInfo(286278, 321867), DeliveryInfo(411382, 183015), DeliveryInfo(260890, 402685), DeliveryInfo(395480, 50953)};
        depots = {421820, 425343, 288395};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(170276, 112668), DeliveryInfo(190154, 239093), DeliveryInfo(80188, 336095), DeliveryInfo(80188, 112668), DeliveryInfo(61822, 239093), DeliveryInfo(170276, 239093), DeliveryInfo(80188, 267144), DeliveryInfo(358371, 85979), DeliveryInfo(80188, 112668)};
        depots = {172642, 110064, 203263};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(411354, 163445), DeliveryInfo(267293, 133242), DeliveryInfo(258123, 282130), DeliveryInfo(40770, 359960), DeliveryInfo(208198, 342506)};
        depots = {58385, 86160, 166467};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(295798, 419835), DeliveryInfo(7962, 189151), DeliveryInfo(233945, 126221), DeliveryInfo(410495, 257142), DeliveryInfo(165412, 255665)};
        depots = {10134, 20715, 165349};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(118890, 86612), DeliveryInfo(294317, 66027), DeliveryInfo(294317, 111580), DeliveryInfo(272264, 268674), DeliveryInfo(272264, 257149), DeliveryInfo(294317, 349573), DeliveryInfo(259485, 392327), DeliveryInfo(118348, 173430)};
        depots = {433524, 49689, 380946};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(259206, 40967), DeliveryInfo(266678, 189134)};
        depots = {301532, 238145};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
        deliveries = {DeliveryInfo(129996, 186417), DeliveryInfo(393573, 285718)};
        depots = {422938};
        turn_penalty = 15;
        result_path = traveling_courier(deliveries, depots, turn_penalty);
        CHECK(courier_path_is_legal(deliveries, depots, result_path));
        
    } //simple_legality_london_england

} //simple_legality_london_england_public

