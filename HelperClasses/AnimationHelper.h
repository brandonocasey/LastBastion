#pragma once

/**
 * Assign an array of sprite sheet ids to use as an animation at a certain speed
 */
class Animation
{
    // Set up everything that animation requires to run
    Animation(float speed, SpriteSheet* spritesheet, int sprite_ids[] )
    {
        m_fAnimationSpeed = speed;
        m_cSpriteSheet = spritesheet;
        for (int i = 0, length = sizeof(sprite_ids); i < length; ++i)
        {
            m_viSpriteIdStack.push_back(sprite_ids[i]);
        }
    }

    ~Animation()
    {
        // Clean our vector
        while( !m_viSpriteIdStack.empty() )
        {
            m_viSpriteIdStack.push_back();
        }
        // Release the pointer, because we might not want it dead yet
        SAFE_RELEASE(m_cSpriteSheet);

        m_fAnimationSpeed = 0.0;
    }

    void RunAnimation(SDL_Renderer* current_renderer, int x, int y)
    {
        for (std::vector<int>::iterator i = m_viSpriteIdStack.begin(); i != m_viSpriteIdStack.end(); ++i)
        {
            m_cSpriteSheet->Draw(current_renderer, i, x, y);
        }
    }
private:
    std::vector<int> m_viSpriteIdStack;
    SpriteSheet* m_cSpriteSheet;
    float m_fAnimationSpeed;
};
