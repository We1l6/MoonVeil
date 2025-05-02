#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <cstring>

class Button
{
  public:
    Button(const char *text,
           Rectangle bounds,
           Color color,
           Color hoverColor,
           Color textColor);
    ~Button();

    void Update();
    void Draw() const;
    bool IsClicked() const;
    bool IsHovered() const;

    void SetText(const char *text);
    void SetPosition(Vector2 position);
    void SetSize(Vector2 size);

  private:
    const char *m_text;
    Rectangle m_bounds;
    Color m_color;
    Color m_hoverColor;
    Color m_textColor;
    bool m_isHovered;
};

#endif // BUTTON_H