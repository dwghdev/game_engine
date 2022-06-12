#pragma once

namespace GameEngine {

  class __declspec(dllexport) Application {
  public:
    Application();
    virtual ~Application();
    void Run();
  };

  // TODO: To be defined in CLIENT
  Application* CreateApplication();
}
