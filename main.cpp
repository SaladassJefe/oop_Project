#include <iostream>
#include "mygraphics.h"
using namespace std;



class Roads
{
protected:
	int x1, y1, x2, y2;
	

public:

	Roads(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	virtual void draw()
	{
		drawRectangle(x1,y1,x2,y2,0,0,0,0,255,127);//background
		drawRectangle((x2/2)-70, y1, (x2/2)+70, y2, 128, 128, 128, 128, 128, 128);//vertical
		drawRectangle(x1,(y2 / 2) - 70, x2, (y2 / 2) + 70, 128, 128, 128, 128, 128, 128);//horizontal
		drawLine(x2/2, 0, x2/2, (y2/2)-71, 255, 255, 0);//top vertical
		drawLine(x2/2, (y2/2)+71, x2/2, y2, 255, 255, 0);//bottom vertical
		drawLine(0, y2 / 2, (x2/2)-71, y2/2, 255, 255, 0);//left horizontal
		drawLine((x2/2)+71, y2/2, x2-1, y2/2, 255, 255, 0);//right horizontal
	}

	void spawnCar(int &i)
	{
		drawRectangle((x2 / 2) + 55, (y2 - (i *10 + 60)), (x2 / 2) + 15, (y2 - (i*10 + 10)), 138, 43, 226, 138, 43, 226);
		delay(50);
		drawRectangle((x2/2) + 55, y2 - (i*10+60), (x2/2)+15, y2 - (i*10+10), 128, 128, 128, 128, 128, 128);
		i++;
		if (y2 - (i*10 + 60) < 0)
		{
			i = 0;
		}
	}



};
class Intersection : public Roads
{
public:
	
	Intersection(int x1, int y1, int x2, int y2) : Roads(x1,y1,x2,y2)
	{

	}

	void drawLights()
	{
		drawRectangle((x2 / 2) - 85, (y2 / 2) + 75, (x2 / 2) - 75, (y2 / 2) + 115, 192, 192, 192, 192, 192, 192);//bottom left
		drawEllipse((x2 / 2) - 85, (y2 / 2) + 77, (x2 / 2) - 76, (y2 / 2) + 86, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) - 85, (y2 / 2) + 91, (x2 / 2) - 76, (y2 / 2) + 100, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) - 85, (y2 / 2) + 105, (x2 / 2) - 76, (y2 / 2) + 114, 128, 128, 128, 128, 128, 128);

