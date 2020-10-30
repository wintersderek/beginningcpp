#pragma once
#ifndef VESSEL_H
#define VESSEL_H

class Vessel
{
public:
    virtual ~Vessel() = default;
    virtual double volume() const = 0;
};
#endif