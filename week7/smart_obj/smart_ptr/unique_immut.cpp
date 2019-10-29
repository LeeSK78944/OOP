//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr
{
unique_immut::unique_immut()
{
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj)
{
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut)
{
    if (immut._mgr)
    {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut()
{
    release();
}

Object *unique_immut::get() const
{
    return _mgr->ptr;
}

void unique_immut::release()
{
    if (_mgr != nullptr)
        _mgr->~mgr();
    _mgr = new mgr();
}

unique_immut unique_immut::operator+(unique_immut &unique)
{
    auto val1 = get()->get();
    auto val2 = unique.get()->get();
    release();
    unique.release();
    return unique_immut(new Object(val1 + val2));
}

unique_immut unique_immut::operator-(unique_immut &unique)
{
    auto val1 = get()->get();
    auto val2 = unique.get()->get();
    release();
    unique.release();
    return unique_immut(new Object(val1 - val2));
}

unique_immut unique_immut::operator*(unique_immut &unique)
{
    auto val1 = get()->get();
    auto val2 = unique.get()->get();
    release();
    unique.release();
    return unique_immut(new Object(val1 * val2));
}

unique_immut unique_immut::operator/(unique_immut &unique)
{
    auto val1 = get()->get();
    auto val2 = unique.get()->get();
    release();
    unique.release();
    return unique_immut(new Object(val1 / val2));
}

Object *unique_immut::operator->()
{
    return _mgr->ptr;
}

unique_immut &unique_immut::operator=(unique_immut &r)
{
    if (_mgr != r._mgr)
    {
        release();
        _mgr = new mgr(r->get());
        r._mgr->ptr = nullptr;
    }
    return *this;
}
} // end of namespace ptr
