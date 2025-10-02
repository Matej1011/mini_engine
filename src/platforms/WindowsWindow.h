
#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "../../core/mini_window.h"

namespace mini_engine {
	class WindowsWindow : public mini_window {

	public:
		WindowsWindow(const window_properties& windowProps);
		WindowsWindow(const WindowsWindow&) = delete;
		WindowsWindow& operator=(const WindowsWindow&) = delete;
		virtual ~WindowsWindow() {}
		
		virtual void OnUpdate()override;
		virtual void OnDraw() override;
		virtual void OnClose() override;

		virtual uint32_t GetWidth() const override { return m_data.width; };
		virtual uint32_t GetHeight() const override { return m_data.height; };
	private:
		bool init(const window_properties& windowProps);
	private:

		struct window_data {
			const char* title;
			uint32_t width, height;
		}m_data;

	};
}

#endif