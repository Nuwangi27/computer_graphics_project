#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 40.0                  //speed of traffic
float i=0.0;                        //movement of car
float m=0.0;                        //movement of clouds
float n=0.0;                        //movement of plane along x-axis
float o=0.0;                        //  and y-axis
float c=0.0;                        //movement of comet	SS
int light=1;                        //1 for green-light, 0 for red-light
int day=1;                          //1 for day ,0 for night
int plane=0;                        //1 for plane
int comet=0;                        //1 for comet
void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}
void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}
void draw_object()
{
int l;
if(day==1)
{
glColor3ub (0, 76, 153);            //sky
glBegin(GL_POLYGON);
    glVertex2f(0,450);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,450);
glEnd();

glColor3f(0.0,0.7,0.0);            //ground
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();
                                    //sun
	for(l=0;l<=55;l++)
{
		glColor3f(1.0,0.7,0.0);
        draw_circle(100,625,l);
}
                                    //plane
if(plane==1)
{
glColor3f(0.8,1.0,1.0);
glBegin(GL_POLYGON);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
glEnd();
glColor3f(0.8,0.8,0.8);
glBegin(GL_LINE_LOOP);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
glEnd();
}
for(l=0;l<=20;l++)                      //cloud1
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(-100+m,620,l);
	}
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(-60+m,620,l);
		draw_circle(-40+m,620,l);
	}
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(-5+m,620,l);
	}


	for(l=0;l<=20;l++)                   //cloud4
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(220+m,550,l);
}
	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(250+m,550,l);
	    draw_circle(290+m,550,l);
        draw_circle(320+m,550,l);
	}

for(l=0;l<=20;l++)
{


		glColor3f(1.0,1.0,1.0);
		draw_circle(350+m,550,l);
}


                                    //cloud3
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}
                                      //cloud5
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}
	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}
for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(510+m,615,l);
}
  for(l=0;l<=20;l++)                   //cloud6
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(600+m,600,l);
}
	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(640+m,600,l);
	    draw_circle(665+m,600,l);
        draw_circle(700+m,600,l);
	}

for(l=0;l<=20;l++)
{


		glColor3f(1.0,1.0,1.0);
		draw_circle(740+m,600,l);
}
 for(l=0;l<=20;l++)                    //cloud2
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(10+m,550,l);
}
	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(40+m,550,l);
	    draw_circle(80+m,550,l);
        draw_circle(100+m,550,l);
	}

for(l=0;l<=20;l++)
{


		glColor3f(1.0,1.0,1.0);
		draw_circle(130+m,550,l);
}

for(l=0;l<=20;l++)                    //cloud7
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(800+m,550,l);
}
	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(840+m,550,l);
	    draw_circle(870+m,548,l);

	}

for(l=0;l<=20;l++)
{


		glColor3f(1.0,1.0,1.0);
		draw_circle(900+m,550,l);
}


glColor3ub (0, 0, 140);//building 1
glBegin(GL_POLYGON);
glVertex2i (30, 390);
glVertex2i (100, 390);
glVertex2i (100, 500);
glVertex2i (30, 500);
                                                                                                                                                                                  glEnd();


glColor3ub (32, 32, 32);//building 1 window 1
glBegin(GL_POLYGON);
glVertex2i (40, 460);
glVertex2i (60, 460);
glVertex2i (60, 480);
glVertex2i (40, 480);
glEnd();

glColor3ub (32, 32, 32);//building 1 window 2
glBegin(GL_POLYGON);
glVertex2i (70, 460);
glVertex2i (90, 460);
glVertex2i (90, 480);
glVertex2i (70, 480);
glEnd();


glColor3ub (0, 153, 76);//building 2
glBegin(GL_POLYGON);
glVertex2i (210, 390);
glVertex2i (280, 390);
glVertex2i (280, 500);
glVertex2i (210, 500);
glEnd();

glColor3ub (255, 255, 102);//building 2 window 1
glBegin(GL_POLYGON);
glVertex2i (220, 460);
glVertex2i (240, 460);
glVertex2i (240, 480);
glVertex2i (220, 480);
glEnd();

glColor3ub (32, 32, 32);//building 2 window 2
glBegin(GL_POLYGON);
glVertex2i (250, 460);
glVertex2i (270, 460);
glVertex2i (270, 480);
glVertex2i (250, 480);
glEnd();

glColor3ub (0, 102, 51);//building 3
glBegin(GL_POLYGON);
glVertex2i (330, 390);
glVertex2i (420, 390);
glVertex2i (420, 500);
glVertex2i (330, 500);
glEnd();

glColor3ub (255, 255, 102);//building 3 window 1
glBegin(GL_POLYGON);
glVertex2i (335, 460);
glVertex2i (355, 460);
glVertex2i (355, 480);
glVertex2i (335, 480);
glEnd();

glColor3ub (32, 32, 32);//building 3 window 2
glBegin(GL_POLYGON);
glVertex2i (365, 460);
glVertex2i (385, 460);
glVertex2i (385, 480);
glVertex2i (365, 480);
glEnd();

glColor3ub (32, 32, 32);//building 3 window 3
glBegin(GL_POLYGON);
glVertex2i (395, 460);
glVertex2i (415, 460);
glVertex2i (415, 480);
glVertex2i (395, 480);
glEnd();

glColor3ub (255, 255, 102);//building 3 window 4
glBegin(GL_POLYGON);
glVertex2i (335, 425);
glVertex2i (355, 425);
glVertex2i (355, 450);
glVertex2i (335, 450);
glEnd();

glColor3ub (32, 32, 32);//building 3 window 5
glBegin(GL_POLYGON);
glVertex2i (365, 425);
glVertex2i (385, 425);
glVertex2i (385, 450);
glVertex2i (365, 450);
glEnd();

