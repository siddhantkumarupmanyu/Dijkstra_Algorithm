#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

#include "Edge.hpp"
#include "Node.hpp"
#include "catch_amalgamated.hpp"

inline void assertEqualEdgeVector(std::vector<Edge*>& expected, std::vector<Edge*>& actual) {
    REQUIRE(expected.size() == actual.size());

    for (int i = 0; i < actual.size(); i++) {
        REQUIRE(expected[i]->equals(actual[i]));
    }
}

inline void assertEqualNodeVector(std::vector<Node*>& expected, std::vector<Node*>& actual) {
    REQUIRE(expected.size() == actual.size());

    for (int i = 0; i < actual.size(); i++) {
        REQUIRE(expected[i]->equals(actual[i]));
    }
}

#endif