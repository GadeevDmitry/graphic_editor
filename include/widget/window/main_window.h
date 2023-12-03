#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "widget/window.h"
#include "widget/menu/main_window_menu.h"

//==================================================================================================

namespace host
{
    class HostWidgetI;
}

class main_window_t: public window_t
{
// static
public:
    static const double main_menu_height;

// member functions
public:
    explicit main_window_t(window_controller_t &controller,                               tool_manager_t &tool_manager, filter_manager_t &filter_manager, const color_t &color, const char *wnd_name);
    explicit main_window_t(window_controller_t &controller, const rectangle_t &enclosing, tool_manager_t &tool_manager, filter_manager_t &filter_manager, const color_t &color, const char *wnd_name);

    void inline set_filters(FilterI *brightness);
    void inline set_tools  (ToolI *fill  , ToolI *rectangle, ToolI *ellipse, ToolI *polyline,
                            ToolI *pencil, ToolI *line     , ToolI *rubber , ToolI *spline);
    void        create     (const rectangle_t &enclosing);

// virtual
protected:
    virtual void inline dump_class_name() const override;

// member data
public:
    main_window_menu_t *main_menu;

// friends
    friend host::HostWidgetI;
};

//--------------------------------------------------------------------------------------------------

inline void main_window_t::set_filters(FilterI *brightness)
{
    main_menu->set_filters(brightness);
}

//--------------------------------------------------------------------------------------------------

inline void main_window_t::set_tools(ToolI *fill  , ToolI *rectangle, ToolI *ellipse, ToolI *polyline,
                                     ToolI *pencil, ToolI *line     , ToolI *rubber , ToolI *spline)
{
    main_menu->set_tools(fill, rectangle, ellipse, polyline, pencil, line, rubber, spline);
}

//--------------------------------------------------------------------------------------------------

inline void main_window_t::dump_class_name() const
{
    LOG_TAB_SERVICE_MESSAGE("main_window_t", "");
}

#endif // MAIN_WINDOW_H
