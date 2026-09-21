#include <cstddef>  // size_t
#include <vector>
#include <list>
#include <random>
#include <iostream>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    std::vector<uint64_t> vector1_forward;
    std::vector<uint64_t> vector2_reserve;
    vector2_reserve.reserve(SIZE);
    std::list<uint64_t> list1;

    std::mt19937_64 rng(0);

    Timer timer;

    for (size_t i = 0; i < SIZE; i++)
    {
        vector1_forward.push_back(rng());
    }
    uint64_t vector_fwdTime = timer.glance<Timer::Micros>();

    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; i++)
    {
        list1.push_back(rng());
    }
    uint64_t list_Time = timer.glance<Timer::Micros>();

    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i < SIZE; i++)
    {
        vector2_reserve.push_back(rng());
    }
    uint64_t vector_rsvTime = timer.glance<Timer::Micros>();

    std::cout << "\n";
    std::cout << "Vector (normal) took " << vector_fwdTime << " microseconds to complete. \n";
    std::cout << "Vector (reserve) took " << vector_rsvTime << " microseconds to complete. \n";
    std::cout << "List (normal) took " << list_Time << " microseconds to complete. \n";
    std::cout << "\n";

    uint64_t sum = 0;
    timer.restart();
    while (!vector1_forward.empty())
    {
        sum += vector1_forward.back();
        vector1_forward.pop_back();
    }
    vector_fwdTime = timer.glance<Timer::Micros>();

    sum = 0;
    timer.restart();
    while (!list1.empty())
    {
        sum += list1.back();
        list1.pop_back();
    }
    list_Time = timer.glance<Timer::Micros>();

    sum = 0;
    timer.restart();
    while (!vector2_reserve.empty())
    {
        sum += vector2_reserve.back();
        vector2_reserve.pop_back();
    }
    vector_rsvTime = timer.glance<Timer::Micros>();

    std::cout << "\n";
    std::cout << "Vector (normal) took " << vector_fwdTime << " microseconds to sum. \n";
    std::cout << "Vector (reserve) took " << vector_rsvTime << " microseconds to sum. \n";
    std::cout << "List (normal) took " << list_Time << " microseconds to sum. \n";
    std::cout << "\n";

    return 0;
}
