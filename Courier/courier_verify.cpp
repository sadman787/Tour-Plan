/* 
 * Copyright 2018 University of Toronto
 *
 * Permission is hereby granted, to use this software and associated 
 * documentation files (the "Software") in course work at the University 
 * of Toronto, or for personal use. Other uses are prohibited, in 
 * particular the distribution of the Software either publicly or to third 
 * parties.
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <map>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <map>
#include "StreetsDatabaseAPI.h"
#include "unit_test_util.h"

#include "courier_verify.h"

//Define this to get more information about every
//pick-up drop-off event
//#define DEBUG_PICK_UP_DROP_OFF

//
//
//
// File-scope function declarations
//
//
//

namespace ece297test {

} //namespace

//
//
//
// Function Implementations
//
//
//

namespace ece297test {

bool courier_path_is_legal(const std::vector<DeliveryInfo>& deliveries,
                           const std::vector<unsigned>& depots,
                           const std::vector<unsigned>& path) {

    //
    //Ensuree we have a valid problem specification
    //
    if(!valid_courier_problem(deliveries, depots)) {
        return false;
    }

    if (path.empty()) {
        //If it is a valid path it must contain at-least one segment
        //(since we gaurentee there is at-least one depot and delivery)
        std::cerr << "Invalid courier path: path was empty\n";

        return false; 

    } else {
        assert(!path.empty());

        //
        //Determine what our start intersection is (it must be a depot)
        //
        unsigned curr_intersection;
        if(!determine_start_intersection(path, depots, curr_intersection)) {
            return false;
        }

        //curr_intersection must be a depot
        assert(is_depot(depots, curr_intersection));


        //We store whether each delivery has been picked-up or dropped-off
        std::vector<bool> deliveries_picked_up(deliveries.size(), false);
        std::vector<bool> deliveries_dropped_off(deliveries.size(), false);

        //We also build fast-lookups from: intersection id to DeliveryInfo index for both
        //pickUp and dropOff intersections
        std::multimap<unsigned,size_t> intersections_to_pick_up; //Intersection_ID -> deliveries index
        std::multimap<unsigned,size_t> intersections_to_drop_off; //Intersection_ID -> deliveries index

        //Load the look-ups
        for(size_t delivery_idx = 0; delivery_idx < deliveries.size(); ++delivery_idx) {
            unsigned pick_up_intersection = deliveries[delivery_idx].pickUp;
            unsigned drop_off_intersection = deliveries[delivery_idx].dropOff;

            intersections_to_pick_up.insert(std::make_pair(pick_up_intersection, delivery_idx));
            intersections_to_drop_off.insert(std::make_pair(drop_off_intersection, delivery_idx));
        }

        //We verify the path by walking along each segment and:
        //  * Checking that the next step along the path is valid (see traverse_segment())
        //  * Recording any package pick-ups (see pick_up_at_intersection())
        //  * Recording any package drop-offs (see drop_off_at_intersection())
        for (size_t path_idx = 0; path_idx < path.size(); ++path_idx) {

            unsigned next_intersection; //Set by traverse_segment

            if(!traverse_segment(path, path_idx, curr_intersection, next_intersection)) {
                return false;
            }

            //Process packages
            pick_up_at_intersection(deliveries, 
                                    intersections_to_pick_up, 
                                    curr_intersection, 
                                    deliveries_picked_up);

            drop_off_at_intersection(deliveries,
                                     intersections_to_drop_off, 
                                     deliveries_picked_up,
                                     curr_intersection, 
                                     deliveries_dropped_off);

            //Advance
            curr_intersection = next_intersection;
        }

        //
        //We should be at a depot
        //
        if (!is_depot(depots, curr_intersection)) {
            //Not at a valid end intersection
            std::cerr << "Invalid courier path: Last path segment did not end at a depot (ended at intersection " << curr_intersection << ")\n";
            return false;
        }

        //
        //Check everything was delivered
        //
        if(!delivered_all_packages(deliveries, deliveries_picked_up, deliveries_dropped_off)) {
            return false;
        }

    }

    //Everything validated
    return true;

}

bool valid_courier_problem(const std::vector<DeliveryInfo>& deliveries_vec,
                           const std::vector<unsigned>& depots_vec) {
    if(deliveries_vec.empty()) {
        std::cerr << "Invalid courier problem: Must have at-least one delivery" << "\n";
        return false;
    }

    if(depots_vec.empty()) {
        std::cerr << "Invalid courier problem: Must have at-least one depot" << "\n";
        return false;
    }

    // Check for duplicates amoung:
    //   * Pick-Ups and depots
    //   * Drop-Offs and depots

    std::vector<unsigned> depots = depots_vec; //Copy since we need to sort the depots

    std::vector<unsigned> delivery_pick_ups;
    std::vector<unsigned> delivery_drop_offs;

    for(const DeliveryInfo& info : deliveries_vec) {
        delivery_pick_ups.push_back(info.pickUp);
        delivery_drop_offs.push_back(info.dropOff);
    }

    //Sort all the ids so we can quickly find the set intersections
    std::sort(delivery_pick_ups.begin(), delivery_pick_ups.end());
    std::sort(delivery_drop_offs.begin(), delivery_drop_offs.end());
    std::sort(depots.begin(), depots.end());

    //Verify that there are is not commonality between:
    //  * pick_ups and depots
    //  * drop_offs and depots
    //
    // Note: we allow duplicates between pick_ups and drop_offs
    std::vector<unsigned> common_pick_up_depots;
    std::vector<unsigned> common_drop_off_depots;

    //Common between pick-ups and depots
    std::set_intersection(delivery_pick_ups.begin(), delivery_pick_ups.end(),
                          depots.begin(), depots.end(),
                          std::back_inserter(common_pick_up_depots));
    
    //Common between drop-offs and depots
    std::set_intersection(delivery_drop_offs.begin(), delivery_drop_offs.end(),
                          depots.begin(), depots.end(),
                          std::back_inserter(common_drop_off_depots));

    if(!common_pick_up_depots.empty()) {
        std::cerr << "Invalid Courier Problem: common pick-up and depot itersections " << common_pick_up_depots << "\n";
        return false;
    }

    if(!common_drop_off_depots.empty()) {
        std::cerr << "Invalid Courier Problem: common drop-off and depot itersections " << common_drop_off_depots << "\n";
        return false;
    }

    //
    //Sanity check on id bounds
    //
    //Since vectors are sorted, can just query first and last elements
    assert(*(--depots.end()) <= getNumberOfIntersections());
    assert(*(--delivery_pick_ups.end()) <= getNumberOfIntersections());
    assert(*(--delivery_drop_offs.end()) <= getNumberOfIntersections());

    return true;
}

bool determine_start_intersection(const std::vector<unsigned>& path,
                                  const std::vector<unsigned>& depots,
                                  unsigned& start_intersection) {
    assert(path.size() > 0);

    StreetSegmentInfo first_seg = getStreetSegmentInfo(path[0]);

    //Look for the from and to in the depot list
    auto to_iter = std::find(depots.begin(), depots.end(), first_seg.to);
    auto from_iter = std::find(depots.begin(), depots.end(), first_seg.from);

    //Initilize the current intersection
    if(to_iter != depots.end() && from_iter == depots.end()) {

        //To is exclusively a depot
        start_intersection = *to_iter;

    } else if(to_iter == depots.end() && from_iter != depots.end()) {

        //From is exclusivley a depot
        start_intersection = *from_iter;

    } else if(to_iter != depots.end() && from_iter != depots.end()) {
        //Both to and from are depots.
        //
        //This is the unlikely case where two depots are adjacent, and the student
        //returns the single segment joining them as the first element of the path.
        if(path.size() == 1) {
            //If we have a path consisting of only a single segment
            //we only need to take care when the segment is a one-way (i.e.
            //we should pick the start intersection to not violate the one-way)
            //
            //If it is not a one-way, we can pick an arbitrary start intersection.
            //
            //As a result we always pick the 'from' intersection as the start, as this
            //is gaurnteed to be correct for a one-way segment
            start_intersection = *from_iter;

        } else {
            //Multiple segments
            //
            //We can determine the start intersection by identify the common 
            //intersection between the two segments.
            assert(path.size() > 1);

            StreetSegmentInfo second_seg = getStreetSegmentInfo(path[1]);

            if(first_seg.to == second_seg.to || first_seg.to == second_seg.from) {
                //first_seg to connects to the second seg via it's 'to' intersection
                start_intersection = first_seg.from;
            } else {
                assert(first_seg.from == second_seg.to || first_seg.from == second_seg.from);

                //first_seg to connects to the second seg via it's 'from' intersection
                start_intersection = first_seg.to;
            }
        }

    } else {
        assert(to_iter == depots.end() && from_iter == depots.end());

        //Neither 'to' nor 'from' are depots
        std::cerr << "Invalid courier path: first path segment not connected to a depot\n";
        return false;
    }
#ifdef DEBUG_PICK_UP_DROP_OFF
    std::cout << "Starting at depot " <<  start_intersection << std::endl;
#endif
    return true;
}

bool is_depot(const std::vector<unsigned>& depots,
              const unsigned intersection_id) {

    auto iter = std::find(depots.begin(), depots.end(), intersection_id);

    return (iter != depots.end());
}

bool traverse_segment(const std::vector<unsigned>& path,
                      const unsigned path_idx,
                      const unsigned curr_intersection,
                      unsigned& next_intersection) {
    assert(path_idx < path.size());

    StreetSegmentInfo seg_info = getStreetSegmentInfo(path[path_idx]);

    //
    //Are we moving forward or back along the segment?
    //
    bool seg_traverse_forward;
    if (seg_info.from == curr_intersection) {
        //We take care to check 'from' first. This ensures
        //we get a reasonable traversal direction even in the 
        //case of a self-looping one-way segment

        //Moving forwards
        seg_traverse_forward = true;

    } else if (seg_info.to == curr_intersection) {
        //Moving backwards
        seg_traverse_forward = false;

    } else {
        assert(seg_info.from != curr_intersection && seg_info.to != curr_intersection);

        //This segment isn't connected to the current intersection
        std::cerr << "Invalid courier path: path disconnected"
                  << " (intersection " << curr_intersection 
                  << " does not connect to street segment " << path[path_idx] 
                  << " at path index " << path_idx << ")\n";
        return false;
    }

    //
    //Are we going the wrong way along the segment?
    //
    if (!seg_traverse_forward && seg_info.oneWay) {
        std::cerr << "Invalid courier path: Attempting to traverse against one-way"
                  << " (from intersection " << curr_intersection 
                  << " along street segment " << path[path_idx] 
                  << " at path index " << path_idx << ")\n";
        return false;
    }

    //
    //Advance to the next intersection
    //
    next_intersection = (seg_traverse_forward) ? seg_info.to : seg_info.from;

    return true;
}

void pick_up_at_intersection(const std::vector<DeliveryInfo>& /*deliveries*/,
                             const std::multimap<unsigned,size_t>& intersections_to_pick_up,
                             const unsigned curr_intersection,
                             std::vector<bool>& deliveries_picked_up) {
    //
    //Check if we are picking up packages
    //

    //Find all the deliveries picking-up from this intersection
    auto range_pair = intersections_to_pick_up.equal_range(curr_intersection);

    //Mark each delivery as picked-up
    for(auto key_value_iter = range_pair.first; key_value_iter != range_pair.second; ++key_value_iter) {
        size_t delivery_idx = key_value_iter->second; 

        deliveries_picked_up[delivery_idx] = true;

#ifdef DEBUG_PICK_UP_DROP_OFF
        std::cerr << "Info: Picked-up package for delivery " << delivery_idx
                  << " at intersection " << curr_intersection << "\n";
#endif

    }
}

