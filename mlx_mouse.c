#include "mlx_int.h"
#include <X11/extensions/Xfixes.h>

int        mlx_mouse_move(t_xvar *xvar, t_win_list *win, int x, int y)
{
    XWarpPointer(xvar->display, None, win->window, 0, 0, 0, 0, x, y);
    return (0);
}

int        mlx_mouse_hide(t_xvar *xvar, t_win_list *win)
{
    XFixesHideCursor(xvar->display, win->window);
}

int        mlx_mouse_show(t_xvar *xvar, t_win_list *win)
{
    XFixesShowCursor(xvar->display, win->window);
}

/*
** Queries the position of the mouse pointer relative to the origin of the
** specified window and saves it to the provided location.
**
** If the pointer is not on the same screen as the specified window, both
** win_x_return and win_y_return are set to zero and the function returns 0.
*/

int		mlx_mouse_get_pos(t_xvar *xvar, t_win_list *win, \
			int *win_x_return, int *win_y_return)
{
	Window		root_return;
	Window		child_return;
	int			root_x_return;
	int			root_y_return;
	unsigned	mask_return;

	return (XQueryPointer(xvar->display, win->window, \
		&root_return, &child_return, &root_x_return, &root_y_return, \
		win_x_return, win_y_return, &mask_return));
}
