#include <random>

void compact(std::vector<int> &_V, bool (*predicate) (int)) {
    auto iSlow(0ul);
    auto iFast(0ul);
    for(/* empty */ ; iFast < _V.size() ; ++iFast)
    {
        if(predicate(_V[iFast]))
            _V[iSlow++] = _V[iFast];
    }
    _V.resize(iSlow); // New vector size.
}


//Fill a vector with random numbers in the range [lower, upper]
void randomFill(std::vector<int> &V, const int lower, const int upper, const unsigned int seed)
{

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    // Fill up vector
    for(auto &elem : V)
        elem = distr(eng);
}