void drop_off_at_intersection(const std::vector<DeliveryInfo>& /*deliveries*/,
                              const std::multimap<unsigned,size_t>& intersections_to_drop_off,
                              const std::vector<bool>& deliveries_picked_up,
                              const unsigned curr_intersection,
                              std::vector<bool>& deliveries_dropped_off) {
    //
    //Check if we are dropping-off packages
    //

    //Find all the deliveries dropping-off to this intersection
    auto range_pair = intersections_to_drop_off.equal_range(curr_intersection);

    //Mark each delivery dropped-off
    for(auto key_value_iter = range_pair.first; key_value_iter != range_pair.second; ++key_value_iter) {
        size_t delivery_idx = key_value_iter->second; 

        if(deliveries_picked_up[delivery_idx]) {
            //Can only drop-off if the delivery was already picked-up
            deliveries_dropped_off[delivery_idx] = true;

#ifdef DEBUG_PICK_UP_DROP_OFF
            std::cerr << "Info: Dropped-off package for delivery " << delivery_idx
                      << " at intersection " << curr_intersection << "\n";
        } else {
            std::cerr << "Info: Did not drop-off package for delivery " << delivery_idx
                      << " at intersection " << curr_intersection 
                      << " since it has not been picked-up" << "\n";
#endif

        }
    }
}


