/*! ========================================================================
** Synfig
** Template Header File
** $Id: toolbox.h,v 1.1.1.1 2005/01/07 03:34:37 darco Exp $
**
**	Copyright (c) 2002-2005 Robert B. Quattlebaum Jr., Adrian Bentley
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**
** === N O T E S ===========================================================
**
** ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_GTKMM_TOOLBOX_H
#define __SYNFIG_GTKMM_TOOLBOX_H

/* === H E A D E R S ======================================================= */

#include <gtkmm/window.h>
#include <gtkmm/tooltips.h>
#include <gtkmm/button.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/menu.h>
#include <gtkmm/table.h>
#include <synfig/string.h>
#include "smach.h"
#include <map>
#include "dialogsettings.h"

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace studio {

class Dockable;
class StateManager;
	
class Toolbox : public Gtk::Window
{
	friend class studio::StateManager;
	
	DialogSettings dialog_settings;

	Gtk::Tooltips tooltips;
	Gtk::Button *button_undo;
	Gtk::Button *button_redo;

	Gtk::Button *button_eyedrop;
	Gtk::Button *button_rotoscope;
	Gtk::Button *button_rotoscope_bline;
	Gtk::Button *button_rotoscope_polygon;
	
	Gtk::Table *tool_table;

	std::map<synfig::String,Gtk::ToggleButton *> state_button_map;
	
	Gtk::Menu	*recent_files_menu;

	Gtk::Menu	*dock_dialogs;

	bool changing_state_;
	
	void on_recent_files_changed();	
	void on_drop_drag_data_received(const Glib::RefPtr<Gdk::DragContext>& context, int x, int y, const Gtk::SelectionData& selection_data, guint info, guint time);

	void change_state_(const Smach::state_base *state);
	
public:

	void change_state(const synfig::String& statename);

	void update_undo_redo();

	void refresh() { update_undo_redo(); }

	void set_active_state(const synfig::String& statename);

	void add_state(const Smach::state_base *state);

	
	void dockable_registered(Dockable* x);
	
	Toolbox();
	virtual ~Toolbox();
	
};

}; // END of namespace studio

/* === E N D =============================================================== */

#endif
