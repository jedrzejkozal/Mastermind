#pragma once

#include <memory>

#include "IAlleles.hpp"
#include "IMutationStrategy.hpp"

class Individual
{
public:
    Individual(unsigned allelesSize);
    Individual(std::shared_ptr<IAlleles> allelesArg);
    Individual(const Individual &lhs);

    void mutate(IMutationStrategy &mutation);
    void cross(Individual &lhs, const unsigned &crossingSpot);

    std::shared_ptr<IAlleles> alleles;

private:
    template <typename IteratorType>
    void moveBeginIteratorToCrossingPoint(IteratorType &beginIterator, unsigned crossingPoint);
};

template <typename IteratorType>
void Individual::moveBeginIteratorToCrossingPoint(IteratorType &beginIterator, unsigned crossingPoint)
{
    while (crossingPoint > 0)
    {
        beginIterator++;
        crossingPoint--;
    }
}
