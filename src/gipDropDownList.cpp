/*
 * gipDropDownList.cpp
 *
 *  Created on: Jun 27, 2021
 *      Author: kayra
 */

#include "gipDropDownList.h"

int gipDropDownList::nextListID = 1;

gipDropDownList::gipDropDownList() {
	id = generateID();
	setup();
}

gipDropDownList::~gipDropDownList() {
	delete textfont;
}

int gipDropDownList::getID() {
	return id;
}

int gipDropDownList::generateID() {
	return nextListID++;
}

void gipDropDownList::create(int x, int y, int w, int h, gFont* font) {
	ddx = x;
	ddy = y;
	if(w > 0 && h > 0) {
		ddw = w + arrowbtnw;
		ddh = h;
	}
	listy = ddy + ddh;
	arrowbtnx = ddx + ddw - arrowbtnw;

	if(!font) {
		textfont->loadFont("FreeSans.ttf", 16);
		fontsize = 20;
	} else {
		textfont = font;
		fontsize = font->getSize();
	}

	addItem("Select an item.");
}

void gipDropDownList::setup() {
	listopen = false;
	ddx = ddy = 0;
	arrowbtnw = 50;
	ddw = 200 + arrowbtnw;
	ddh = 40;
	currentindex = 0;
	textfont = new gFont();
	fontx = 0;
	fonty = 0;
	fontsize = 0;
	margin = 5;
	background.loadImage("textbox.png");
	arrow.loadImage("triangle.png");
}

void gipDropDownList::draw() {
	/* Background */
	background.draw(ddx, ddy, ddw, ddh);

	/* Boundaries */
	gRenderObject::renderer->setColor(gColor::BLACK);
	gDrawLine(ddx, ddy, ddx + ddw, ddy);
	gDrawLine(ddx + ddw, ddy, ddx + ddw, ddy + ddh);
	gDrawLine(ddx + ddw, ddy + ddh, ddx, ddy + ddh);
	gDrawLine(ddx, ddy + ddh, ddx, ddy);
	gDrawLine(arrowbtnx, ddy, arrowbtnx, ddy + ddh);

	/* Arrow */
	gRenderObject::renderer->setColor(gColor::WHITE);
	arrow.draw(arrowbtnx, ddy, arrowbtnw, ddh, listopen * 180);

	/* Text */
	gRenderObject::renderer->setColor(gColor::BLACK);
	textfont->drawText(itemlist[currentindex], ddx + margin, ddy + fontsize + margin);

	/* The list */
	if(listopen) {
		gRenderObject::renderer->setColor(gColor::WHITE);
		background.draw(ddx, ddy + ddh, ddw, ddh * itemlist.size());

		gRenderObject::renderer->setColor(gColor::BLACK);
		gDrawLine(ddx, listy, ddx + ddw, listy);
		gDrawLine(ddx + ddw, listy, ddx + ddw, listy + ddh * itemlist.size());
		gDrawLine(ddx + ddw, listy + ddh * itemlist.size(), ddx, listy + ddh * itemlist.size());
		gDrawLine(ddx, listy + ddh * itemlist.size(), ddx, listy);

		for(int i = 0; i < itemlist.size(); i++) {
			textfont->drawText(itemlist[i], ddx + margin, listy + i * ddh + fontsize + margin);
		}
	}
	gRenderObject::renderer->setColor(gColor::WHITE);
}

void gipDropDownList::addItem(std::string item) {
	itemlist.push_back(item);

	// Adapt the width to the largest item.
	int width = (int)textfont->getStringWidth(item);

	if(ddw - margin * 2 < width) {
		ddw = margin * 2 + width;
	}
}

std::string gipDropDownList::getSelectedItem() {
	return itemlist[currentindex];
}

std::string gipDropDownList::getItem(int index) {
	return itemlist[index];
}

void gipDropDownList::keyPressed(int button) {

}

void gipDropDownList::mouseReleased(int x, int y, int button) {
	if(x < ddx && x >= ddx + ddw) return;
	if(listopen) {
		for(int i = 0; i < itemlist.size(); i++) {
			if(y >= listy + i * ddh && y < listy + i * ddh + ddh) {
				currentindex = i;
			}
		}
	}
	if(y >= ddy && y < ddy + ddh && button == 0) {
		listopen = !listopen;
	}
}
