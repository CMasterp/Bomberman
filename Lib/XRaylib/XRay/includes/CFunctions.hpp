/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** CFunctions
*/

#ifndef CHUNCTIONS_HPP_
#define CHUNCTIONS_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <array>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class CFunctions {
public:
    /**
     * @brief Construct a new CFunctions object
     */
    CFunctions() = default;

    /**
     * @brief Destroy the CFunctions object
     */
    ~CFunctions() = default;

    /**
     * @brief This function use c functions to generate a pair of random integers
     *
     * @param limitOfFirst A size_t
     * @param limitOfSecond A size_t
     * @return std::pair<size_t, size_t>
     */
    static std::pair<size_t, size_t> generatePairOfRandomIntegers(size_t limitOfFirst, size_t limitOfSecond);

    /**
     * @brief generates a random number
     *
     * @param limit limit value
     * @return size_t the number generated
     */
    static size_t generateRandomInteger(size_t limit);

private:
};

#include "CFunctions.inl"

#endif /* !CHUNCTIONS_HPP_ */