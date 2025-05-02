#include "button.h"


Button::Button(const char *text,
               Rectangle bounds,
               Color color,
               Color hoverColor,
               Color textColor)
    : m_bounds(bounds),
      m_color(color),
      m_hoverColor(hoverColor),
      m_textColor(textColor)
{
    m_text = text;
    m_isHovered = false;
}

Button::~Button() {}

void Button::Update()
{
    Vector2 mousePos = GetMousePosition();
    m_isHovered = CheckCollisionPointRec(mousePos, m_bounds);
}

void Button::Draw() const
{
    DrawRectangleRec(m_bounds, m_isHovered ? m_hoverColor : m_color);

    int textWidth = MeasureText(m_text, 20);
    DrawText(m_text, m_bounds.x + m_bounds.width / 2 - textWidth / 2,
             m_bounds.y + m_bounds.height / 2 - 10, 20, m_textColor);
}

bool Button::IsClicked() const
{
    return m_isHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool Button::IsHovered() const { return m_isHovered; }

void Button::SetText(const char *text) { m_text = text; }

void Button::SetPosition(Vector2 position)
{
    m_bounds.x = position.x;
    m_bounds.y = position.y;
}

void Button::SetSize(Vector2 size)
{
    m_bounds.width = size.x;
    m_bounds.height = size.y;
}