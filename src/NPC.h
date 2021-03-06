/*
Copyright © 2011-2012 Clint Bellanger
Copyright © 2013 Henrik Andersson

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

/**
 * class NPC
 */

#pragma once
#ifndef NPC_H
#define NPC_H

#include "CommonIncludes.h"
#include "Entity.h"
#include "ItemStorage.h"
#include "Utils.h"

const int NPC_VENDOR_MAX_STOCK = 80;
const int NPC_VOX_INTRO = 0;
const int NPC_VOX_QUEST = 1;
const int NPC_NO_DIALOG_AVAIL = -1;

class NPC : public Entity {
private:
	bool isDialogType(const std::string &type);
public:
	NPC();
	~NPC();
	void load(const std::string& npc_id, int hero_level);
	void loadGraphics(const std::string& filename_portrait);
	int loadSound(const std::string& fname, int type);
	void logic();
	bool playSound(int type, int id=-1);
	void getDialogNodes(std::vector<int> &result);
	std::string getDialogTopic(unsigned int dialog_node);
	bool checkMovement(unsigned int dialog_node);
	bool processDialog(unsigned int dialog_node, unsigned int& event_cursor);
	void processEvent(unsigned int dialog_node, unsigned int cursor);
	virtual Renderable getRender();

	// general info
	std::string name;
	std::string filename;
	std::string gfx; // filename of sprite.
	FPoint pos; // map position
	int level; // used in determining item quality

	int direction;

	// talker info
	Sprite portrait;
	bool talker;

	// vendor info
	bool vendor;
	ItemStorage stock;
	int stock_count;

	// vocals
	std::vector<SoundManager::SoundID> vox_intro;
	std::vector<SoundManager::SoundID> vox_quests;

	// story and dialog options
	// outer vector is addressing the dialog and the inner vector is
	// addressing the events during one dialog
	std::vector<std::vector<Event_Component> > dialog;
};

#endif