		drawRectangle((x2 / 2) + 75, (y2 / 2) - 115, (x2 / 2) + 85, (y2 / 2) - 75, 192, 192, 192, 192, 192, 192);//top right
		drawEllipse((x2 / 2) + 75, (y2 / 2) - 86, (x2 / 2) + 84, (y2 / 2) - 77, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) + 75, (y2 / 2) - 100, (x2 / 2) + 84, (y2 / 2) - 91, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) + 75, (y2 / 2) - 113, (x2 / 2) + 84, (y2 / 2) - 105, 128, 128, 128, 128, 128, 128);

		drawRectangle((x2 / 2) - 115, (y2 / 2) - 85, (x2 / 2) - 75, (y2 / 2) - 75, 192, 192, 192, 192, 192, 192);//top left
		drawEllipse((x2 / 2) - 86, (y2 / 2) - 84, (x2 / 2) - 77, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) - 100, (y2 / 2) - 84, (x2 / 2) - 91, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) - 114, (y2 / 2) - 84, (x2 / 2) - 105, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);

		drawRectangle((x2 / 2) + 75, (y2 / 2) + 75, (x2 / 2) + 115, (y2 / 2) + 85, 192, 192, 192, 192, 192, 192);//bottom right
		drawEllipse((x2 / 2) + 76, (y2 / 2) + 76, (x2 / 2) + 85, (y2 / 2) + 84, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) + 90, (y2 / 2) + 76, (x2 / 2) + 100, (y2 / 2) + 84, 128, 128, 128, 128, 128, 128);
		drawEllipse((x2 / 2) + 104, (y2 / 2) + 76, (x2 / 2) + 114, (y2 / 2) + 85, 128, 128, 128, 128, 128, 128);


		drawEllipse((x2 / 2) - 85, (y2 / 2) + 77, (x2 / 2) - 76, (y2 / 2) + 86, 255, 0, 0, 255, 0, 0);//red bl
		//delay(900);
		//drawEllipse((x2 / 2) - 85, (y2 / 2) + 91, (x2 / 2) - 76, (y2 / 2) + 100, 255, 255, 0, 255, 255, 0);//yellow bl
		//delay(900);
		//drawEllipse((x2 / 2) - 85, (y2 / 2) + 105, (x2 / 2) - 76, (y2 / 2) + 114, 50, 205, 50, 50, 205, 50);//green bl
		//delay(900);

		drawEllipse((x2 / 2) + 75, (y2 / 2) - 86, (x2 / 2) + 84, (y2 / 2) - 77, 255, 0, 0, 255, 0, 0);//red tr
		//delay(900);
		//drawEllipse((x2 / 2) + 75, (y2 / 2) - 100, (x2 / 2) + 84, (y2 / 2) - 91, 255, 255, 0, 255, 255, 0);//yellow tr
		//delay(900);	
		//drawEllipse((x2 / 2) + 75, (y2 / 2) - 113, (x2 / 2) + 84, (y2 / 2) - 105, 50, 205, 50, 50, 205, 50);//green tr
		//delay(900);

		drawEllipse((x2 / 2) - 86, (y2 / 2) - 84, (x2 / 2) - 77, (y2 / 2) - 76, 255, 0, 0, 255, 0, 0);//red tl
		//delay(900);
		//drawEllipse((x2 / 2) - 100, (y2 / 2) - 84, (x2 / 2) - 91, (y2 / 2) - 76, 255, 255, 0, 255, 255, 0);//yellow tl
		//delay(900);
		//drawEllipse((x2 / 2) - 114, (y2 / 2) - 84, (x2 / 2) - 105, (y2 / 2) - 76, 50, 205, 50, 50, 205, 50);//green tl
		//delay(900);

		drawEllipse((x2 / 2) + 76, (y2 / 2) + 76, (x2 / 2) + 85, (y2 / 2) + 84, 255, 0, 0, 255, 0, 0);//red br
		//delay(900);
		//drawEllipse((x2 / 2) + 90, (y2 / 2) + 76, (x2 / 2) + 100, (y2 / 2) + 84, 255, 255, 0, 255, 255, 0);//yellow br
		//delay(900);
		//drawEllipse((x2 / 2) + 104, (y2 / 2) + 76, (x2 / 2) + 114, (y2 / 2) + 85, 50, 205, 50, 50, 205, 50);//green br
		//delay(900);

	}

	void ChangeLight(int i)
	{
		switch (i)
		{
		case 0:
			delay(500);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 77, (x2 / 2) - 76, (y2 / 2) + 86, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 91, (x2 / 2) - 76, (y2 / 2) + 100, 255, 255, 0, 255, 255, 0);//yellow bl
			delay(800);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 91, (x2 / 2) - 76, (y2 / 2) + 100, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 105, (x2 / 2) - 76, (y2 / 2) + 114, 50, 205, 50, 50, 205, 50);//green bl
			delay(1500);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 105, (x2 / 2) - 76, (y2 / 2) + 114, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 91, (x2 / 2) - 76, (y2 / 2) + 100, 255, 255, 0, 255, 255, 0);//yellow bl
			delay(800);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 91, (x2 / 2) - 76, (y2 / 2) + 100, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 85, (y2 / 2) + 77, (x2 / 2) - 76, (y2 / 2) + 86, 255, 0, 0, 255, 0, 0);//red bl
			break;
		case 1:
			delay(500);
			drawEllipse((x2 / 2) - 86, (y2 / 2) - 84, (x2 / 2) - 77, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 100, (y2 / 2) - 84, (x2 / 2) - 91, (y2 / 2) - 76, 255, 255, 0, 255, 255, 0);//yellow tl
			delay(800);
			drawEllipse((x2 / 2) - 100, (y2 / 2) - 84, (x2 / 2) - 91, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 114, (y2 / 2) - 84, (x2 / 2) - 105, (y2 / 2) - 76, 50, 205, 50, 50, 205, 50);//green tl
			delay(1500);
			drawEllipse((x2 / 2) - 114, (y2 / 2) - 84, (x2 / 2) - 105, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 100, (y2 / 2) - 84, (x2 / 2) - 91, (y2 / 2) - 76, 255, 255, 0, 255, 255, 0);//yellow tl
			delay(800);
			drawEllipse((x2 / 2) - 100, (y2 / 2) - 84, (x2 / 2) - 91, (y2 / 2) - 76, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) - 86, (y2 / 2) - 84, (x2 / 2) - 77, (y2 / 2) - 76, 255, 0, 0, 255, 0, 0);//red tl
			break;
		case 2:
			delay(500);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 86, (x2 / 2) + 84, (y2 / 2) - 77, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 100, (x2 / 2) + 84, (y2 / 2) - 91, 255, 255, 0, 255, 255, 0);//yellow tr
			delay(800);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 100, (x2 / 2) + 84, (y2 / 2) - 91, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 113, (x2 / 2) + 84, (y2 / 2) - 105, 50, 205, 50, 50, 205, 50);//green tr
			delay(1500);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 113, (x2 / 2) + 84, (y2 / 2) - 105, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 100, (x2 / 2) + 84, (y2 / 2) - 91, 255, 255, 0, 255, 255, 0);//yellow tr
			delay(800);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 100, (x2 / 2) + 84, (y2 / 2) - 91, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 75, (y2 / 2) - 86, (x2 / 2) + 84, (y2 / 2) - 77, 255, 0, 0, 255, 0, 0);//red tr
			break;
		case 3:
			delay(500);
			drawEllipse((x2 / 2) + 76, (y2 / 2) + 76, (x2 / 2) + 85, (y2 / 2) + 84, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 90, (y2 / 2) + 76, (x2 / 2) + 100, (y2 / 2) + 84, 255, 255, 0, 255, 255, 0);//yellow br
			delay(800);
			drawEllipse((x2 / 2) + 90, (y2 / 2) + 76, (x2 / 2) + 100, (y2 / 2) + 84, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 104, (y2 / 2) + 76, (x2 / 2) + 114, (y2 / 2) + 85, 50, 205, 50, 50, 205, 50);//green br
			delay(1500);
			drawEllipse((x2 / 2) + 104, (y2 / 2) + 76, (x2 / 2) + 114, (y2 / 2) + 85, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 90, (y2 / 2) + 76, (x2 / 2) + 100, (y2 / 2) + 84, 255, 255, 0, 255, 255, 0);//yellow br
			delay(800);
			drawEllipse((x2 / 2) + 90, (y2 / 2) + 76, (x2 / 2) + 100, (y2 / 2) + 84, 128, 128, 128, 128, 128, 128);
			drawEllipse((x2 / 2) + 76, (y2 / 2) + 76, (x2 / 2) + 85, (y2 / 2) + 84, 255, 0, 0, 255, 0, 0);//red br
			break;
		default:
			break;
		}
	}

};