glColor3ub (255, 255, 102);//building 3 window 6
glBegin(GL_POLYGON);
glVertex2i (395, 425);
glVertex2i (415, 425);
glVertex2i (415, 450);
glVertex2i (395, 450);
glEnd();



glColor3ub (0, 102, 102);//building 4
glBegin(GL_POLYGON);
glVertex2i (430, 390);
glVertex2i (500, 390);
glVertex2i (500, 500);
glVertex2i (430, 500);
glEnd();

glColor3ub (32, 32, 32);//building 4 window 1
glBegin(GL_POLYGON);
glVertex2i (440, 460);
glVertex2i (460, 460);
glVertex2i (460, 480);
glVertex2i (440, 480);
glEnd();

glColor3ub (32, 32, 32);//building 4 window 2
glBegin(GL_POLYGON);
glVertex2i (470, 460);
glVertex2i (490, 460);
glVertex2i (490, 480);
glVertex2i (470, 480);
glEnd();

glColor3ub (255, 255, 102);//building 4 window 3
glBegin(GL_POLYGON);
glVertex2i (440, 430);
glVertex2i (460, 430);
glVertex2i (460, 450);
glVertex2i (440, 450);
glEnd();

glColor3ub (32, 32, 32);//building 4 window 4
glBegin(GL_POLYGON);
glVertex2i (470, 430);
glVertex2i (490, 430);
glVertex2i (490, 450);
glVertex2i (470, 450);
glEnd();


glColor3ub (0, 102, 102);//building 5
glBegin(GL_POLYGON);
glVertex2i (600, 390);
glVertex2i (700, 390);
glVertex2i (700, 500);
glVertex2i (600, 500);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 1
glBegin(GL_POLYGON);
glVertex2i (610, 460);
glVertex2i (630, 460);
glVertex2i (630, 480);
glVertex2i (610, 480);
glEnd();

glColor3ub (32, 32, 32);//building 5 window 2
glBegin(GL_POLYGON);
glVertex2i (640, 460);
glVertex2i (660, 460);
glVertex2i (660, 480);
glVertex2i (640, 480);
glEnd();

glColor3ub (32, 32, 32);//building 5 window 3
glBegin(GL_POLYGON);
glVertex2i (670, 460);
glVertex2i (690, 460);
glVertex2i (690, 480);
glVertex2i (670, 480);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 4
glBegin(GL_POLYGON);
glVertex2i (610, 430);
glVertex2i (630, 430);
glVertex2i (630, 450);
glVertex2i (610, 450);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 5
glBegin(GL_POLYGON);
glVertex2i (640, 430);
glVertex2i (660, 430);
glVertex2i (660, 450);
glVertex2i (640, 450);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 6
glBegin(GL_POLYGON);
glVertex2i (670, 430);
glVertex2i (690, 430);
glVertex2i (690, 450);
glVertex2i (670, 450);
glEnd();

glColor3ub (255, 51, 51);//Behind Clock Tower building
glBegin(GL_POLYGON);
glVertex2i (280, 340);
glVertex2i (345, 340);
glVertex2i (345, 460);
glVertex2i (280, 460);
glEnd();


glColor3ub (153, 0, 76);//building
glBegin(GL_POLYGON);
glVertex2i (130, 270);
glVertex2i (230, 270);
glVertex2i (230, 480);
glVertex2i (130, 480);
glEnd();

glColor3ub (255, 255, 102); //build  window 1
glBegin(GL_POLYGON);
glVertex2i (150, 430);
glVertex2i (170, 430);
glVertex2i (170, 460);
glVertex2i (150, 460);
glEnd();

glColor3ub (32, 32, 32); //build  window 2
glBegin(GL_POLYGON);
glVertex2i (190, 430);
glVertex2i (210, 430);
glVertex2i (210, 460);
glVertex2i (190, 460);
glEnd();


glColor3ub (32, 32, 32); //build  window 3
glBegin(GL_POLYGON);
glVertex2i (150, 380);
glVertex2i (170, 380);
glVertex2i (170, 410);
glVertex2i (150, 410);
glEnd();

glColor3ub (255, 255, 102); //build  window 4
glBegin(GL_POLYGON);
glVertex2i (190, 380);
glVertex2i (210, 380);
glVertex2i (210, 410);
glVertex2i (190, 410);
glEnd();


glColor3ub (0, 0, 102);//building
glBegin(GL_POLYGON);
glVertex2i (50, 250);
glVertex2i (150, 250);
glVertex2i (150, 450);
glVertex2i (50, 450);
glEnd();

glColor3ub (255, 255, 102); //build  window 1
glBegin(GL_POLYGON);
glVertex2i (70, 400);
glVertex2i (90, 400);
glVertex2i (90, 430);
glVertex2i (70, 430);
glEnd();

glColor3ub (255, 255, 102); //build  window 2
glBegin(GL_POLYGON);
glVertex2i (110, 400);
glVertex2i (130, 400);
glVertex2i (130, 430);
glVertex2i (110, 430);
glEnd();


glColor3ub (255, 255, 102); //build  window 3
glBegin(GL_POLYGON);
glVertex2i (70, 350);
glVertex2i (90, 350);
glVertex2i (90, 380);
glVertex2i (70, 380);
glEnd();

glColor3ub (255, 255, 102); //build  window 4
glBegin(GL_POLYGON);
glVertex2i (110, 350);
glVertex2i (130, 350);
glVertex2i (130, 380);
glVertex2i (110, 380);
glEnd();


glColor3ub (204, 204, 0); //City clock Triangle
glBegin(GL_TRIANGLES);
glVertex2i (250, 420);
glVertex2i (295, 480);
glVertex2i (340, 420);
glEnd();

