/*
 * gipDropDownList.h
 *
 *  Created on: Jun 27, 2021
 *      Author: kayra
 */

#ifndef SRC_GIPDROPDOWNLIST_H_
#define SRC_GIPDROPDOWNLIST_H_

#include "gBasePlugin.h"
#include "gFont.h"
#include "gImage.h"

class gipDropDownList : public gBasePlugin{
public:
	gipDropDownList();
	virtual ~gipDropDownList();

	int getID();

	void create(int x, int y, int w = 0, int h = 0, gFont* font = nullptr);

	void addItem(std::string item);
	std::string getSelectedItem();
	std::string getItem(int index);

	void draw();

	void keyPressed(int button);
	void mouseReleased(int x, int y, int button);

private:
	int id;
	int currentindex;
	bool listopen;
	std::vector<std::string> itemlist;
	gImage background;
	gImage arrow;

	int ddx, ddy; // textbox x,y
	int ddw, ddh;
	int listy; // dropdown list y
	int arrowbtnx, arrowbtnw;

	gFont* textfont;
	int fontx, fonty;
	int fontsize;
	int margin;

	void setup();
	static int generateID();
	static int nextListID;
};

#endif /* SRC_GIPDROPDOWNLIST_H_ */
