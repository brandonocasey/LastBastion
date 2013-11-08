#pragma once

#include "../Utils.h"
#include "BaseMovingObject.h"

class BaseMonster : public BaseMovingObject
{
public:
    bool TakeDamage(int attack_damage, ElementType element_type);
    BaseMonster();
    ~BaseMonster();

    /* data */
};
