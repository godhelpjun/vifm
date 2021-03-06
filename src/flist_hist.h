/* vifm
 * Copyright (C) 2016 xaizek.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef VIFM__FLIST_HIST_H__
#define VIFM__FLIST_HIST_H__

/* Directory history related functions. */

#include "ui/ui.h"

/* Changes current directory of the view to next location backward in
 * history, if available. */
void flist_hist_go_back(view_t *view);

/* Changes current directory of the view to next location forward in history, if
 * available. */
void flist_hist_go_forward(view_t *view);

/* Adds new entry to directory history of the view or updates an existing entry.
 * If path is NULL, current path is used.  If file is NULL current file is used.
 * rel_pos specifies position of file relative to top of the view.  If rel_pos
 * is negative, it's computed for current file.  Empty file name signifies
 * visiting directory, which shouldn't reset name of previously active file in
 * it. */
void flist_hist_save(view_t *view, const char path[], const char file[],
		int rel_pos);

/* Checks whether given path to directory is in view history.  Returns non-zero
 * if so, otherwise zero is returned. */
int flist_hist_contains(view_t *view, const char path[]);

/* Empties history of the view. */
void flist_hist_clear(view_t *view);

/* Looks up history in the source to update cursor position in the view. */
void flist_hist_lookup(view_t *view, const view_t *source);

/* Finds top and item positions for specified directory path.  Uses history from
 * view and elements of entries.  Sets *top and returns position.  Both values
 * are defaulted to zero for the case when search fails. */
int flist_hist_find(const view_t *view, entries_t entries, const char dir[],
		int *top);

/* Updates existing history entry for the path with new data or does nothing if
 * directory path is absent from history. */
void flist_hist_update(view_t *view, const char dir[], const char file[],
		int rel_pos);

#endif /* VIFM__FLIST_HIST_H__ */

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 : */
