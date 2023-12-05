#ifndef PLUGIN_APPLICATION_H
#define PLUGIN_APPLICATION_H

#include "Tool.h"
#include "Filter.h"
#include "Widget.h"

//==================================================================================================

namespace plugin
{
    struct Plugin;

    struct GuiI
    {
        virtual vec2d          get_size           ()                                                  = 0;
        virtual RenderTargetI* get_render_target  (vec2d size, vec2d pos, Plugin *self)               = 0;
        virtual void           create_param_window(Array<const char *> param_names, Interface * self) = 0;
        virtual WidgetI*       get_root           ()                                                  = 0;
    };

    struct App
    {
        GuiI           *root;
        EventManagerI  *event_manager;
        ToolManagerI   *tool_manager;
        FilterManagerI *filter_manager;
    };
}

#endif // PLUGIN_APPLICATION_H
