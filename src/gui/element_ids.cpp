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

#include "gui/element_ids.h"

#include <cmath>
#include <cstdint>

#include <string>

#include <boost/format.hpp>
#include <boost/locale.hpp>

#include <git2.h>

#include <wx/progdlg.h>

namespace boss {

namespace bloc = boost::locale;

wxString translate(char *cstr) {
	return wxString(bloc::translate(cstr).str().c_str(), wxConvUTF8);
}

wxString translate(std::string str) {
	return wxString(bloc::translate(str).str().c_str(), wxConvUTF8);
}

wxString FromUTF8(std::string str) {
	return wxString(str.c_str(), wxConvUTF8);
}

wxString FromUTF8(boost::format f) {
	return FromUTF8(f.str());
}

int progress(const git_transfer_progress *stats, void *payload) {
	int currentProgress = (int)std::floor(float(stats->received_objects) / stats->total_objects * 1000);
	if (currentProgress == 1000)
		--currentProgress;  // Stop the progress bar from closing in case of multiple downloads.
	wxProgressDialog *progress = (wxProgressDialog*)payload;
	bool cont = progress->Update(currentProgress, FromUTF8(boost::format(bloc::translate("Downloading masterlist: %1% of %2% objects (%3% KB)")) % stats->received_objects % stats->total_objects % (stats->received_bytes / 1024)));
	if (!cont) {  // The user decided to cancel. Slightly temperamental, the progDia seems to hang a little sometimes and keypresses don't get registered. Can't do much about that.
		std::uint32_t ans = wxMessageBox(translate("Are you sure you want to cancel?"),
		                                 translate("BOSS: Updater"),
		                                 wxYES_NO | wxICON_EXCLAMATION,
		                                 progress);
		if (ans == wxYES)
			return 1;
		progress->Resume();
	}
	return 0;
}

}  // namespace boss
