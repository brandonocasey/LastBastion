#pragma once
#include "../Classes/GameEngine.h"


class BaseObject
{
public:
    virtual void CheckAlive() = 0;
    virtual void Draw(GameEngine* game, int x, int y) = 0;
    virtual void Update(GameEngine* game, int x, int y) = 0;
    void Attack(BaseObject* thing_to_attack)
    {
        thing_to_attack->Defend(m_iAttack, m_eElementType);
    }
    void Defend(int attack_damage, ElementType element_type)
    {
        float damage_modifier = CheckElementDamageModifier(element_type);

       // m_iCurrentHealth-= (attack_damage*damage_modifier)-m_iDefense;
    }
    float CheckElementDamageModifier( ElementType element_type, bool defense = true)
    {
        float normal_damage = 1.0;
        float weak_against_damage = 2.0;
        float strong_against_damage = 0.5;

        // Water > Fire
        if( m_eElementType == Water && element_type == Fire )
        {
           // return more_damage;
        }

        // Water < Fire
        if( m_eElementType == Fire && element_type == Water )
        {
            //return less_damage;
        }

        // Fire > Air
        if( m_eElementType == Fire && element_type == Air )
        {
           // return more_damage;
        }

        // Air < Fire
        if( m_eElementType == Air && element_type == Fire )
        {
            //return less_damage;
        }

        return normal_damage;
    }

private:
    int m_iDefense;
    int m_iAttack;
    int m_iCurrentHealth;
    int m_iTotalHealth;
    bool m_bVisible;
    ElementType m_eElementType;
};
