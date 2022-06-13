#include "gepch.h"
#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace GameEngine {
  Application::Application() { }
  Application::~Application() { }

  void Application::Run() {
    WindowResizeEvent e(1280, 720);

    if (e.IsInCategory(EventCategoryApplication))
      GE_INFO(e);
    
    if (e.IsInCategory(EventCategoryInput)) 
      GE_INFO(e);

    while(true);
  }
}
