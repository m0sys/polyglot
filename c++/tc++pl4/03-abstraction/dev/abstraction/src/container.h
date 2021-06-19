#pragma once

class Container {
public:
    virtual double& operator[](int) = 0; // pure virtual i.e. derived class must provide impl
    virtual int size() const = 0;
    virtual ~Container() { }
};
