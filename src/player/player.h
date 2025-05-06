#ifndef PLAYER_H
#define PLAYER_H

#include "../abilities/defaultAttack/defaultAttack.h"
#include "../entity/entity.h"
#include "../resourceManager/resourceManager.h"
#include "../tileMap/tileMap.h"
#include "raylib.h"
#include <vector>


struct Spell
{
    float cooldown;
    float currentCooldown = 0.0f;
    bool isActive = false;
    std::function<void()> action;

    void Update(float deltaTime)
    {
        if (isActive)
        {
            currentCooldown -= deltaTime;
            if (currentCooldown <= 0.0f)
            {
                isActive = false;
                currentCooldown = 0.0f;
            }
        }
    }

    bool Cast()
    {
        if (!isActive && action)
        {
            action();
            currentCooldown = cooldown;
            isActive = true;
            return true;
        }
        return false;
    }
};

class Player : public Entity
{
  protected:
    Spell m_firstSpell;
    Spell m_secondSpell;
    Spell m_thirdSpell;

    virtual void firstSpell() = 0;
    virtual void secondSpell() = 0;
    virtual void thirdSpell() = 0;

  private:
    float m_attackCooldown = 0.0f;
    const float ATTACK_COOLDOWN_TIME = 0.5f;
    void Attack();
    int m_currentAttackFrame = 0;
    bool m_isAttackAnimationPlaying = false;

  public:
    Player(TileMap &tilemap,
           ObjectAttributes &&objectAttributes,
           FrameAtributes &&frameAtributes,
           float hitPoints,
           std::vector<std::shared_ptr<Ability>> &gameObjects,
           Texture2D spellsTexture);

    Texture2D m_spellsTexture;
    virtual ~Player() = default;
    virtual void HandleInput(float deltaTime);
    void Update(float deltaTime) override;
    void Draw(const Camera2D &camera) const;
    int m_remainingAbilitiesByArea = 3;
    int m_level = 1;
    int m_levelBarWidth = 0;
    float getFirstSpellСurrCooldown() const
    {
        return m_firstSpell.currentCooldown;
    }
    float getSecondSpellСurrCooldown() const
    {
        return m_secondSpell.currentCooldown;
    }
    float getThirdSpellСurrCooldown() const
    {
        return m_thirdSpell.currentCooldown;
    }
    void addLevelBarWidth(int width);
};


#endif // PLAYER_H