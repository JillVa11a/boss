/*	BOSS

	A "one-click" program for users that quickly optimises and avoids
	detrimental conflicts in their TES IV: Oblivion, Nehrim - At Fate's Edge,
	TES V: Skyrim, Fallout 3 and Fallout: New Vegas mod load orders.

	Copyright (C) 2009-2012    BOSS Development Team.

	This file is part of BOSS.

	BOSS is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation, either version 3 of
	the License, or (at your option) any later version.

	BOSS is distributed in the hope that it will
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with BOSS.  If not, see
	<http://www.gnu.org/licenses/>.

	$Revision: 2188 $, $Date: 2011-01-20 10:05:16 +0000 (Thu, 20 Jan 2011) $
*/

#ifndef GUI_ELEMENT_IDS_H_
#define GUI_ELEMENT_IDS_H_

#include <string>

#include <boost/format.hpp>

#include <git2.h>

// TODO(MCP): Replace these includes with the ones we need as opposed to including all of them

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#	include <wx/wx.h>
#endif

enum {
	// Main window.
	OPTION_EditUserRules = wxID_HIGHEST + 1,  // Declares an id which will be used to call our button
	OPTION_OpenBOSSlog,
	OPTION_Run,
	MENU_Quit,
	MENU_OpenMainReadMe,
	MENU_OpenUserlistReadMe,
	MENU_OpenMasterlistReadMe,
	MENU_OpenVersionHistory,
	MENU_OpenLicenses,
	MENU_ShowAbout,
	MENU_ShowSettings,
	MENU_Oblivion,
	MENU_Nehrim,
	MENU_Skyrim,
	MENU_Fallout3,
	MENU_FalloutNewVegas,
	DROPDOWN_LogFormat,
	DROPDOWN_Game,
	DROPDOWN_Revert,
	CHECKBOX_ShowBOSSlog,
	CHECKBOX_Update,
	CHECKBOX_EnableCRCs,
	CHECKBOX_TrialRun,
	RADIOBUTTON_SortOption,
	RADIOBUTTON_UpdateOption,
	RADIOBUTTON_UndoOption,
	// About window.
	OPTION_ExitAbout,
	// Settings window.
	OPTION_OKExitSettings,
	OPTION_CancelExitSettings,
	// User Rules Manager.
	LIST_RuleList,
	BUTTON_NewRule,
	BUTTON_EditRule,
	BUTTON_DeleteRule,
	LIST_Modlist,
	LIST_Masterlist,
	BUTTON_OKExitEditor,
	BUTTON_CancelExitEditor,
	TEXT_ModMessages,
	SEARCH_Masterlist,
	SEARCH_Modlist,
	TEXT_RuleMod,
	CHECKBOX_SortMods,
	RADIO_SortMod,
	RADIO_InsertMod,
	CHOICE_BeforeAfter,
	CHOICE_TopBottom,
	TEXT_SortMod,
	TEXT_InsertMod,
	CHECKBOX_RemoveMessages,
	CHECKBOX_AddMessages,
	TEXT_NewMessages,
	BUTTON_MoveRuleUp,
	BUTTON_MoveRuleDown
};

// Convenience wrapper function, because wxWidgets's own translation system doesn't work as well as Boost's,
// but Boost's requires a UTF-8 -> (whatever display encoding) conversion to work with the UI.
namespace boss {

wxString translate(char *cstr);

wxString translate(std::string str);

wxString FromUTF8(std::string str);

wxString FromUTF8(boost::format f);

int progress(const git_transfer_progress *stats, void *payload);

}  // namespace boss
#endif  // GUI_ELEMENT_IDS_H_
