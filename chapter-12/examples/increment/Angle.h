#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>

class Angle
{
private:
    double angle;

public:
    explicit Angle(double value) : angle {value}
    {
#ifdef DEBUG
        std::cout << "Constructor called"
#endif
    };

    ~Angle() = default;

    inline Angle& operator++()
    {
        ++this->angle;
        if (this->angle >= 360)
        {
            this->angle -= 360;
        }
        return *this;
    }

    inline const Angle operator++(int)
    {
        Angle copy {*this};
        ++(*this);
        return copy;
    }

    inline Angle& operator--()
    {
        --this->angle;
        if (this->angle < 0)
        {
            this->angle += 360;
        }
        return *this;
    }

    inline const Angle operator--(int)
    {
        Angle copy {*this};
        --(*this);
        return copy;
    }

    inline std::ostream& write(std::ostream& stream) const
    {
        stream << this->angle;
        return stream;
    }
};

inline std::ostream& operator<<(std::ostream& stream, const Angle& a)
{
    a.write(stream);
    return stream;
}

#endif