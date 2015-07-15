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

#ifndef BOSS_COMMON_H_
#define BOSS_COMMON_H_

#include "common/conditional_data.h"
#include "common/error.h"
#include "common/game.h"
#include "common/globals.h"
#inlcude "common/item_list.h"
#include "common/rule_line.h"
#inlcude "common/settings.h"
#include "output/output.h"
#include "support/helpers.h"
#include "support/logger.h"
#include "updating/updater.h"

/* For easy reference, the following functions may throw exceptions (using boss_error) on failure:

bool Item::operator< (Item);

void SetModTime(time_t modificationTime);

void ItemList::Load(fs::path path);

void ItemList::Save(fs::path file);

void RuleList::Load(fs::path file);

void RuleList::Save(fs::path file);

void Ini::Load(fs::path file);

void Ini::Save(fs::path file);

void GetGame();

void Outputter::Save(fs::path file, bool overwrite);

void CleanUp();

void UpdateMasterlist(uiStruct ui, uint32_t& localRevision, string& localDate, uint32_t& remoteRevision, string& remoteDate);

string IsBOSSUpdateAvailable();

string FetchReleaseNotes(const string updateVersion);

vector<string> DownloadInstallBOSSUpdate(uiStruct ui, const uint32_t updateType, const string updateVersion);
*/

#endif  // BOSS_COMMON_H_