glColor3ub (102, 51, 0); //City Clock Polygon
glBegin(GL_POLYGON);
glVertex2i (250, 250);
glVertex2i (340, 250);
glVertex2i (340, 420);
glVertex2i (250, 420);
glEnd();

glColor3ub (0, 51, 0); //City Clock Door
glBegin(GL_POLYGON);
glVertex2i (280, 250);
glVertex2i (310, 250);
glVertex2i (310, 300);
glVertex2i (280, 300);
glEnd();

glColor3ub(0, 0, 0);//Clock outdoor line 1
glBegin(GL_LINE_LOOP);
glVertex2i(280,240);
glVertex2i(310,240);
glEnd();

glColor3ub(0, 0, 0);//Clock Outdoor Line 2
glBegin(GL_LINE_LOOP);
glVertex2i(280,235);
glVertex2i(310,235);
glEnd();


//Clock Shape
int p1,x1,y1;
int xc1=295, yc1=380, r1=35;
p1=1-r1;
x1=0;
y1=r1;
while(x1<=y1)
{
if(p1<0)
{
x1=x1+1;
p1=p1+2*x1+1;
}
else
{
x1=x1+1;
y1=y1-1;
p1=p1+2*(x1+1)-2*(y1+1);
}
glColor3ub(160, 160, 160);
glBegin(GL_POLYGON);
glVertex2i(x1+xc1,y1+yc1);
glVertex2i(x1+xc1,-y1+yc1);
glVertex2i(-x1+xc1,-y1+yc1);
glVertex2i(-x1+xc1,y1+yc1);
glVertex2i(y1+xc1,x1+yc1);
glVertex2i(y1+xc1,-x1+yc1);
glVertex2i(-y1+xc1,-x1+yc1);
glVertex2i(-y1+xc1,x1+yc1);
glEnd();
}

glColor3ub(0, 0, 0);//Minute Clock
glBegin(GL_LINE_LOOP);
glVertex2i(295,380);
glVertex2i(295,410);
glEnd();

glColor3ub(0, 0, 0);//Hour Clock
glBegin(GL_LINE_LOOP);
glVertex2i(295,380);
glVertex2i(280,370);
glEnd();


glColor3ub(76,0,153);//1
glBegin(GL_POLYGON);
glVertex2i (410, 250);
glVertex2i (480, 210);
glVertex2i (480, 380);
glVertex2i (410, 400);
glEnd();

glColor3ub(153,0,153);//2
glBegin(GL_POLYGON);
glVertex2i (480, 210);
glVertex2i (520, 230);
glVertex2i (520, 400);
glVertex2i (480, 380);
glEnd();


glColor3ub(229,204,255);//3
glBegin(GL_POLYGON);
glVertex2i (410, 400);
glVertex2i (480, 380);
glVertex2i (520, 400);
glVertex2i (450, 420);
glEnd();


glColor3ub(153,0,0);//Building
glBegin(GL_POLYGON);
glVertex2i (550, 230);
glVertex2i (640, 230);
glVertex2i (640, 400);
glVertex2i (550, 400);
glEnd();


glColor3ub(32,32,32);//Building window
glBegin(GL_POLYGON);
glVertex2i (565, 350);
glVertex2i (590, 350);
glVertex2i (590, 380);
glVertex2i (565, 380);
glEnd();

glColor3ub(255,255,102);//Building window
glBegin(GL_POLYGON);
glVertex2i (600, 350);
glVertex2i (625, 350);
glVertex2i (625, 380);
glVertex2i (600, 380);
glEnd();


glColor3ub(255,255,102);//Building window
glBegin(GL_POLYGON);
glVertex2i (565, 310);
glVertex2i (590, 310);
glVertex2i (590, 340);
glVertex2i (565, 340);
glEnd();

glColor3ub(32,32,32);//Building window
glBegin(GL_POLYGON);
glVertex2i (600, 310);
glVertex2i (625, 310);
glVertex2i (625, 340);
glVertex2i (600, 340);
glEnd();

glColor3ub(32,32,32);//Playgroung Road
glBegin(GL_POLYGON);
glVertex2i (710, 330);
glVertex2i (730, 330);
glVertex2i (730, 350);
glVertex2i (710, 350);
glEnd();
                                    //grass


                                    //pond
//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(50,185);
glVertex2f(50,255);
glVertex2f(65,255);
glVertex2f(65,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,250,l);
		draw_circle(80,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(50,290,l);
		draw_circle(70,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,315,l);
	}

//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(300,185);
glVertex2f(300,255);
glVertex2f(315,255);
glVertex2f(315,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,250,l);
		draw_circle(330,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(300,290,l);
		draw_circle(320,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(310,315,l);
	}


//tree 5
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(1050,185);
glVertex2f(1050,255);
glVertex2f(1065,255);
glVertex2f(1065,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,250,l);
		draw_circle(1080,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1050,290,l);
		draw_circle(1070,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1060,315,l);
	}


//railway station
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(400,250);
glVertex2f(400,450);
glVertex2f(950,450);
glVertex2f(950,250);
glEnd();

//roof
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(350,450);
glVertex2f(450,500);
glVertex2f(900,500);
glVertex2f(1000,450);
glEnd();
//side window
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(400,400);
glVertex2f(350,350);
glVertex2f(400,350);
glEnd();

//side window
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(950,400);
glVertex2f(1000,350);
glVertex2f(950,350);
glEnd();


