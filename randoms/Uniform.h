#pragma once

#include <vector>
#include <random>

using namespace std;

namespace randoms
{
    class Uniform
    {
    public:
        static vector<double> get(const double left, const double right, const uint64_t count) noexcept
        {
            vector<double> result;
            result.reserve(count);
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_real_distribution<> dis(left, right);
            for (uint64_t n = 0; n < count; ++n)
            {
                result.emplace_back(dis(gen));
            }
            return result;
        }
    };

} // namespace randoms