int main()
{

	showConsoleCursor(false);

	// Initializing
	int w = 0, h = 0;
	getWindowDimensions(w,h);
	w = h;

	cls();
	showConsoleCursor(false);
	
	Intersection obj(0, 0, w, h);

	
	
	int c = 0, i = 0;
	while (true)
	{
		obj.Roads::draw();
		//delay(100);
		obj.drawLights();

		obj.spawnCar(i);
		//i++;
		//if (h - (i * 10 + 60) < 0)
		//{
		//	i = 0;
		//}

		obj.ChangeLight(c);
		if (c == 3)
		{
			c = 0;
			continue;
		}
		c++;
	}






	//drawLine(0,5,w,5,0,0,255);
	//drawEllipse(w-10,0,w,10,0,255,0,0,255,0);

	// main event loop
	//int i=0,j=0;

	//while (true){
	//	drawRectangle(10*i+0,j+0,10*i+25,j+25,0,0,0,173,255,47);
	//	delay(50);
	//	drawRectangle(10*i+0,j+0,10*i+25,j+25,0,0,0,0,0,0);

	//	i++;
	//	if (10*i > w) i = 0;

	//	char c = getKey();

	//	if (c == 'q') break;

	//	if (c == 's') i = 0;

	//	if (c == 'k') j += 10;

	//	if (c == 'i') j -= 10;

	//}

	// cleaning
	//drawLine(0,5,w,5,0);
	//drawEllipse(w-10,0,w,10,0,0,0,0,0,0);

	cls();
	showConsoleCursor(true);

	gotoxy(0,0);

	return 0;
}

