//
// Created by Eric Mandolesi on 17/11/2019.
//

#ifndef MTMCMC_TEST_MTTENSOR_H
#define MTMCMC_TEST_MTTENSOR_H

#include <complex>
#include <math.h>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/complex.hpp>
#include <array>

typedef std::complex<double> MTComplex;

struct MTTensor {

    MTComplex xx, xy, yx, yy;

//    MTTensor(){xx=nan("");xy=nan("");yx=nan("");yy=nan("");};
    MTTensor() {
        xx = 0;
        xy = 0;
        yx = 0;
        yy = 0;
    };

    MTTensor(const MTComplex &xx,
             const MTComplex &xy,
             const MTComplex &yx,
             const MTComplex &yy) : xx(xx), xy(xy),
                                    yx(yx),
                                    yy(yy) {}

    MTTensor operator+(const MTTensor &rhs) const;
    MTTensor operator-(const MTTensor &rhs) const;
    MTTensor operator*(double const &rhs) const;
    MTTensor dot_times(const MTTensor &rhs) const;
    MTTensor dot_divide(const MTTensor &rhs) const;
    MTTensor dot_atomic_minus(const MTTensor &rhs) const;
    MTTensor dot_atomic_divide(const MTTensor &rhs) const;
    MTTensor dot_square() const;
    MTTensor dot_atomic_square() const;
    MTTensor dot_sqrt() const;
    MTTensor dot_log() const;
    MTTensor dot_atomic_log() const;
    double maxAbsImpedance() const;
    double meanAbsImpedance() const;

    /**
     *
     * @return (double) sum of real and imaginary parts of the complex tensor elements
     */
    [[gnu::pure]] double reduce() const noexcept;

    MTTensor rot_z(double beta_rad) const;
    friend std::ostream &operator<<(std::ostream &os, const MTTensor &tensor){
        os << "xx: " << tensor.xx << "; xy: " << tensor.xy << "; yx: " << tensor.yx << "; yy: " << tensor.yy;
        return os;
    };
private:
    friend boost::serialization::access;
    template<typename Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & xx;
        ar & xy;
        ar & yx;
        ar & yy;
    }

};

MTTensor abs(MTTensor const &z);
MTTensor dot_abs(MTTensor const &z);
#endif //MTMCMC_TEST_MTTENSOR_H
