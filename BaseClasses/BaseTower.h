#pragma once
#include "../Utils.h"
#include "../BaseClasses/BaseMonster.h"

class BaseTower : public BaseObject
{
public:
    int attack_radius;
    int attack_cooldown;
    int towerx;
    int towery;
    int attack_damage;
    bool cooling_down;
    ElementType element_type;
    //void Update(std::vector monster_list)
    void Update();
    /*
    {
        if( ! cooling_down )
        {
            // Needs a loop that can have items taken from it
            // but will not loop forever
            for(BaseMonster* monster : monster_list)
            {
                // Radius Check
                if((monster.x - towerx)^2 + (monster.y - towery)^2 < attack_radius^2 )
                {
                    if( Attack(monster) )
                    {
                        //remove this monster from list
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
        }
        
        // Check if monster is in range
        // if so we use an attack and use an animation for this
    }
    */
    bool Attack(BaseMonster* monster)
    {
        bool dead = false;
        dead = monster->TakeDamage(attack_damage, element_type);
        return dead;
    }
};