bool delivered_all_packages(const std::vector<DeliveryInfo>& deliveries,
                            const std::vector<bool>& deliveries_picked_up,
                            const std::vector<bool>& deliveries_dropped_off) {

    //
    //Check how many undelivered packages there are
    //
    size_t undelivered_packages = 0;
    for(size_t delivery_idx = 0; delivery_idx < deliveries.size(); ++delivery_idx) {
        if(!deliveries_dropped_off[delivery_idx]) {
            ++undelivered_packages;
        } else {
            //If it was dropped-off it must have been picked-up
            assert(deliveries_picked_up[delivery_idx]);
        }
    }

    //
    //Report to the user the missing packages
    //
    if(undelivered_packages > 0) {
        std::cerr << "Invalid courier path: " << undelivered_packages << " packages were never delivered:\n";

        for(size_t delivery_idx = 0; delivery_idx < deliveries.size(); ++delivery_idx) {
            //Un-picked up
            if(!deliveries_picked_up[delivery_idx]) {
                std::cerr << "\tDelivery " << delivery_idx
                          << " was never picked-up at intersection " << deliveries[delivery_idx].pickUp
                          << "\n";
            }

            //Un-delivered up
            if(!deliveries_dropped_off[delivery_idx]) {
                std::cerr << "\tDelivery " << delivery_idx
                          << " was never dropped-off at intersection " << deliveries[delivery_idx].dropOff
                          << "\n";
            }
        }

        //Some un-delivered
        return false;
    }

    //All delivered
    return true;
}


} //namespace