glColor3f(0.847059,0.847059,0.74902);
glBegin(GL_POLYGON);
glVertex2f(425,250);
glVertex2f(425,250);
glVertex2f(425,400);
glVertex2f(450,425);
glVertex2f(550,425);
glVertex2f(575,400);
glVertex2f(575,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(600,250);
glVertex2f(600,400);
glVertex2f(625,425);
glVertex2f(725,425);
glVertex2f(750,400);
glVertex2f(750,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(775,250);
glVertex2f(775,400);
glVertex2f(800,425);
glVertex2f(900,425);
glVertex2f(925,400);
glVertex2f(925,250);
glEnd();

//window 1
glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(450,300);
glVertex2f(450,375);
glVertex2f(550,375);
glVertex2f(550,300);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(450,337.5);
glVertex2f(550,337.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(500,375);
glVertex2f(500,300);
glEnd();


//window 2
glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(800,300);
glVertex2f(800,375);
glVertex2f(900,375);
glVertex2f(900,300);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(800,337.5);
glVertex2f(900,337.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(850,375);
glVertex2f(850,300);
glEnd();

//door
glColor3f(0.329412,0.329412,0.329412);
glBegin(GL_POLYGON);
glVertex2f(625,250);
glVertex2f(625,375);
glVertex2f(725,375);
glVertex2f(725,250);
glEnd();
}
else
{                                    //sky
glColor3f(0.0,0.0,0.1);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();
                                          //moon
int l;
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}
//star1
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();
//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();
                                    //star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();
                                    //star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();
                                    //star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();
                                    //star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();
                                    //star7
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(500,543);
glVertex2f(495,535);
glVertex2f(505,535);
glVertex2f(500,532);
glVertex2f(495,540);
glVertex2f(505,540);
glEnd();
                                    //comet
if(comet==1)
{
	for(l=0;l<=7;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(300+c,675,l);
	}
glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200+c,675);
	glVertex2f(300+c,682);
	glVertex2f(300+c,668);
	glEnd();
}
                                    //Plane
if(plane==1)
{
	for(l=0;l<=1;l++)
	{
		glColor3f(1.0,0.0,0.0);
		draw_circle(950+n,625+o,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(954+n,623+o,l);
	}
}
                                     //grass
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

}

glColor3ub (102, 0, 0);//building 1
glBegin(GL_POLYGON);
glVertex2i (30, 390);
glVertex2i (100, 390);
glVertex2i (100, 500);
glVertex2i (30, 500);
glEnd();


glColor3ub (255, 255, 102);//building 1 window 1
glBegin(GL_POLYGON);
glVertex2i (40, 460);
glVertex2i (60, 460);
glVertex2i (60, 480);
glVertex2i (40, 480);
glEnd();

glColor3ub (255, 255, 102);//building 1 window 2
glBegin(GL_POLYGON);
glVertex2i (70, 460);
glVertex2i (90, 460);
glVertex2i (90, 480);
glVertex2i (70, 480);
glEnd();


glColor3ub (0, 153, 76);//building 2
glBegin(GL_POLYGON);
glVertex2i (210, 390);
glVertex2i (280, 390);
glVertex2i (280, 500);
glVertex2i (210, 500);
glEnd();

glColor3ub (255, 255, 102);//building 2 window 1
glBegin(GL_POLYGON);
glVertex2i (220, 460);
glVertex2i (240, 460);
glVertex2i (240, 480);
glVertex2i (220, 480);
glEnd();

glColor3ub (32, 32, 32);//building 2 window 2
glBegin(GL_POLYGON);
glVertex2i (250, 460);
glVertex2i (270, 460);
glVertex2i (270, 480);
glVertex2i (250, 480);
glEnd();

glColor3ub (0, 102, 51);//building 3
glBegin(GL_POLYGON);
glVertex2i (330, 390);
glVertex2i (420, 390);
glVertex2i (420, 500);
glVertex2i (330, 500);
glEnd();

glColor3ub (255, 255, 102);//building 3 window 1
glBegin(GL_POLYGON);
glVertex2i (335, 460);
glVertex2i (355, 460);
glVertex2i (355, 480);
glVertex2i (335, 480);
glEnd();

glColor3ub (32, 32, 32);//building 3 window 2
glBegin(GL_POLYGON);
glVertex2i (365, 460);
glVertex2i (385, 460);
glVertex2i (385, 480);
glVertex2i (365, 480);
glEnd();

glColor3ub (32, 32, 32);//building 3 window 3
glBegin(GL_POLYGON);
glVertex2i (395, 460);
glVertex2i (415, 460);
glVertex2i (415, 480);
glVertex2i (395, 480);
glEnd();

glColor3ub (255, 255, 102);//building 3 window 4
glBegin(GL_POLYGON);
glVertex2i (335, 425);
glVertex2i (355, 425);
glVertex2i (355, 450);
glVertex2i (335, 450);
glEnd();

glColor3ub (32, 32, 32);//building 3 window 5
glBegin(GL_POLYGON);
glVertex2i (365, 425);
glVertex2i (385, 425);
glVertex2i (385, 450);
glVertex2i (365, 450);
glEnd();

glColor3ub (255, 255, 102);//building 3 window 6
glBegin(GL_POLYGON);
glVertex2i (395, 425);
glVertex2i (415, 425);
glVertex2i (415, 450);
glVertex2i (395, 450);
glEnd();





glColor3ub (32, 32, 32);//building 4 window 1
glBegin(GL_POLYGON);
glVertex2i (440, 460);
glVertex2i (460, 460);
glVertex2i (460, 480);
glVertex2i (440, 480);
glEnd();

glColor3ub (32, 32, 32);//building 4 window 2
glBegin(GL_POLYGON);
glVertex2i (470, 460);
glVertex2i (490, 460);
glVertex2i (490, 480);
glVertex2i (470, 480);
glEnd();

glColor3ub (255, 255, 102);//building 4 window 3
glBegin(GL_POLYGON);
glVertex2i (440, 430);
glVertex2i (460, 430);
glVertex2i (460, 450);
glVertex2i (440, 450);
glEnd();

/*glColor3ub (32, 32, 32);//building 4 window 4
glBegin(GL_POLYGON);
glVertex2i (470, 430);
glVertex2i (490, 430);
glVertex2i (490, 450);
glVertex2i (470, 450);
glEnd();


glColor3ub (0, 102, 102);//building 5
glBegin(GL_POLYGON);
glVertex2i (600, 390);
glVertex2i (700, 390);
glVertex2i (700, 500);
glVertex2i (600, 500);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 1
glBegin(GL_POLYGON);
glVertex2i (610, 460);
glVertex2i (630, 460);
glVertex2i (630, 480);
glVertex2i (610, 480);
glEnd();

glColor3ub (32, 32, 32);//building 5 window 2
glBegin(GL_POLYGON);
glVertex2i (640, 460);
glVertex2i (660, 460);
glVertex2i (660, 480);
glVertex2i (640, 480);
glEnd();

glColor3ub (32, 32, 32);//building 5 window 3
glBegin(GL_POLYGON);
glVertex2i (670, 460);
glVertex2i (690, 460);
glVertex2i (690, 480);
glVertex2i (670, 480);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 4
glBegin(GL_POLYGON);
glVertex2i (610, 430);
glVertex2i (630, 430);
glVertex2i (630, 450);
glVertex2i (610, 450);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 5
glBegin(GL_POLYGON);
glVertex2i (640, 430);
glVertex2i (660, 430);
glVertex2i (660, 450);
glVertex2i (640, 450);
glEnd();

glColor3ub (255, 255, 102);//building 5 window 6
glBegin(GL_POLYGON);
glVertex2i (670, 430);
glVertex2i (690, 430);
glVertex2i (690, 450);
glVertex2i (670, 450);
glEnd();
*/
/*glColor3ub (255, 51, 51);//Behind Clock Tower building
glBegin(GL_POLYGON);
glVertex2i (280, 340);
glVertex2i (345, 340);
glVertex2i (345, 460);
glVertex2i (280, 460);
glEnd();

*/
glColor3ub (153, 0, 76);//building4
glBegin(GL_POLYGON);
glVertex2i (130, 270);
glVertex2i (230, 270);
glVertex2i (230, 480);
glVertex2i (130, 480);
glEnd();

glColor3ub (255, 255, 102); //build4  window 1
glBegin(GL_POLYGON);
glVertex2i (150, 430);
glVertex2i (170, 430);
glVertex2i (170, 460);
glVertex2i (150, 460);
glEnd();

glColor3ub (32, 32, 32); //build4  window 2
glBegin(GL_POLYGON);
glVertex2i (190, 430);
glVertex2i (210, 430);
glVertex2i (210, 460);
glVertex2i (190, 460);
glEnd();


glColor3ub (32, 32, 32); //build4  window 3
glBegin(GL_POLYGON);
glVertex2i (150, 380);
glVertex2i (170, 380);
glVertex2i (170, 410);
glVertex2i (150, 410);
glEnd();

glColor3ub (255, 255, 102); //build4  window 4
glBegin(GL_POLYGON);
glVertex2i (190, 380);
glVertex2i (210, 380);
glVertex2i (210, 410);
glVertex2i (190, 410);
glEnd();


glColor3ub (0, 0, 102);//building5
glBegin(GL_POLYGON);
glVertex2i (50, 250);
glVertex2i (150, 250);
glVertex2i (150, 450);
glVertex2i (50, 450);
glEnd();

glColor3ub (255, 255, 102); //build5  window 1
glBegin(GL_POLYGON);
glVertex2i (70, 400);
glVertex2i (90, 400);
glVertex2i (90, 430);
glVertex2i (70, 430);
glEnd();

glColor3ub (255, 255, 102); //build5  window 2
glBegin(GL_POLYGON);
glVertex2i (110, 400);
glVertex2i (130, 400);
glVertex2i (130, 430);
glVertex2i (110, 430);
glEnd();


glColor3ub (255, 255, 102); //build5  window 3
glBegin(GL_POLYGON);
glVertex2i (70, 350);
glVertex2i (90, 350);
glVertex2i (90, 380);
glVertex2i (70, 380);
glEnd();

glColor3ub (255, 255, 102); //build5  window 4
glBegin(GL_POLYGON);
glVertex2i (110, 350);
glVertex2i (130, 350);
glVertex2i (130, 380);
glVertex2i (110, 380);
glEnd();


glColor3ub (204, 204, 0); //City clock Triangle
glBegin(GL_TRIANGLES);
glVertex2i (250, 420);
glVertex2i (295, 480);
glVertex2i (340, 420);
glEnd();

glColor3ub (102, 51, 0); //City Clock Polygon
glBegin(GL_POLYGON);
glVertex2i (250, 250);
glVertex2i (340, 250);
glVertex2i (340, 420);
glVertex2i (250, 420);
glEnd();

/*glColor3ub (0, 51, 0); //City Clock Door
glBegin(GL_POLYGON);
glVertex2i (280, 250);
glVertex2i (310, 250);
glVertex2i (310, 300);
glVertex2i (280, 300);
glEnd();

glColor3ub(0, 0, 0);//Clock outdoor line 1
glBegin(GL_LINE_LOOP);
glVertex2i(280,240);
glVertex2i(310,240);
glEnd();

glColor3ub(0, 0, 0);//Clock Outdoor Line 2
glBegin(GL_LINE_LOOP);
glVertex2i(280,235);
glVertex2i(310,235);
glEnd();
*/

//Clock Shape
int p1,x1,y1;
int xc1=295, yc1=380, r1=35;
p1=1-r1;
x1=0;
y1=r1;
while(x1<=y1)
{
if(p1<0)
{
x1=x1+1;
p1=p1+2*x1+1;
}
else
{
x1=x1+1;
y1=y1-1;
p1=p1+2*(x1+1)-2*(y1+1);
}
glColor3ub(160, 160, 160);
glBegin(GL_POLYGON);
glVertex2i(x1+xc1,y1+yc1);
glVertex2i(x1+xc1,-y1+yc1);
glVertex2i(-x1+xc1,-y1+yc1);
glVertex2i(-x1+xc1,y1+yc1);
glVertex2i(y1+xc1,x1+yc1);
glVertex2i(y1+xc1,-x1+yc1);
glVertex2i(-y1+xc1,-x1+yc1);
glVertex2i(-y1+xc1,x1+yc1);
glEnd();
}

glColor3ub(0, 0, 0);//Minute Clock
glBegin(GL_LINE_LOOP);
glVertex2i(295,380);
glVertex2i(295,410);
glEnd();

glColor3ub(0, 0, 0);//Hour Clock
glBegin(GL_LINE_LOOP);
glVertex2i(295,380);
glVertex2i(280,370);
glEnd();


/*glColor3ub(76,0,153);//1
glBegin(GL_POLYGON);
glVertex2i (410, 250);
glVertex2i (480, 210);
glVertex2i (480, 380);
glVertex2i (410, 400);
glEnd();

glColor3ub(153,0,153);//2
glBegin(GL_POLYGON);
glVertex2i (480, 210);
glVertex2i (520, 230);
glVertex2i (520, 400);
glVertex2i (480, 380);
glEnd();


glColor3ub(229,204,255);//3
glBegin(GL_POLYGON);
glVertex2i (410, 400);
glVertex2i (480, 380);
glVertex2i (520, 400);
glVertex2i (450, 420);
glEnd();
*/
/*
glColor3ub(153,0,0);//Building
glBegin(GL_POLYGON);
glVertex2i (550, 230);
glVertex2i (640, 230);
glVertex2i (640, 400);
glVertex2i (550, 400);
glEnd();


glColor3ub(32,32,32);//Building window
glBegin(GL_POLYGON);
glVertex2i (565, 350);
glVertex2i (590, 350);
glVertex2i (590, 380);
glVertex2i (565, 380);
glEnd();

glColor3ub(255,255,102);//Building window
glBegin(GL_POLYGON);
glVertex2i (600, 350);
glVertex2i (625, 350);
glVertex2i (625, 380);
glVertex2i (600, 380);
glEnd();


glColor3ub(255,255,102);//Building window
glBegin(GL_POLYGON);
glVertex2i (565, 310);
glVertex2i (590, 310);
glVertex2i (590, 340);
glVertex2i (565, 340);
glEnd();

glColor3ub(32,32,32);//Building window
glBegin(GL_POLYGON);
glVertex2i (600, 310);
glVertex2i (625, 310);
glVertex2i (625, 340);
glVertex2i (600, 340);
glEnd();

glColor3ub(32,32,32);//Playgroung Road
glBegin(GL_POLYGON);
glVertex2i (710, 330);
glVertex2i (730, 330);
glVertex2i (730, 350);
glVertex2i (710, 350);
glEnd();

*/


//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(50,185);
glVertex2f(50,255);
glVertex2f(65,255);
glVertex2f(65,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,250,l);
		draw_circle(80,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(50,290,l);
		draw_circle(70,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,315,l);
	}

//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(300,185);
glVertex2f(300,255);
glVertex2f(315,255);
glVertex2f(315,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,250,l);
		draw_circle(330,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(300,290,l);
		draw_circle(320,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(310,315,l);
	}


//tree 5
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(1050,185);
glVertex2f(1050,255);
glVertex2f(1065,255);
glVertex2f(1065,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1040,250,l);
		draw_circle(1080,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1050,290,l);
		draw_circle(1070,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(1060,315,l);
	}


//railway station
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(400,250);
glVertex2f(400,450);
glVertex2f(950,450);
glVertex2f(950,250);
glEnd();

//roof
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(350,450);
glVertex2f(450,500);
glVertex2f(900,500);
glVertex2f(1000,450);
glEnd();
//side window
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(400,400);
glVertex2f(350,350);
glVertex2f(400,350);
glEnd();

//side window
glColor3f(0.556863,0.419608,0.137255);
glBegin(GL_POLYGON);
glVertex2f(950,400);
glVertex2f(1000,350);
glVertex2f(950,350);
glEnd();


glColor3f(0.847059,0.847059,0.74902);
glBegin(GL_POLYGON);
glVertex2f(425,250);
glVertex2f(425,250);
glVertex2f(425,400);
glVertex2f(450,425);
glVertex2f(550,425);
glVertex2f(575,400);
glVertex2f(575,250);
glEnd();

glBegin(GL_POLYGON);    //window cover-right
glVertex2f(600,250);
glVertex2f(600,400);
glVertex2f(625,425);
glVertex2f(725,425);
glVertex2f(750,400);
glVertex2f(750,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(775,250);
glVertex2f(775,400);
glVertex2f(800,425);
glVertex2f(900,425);
glVertex2f(925,400);
glVertex2f(925,250);
glEnd();

//window 1
glColor3f(0.196867,0.6,0.6);
glBegin(GL_POLYGON);
glVertex2f(450,300);
glVertex2f(450,375);
glVertex2f(550,375);
glVertex2f(550,300);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(450,337.5);
glVertex2f(550,337.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(500,375);
glVertex2f(500,300);
glEnd();


//window 2
glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(800,300);
glVertex2f(800,375);
glVertex2f(900,375);
glVertex2f(900,300);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(800,337.5);
glVertex2f(900,337.5);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2f(850,375);
glVertex2f(850,300);
glEnd();

//door
glColor3f(0.329912,0.29412,0.329412);
glBegin(GL_POLYGON);
glVertex2f(625,250);
glVertex2f(625,375);
glVertex2f(725,375);
glVertex2f(725,250);
glEnd();

/*//track boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();
*/
//platform

glColor3f(0.560784,0.560784,0.737255);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,250);
glVertex2f(1100,250);
glVertex2f(1100,160);
glEnd();

//table 1

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(140,190);
glVertex2f(140,210);
glVertex2f(155,210);
glVertex2f(155,190);
glEnd();

glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(130,210);
glVertex2f(130,215);
glVertex2f(225,215);
glVertex2f(225,210);
glEnd();

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(200,190);
glVertex2f(200,210);
glVertex2f(215,210);
glVertex2f(215,190);
glEnd();

//table 2-bench

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(390,190);
glVertex2f(390,210);
glVertex2f(405,210);
glVertex2f(405,190);
glEnd();

glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(380,210);
glVertex2f(380,215);
glVertex2f(475,215);
glVertex2f(475,210);
glEnd();

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(450,190);
glVertex2f(450,210);
glVertex2f(465,210);
glVertex2f(465,190);
glEnd();

//table 3 -bench

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(840,190);
glVertex2f(840,210);
glVertex2f(855,210);
glVertex2f(855,190);
glEnd();

glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(830,210);
glVertex2f(830,215);
glVertex2f(925,215);
glVertex2f(925,210);
glEnd();

glColor3f(1.0,0.498039,0.0);
glBegin(GL_POLYGON);
glVertex2f(900,190);
glVertex2f(900,210);
glVertex2f(915,210);
glVertex2f(915,190);
glEnd();

/*//below track
glColor3f(0.623529,0.623529,0.372549);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();
*/

//Railway track

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100,0);
glVertex2f(-100,20);
glVertex2f(1100,20);
glVertex2f(1100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-100,80);
glVertex2f(-100,100);
glVertex2f(1100,100);
glVertex2f(1100,80);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,80);
glVertex2f(10,80);
glVertex2f(10,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(80,0);
glVertex2f(80,80);
glVertex2f(90,80);
glVertex2f(90,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(150,0);
glVertex2f(150,80);
glVertex2f(160,80);
glVertex2f(160,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(220,0);
glVertex2f(220,80);
glVertex2f(230,80);
glVertex2f(230,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(290,0);
glVertex2f(290,80);
glVertex2f(300,80);
glVertex2f(300,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(360,0);
glVertex2f(360,80);
glVertex2f(370,80);
glVertex2f(370,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(430,0);
glVertex2f(430,80);
glVertex2f(440,80);
glVertex2f(440,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(500,0);
glVertex2f(500,80);
glVertex2f(510,80);
glVertex2f(510,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(570,0);
glVertex2f(570,80);
glVertex2f(580,80);
glVertex2f(580,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(640,0);
glVertex2f(640,80);
glVertex2f(650,80);
glVertex2f(650,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(710,0);
glVertex2f(710,80);
glVertex2f(720,80);
glVertex2f(720,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(770,0);
glVertex2f(770,80);
glVertex2f(780,80);
glVertex2f(780,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(840,0);
glVertex2f(840,80);
glVertex2f(850,80);
glVertex2f(850,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(900,0);
glVertex2f(900,80);
glVertex2f(910,80);
glVertex2f(910,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(970,0);
glVertex2f(970,80);
glVertex2f(980,80);
glVertex2f(980,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1040,0);
glVertex2f(1040,80);
glVertex2f(1050,80);
glVertex2f(1050,0);
glEnd();

//track bounbary
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(-100,100);
glVertex2f(-100,150);
glVertex2f(1100,150);
glVertex2f(1100,100);
glEnd();

//railway station boundary (fence)
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(0,250);
glVertex2f(0,310);
glVertex2f(5,320);
glVertex2f(10,310);
glVertex2f(10,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,250);
glVertex2f(90,310);
glVertex2f(95,320);
glVertex2f(100,310);
glVertex2f(100,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(140,250);
glVertex2f(140,310);
glVertex2f(145,320);
glVertex2f(150,310);
glVertex2f(150,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(190,250);
glVertex2f(190,310);
glVertex2f(195,320);
glVertex2f(200,310);
glVertex2f(200,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(240,250);
glVertex2f(240,310);
glVertex2f(245,320);
glVertex2f(250,310);
glVertex2f(250,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(340,250);
glVertex2f(340,310);
glVertex2f(345,320);
glVertex2f(350,310);
glVertex2f(350,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(390,250);
glVertex2f(390,310);
glVertex2f(395,320);
glVertex2f(400,310);
glVertex2f(400,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,250);
glVertex2f(950,310);
glVertex2f(955,320);
glVertex2f(960,310);
glVertex2f(960,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1000,250);
glVertex2f(1000,310);
glVertex2f(1005,320);
glVertex2f(1010,310);
glVertex2f(1010,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1050,250);
glVertex2f(1050,310);
glVertex2f(1055,320);
glVertex2f(1060,310);
glVertex2f(1060,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,295);
glVertex2f(950,305);
glVertex2f(1100,305);
glVertex2f(1100,295);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(950,265);
glVertex2f(950,275);
glVertex2f(1100,275);
glVertex2f(1100,265);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,295);
glVertex2f(0,305);
glVertex2f(400,305);
glVertex2f(400,295);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,265);
glVertex2f(0,275);
glVertex2f(400,275);
glVertex2f(400,265);
glEnd();
                                    //road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();
                                    //road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();


                                    //signal
	glColor3f(1.0,.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();
	glColor3f(0.5,0.7,0.7);       //signal-cover
	glBegin(GL_POLYGON);
		glVertex2f(1030,350);
		glVertex2f(1030,500);
		glVertex2f(1095,500);
		glVertex2f(1095,350);
	glEnd();
	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}


glColor3f(0.9,0.0,0.0);  //new-one
glBegin(GL_POLYGON);
glVertex2f(-900+i,50);
glVertex2f(-900+i,125);
glVertex2f(-800+i,200);
glVertex2f(-700+i,200);
glVertex2f(-630+i,125);
glVertex2f(-590+i,115);
glVertex2f(-540+i,50);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-890+i,125);
glVertex2f(-800+i,190);
glVertex2f(-750+i,190);
glVertex2f(-750+i,125);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-740+i,125);
glVertex2f(-740+i,190);
glVertex2f(-700+i,190);
glVertex2f(-650+i,125);
glEnd();
for(l=0;l<25;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-800+i,50,l);
	draw_circle(-670+i,50,l);
   }
                                    //car 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(25+i,50);
glVertex2f(25+i,125);
glVertex2f(75+i,200);
glVertex2f(175+i,200);
glVertex2f(200+i,125);
glVertex2f(250+i,115);
glVertex2f(250+i,50);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(35+i,125);
glVertex2f(80+i,190);
glVertex2f(115+i,190);
glVertex2f(115+i,125);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(125+i,125);
glVertex2f(125+i,190);
glVertex2f(170+i,190);
glVertex2f(190+i,125);
glEnd();
for(l=0;l<20;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(75+i,50,l);
	draw_circle(175+i,50,l);
   }
                                    //car2
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-470+i,50);
glVertex2f(-470+i,112);
glVertex2f(-400+i,125);
glVertex2f(-372+i,210);
glVertex2f(-210+i,210);
glVertex2f(-180+i,125);
glVertex2f(-135+i,125);
glVertex2f(-110+i,50);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-410+i,125);
glVertex2f(-364+i,200);
glVertex2f(-300+i,200);
glVertex2f(-300+i,125);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
    glVertex2f(-290+i,125);
    glVertex2f(-290+i,200);
    glVertex2f(-217+i,200);
    glVertex2f(-192+i,125);
glEnd();
for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-350+i,50,l);
	draw_circle(-200+i,50,l);
   }
glColor3f(0.7,0.0,0.9);   //bus
glBegin(GL_POLYGON);
glVertex2f(350+i,50);
glVertex2f(350+i,275);
glVertex2f(722+i,275);
glVertex2f(750+i,175);
glVertex2f(750+i,50);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(650+i,175);
glVertex2f(650+i,260);
glVertex2f(720+i,260);
glVertex2f(745+i,175);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(550+i,175);
glVertex2f(550+i,260);
glVertex2f(625+i,260);
glVertex2f(625+i,175);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(450+i,175);
glVertex2f(450+i,260);
glVertex2f(525+i,260);
glVertex2f(525+i,175);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(375+i,175);
glVertex2f(375+i,260);
glVertex2f(425+i,260);
glVertex2f(425+i,175);
glEnd();
for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(450+i,50,l);
	draw_circle(625+i,50,l);
   }
glFlush();
}
void traffic_light()
{
	int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{
  glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
	glColor3f(0.0,0.7,0.0);
		draw_circle(1065,375,l);
		}
	  }
	else
	  {
for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);
	                                   // glColor3f(0.0,0.0,0.0);
                                    //draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
}
void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (i>=330 && i<=750))  //value of i when first vehicle is near the traffic-signal
 {
	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(light==0 && (i>=830 && i<=1100)) //value of i when second vehicle is near the traffic-signal
 {
	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(light==0 && (i>=1200 && i<=1620))// value of i when third vehicle is near the traffic signal
 {
	 i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(light==0)
 {
	 i=i;
	 ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
else
 {
     i+=SPEED/10;
     ++m;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>1630)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
if(c>500)
 {
	comet=0;
 }
glutPostRedisplay();
}
void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;
	case 'r':
	case 'R':
		light=0;
		break;
case 'd':
	case 'D':
		day=1;
		break;
	case 'n':
case 'N':
		day=0;
		break;
    };
}
void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;
	case 2:
	if(index==2)
	 {
		comet=1;
		 c=0.0;
	 }
	break;
	case 3:
        if(index==3)
        {
            exit(0);
        }
    break;
	}
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
traffic_light();
glFlush();
}
int main(int argc,char*argv[])
{
int c_menu;
    printf("\n");

    printf("     (How to Operate ?) \n\n\n");
	printf("  Press 'r' or 'R' to change the signal light to Red  \n\n");
	printf("  Press 'g' or 'G' to change the signal light to Green\n\n");
	printf("  Press 'd' or 'D' to make it Day Time                \n\n");
	printf("  Press 'n' or 'N' to make it Night Time              \n\n\n");
	printf("  Press RIGHT MOUSE BUTTON to display menu            \n\n");
	printf("  Select  'Aeroplane' to add moving Aeroplane      \n\n");
	printf("  Select  'Comet' to add moving Comet              \n\n");
	printf("  Select  'Quite' to Exit the application          \n\n");


    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(250,0);
	glutCreateWindow("Traffic Control");
	myinit();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	c_menu=glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane",1);
	glutAddMenuEntry("Comet",2);
	glutAddMenuEntry("Quite",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
