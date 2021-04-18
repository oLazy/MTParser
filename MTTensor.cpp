//
// Created by Eric Mandolesi on 17/11/2019.
//

#include "MTTensor.h"
#include <array>
#include<algorithm>
MTTensor MTTensor::operator+(MTTensor const &rhs) const{
    return {{this->xx + rhs.xx},
            {this->xy + rhs.xy},
            {this->yx + rhs.yx},
            {this->yy + rhs.yy}};
}
MTTensor MTTensor::operator-(const MTTensor &rhs) const{
    return {{this->xx - rhs.xx},
            {this->xy - rhs.xy},
            {this->yx - rhs.yx},
            {this->yy - rhs.yy}};
}
MTTensor MTTensor::operator*(double const &rhs) const{
    return {{this->xx*rhs},
            {this->xy*rhs},
            {this->yx*rhs},
            {this->yy*rhs}};
}
MTTensor MTTensor::dot_times(const MTTensor &rhs) const {
    return {{this->xx * rhs.xx},
            {this->xy * rhs.xy},
            {this->yx * rhs.yx},
            {this->yy * rhs.yy}};
}
MTTensor MTTensor::dot_divide(const MTTensor &rhs) const {
    return {{this->xx / rhs.xx},
            {this->xy / rhs.xy},
            {this->yx / rhs.yx},
            {this->yy / rhs.yy}};
}
MTTensor MTTensor::dot_atomic_minus(const MTTensor &rhs) const {
    return {
            {(std::real(this->xx) - std::real(rhs.xx)), (std::imag(this->xx) - std::imag(rhs.xx))},
            {(std::real(this->xy) - std::real(rhs.xy)), (std::imag(this->xy) - std::imag(rhs.xy))},
            {(std::real(this->yx) - std::real(rhs.yx)), (std::imag(this->yx) - std::imag(rhs.yx))},
            {(std::real(this->yy) - std::real(rhs.yy)), (std::imag(this->yy) - std::imag(rhs.yy))}
    };
}
MTTensor MTTensor::dot_square() const {
    return {{this->xx * this->xx},
            {this->xy * this->xy},
            {this->yx * this->yx},
            {this->yy * this->yy}};
}
MTTensor MTTensor::dot_atomic_square() const {
    return {
            {std::pow(std::real(this->xx), 2), std::pow(std::imag(this->xx), 2)},
            {std::pow(std::real(this->xy), 2), std::pow(std::imag(this->xy), 2)},
            {std::pow(std::real(this->yx), 2), std::pow(std::imag(this->yx), 2)},
            {std::pow(std::real(this->yy), 2), std::pow(std::imag(this->yy), 2)}
    };
}
MTTensor MTTensor::dot_sqrt() const {
    return {{std::sqrt(this->xx)},
            {std::sqrt(this->xy)},
            {std::sqrt(this->yx)},
            {std::sqrt(this->yy)}};
}
MTTensor MTTensor::dot_log() const {
    return {{std::log(this->xx)},
            {std::log(this->xy)},
            {std::log(this->yx)},
            {std::log(this->yy)}};
}
MTTensor MTTensor::dot_atomic_log() const {
    return {
            {std::log(std::real(this->xx)), std::log(std::imag(this->xx))},
            {std::log(std::real(this->xy)), std::log(std::imag(this->xy))},
            {std::log(std::real(this->yx)), std::log(std::imag(this->yx))},
            {std::log(std::real(this->yy)), std::log(std::imag(this->yy))}
    };
}
MTTensor MTTensor::rot_z(double beta_rad) const {
    if (std::isnan(beta_rad)) beta_rad = 0.;
    MTTensor result;
    double co2 = cos(2.*beta_rad);
    double si2 = sin(2.*beta_rad);

    MTComplex sum1 = xx+yy;
    MTComplex sum2 = xy+yx;

    MTComplex dif1 = xx-yy;
    MTComplex dif2 = xy-yx;

    result.xx = 0.5*(sum1+dif1*co2+sum2*si2);
    result.xy = 0.5*(dif2+sum2*co2-dif1*si2);
    result.yx = 0.5*(-dif2+sum2*co2-dif1*si2);
    result.yy = 0.5*(sum1-dif1*co2-sum2*si2);
    return result;
}

/**
 *
 * @return (double) sum of real and imaginary parts of the complex tensor elements
 */
[[gnu::pure]] double MTTensor::reduce() const noexcept {
    return
            std::real(this->xx) + std::imag(this->xx) +
            std::real(this->xy) + std::imag(this->xy) +
            std::real(this->yx) + std::imag(this->yx) +
            std::real(this->yy) + std::imag(this->yy);
}

MTTensor MTTensor::dot_atomic_divide(const MTTensor &rhs) const {
    return MTTensor({std::real(xx)/std::real(rhs.xx), std::imag(xx)/std::imag(rhs.xx)},
                    {std::real(xy)/std::real(rhs.xy), std::imag(xy)/std::imag(rhs.xy)},
                    {std::real(yx)/std::real(rhs.yx), std::imag(yx)/std::imag(rhs.yx)},
                    {std::real(yy)/std::real(rhs.yy), std::imag(yy)/std::imag(rhs.yy)});
}

double MTTensor::maxAbsImpedance() const {
    std::array<double,4> absZ({std::abs(xx), std::abs(xy), std::abs(yx), std::abs(yy)});
    double res = *(std::max_element(absZ.begin(), absZ.end()));
    return res;
};

double MTTensor::meanAbsImpedance() const {
    double axx = std::abs(xx);
    double axy = std::abs(xy);
    double ayx = std::abs(yx);
    double ayy = std::abs(yy);
    return 0.25*(axx+axy+ayx+ayy);

}

MTTensor abs(MTTensor const &z) {
    return MTTensor({std::abs(z.xx),std::abs(z.xx)},
                    {std::abs(z.xy),std::abs(z.xy)},
                    {std::abs(z.yx),std::abs(z.yx)},
                    {std::abs(z.yy),std::abs(z.yy)});
}

MTTensor dot_abs(MTTensor const &z) {
    return MTTensor({std::abs(std::real(z.xx)),std::abs(std::imag(z.xx))},
                    {std::abs(std::real(z.xy)),std::abs(std::imag(z.xy))},
                    {std::abs(std::real(z.yx)),std::abs(std::imag(z.yx))},
                    {std::abs(std::real(z.yy)),std::abs(std::imag(z.yy))});
}

//double MTTensor::maxAbsImpedance() const {
//    std::array<double,4> absZ({std::abs(xx), std::abs(xy), std::abs(yx), std::abs(yy)});
//    return *(std::max_element(absZ.begin(), absZ.end()));
//}
