#include "WindowsWindow.h"
#include <iostream>

namespace mini_engine {

	std::unique_ptr<mini_window> mini_window::Create(const window_properties& props) {
		return std::make_unique<WindowsWindow>(props);
	}

	WindowsWindow::WindowsWindow(const window_properties& windowProps) {
		init(windowProps);
	}
	void WindowsWindow::OnUpdate() {
		std::cout << "window on update()\n";
	}
	void WindowsWindow::OnDraw() {

	}
	void WindowsWindow::OnClose() {

	}
	bool WindowsWindow::init(const window_properties& windowProps) {
		m_data.height = windowProps.height;
		m_data.width = windowProps.width;
		m_data.title = windowProps.title;

		return true;
	}

}