#pragma once

#include <vector>

#include "../Individual.hpp"

template <typename IndividualType = Individual>
class ISelectionStrategy
{
public:
    virtual ~ISelectionStrategy() = default;

    virtual void select(std::vector<IndividualType> &population) = 0;
};