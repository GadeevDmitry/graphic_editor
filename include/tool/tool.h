#ifndef TOOL_H
#define TOOL_H

#include "event/eventable.h"
#include "graphic/render_texture.h"

//==================================================================================================

class tool_t
{
// member functions
public:
             inline  tool_t();
    virtual  inline ~tool_t() {}

// virtual
public:
    virtual void inline deactivate     (render_texture_t &perm, render_texture_t &temp, const color_t &color, const eventable::mouse_context_t &local_context);
    virtual void paint_on_mouse_press  (render_texture_t &perm, render_texture_t &temp, const color_t &color, const eventable::mouse_context_t &local_context, const MOUSE_BUTTON_TYPE &btn) = 0;
    virtual void paint_on_mouse_release(render_texture_t &perm, render_texture_t &temp, const color_t &color, const eventable::mouse_context_t &local_context, const MOUSE_BUTTON_TYPE &btn) = 0;
    virtual void paint_on_mouse_move   (render_texture_t &perm, render_texture_t &temp, const color_t &color, const eventable::mouse_context_t &local_context, const vec2d             &off) = 0;

// member data
protected:
    vec2d start;
    vec2d last;
};

//--------------------------------------------------------------------------------------------------

tool_t::tool_t():
start(),
last ()
{}

//--------------------------------------------------------------------------------------------------

inline void tool_t::deactivate(render_texture_t &perm, render_texture_t &temp, const color_t &color, const eventable::mouse_context_t &local_context)
{
    (void) perm;
    (void) temp;
    (void) color;
    (void) local_context;
}

#endif // TOOL_H
