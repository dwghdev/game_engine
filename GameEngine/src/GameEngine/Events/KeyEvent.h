#pragma once 

#include "Event.h"

namespace GameEngine {
  class GAME_ENGINE_API KeyEvent : public Event {
  public:
    inline int GetKeyCode() const { return m_KeyCode; }
    
    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

  protected:
    KeyEvent(int keycode) : m_KeyCode(keycode) {}
    int m_KeyCode;  
  };

  class GAME_ENGINE_API KeyDownEvent : public KeyEvent {
  public:
    KeyPressedEvent(int keycode, int repeatCount)
      : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
    
    inline int GetRepeatCount() const { return m_RepeatCount; }
    
    std::string ToString() const override { 
      std::stringstream ss;
      ss << "KeyDownEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyDown)

  private:
    int m_RepeatCount;
  };

  class GAME_ENGINE_API KeyUpEvent : public KeyEvent {
  public:
    KeyUpEvent(int keycode) : KeyEvent(keycode) {}

    std::string ToString() const override {
      std::stringstream ss; 
      ss << "KeyUpEvent: " << m_KeyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyUp)
  };
}
