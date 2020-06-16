#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>
#define PI 3.1414926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))


//make a global variable -- for tracking the anglular position of camera
double cameraAngle;			//in radian
double cameraAngleDelta;

double cameraHeight;
double cameraRadius;

double rectAngle;	

bool canDrawGrid;

bool stopWindow = true;

bool keys[256];

double moveX;
double moveY;

int rotateX = 0;

int day_night = 0;
double light = 1;
double field = 0;

int left_right1 = 0;
int back = 0;

int head_light = 0;

int left_right2 = 0;
int car_color = 1;


void display() {

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//color blue sky
	if (day_night == 1)
	{
		glClearColor(0, .6, 1, 1);
	}
	//colore black sky	
	else {
		glClearColor(0.1, 0.1, 0.1, 1);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	

	gluLookAt(cameraRadius * cos(cameraAngle) + moveX, cameraRadius * sin(cameraAngle) + moveY, cameraHeight, 0 + moveX, 0 + moveY, 0, 0, 0, 1);
	


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

//	Green Field
	glColor3f(0 + field, .8 - field, 0.3);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, -90, -3);
		glVertex3f(10000, -90, -3);
		glVertex3f(10000, -1000, -3);
		glVertex3f(-10000, -1000, -3);
	}glEnd();

	glColor3f(0 + field, .8 - field, 0.3);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, 250, -3);
		glVertex3f(10000, 250, -3);
		glVertex3f(10000, 1000, -3);
		glVertex3f(-10000, 1000, -3);
	}glEnd();



	//	an square road

  //road
	glColor3f(0.0, 0.0, 0.0);
	//glColor3f(0.2 * light, 0.2 * light, 0.2 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, -100, 0);
		glVertex3f(10000, -100, 0);
		glVertex3f(10000, 260, 0);
		glVertex3f(-10000, 260, 0);
	}glEnd();

	glColor3f(1 - field, 1 - field, 0.1 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, 70, 1);
		glVertex3f(10000, 70, 1);
		glVertex3f(10000, 75, 1);
		glVertex3f(-10000, 75, 1);
	}glEnd();

	glColor3f(1 - field, 1 - field, 0.1 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, 80, 1);
		glVertex3f(10000, 80, 1);
		glVertex3f(10000, 85, 1);
		glVertex3f(-10000, 85, 1);
	}glEnd();


	glColor3f(.8 * light, .8 * light, .8 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, -75, 1);
		glVertex3f(10000, -75, 1);
		glVertex3f(10000, -80, 1);
		glVertex3f(-10000, -80, 1);
	}glEnd();


	glColor3f(.8 * light, .8 * light, .8 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, 235, 1);
		glVertex3f(10000, 235, 1);
		glVertex3f(10000, 240, 1);
		glVertex3f(-10000, 240, 1);
	}glEnd();

	glColor3f(.35 * light, .35 * light, .35 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, -90, 1);
		glVertex3f(10000, -90, 1);
		glVertex3f(10000, -100, 1);
		glVertex3f(-10000, -100, 1);
	}glEnd();

	glColor3f(.35 * light, .35 * light, .35 * light);
	glBegin(GL_QUADS); {
		glVertex3f(-10000, 250, 1);
		glVertex3f(10000, 250, 1);
		glVertex3f(10000, 260, 1);
		glVertex3f(-10000, 260, 1);
	}glEnd();


	if (head_light % 2 == 1)
	{
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, -100, 0.5);
			glVertex3f(-1000 + moveX, -100, 0.5);
			glVertex3f(-1000 + moveX, 260, 1.5);
			glVertex3f(-90 + moveX, 260, 1.5);
		}glEnd();

		glColor3f(1, 1, 0.1);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, 70, 0.5);
			glVertex3f(-1000 + moveX, 70, 0.5);
			glVertex3f(-1000 + moveX, 75, 0.5);
			glVertex3f(-90 + moveX, 75, 0.5);
		}glEnd();

		glColor3f(1, 1, 0.1);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, 80, 1.5);
			glVertex3f(-1000 + moveX, 80, 1.5);
			glVertex3f(-1000 + moveX, 85, 1.5);
			glVertex3f(-90 + moveX, 85, 1.5);
		}glEnd();


		glColor3f(.8, .8, .8);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, -75, 1.5);
			glVertex3f(-1000 + moveX, -75, 1.5);
			glVertex3f(-1000 + moveX, -80, 1.5);
			glVertex3f(-90 + moveX, -80, 1.5);
		}glEnd();


		glColor3f(.8, .8, .8);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, 235, 1.5);
			glVertex3f(-1000 + moveX, 235, 1.5);
			glVertex3f(-1000 + moveX, 240, 1.5);
			glVertex3f(-90 + moveX, 240, 1.5);
		}glEnd();

		glColor3f(.35, .35, .35);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, -90, 1.5);
			glVertex3f(-1000 + moveX, -90, 1.5);
			glVertex3f(-1000 + moveX, -100, 1.5);
			glVertex3f(-90 + moveX, -100, 1.5);
		}glEnd();

		glColor3f(.35, .35, .35);
		glBegin(GL_QUADS); {
			glVertex3f(-90 + moveX, 250, 1.5);
			glVertex3f(-1000 + moveX, 250, 1.5);
			glVertex3f(-1000 + moveX, 260, 1.5);
			glVertex3f(-90 + moveX, 260, 1.5);
		}glEnd();
	}


	

	for (int i = 10000; i >= -10000; i -= 500)
	{

		glPushMatrix(); {

			glColor3f(0.42, .26, .15);
			glTranslatef(i, -130, 0);
			glScalef(1, 1, 1);
			GLUquadricObj* obj = gluNewQuadric();

			gluCylinder(obj, 10, 10, 100, 10, 8);

			
			glTranslatef(0, 0, 100);
			glScalef(50, 50, 50);
			glBegin(GL_TRIANGLES);
			for (int k = 0; k <= 360; k += 5)
			{
				glColor3f(0.0, 1.0, 0.0);
				glVertex3f(0, 0, 1);
				glVertex3f(Cos(k), Sin(k), 0);
				glVertex3f(Cos(k + 5), Sin(k + 5), 0);
			}
			glEnd();
			


		}glPopMatrix();

	}

	
	for (int ii = 10000; ii >= -10000; ii -= 500)
	{

		glPushMatrix(); {


			
			glColor3f(0.42, .26, .15);
			glTranslatef(ii, 290, 0);
			glScalef(1, 1, 1);
			GLUquadricObj* obj = gluNewQuadric();
			gluCylinder(obj, 10, 10, 100, 10, 8);

			glTranslatef(0, 0, 100);
			glScalef(50, 50, 50);
			glBegin(GL_TRIANGLES);
			for (int k = 0; k <= 360; k += 5)
			{
				glColor3f(0.0, 1.0, 0.0);
				glVertex3f(0, 0, 1);
				glVertex3f(Cos(k), Sin(k), 0);
				glVertex3f(Cos(k + 5), Sin(k + 5), 0);
			}
			glEnd();



		}glPopMatrix();

	}

		
	glPushMatrix(); {
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		
		if (car_color == 1)
		{
			glColor3f(1.0, 0.0, 0.0);
		}
		else if (car_color == 2)
		{
			glColor3f(0.0, 0.0, 1.0);
		}
		else if (car_color == 3) 
		{
			glColor3f(0.0, 1.0, 0.0); 
		}
		else if (car_color == 4) 
		{
			glColor3f(0.0, 0.0, 0.0);
		}
		else if (car_color == 5) 
		{
			glColor3f(1.0, 1.0, 1.0);
		}
		else if (car_color == 6)
		{
			glColor3f(0.85, 0.55, 0.10);
		}




		//front lower
		glBegin(GL_QUADS); {
			glVertex3f(-75, -37, 3);
			glVertex3f(-75, -37, 8);
			glVertex3f(-82, -37, 8);
			glVertex3f(-82, -37, 5);
		}glEnd();


		glBegin(GL_QUADS); {
			glVertex3f(-75, 37, 3);
			glVertex3f(-75, 37, 8);
			glVertex3f(-82, 37, 8);
			glVertex3f(-82, 37, 5);
		}glEnd();

		//middle lower
		glBegin(GL_QUADS); {
			glVertex3f(-47, -37, 3);
			glVertex3f(-47, -37, 8);
			glVertex3f(47, -37, 8);
			glVertex3f(47, -37, 3);
		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-47, 37, 3);
			glVertex3f(-47, 37, 8);
			glVertex3f(47, 37, 8);
			glVertex3f(47, 37, 3);
		}glEnd();
		// back lower
		glBegin(GL_QUADS); {
			glVertex3f(75, 37, 3);
			glVertex3f(85, 37, 5);
			glVertex3f(85, 37, 8);
			glVertex3f(75, 37, 8);
		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(75, -37, 3);
			glVertex3f(85, -37, 5);
			glVertex3f(85, -37, 8);
			glVertex3f(75, -37, 8);
		}glEnd();





		//roof side left
		glBegin(GL_TRIANGLE_FAN); {
			//		glVertex3f(47,-37,40);
			for (float ai = 0.0; ai <= 3.15; ai += 0.1)
			{
				glVertex3f(47 * cos(ai), -37, 40 * sin(ai));
			}
			//		glVertex3f(60,-37,15);
			//		glVertex3f(47,-37,15);
			//		glVertex3f(47,-37,8);


		}glEnd();
		//right

		glBegin(GL_TRIANGLE_FAN); {
			//		glVertex3f(47,-37,40);
			for (float ai = 0.0; ai <= 3.15; ai += 0.1)
			{
				glVertex3f(47 * cos(ai), 37, 40 * sin(ai));
			}
			//		glVertex3f(60,-37,15);
			//		glVertex3f(47,-37,15);
			//		glVertex3f(47,-37,8);
		}glEnd();

		// front left
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-47, -37, 8);
			glVertex3f(0, -37, 8);

			glVertex3f(-47.5, -37, 8.5);
			glVertex3f(0, -37, 8.5);
			glVertex3f(-48, -37, 9);
			glVertex3f(0, -37, 9);
			glVertex3f(-48.5, -37, 9.5);
			glVertex3f(0, -37, 9.5);
			glVertex3f(-49, -37, 10);
			glVertex3f(0, -37, 10);

			glVertex3f(-49.5, -37, 10.5);
			glVertex3f(0, -37, 10.5);
			glVertex3f(-50, -37, 11);
			glVertex3f(0, -37, 11);
			glVertex3f(-50.5, -37, 11.5);
			glVertex3f(0, -37, 11.5);

			glVertex3f(-51, -37, 12);
			glVertex3f(0, -37, 12);
			glVertex3f(-51.5, -37, 12.5);
			glVertex3f(0, -37, 12.5);


			glVertex3f(-72, -37, 12.5);
			glVertex3f(0, -37, 12.5);



		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(0, -37, 12.5);
			glVertex3f(-79.5, -37, 12.5);
			glVertex3f(-79.5, -37, 21);
			glVertex3f(0, -37, 21);
		}glEnd();








		
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-75, -37, 8);
			glVertex3f(-82, -37, 8);

			glVertex3f(-74.5, -37, 8.5);
			glVertex3f(-81.9, -37, 8.5);
			glVertex3f(-74, -37, 9);
			glVertex3f(-81.8, -37, 9);

			glVertex3f(-73.5, -37, 9.5);
			glVertex3f(-81.7, -37, 9.5);




			glVertex3f(-73, -37, 10);
			glVertex3f(-81.6, -37, 10);
			glVertex3f(-72.8, -37, 10.5);
			glVertex3f(-81.5, -37, 10.5);

			glVertex3f(-72.6, -37, 11);
			glVertex3f(-81.4, -37, 11);
			glVertex3f(-72.4, -37, 11.5);
			glVertex3f(-81.3, -37, 11.5);
			glVertex3f(-72.2, -37, 12);
			glVertex3f(-81.25, -37, 12);


			glVertex3f(-72.1, -37, 12.3);
			glVertex3f(-81.1, -37, 12.3);


			glVertex3f(-72, -37, 12.5);
			glVertex3f(-81, -37, 12.5);

			glVertex3f(-72, -37, 13);
			glVertex3f(-80.8, -37, 13);


			glVertex3f(-72, -37, 14);
			glVertex3f(80.6, -37, 14);

			glVertex3f(-72, -37, 15);
			glVertex3f(-80.4, -37, 15);

			glVertex3f(-72, -37, 16);
			glVertex3f(-80.2, -37, 16);

			glVertex3f(-72, -37, 18);
			glVertex3f(-80, -37, 18);


			glVertex3f(-72, -37, 18);
			glVertex3f(-79.5, -37, 21);

			glVertex3f(-72, -37, 20);
			glVertex3f(-79.5, -37, 21);


			glVertex3f(-35, -37, 24);
			glVertex3f(-72, -37, 15);

			glVertex3f(-35, -37, 24);
			glVertex3f(-35, -37, 21);



		}glEnd();

		// front right
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-47, 37, 8);
			glVertex3f(0, 37, 8);

			glVertex3f(-47.5, 37, 8.5);
			glVertex3f(0, 37, 8.5);
			glVertex3f(-48, 37, 9);
			glVertex3f(0, 37, 9);
			glVertex3f(-48.5, 37, 9.5);
			glVertex3f(0, 37, 9.5);
			glVertex3f(-49, 37, 10);
			glVertex3f(0, 37, 10);

			glVertex3f(-49.5, 37, 10.5);
			glVertex3f(0, 37, 10.5);
			glVertex3f(-50, 37, 11);
			glVertex3f(0, 37, 11);
			glVertex3f(-50.5, 37, 11.5);
			glVertex3f(0, 37, 11.5);

			glVertex3f(-51, 37, 12);
			glVertex3f(0, 37, 12);
			glVertex3f(-51.5, 37, 12.5);
			glVertex3f(0, 37, 12.5);


			glVertex3f(-72, 37, 12.5);
			glVertex3f(0, 37, 12.5);



		}glEnd();
		//front front right
		glBegin(GL_QUADS); {
			glVertex3f(0, 37, 12.5);
			glVertex3f(-79.5, 37, 12.5);
			glVertex3f(-79.5, 37, 18);
			glVertex3f(0, 37, 18);
		}glEnd();

		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-75, 37, 8);
			glVertex3f(-82, 37, 8);

			glVertex3f(-74.5, 37, 8.5);
			glVertex3f(-81.9, 37, 8.5);
			glVertex3f(-74, 37, 9);
			glVertex3f(-81.8, 37, 9);

			glVertex3f(-73.5, 37, 9.5);
			glVertex3f(-81.7, 37, 9.5);




			glVertex3f(-73, 37, 10);
			glVertex3f(-81.6, 37, 10);
			glVertex3f(-72.8, 37, 10.5);
			glVertex3f(-81.5, 37, 10.5);

			glVertex3f(-72.6, 37, 11);
			glVertex3f(-81.4, 37, 11);
			glVertex3f(-72.4, 37, 11.5);
			glVertex3f(-81.3, 37, 11.5);
			glVertex3f(-72.2, 37, 12);
			glVertex3f(-81.25, 37, 12);


			glVertex3f(-72.1, 37, 12.3);
			glVertex3f(-81.1, 37, 12.3);


			glVertex3f(-72, 37, 12.5);
			glVertex3f(-81, 37, 12.5);

			glVertex3f(-72, 37, 13);
			glVertex3f(-80.8, 37, 13);


			glVertex3f(-72, 37, 14);
			glVertex3f(80.6, 37, 14);

			glVertex3f(-72, 37, 15);
			glVertex3f(-80.4, 37, 15);

			glVertex3f(-72, 37, 16);
			glVertex3f(-80.2, 37, 16);

			glVertex3f(-72, 37, 18);
			glVertex3f(-80, 37, 18);


			glVertex3f(-72, 37, 21);
			glVertex3f(-79.5, 37, 21);

			glVertex3f(-72, 37, 20);
			glVertex3f(-79.5, 37, 21);


			glVertex3f(-35, 37, 24);
			glVertex3f(-72, 37, 15);

			glVertex3f(-35, 37, 24);
			glVertex3f(-35, 37, 21);


		}glEnd();


		// back left
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(47, -37, 8);
			glVertex3f(0, -37, 8);

			glVertex3f(47.5, -37, 8.5);
			glVertex3f(0, -37, 8.5);
			glVertex3f(48, -37, 9);
			glVertex3f(0, -37, 9);
			glVertex3f(48.5, -37, 9.5);
			glVertex3f(0, -37, 9.5);
			glVertex3f(49, -37, 10);
			glVertex3f(0, -37, 10);

			glVertex3f(49.5, -37, 10.5);
			glVertex3f(0, -37, 10.5);
			glVertex3f(50, -37, 11);
			glVertex3f(0, -37, 11);
			glVertex3f(50.5, -37, 11.5);
			glVertex3f(0, -37, 11.5);

			glVertex3f(51, -37, 12);
			glVertex3f(0, -37, 12);
			glVertex3f(51.5, -37, 12.5);
			glVertex3f(0, -37, 12.5);


			glVertex3f(72, -37, 12.5);
			glVertex3f(0, -37, 12.5);



		}glEnd();
		glBegin(GL_QUADS); {
			glVertex3f(0, -37, 12.5);
			glVertex3f(72, -37, 12.5);
			glVertex3f(72, -37, 20);
			glVertex3f(0, -37, 20);
		}glEnd();

		//back right
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(47, 37, 8);
			glVertex3f(0, 37, 8);

			glVertex3f(47.5, 37, 8.5);
			glVertex3f(0, 37, 8.5);
			glVertex3f(48, 37, 9);
			glVertex3f(0, 37, 9);
			glVertex3f(48.5, 37, 9.5);
			glVertex3f(0, 37, 9.5);
			glVertex3f(49, 37, 10);
			glVertex3f(0, 37, 10);

			glVertex3f(49.5, 37, 10.5);
			glVertex3f(0, 37, 10.5);
			glVertex3f(50, 37, 11);
			glVertex3f(0, 37, 11);
			glVertex3f(50.5, 37, 11.5);
			glVertex3f(0, 37, 11.5);

			glVertex3f(51, 37, 12);
			glVertex3f(0, 37, 12);
			glVertex3f(51.5, 37, 12.5);
			glVertex3f(0, 37, 12.5);


			glVertex3f(72, 37, 12.5);
			glVertex3f(0, 37, 12.5);

		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(0, 37, 12.5);
			glVertex3f(72, 37, 12.5);
			glVertex3f(72, 37, 20);
			glVertex3f(0, 37, 20);
		}glEnd();

		//back back right

		glBegin(GL_QUAD_STRIP); {
			glVertex3f(75, 37, 8);
			glVertex3f(85, 37, 8);

			glVertex3f(74.5, 37, 8.5);
			glVertex3f(84.9, 37, 8.5);
			glVertex3f(74, 37, 9);
			glVertex3f(84.8, 37, 9);

			glVertex3f(73.5, 37, 9.5);
			glVertex3f(84.7, 37, 9.5);
			glVertex3f(73, 37, 10);
			glVertex3f(84.6, 37, 10);
			glVertex3f(72.8, 37, 10.5);
			glVertex3f(84.5, 37, 10.5);

			glVertex3f(72.6, 37, 11);
			glVertex3f(84.4, 37, 11);
			glVertex3f(72.4, 37, 11.5);
			glVertex3f(84.3, 37, 11.5);
			glVertex3f(72.2, 37, 12);
			glVertex3f(84.25, 37, 12);

			glVertex3f(72.1, 37, 12);
			glVertex3f(84.2, 37, 12);
			glVertex3f(72.1, 37, 12.3);
			glVertex3f(84.1, 37, 12.3);


			glVertex3f(72, 37, 12.5);
			glVertex3f(84, 37, 12.5);

			glVertex3f(72, 37, 13);
			glVertex3f(83.8, 37, 13);


			glVertex3f(72, 37, 14);
			glVertex3f(83.6, 37, 14);

			glVertex3f(72, 37, 15);
			glVertex3f(83.4, 37, 15);

			glVertex3f(72, 37, 16);
			glVertex3f(83.2, 37, 16);

			glVertex3f(72, 37, 17);
			glVertex3f(83, 37, 17);


			glVertex3f(72, 37, 18);
			glVertex3f(82.8, 37, 18);

			glVertex3f(72, 37, 19);
			glVertex3f(82.6, 37, 19);

			glVertex3f(72, 37, 20);
			glVertex3f(82.4, 37, 20);

			glVertex3f(72, 37, 20);
			glVertex3f(82.2, 37, 20);


			glVertex3f(32, 37, 26);
			glVertex3f(82, 37, 20);

			glVertex3f(32, 37, 20);
			glVertex3f(82.2, 37, 20);

			glVertex3f(82, 37, 20);
			glVertex3f(28, 37, 32);



		}glEnd();

		//back back left
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(75, -37, 8);
			glVertex3f(85, -37, 8);

			glVertex3f(74.5, -37, 8.5);
			glVertex3f(84.9, -37, 8.5);
			glVertex3f(74, -37, 9);
			glVertex3f(84.8, -37, 9);

			glVertex3f(73.5, -37, 9.5);
			glVertex3f(84.7, -37, 9.5);
			glVertex3f(73, -37, 10);
			glVertex3f(84.6, -37, 10);
			glVertex3f(72.8, -37, 10.5);
			glVertex3f(84.5, -37, 10.5);

			glVertex3f(72.6, -37, 11);
			glVertex3f(84.4, -37, 11);
			glVertex3f(72.4, -37, 11.5);
			glVertex3f(84.3, -37, 11.5);
			glVertex3f(72.2, -37, 12);
			glVertex3f(84.25, -37, 12);

			glVertex3f(72.1, -37, 12);
			glVertex3f(84.2, -37, 12);
			glVertex3f(72.1, -37, 12.3);
			glVertex3f(84.1, -37, 12.3);


			glVertex3f(72, -37, 12.5);
			glVertex3f(84, -37, 12.5);

			glVertex3f(72, -37, 13);
			glVertex3f(83.8, -37, 13);


			glVertex3f(72, -37, 14);
			glVertex3f(83.6, -37, 14);

			glVertex3f(72, -37, 15);
			glVertex3f(83.4, -37, 15);

			glVertex3f(72, -37, 16);
			glVertex3f(83.2, -37, 16);

			glVertex3f(72, -37, 17);
			glVertex3f(83, -37, 17);


			glVertex3f(72, -37, 18);
			glVertex3f(82.8, -37, 18);

			glVertex3f(72, -37, 19);
			glVertex3f(82.6, -37, 19);

			glVertex3f(72, -37, 20);
			glVertex3f(82.4, -37, 20);

			glVertex3f(72, -37, 20);
			glVertex3f(82.2, -37, 20);


			glVertex3f(32, -37, 26);
			glVertex3f(82, -37, 20);

			glVertex3f(32, -37, 20);
			glVertex3f(82.2, -37, 20);

			glVertex3f(82, -37, 20);
			glVertex3f(28, -37, 32);



		}glEnd();

		// front front top
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-79.5, -37, 21);
			glVertex3f(-79.5, 37, 21);

			glVertex3f(-80.5, -37, 9);
			glVertex3f(-80.5, 37, 9);

			glVertex3f(-81.5, -37, 8);
			glVertex3f(-81.5, 37, 8);


			glVertex3f(-82, -37, 5);
			glVertex3f(-82, 37, 5);


		}glEnd();

		//front top
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-79.5, -27, 21);
			glVertex3f(-79.5, 27, 21);

			glVertex3f(-70, -27, 22);
			glVertex3f(-70, 27, 22);

			glVertex3f(-60, -27, 23);
			glVertex3f(-60, 27, 23);

			glVertex3f(-50, -27, 24);
			glVertex3f(-50, 27, 24);

			glVertex3f(-45, -27, 25);
			glVertex3f(-45, 27, 25);

			glVertex3f(-40, -27, 26);
			glVertex3f(-40, 27, 26);

			glVertex3f(-35, -27, 27);
			glVertex3f(-35, 27, 27);



		}glEnd();

		//front side top right
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-79.5, 37, 21);
			glVertex3f(-35, 37, 24);

			glVertex3f(-79.5, 33, 21);
			glVertex3f(-35, 33, 24.1);

			glVertex3f(-79.5, 31, 21);
			glVertex3f(-35, 31, 24.2);

			glVertex3f(-79.5, 29, 21);
			glVertex3f(-35, 29, 24.1);

			glVertex3f(-79.5, 26, 21);
			glVertex3f(-35, 26, 24);



		}glEnd();


		//front side top left
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-79.5, -37, 21);
			glVertex3f(-35, -37, 24);

			glVertex3f(-79.5, -33, 21);
			glVertex3f(-35, -33, 24.1);

			glVertex3f(-79.5, -31, 21);
			glVertex3f(-35, -31, 24.2);

			glVertex3f(-79.5, -29, 21);
			glVertex3f(-35, -29, 24.1);

			glVertex3f(-79.5, -26, 21);
			glVertex3f(-35, -26, 24);



		}glEnd();

		//top first
		//glColor3f(0.5,0.5,0.5);
		glBegin(GL_QUAD_STRIP); {

			glVertex3f(0, 37, 40);
			glVertex3f(0, -37, 40);

			glVertex3f(-2, 37, 39.6);
			glVertex3f(-2, -37, 39.6);

			glVertex3f(-4, 37, 39.3);
			glVertex3f(-4, -37, 39.3);

			glVertex3f(-6, 37, 39);
			glVertex3f(-6, -37, 39);

			glVertex3f(-8, 37, 38.6);
			glVertex3f(-8, -37, 38.6);

			glVertex3f(-10, 37, 38.3);
			glVertex3f(-10, -37, 38.3);


			glVertex3f(-12, 37, 38);
			glVertex3f(-12, -37, 38);

			glVertex3f(-14, 37, 37.6);
			glVertex3f(-14, -37, 37.6);

			glVertex3f(-16, 37, 37.3);
			glVertex3f(-16, -37, 37.3);

			glVertex3f(-18, 37, 37.1);
			glVertex3f(-18, -37, 37.1);

			glVertex3f(-19, 37, 37);
			glVertex3f(-19, -37, 37);


			glVertex3f(-20, 37, 36.3);
			glVertex3f(-20, -37, 36.3);

			glVertex3f(-35, 37, 24);
			glVertex3f(-35, -37, 24);

		}glEnd();

		//top second

		glBegin(GL_QUAD_STRIP); {

			glVertex3f(0, 37, 40);
			glVertex3f(0, -37, 40);

			glVertex3f(2, 37, 39.6);
			glVertex3f(2, -37, 39.6);

			glVertex3f(4, 37, 39.3);
			glVertex3f(4, -37, 39.3);

			glVertex3f(6, 37, 39);
			glVertex3f(6, -37, 39);

			glVertex3f(8, 37, 38.6);
			glVertex3f(8, -37, 38.6);

			glVertex3f(10, 37, 38.3);
			glVertex3f(10, -37, 38.3);


			glVertex3f(12, 37, 38);
			glVertex3f(12, -37, 38);

			glVertex3f(14, 37, 37.6);
			glVertex3f(14, -37, 37.6);

			glVertex3f(16, 37, 37.3);
			glVertex3f(16, -37, 37.3);

			glVertex3f(18, 37, 37.1);
			glVertex3f(18, -37, 37.1);

			glVertex3f(19, 37, 37);
			glVertex3f(19, -37, 37);


			glVertex3f(20, 37, 36);
			glVertex3f(20, -37, 36);



		}glEnd();
		//glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS); {
			glVertex3f(19, 37, 37.1);
			glVertex3f(19, -37, 37.1);
			glVertex3f(45, -37, 28);
			glVertex3f(45, 37, 28);

		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(42, 37, 28);
			glVertex3f(42, -37, 28);
			glVertex3f(50, -37, 27.8);
			glVertex3f(50, 37, 27.8);

		}glEnd();


		glBegin(GL_QUADS); {
			glVertex3f(50, 37, 27.8);
			glVertex3f(50, -37, 27.8);
			glVertex3f(55, -37, 27.8);
			glVertex3f(55, 37, 27.8);

		}glEnd();

		//back end left	
		//glColor3f(0.97,0.97,0.97);
		glBegin(GL_QUADS); {
			glVertex3f(55, 37, 27.8);
			glVertex3f(55, -37, 27.8);

			glVertex3f(83, -37, 23.5);
			glVertex3f(83, 37, 23.5);

		}glEnd();

		glBegin(GL_QUAD_STRIP); {
			glVertex3f(83, -37, 23.5);
			glVertex3f(82, -37, 20);

			glVertex3f(55, -37, 27.8);
			glVertex3f(50, -37, 25);
			glVertex3f(45, -37, 22);
		}glEnd();

		//back end right


		glBegin(GL_QUAD_STRIP); {
			glVertex3f(83, 37, 23.5);
			glVertex3f(82, 37, 20);

			glVertex3f(55, 37, 27.8);
			glVertex3f(50, 37, 25);
			glVertex3f(45, 37, 22);
		}glEnd();
		//back end lower
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(85, 37, 5);
			glVertex3f(85, -37, 5);

			glVertex3f(82, 37, 20);
			glVertex3f(82, -37, 20);

			glVertex3f(83, 37, 23.5);
			glVertex3f(83, -37, 23.5);

		}glEnd();

		//front design fog
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-82.5, -37, 4.5);
			glVertex3f(-81, -37, 12.5);

			glVertex3f(-82.5, 0, 4.5);
			glVertex3f(-82, 0, 10);

			glVertex3f(-82.5, 37, 4.5);
			glVertex3f(-81, 37, 12.5);
		}glEnd();




		/*
	//glass back

	glColor3f(0.1,0.1,0.1);
		glBegin(GL_QUADS);{
			glVertex3f(21,35,37.05);
			glVertex3f(21,-35,37.05);
			glVertex3f(45,-35,28.05);
			glVertex3f(45,35,28.05);

		}glEnd();

		glBegin(GL_QUADS);{
			glVertex3f(48,35,28.1);
			glVertex3f(48,-35,28.1);
			glVertex3f(48,-35,27.9);
			glVertex3f(48,35,27.9);

		}glEnd();


		glBegin(GL_QUADS);{
			glVertex3f(48,35,27.9);
			glVertex3f(48,-35,27.9);
			glVertex3f(48,-35,27.9);
			glVertex3f(48,35,27.9);

		}glEnd();


	//glass front

		glBegin(GL_QUADS);{
			glVertex3f(-21,34,37);
			glVertex3f(-21,-34,37);
			glVertex3f(-45,-34,24);
			glVertex3f(-45,34,24);

		}glEnd();

	*/
	//fine tunes
	//front
	//glColor3f(0.97,0.97,0.97);	
		glBegin(GL_TRIANGLE_STRIP); {
			glVertex3f(-21, 34, 37);

			glVertex3f(-48, 34, 24);
			glVertex3f(0, 37, 22);
			glVertex3f(0, 37, 40);
		}glEnd();

		glBegin(GL_TRIANGLE_STRIP); {
			glVertex3f(-21, -34, 37);

			glVertex3f(-48, -34, 24);
			glVertex3f(0, -37, 22);
			glVertex3f(0, -37, 40);
		}glEnd();


		glBegin(GL_TRIANGLES); {
			glVertex3f(-80, -37, 20);;
			glVertex3f(-35, -37, 18);
			glVertex3f(-35, -37, 25);
		}glEnd();
		//	glColor3f(.5,.5,.5);
		glBegin(GL_TRIANGLES); {
			glVertex3f(-80, 37, 20);;
			glVertex3f(-35, 37, 16);
			glVertex3f(-35, 37, 25);
		}glEnd();
		//	glColor3f(.5,.5,.5);

		glBegin(GL_QUADS); {
			glVertex3f(-79.5, -37, 17);

			glVertex3f(-79.5, 37, 17);
			glVertex3f(57, 37, 21);
			glVertex3f(54, -37, 21);
		}glEnd();
		glBegin(GL_QUADS); {
			glVertex3f(-79.5, -37, 20.5);

			glVertex3f(-79.5, 37, 20.5);
			glVertex3f(-45, 37, 24);
			glVertex3f(-45, -37, 24);
		}glEnd();
		//back

		glBegin(GL_TRIANGLE_STRIP); {
			glVertex3f(21, -35, 37.05);

			glVertex3f(46, -36, 28.05);
			glVertex3f(0, -37, 22);
			glVertex3f(0, -37, 40);
		}glEnd();

		glBegin(GL_TRIANGLE_STRIP); {
			glVertex3f(21, 35, 37.05);

			glVertex3f(46, 36, 28.05);
			glVertex3f(0, 37, 22);
			glVertex3f(0, 37, 40);
		}glEnd();
		glBegin(GL_QUADS); {
			glVertex3f(45, -37, 28.05);

			glVertex3f(55, -37, 27.75);
			glVertex3f(55, -37, 22);
			glVertex3f(45, -37, 22);
		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(45, 37, 28.05);

			glVertex3f(55, 37, 27.75);
			glVertex3f(55, 37, 22);
			glVertex3f(45, 37, 22);
		}glEnd();

		// for looking glass holder
		glPushMatrix(); {

			//	glColor3f(.5,0.7,.5);
			glTranslatef(-45, -40.5, 24);
			glScalef(.4, 2.5, .8);

			glutSolidCube(3.5);
		}glPopMatrix();

		glPushMatrix(); {

			//	glColor3f(.5,0.7,.5);
			glTranslatef(-45, 40.5, 24);
			glScalef(.4, 2.5, .8);

			glutSolidCube(3.5);
		}glPopMatrix();

		//glColor3f(.5,0.7,.5);

		glBegin(GL_TRIANGLES); {
			glVertex3f(-47, -37, 8);

			glVertex3f(-49, -37, 13);
			glVertex3f(-55, -37, 13);

		}glEnd();

		glBegin(GL_TRIANGLES); {
			glVertex3f(-47, 37, 8);

			glVertex3f(-49, 37, 13);
			glVertex3f(-55, 37, 13);

		}glEnd();


		glBegin(GL_TRIANGLES); {
			glVertex3f(46.5, -37, 8);

			glVertex3f(50, -37, 13);
			glVertex3f(56, -37, 13);

		}glEnd();

		glBegin(GL_TRIANGLES); {
			glVertex3f(46.5, 37, 8);

			glVertex3f(50, 37, 13);
			glVertex3f(56, 37, 13);

		}glEnd();



		glBegin(GL_TRIANGLES); {
			glVertex3f(76, -37, 8);

			glVertex3f(66, -37, 13);
			glVertex3f(73, -37, 13);

		}glEnd();

		glBegin(GL_TRIANGLES); {
			glVertex3f(76, 37, 8);

			glVertex3f(66, 37, 13);
			glVertex3f(73, 37, 13);

		}glEnd();


		glBegin(GL_TRIANGLES); {
			glVertex3f(-75, -37, 7.5);

			glVertex3f(-68, -37, 13.5);
			glVertex3f(-74, -37, 13.5);

		}glEnd();

		glBegin(GL_TRIANGLES); {
			glVertex3f(-75, 37, 7.5);

			glVertex3f(-68, 37, 13.5);
			glVertex3f(-74, 37, 13.5);

		}glEnd();

	}glPopMatrix();






	//glass

	//glass back
	glPushMatrix(); {
		glColor3f(0.15, 0.15, 0.15);
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);


		glBegin(GL_QUADS); {
			glVertex3f(21, 35, 37.1);
			glVertex3f(21, -35, 37.1);
			glVertex3f(46, -35, 28.2);
			glVertex3f(46, 35, 28.2);

		}glEnd();
		/*
			glBegin(GL_QUADS);{
				glVertex3f(48,35,28.1);
				glVertex3f(48,-35,28.1);
				glVertex3f(48,-35,27.9);
				glVertex3f(48,35,27.9);

			}glEnd();


			glBegin(GL_QUADS);{
				glVertex3f(48,35,27.9);
				glVertex3f(48,-35,27.9);
				glVertex3f(48,-35,27.9);
				glVertex3f(48,35,27.9);

			}glEnd();
		*/

		//glass front

		glBegin(GL_QUADS); {
			glVertex3f(-21.5, 32, 37.1);
			glVertex3f(-21.5, -32, 37.1);
			glVertex3f(-45, -33, 26.1);
			glVertex3f(-45, 33, 26.1);

		}glEnd();
		//glass side
		/*
			glBegin(GL_QUADS);{
				glVertex3f(-45,-37.5,21);
				glVertex3f(-45,-37.5,23);
				glVertex3f(0,-37.5,23);
				glVertex3f(0,-37.5,37);

			}glEnd();

				glBegin(GL_QUADS);{
				glVertex3f(-45,37.5,21);
				glVertex3f(-45,37.5,23);
				glVertex3f(0,37.5,23);
				glVertex3f(0,37.5,37);

			}glEnd();

				glBegin(GL_QUADS);{
				glVertex3f(40,-37.5,25);
				glVertex3f(40,-37.5,21);
				glVertex3f(3,-37.5,23);
				glVertex3f(3,-37.5,37);

			}glEnd();

				glBegin(GL_QUADS);{
				glVertex3f(40,37.5,25);
				glVertex3f(40,37.5,21);
				glVertex3f(3,37.5,23);
				glVertex3f(3,37.5,37);

			}glEnd();
		*/
		/*

			glBegin(GL_TRIANGLE_FAN);{
				glVertex3f(10,-37.5,24);
		//		for(float ai=0.0;ai<=45;ai+=.1)
		//		{
		//			glVertex3f(40*cos(ai),40,40*sin(ai));
		//		}

				//		glVertex3f(60,-37,15);
				glVertex3f(-44,-37.5,24);
				glVertex3f(-43,-37.5,25);
				glVertex3f(-41,-37.5,26);
				glVertex3f(-39,-37.5,27);
				glVertex3f(-35,-37.5,29);
				glVertex3f(-31,-37.5,31);
		//		glVertex3f(-30,-39,31.5);
		//		glVertex3f(-29,-39,31.75);
				glVertex3f(-28,-37.5,32);
		//		glVertex3f(-27,-39,32.25);
				glVertex3f(-26.5,-37.5,33);
				glVertex3f(-25,-37.5,33.25);








				glVertex3f(-20,-37.5,35.5);
				glVertex3f(-19,-37.5,35.75);
				glVertex3f(-18,-37.5,35.85);
				glVertex3f(-17,-37.5,36);
				glVertex3f(-16,-37.5,37);
				glVertex3f(-10,-37.5,38);
				glVertex3f(0,-37.5,38.5);
				glVertex3f(10,-37.5,38);
			}glEnd();
		*/
		// glass side

		// door 

		glBegin(GL_LINE_STRIP); {
			glVertex3f(10, -37.5, 23.5);
			glVertex3f(12, -37.5, 18);
			//		glVertex3f(15,-37.5,14);
			//		glVertex3f(12,-37.5,10);
			glVertex3f(11, -37.5, 8);
			glVertex3f(10, -37.5, 4);
			glVertex3f(-44, -37.5, 5);
			glVertex3f(-45, -37.5, 12);
			glVertex3f(-44, -37.5, 24);
		}glEnd();

		glBegin(GL_LINE_STRIP); {
			glVertex3f(10, 37.5, 23.5);
			glVertex3f(12, 37.5, 18);
			//		glVertex3f(15,-37.5,14);
			//		glVertex3f(12,-37.5,10);
			glVertex3f(11, 37.5, 8);
			glVertex3f(10, 37.5, 4);
			glVertex3f(-44, 37.5, 5);
			glVertex3f(-45, 37.5, 12);
			glVertex3f(-44, 37.5, 24);
		}glEnd();

		glBegin(GL_LINES); {
			glVertex3f(10, -37.5, 4);
			glVertex3f(47, -37.5, 4);
			glVertex3f(-44, -37.5, 5);
			glVertex3f(-47, -37.5, 5);
			glVertex3f(-75, -37.5, 7);
			glVertex3f(-82, -37.5, 6.8);
		}glEnd();

		glBegin(GL_LINES); {
			glVertex3f(10, 37.5, 4);
			glVertex3f(47, 37.5, 4);
			glVertex3f(-44, 37.5, 5);
			glVertex3f(-47, 37.5, 5);
			glVertex3f(-75, 37.5, 7);
			glVertex3f(-82, 37.5, 6.8);
		}glEnd();

		glBegin(GL_LINE_STRIP); {
			glVertex3f(66, -37.5, 12.5);
			glVertex3f(77, -37.5, 13.5);
			glVertex3f(81, -37.5, 15);
			//		glVertex3f(-47,37.5,5);
		}glEnd();

		glBegin(GL_LINE_STRIP); {
			glVertex3f(66, 37.5, 12.5);
			glVertex3f(77, 37.5, 13.5);
			glVertex3f(81, 37.5, 15);
			//		glVertex3f(-47,37.5,5);
		}glEnd();

		glBegin(GL_LINE_STRIP); {
			glVertex3f(-65, -37.5, 12.5);
			glVertex3f(-70, -37.5, 14);
			glVertex3f(-76, -37.5, 18);
			glVertex3f(-79, -37.5, 20);

		}glEnd();

		glBegin(GL_LINE_STRIP); {
			glVertex3f(-65, 37.5, 12.5);
			glVertex3f(-70, 37.5, 14);
			glVertex3f(-76, 37.5, 18);
			glVertex3f(-79, 37.5, 20);

		}glEnd();


		glBegin(GL_LINE_STRIP); {
			/*		glVertex3f(86,-36.5,22);
					glVertex3f(85,-35.5,20);
					glVertex3f(85,34,15);
					glVertex3f(85,-33,12);
					glVertex3f(86,33,12);
					glVertex3f(47,-35,28);
					glVertex3f(47,35,28);
					glVertex3f(83,33,26);

					glVertex3f(83,-33,26);
					glVertex3f(47,-35,28);
			*/
			glVertex3f(83, -28, 23);
			glVertex3f(84, -26, 12);
			glVertex3f(84, 26, 12);
			glVertex3f(83, 28, 23);
			glVertex3f(83, -28, 23);
			//		glVertex3f(84,33.5,22);
			//		glVertex3f(84,-33.5,22);

		}glEnd();

		glBegin(GL_LINE_STRIP); {


			glVertex3f(83, -18, 19);
			glVertex3f(84, -19, 14);
			glVertex3f(84, 19, 14);
			glVertex3f(83, 18, 19);
			glVertex3f(83, -18, 19);


		}glEnd();
		/*
				glBegin(GL_LINE_STRIP);{


				glVertex3f(83,-18,19);
				glVertex3f(84,-19,14);
				glVertex3f(84,19,14);
				glVertex3f(83,18,19);
				glVertex3f(83,-18,19);


			  }glEnd();

		*/

		glBegin(GL_LINE_STRIP); {
			glVertex3f(-83, -37, 5.5);
			glVertex3f(-81.5, -37, 12.5);

			glVertex3f(-82, -1, 10);
			glVertex3f(-83, -1, 5.5);
			glVertex3f(-83, -37, 5.5);

			//		glVertex3f(-82.5,37,4.5);
			//		glVertex3f(-81,37,12.5);
		}glEnd();

		glBegin(GL_LINE_STRIP); {
			glVertex3f(-83, 37, 5.5);
			glVertex3f(-81.5, 37, 12.5);

			glVertex3f(-82, 1, 10);
			glVertex3f(-83, 1, 5.5);
			glVertex3f(-83, 37, 5.5);

			//		glVertex3f(-82.5,37,4.5);
			//		glVertex3f(-81,37,12.5);
		}glEnd();













		glPushMatrix(); {
			glTranslatef(10, 0, 23);
			glBegin(GL_TRIANGLE_FAN); {
				glVertex3f(0, -37.5, 0);
				for (float ai = 0.0; ai <= 1.58; ai += .01)
				{
					glVertex3f(-45 * cos(ai), -37.5, 15 * sin(ai));
				}


			}glEnd();

		}glPopMatrix();

		glBegin(GL_QUADS); {
			glVertex3f(45, -37.5, 26);
			glVertex3f(45, -37.5, 23);
			glVertex3f(11.9, -37.5, 23);
			glVertex3f(11.9, -37.5, 37.5);

		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-26, -37.5, 32);
			glVertex3f(-26, -37.5, 23);
			glVertex3f(-46, -37.5, 23);
			glVertex3f(-46, -37.5, 22);

		}glEnd();

		glPushMatrix(); {
			glTranslatef(10, 0, 23);
			glBegin(GL_TRIANGLE_FAN); {
				glVertex3f(0, 37.5, 0);
				for (float ai = 0.0; ai <= 1.58; ai += .01)
				{
					glVertex3f(-45 * cos(ai), 37.5, 15 * sin(ai));
				}


			}glEnd();

		}glPopMatrix();

		glBegin(GL_QUADS); {
			glVertex3f(45, 37.5, 26);
			glVertex3f(45, 37.5, 23);
			glVertex3f(11.9, 37.5, 23);
			glVertex3f(11.9, 37.5, 37.5);

		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-26, 37.5, 32);
			glVertex3f(-26, 37.5, 23);
			glVertex3f(-46, 37.5, 23);
			glVertex3f(-46, 37.5, 22);

		}glEnd();



	}glPopMatrix();

	// back light

	glPushMatrix(); {

		glColor3f(.9, 0.3 * light, 0.3 * light);
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(83, -37, 13.5);
			glVertex3f(82.8, -37, 20);

			glVertex3f(83, -20, 20);
			glVertex3f(82.8, -20, 13.5);



		}glEnd();
		glBegin(GL_QUADS); {
			glVertex3f(83, 37, 13.5);
			glVertex3f(82.8, 37, 20);

			glVertex3f(83, 20, 20);
			glVertex3f(82.8, 20, 13.5);



		}glEnd();


		glBegin(GL_QUAD_STRIP); {

			glVertex3f(83.5, -37.15, 15);
			glVertex3f(83, -37.15, 20);
			glVertex3f(78, -37.15, 15);
			glVertex3f(78, -37.15, 20);



		}glEnd();


		glBegin(GL_QUAD_STRIP); {

			glVertex3f(83.5, 37.15, 15);
			glVertex3f(83, 37.15, 20);
			glVertex3f(78, 37.15, 15);
			glVertex3f(78, 37.15, 20);


		}glEnd();

	}glPopMatrix();

	//silencer back

	glPushMatrix(); {

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glColor3f(0.3, 0.3, .3);
		GLUquadricObj* obj = gluNewQuadric();

		//		gluCylinder(obj,4,2,100,10,8);
		//light upper
			 //	glColor3f(1,1,.9*light);
		glTranslatef(80, -15, 5);
		glRotatef(90, 0, 1, 0);




		gluCylinder(obj, 1.5, 1.5, 6.5, 20, 8);

		glTranslatef(0, 30, 0);
		//		glRotatef(90,0,1,0);

		gluCylinder(obj, 1.5, 1.5, 6.5, 20, 8);

		/*
				glTranslatef(0,0,-20);
				glutSolidSphere(1,50,20);
		*/
	}glPopMatrix();


	// handle



	glPushMatrix(); {
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glColor3f(.2, .2, .2);
		glTranslatef(5, -27.5, 19);
		GLUquadricObj* obj = gluNewQuadric();

		gluCylinder(obj, 3.8, 3.8, 1.5, 50, 10);

		//		glTranslatef(100,100,100);
		//		glutSolidSphere(4,5,20);


		glTranslatef(0, 55, 0);


		gluCylinder(obj, 3.8, 3.8, 1.5, 50, 10);

		//		glTranslatef(100,100,100);
	}glPopMatrix();

	glPushMatrix(); {

		glColor3f(1, 1, .92);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-80, -37, 15.5);
			glVertex3f(-80, -37, 20.5);

			glVertex3f(-80, -25, 15.5);
			glVertex3f(-80, -25, 20);

			glVertex3f(-80, -18, 15);
			glVertex3f(-80, -18, 19.5);



		}glEnd();
		glBegin(GL_QUAD_STRIP); {
			glVertex3f(-80, 37, 15.5);
			glVertex3f(-80, 37, 20.5);

			glVertex3f(-80, 25, 15.5);
			glVertex3f(-80, 25, 20);

			glVertex3f(-80, 18, 15);
			glVertex3f(-80, 18, 19.5);


		}glEnd();


	}glPopMatrix();

	// back design



	glPushMatrix(); {

		glColor3f(.2, 0.2, 0.2);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(85.1, -35.5, 9);
			glVertex3f(84.2, -36, 11);

			glVertex3f(84.2, 36, 11);
			glVertex3f(85.1, 35.5, 9);


		}glEnd();



	}glPopMatrix();

	// back extra light _left -Right1

	// BACK LIGHT FOR BACK GEAR
	glPushMatrix(); {

		if (back < 0)
			glColor3f(1, 0, .18);
		else
			glColor3f(.9, 0.3 * light, 0.3 * light);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(83.5, -32, 14.5);
			glVertex3f(83.5, -20, 14.5);

			glVertex3f(83, -20, 17);
			glVertex3f(83, -32, 17);


		}glEnd();



	}glPopMatrix();


	glPushMatrix(); {

		if (back < 0)
			glColor3f(1, 0, .18);
		else
			glColor3f(.9, 0.3 * light, 0.3 * light);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(83.5, 32, 14.5);
			glVertex3f(83.5, 20, 14.5);

			glVertex3f(83, 20, 17);
			glVertex3f(83, 32, 17);


		}glEnd();



	}glPopMatrix();














	//LEFT LIGHT1


	glPushMatrix(); {

		if (left_right1 % 2 == 1)
			glColor3f(1, 1, .18);
		else
			glColor3f(1, 1, .9);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(83.5, -37.5, 14.5);
			glVertex3f(83.5, -32, 14.5);

			glVertex3f(83.5, -32, 17);
			glVertex3f(83.5, -37.5, 17);


		}glEnd();



	}glPopMatrix();

	// right light2
	glPushMatrix(); {

		if (left_right2 % 2 == 1)
			glColor3f(1, 1, .18);
		else
			glColor3f(1, 1, .9);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(83.5, 37.5, 14.5);
			glVertex3f(83.5, 32, 14.5);

			glVertex3f(83.5, 32, 17);
			glVertex3f(83.5, 37.5, 17);


		}glEnd();



	}glPopMatrix();

	// front design

	glPushMatrix(); {

		glColor3f(0.2, 0.2, 0.2);

		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(-80, -16, 15);
			glVertex3f(-80, -16, 19.5);

			glVertex3f(-80, -10, 19.5);
			glVertex3f(-80, -10, 15);


		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-80, -9.5, 14.5);
			glVertex3f(-80, -9.5, 19);

			glVertex3f(-80, -5, 19);
			glVertex3f(-80, -5, 14.5);


		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-80, -4.5, 13);
			glVertex3f(-80, -4.5, 18.5);

			glVertex3f(-80, -.5, 18.5);
			glVertex3f(-80, -.5, 13);


		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-80, 16, 15);
			glVertex3f(-80, 16, 19.5);

			glVertex3f(-80, 10, 19.5);
			glVertex3f(-80, 10, 15);


		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-80, 9.5, 14.5);
			glVertex3f(-80, 9.5, 19);

			glVertex3f(-80, 5, 19);
			glVertex3f(-80, 5, 14.5);


		}glEnd();

		glBegin(GL_QUADS); {
			glVertex3f(-80, 4.5, 13);
			glVertex3f(-80, 4.5, 18.5);

			glVertex3f(-80, .5, 18.5);
			glVertex3f(-80, .5, 13);


		}glEnd();

		/*

			glBegin(GL_QUAD_STRIP);{
				glVertex3f(-82.5,-37,4.5);
				glVertex3f(-81,-37,12.5);

				glVertex3f(-82.5,0,4.5);
				glVertex3f(-82,0,10);

				glVertex3f(-82.5,37,4.5);
				glVertex3f(-81,37,12.5);
			}glEnd();


		*/

	}glPopMatrix();

	// fog light
	glPushMatrix(); {

		glColor3f(.8 + field, 0.8 + field, 0.8 + field);
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glTranslatef(-80.5, -23, 8);
		glutSolidSphere(2.2, 50, 30);


		glTranslatef(0, 46, 0);
		glutSolidSphere(2.2, 50, 30);
	}glPopMatrix();


	// looking glass
	glPushMatrix(); {

		glColor3f(.9, 0.9, 0.9);
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1, .8, 1);
		glBegin(GL_QUADS); {
			glVertex3f(-44, -37, 22.5);
			glVertex3f(-44, -37, 24.9);

			glVertex3f(-44, -44.5, 25.1);
			glVertex3f(-44, -44.5, 22.5);



		}glEnd();
		glBegin(GL_QUADS); {
			glVertex3f(-44, 37, 22.5);
			glVertex3f(-44, 37, 24.9);

			glVertex3f(-44, 44.5, 25.1);
			glVertex3f(-44, 44.5, 22.5);

		}glEnd();



	}glPopMatrix();












	//for Wheel RIM
	for (int jk = -26; jk <= 26; jk++) {    //normal 33
		glPushMatrix(); {
			glColor3f(0.1, 0.1, 0.1);
			glTranslatef(62 + moveX, 0 + jk + moveY, 6);
			glutSolidCube(4);
			glScalef(1, .01, .01);
		}glPopMatrix();
	}
	//glColor3f(0.1,0.1,0.1);
	for (int ik = -26; ik <= 26; ik++) {
		glPushMatrix(); {
			glTranslatef(-62 + moveX, 0 + ik + moveY, 6);
			glutSolidCube(4);
			glScalef(1, .01, .01);
		}glPopMatrix();
	}

	//for wheel

	glColor3f(0.1, 0.1, 0.1);

	glPushMatrix(); {
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1.75, 1, .75);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-35, 8, 28);
		glutSolidTorus(2, 6, 100, 100);
	}glPopMatrix();

	//			glColor3f(.5,0.2,0.1);
	glPushMatrix(); {
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1.75, 1, .75);
		glRotatef(90, 1, 0, 0);
		glTranslatef(35, 8, 28);  //normal 35
		glutSolidTorus(2, 6, 100, 100);

	}glPopMatrix();

	glPushMatrix(); {
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1.75, 1, .75);
		glRotatef(90, 1, 0, 0);
		glTranslatef(35, 8, -28);
		glutSolidTorus(2, 6, 100, 100);
	}glPopMatrix();
	glPushMatrix(); {
		glTranslatef(0 + moveX, 0 + moveY, 0);
		glScalef(1.75, 1, .75);
		glRotatef(90, 1, 0, 0);
		glTranslatef(-35, 8, -28);
		glutSolidTorus(2, 6, 100, 100);
	}glPopMatrix();


	// for two types of Rotated RIM 


	//for 90 rotation ------------

	if (rotateX % 2 == 0) {

		glPushMatrix(); {
			//for wheel rim left 1st

			glPushMatrix(); {

				glTranslatef(-61 + moveX, -29 + moveY, 1);
				glScalef(1.6, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(0, 0, 5);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 0

					glColor3f(1, 1, 1);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 90

					glColor3f(1, 1, 1);
					glTranslatef(4.5, 0, 5);
					glRotatef(-90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 180

					glColor3f(1, 1, 1);
					glTranslatef(0, 0, 9.5);
					glRotatef(180, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 270

					glColor3f(1, 1, 1);
					glTranslatef(-4.5, 0, 5);
					glRotatef(90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


			}glPopMatrix();


			//for wheel rim right 1st

			glPushMatrix(); {

				glTranslatef(-61 + moveX, 29 + moveY, 1);
				glScalef(1.6, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(0, 0, 5);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 0

					glColor3f(1, 1, 1);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 90

					glColor3f(1, 1, 1);
					glTranslatef(4.5, 0, 5);
					glRotatef(-90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 180

					glColor3f(1, 1, 1);
					glTranslatef(0, 0, 9.5);
					glRotatef(180, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 270

					glColor3f(1, 1, 1);
					glTranslatef(-4.5, 0, 5);
					glRotatef(90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


			}glPopMatrix();



			//for wheel rim left 2nd

			glPushMatrix(); {

				glTranslatef(62 + moveX, -29 + moveY, 1);
				glScalef(1.6, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(0, 0, 5);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 0

					glColor3f(1, 1, 1);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 90

					glColor3f(1, 1, 1);
					glTranslatef(4.5, 0, 5);
					glRotatef(-90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 180

					glColor3f(1, 1, 1);
					glTranslatef(0, 0, 9.5);
					glRotatef(180, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 270

					glColor3f(1, 1, 1);
					glTranslatef(-4.5, 0, 5);
					glRotatef(90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


			}glPopMatrix();




			//for wheel rim right 2nd

			glPushMatrix(); {

				glTranslatef(62 + moveX, 29 + moveY, 1);
				glScalef(1.6, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(0, 0, 5);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 0

					glColor3f(1, 1, 1);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 90

					glColor3f(1, 1, 1);
					glTranslatef(4.5, 0, 5);
					glRotatef(-90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 180

					glColor3f(1, 1, 1);
					glTranslatef(0, 0, 9.5);
					glRotatef(180, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 270

					glColor3f(1, 1, 1);
					glTranslatef(-4.5, 0, 5);
					glRotatef(90, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


			}glPopMatrix();



		}glPopMatrix();


	}







	else if (rotateX % 2 == 1) {
		//for 45 rotation ----------------

		glPushMatrix(); {
			//	glTranslatef(-22.5+moveX,0+moveY,-41);
			//	glRotatef(360+45,0,1,0);
			//for wheel rim left 1st

			glPushMatrix(); {

				glTranslatef(-38 + moveX, -29 + moveY, 2.5);
				glScalef(1.7, 1.5, 1);


				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(-13.6, 0, 3.1);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 0);
					glRotatef(-45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 7);
					glRotatef(-135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 7);
					glRotatef(135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 0);
					glRotatef(45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

			}glPopMatrix();


			//for wheel rim right 1st

			glPushMatrix(); {

				glTranslatef(-38 + moveX, 29 + moveY, 2.5);
				glScalef(1.7, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(-13.6, 0, 3.1);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 0);
					glRotatef(-45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 7);
					glRotatef(-135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 7);
					glRotatef(135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 0);
					glRotatef(45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

			}glPopMatrix();

		}glPopMatrix();


		//for wheel rim left 2nd
		glPushMatrix(); {

			glPushMatrix(); {

				glTranslatef(85 + moveX, -29 + moveY, 2.5);
				glScalef(1.7, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(-13.6, 0, 3.1);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 0);
					glRotatef(-45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 7);
					glRotatef(-135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 7);
					glRotatef(135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 0);
					glRotatef(45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

			}glPopMatrix();





			//for wheel rim right 2nd

			glPushMatrix(); {

				glTranslatef(85 + moveX, 29 + moveY, 2.5);
				glScalef(1.7, 1.5, 1);

				glPushMatrix(); {
					glColor3f(.1, .1, .1);
					glTranslatef(-13.6, 0, 3.1);
					glutSolidSphere(1.4, 50, 20);

				}glPopMatrix();

				glPushMatrix(); {
					

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 0);
					glRotatef(-45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();



				glPushMatrix(); {

					

					glColor3f(1, 1, 1);
					glTranslatef(-10, 0, 7);
					glRotatef(-135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();


				glPushMatrix(); {

					//for circular RIM 135

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 7);
					glRotatef(135, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

				glPushMatrix(); {

					//for circular RIM 45

					glColor3f(1, 1, 1);
					glTranslatef(-17, 0, 0);
					glRotatef(45, 0, 1, 0);

					glBegin(GL_QUADS); {
						glVertex3f(-.5, 0, 5);
						glVertex3f(.5, 0, 5);
						glVertex3f(1, 0, 9);
						glVertex3f(-1, 0, 9);
					}glEnd();

				}glPopMatrix();

			}glPopMatrix();

		}glPopMatrix();



	}
	glutSwapBuffers();
}

void animate() {
	//codes for any changes in Camera
/*
	cameraAngle += cameraAngleDelta;
	cameraAngle =0;// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!
	cameraAngle-=.01;
	if(stopWindow){
	cameraAngle-=.0001;
	}
//*/	//codes for any changes in Models

//	rectAngle -= 1;

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x, int y) {


	switch (key) {

	case 'q':
		stopWindow = !stopWindow;
		break;

	case '1':	//reverse the rotation of camera
		cameraAngleDelta = -cameraAngleDelta;
		break;

	case '2':	//increase rotation of camera by 10%
		cameraAngleDelta *= 1.1;
		break;

	case '3':	//decrease rotation
		cameraAngleDelta /= 1.1;
		break;

	case '8':	//toggle grids
//		canDrawGrid = 1 - canDrawGrid;
		break;

	case 27:	//ESCAPE KEY -- simply exit
		exit(0);
		break;

	case 's':
	{
		moveX += 5;
		rotateX += 1;
		back -= 1;
	}

	break;

	case 'w':
	{
		moveX -= 10;
		rotateX += 1;
		back += 1;
	}

	break;

	case 'S':
	{
		moveX += 5;
		rotateX += 1;
		back -= 1;
	}

	break;
	case 'W':
	{
		moveX -= 10;
		rotateX += 1;
		back += 1;
	}
	break;

	case 'a':
	{
		if (moveY > -40)
			moveY -= 3;
		left_right1 += 1;
	}
	break;
	case 'd':
	{
		if (moveY < 200)
			moveY += 3;
		left_right2 += 1;
	}
	break;

	case 'A':
	{
		if (moveY > -40)
			moveY -= 3;
		left_right1 += 1;
	}
	break;
	case 'D':
	{
		if (moveY < 200)
			moveY += 3;
		left_right2 += 1;
	}
	break;

	case 'm':
	{
		day_night = 1;
		light = 1;
		field = 0;
	}
	break;


	case 'M':
	{
		day_night = 1;
		light = 1;
		field = 0;
	}
	break;

	case 'n':
	{
		day_night = 0;
		light = .2;
		field = .2;
	}
	break;


	case 'N':
	{
		day_night = 0;
		light = .2;
		field = .2;
	}
	break;
	case 'c':
	{
		car_color += 1;
	}
	break;

	case 'C':
	{
		car_color += 1;
	}
	break;

	case 'h':
	{
		head_light += 1;
	}
	break;

	case 'H':
	{
		head_light += 1;
	}
	break;
	default:

		break;
	}



}

void specialKeyListener(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:		
		cameraRadius += 10;
		break;
	case GLUT_KEY_UP:		
		if (cameraRadius > 10)
			cameraRadius -= 10;
		break;

	case GLUT_KEY_RIGHT:
		cameraAngle += +.02;
		break;
	case GLUT_KEY_LEFT:
		cameraAngleDelta = -cameraAngleDelta;
		cameraAngle -= .02;
		break;

	case GLUT_KEY_PAGE_UP:
		cameraHeight += 10;
		break;
	case GLUT_KEY_PAGE_DOWN:
		cameraHeight -= 10;
		break;

	case GLUT_KEY_INSERT:
		//fanOn=-fanOn;
		break;

		/*
				case GLUT_KEY_HOME:
					{
						if(countSlit<18)
							countSlit++;
					}
					break;
				case GLUT_KEY_END:
					{
						if(countSlit>0)
							countSlit--;
					}
					break;
		*/
	default:
		break;
	}
}


void init() {
	
	cameraAngle = 0;	
	cameraAngleDelta = 0.002;
	
	canDrawGrid = true;
	cameraHeight = 200;
	cameraRadius = 200;


	
	glClearColor(0, 0, 0, 0);          
	
	glMatrixMode(GL_PROJECTION);

	
	glLoadIdentity();

	
	gluPerspective(70, 1, 0.1, 100000.0);
	
}

void color_choose(int ch)
{
	switch (ch)
	{
	case 1: car_color = 1;
		break;
	case 2:car_color = 2;
		break;
	case 3:car_color = 3;
		break;
	case 4:car_color = 4;
		break;
	case 5:car_color = 5;
		break;
	case 6:car_color = 6;
	default:
		break;
	}
	glutPostRedisplay();
}
void sky_choose(int ch)
{
	switch (ch)
	{
	case 1:day_night = 1;
		break;
	case 2:day_night = 2;
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	

	glutCreateWindow("3D Moving Car");

	init();

	glEnable(GL_DEPTH_TEST);	


	glutCreateMenu(color_choose);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Black", 4);
	glutAddMenuEntry("White", 5);
	glutAddMenuEntry("Gold", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutCreateMenu(sky_choose);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutDisplayFunc(display);	
	glutIdleFunc(animate);		

	
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	glutMainLoop();		
	return 0;
}