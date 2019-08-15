from graphics import *
import math

width = 500
height = 500

NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3

win = GraphWin('Hexapod Simulation V2',width,height)

def drawGrid():
	for i in range(10):
		line = Line(Point(i*width/10,0),Point(i*width/10,height))
		line.draw(win)

	for j in range(10):
		line = Line(Point(0,j*height/10),Point(width,j*height/10))
		line.draw(win)

def grid(row, col):
	return row*width/10,col*height/10

def drawChassis():
	rect = Rectangle(Point(grid(4,3)[0],grid(4,3)[1]),Point(grid(6,6)[0],grid(6,6)[1]))
	# rect.setFill('black')
	rect.setWidth(10)
	rect.draw(win)

def rotatePoint(centerPoint,point,angle):
    """Rotates a point around another centerPoint. Angle is in degrees.
    Rotation is counter-clockwise"""
    angle = math.radians(angle)
    temp_point = point[0]-centerPoint[0] , point[1]-centerPoint[1]
    temp_point = ( temp_point[0]*math.cos(angle)-temp_point[1]*math.sin(angle) , temp_point[0]*math.sin(angle)+temp_point[1]*math.cos(angle))
    temp_point = temp_point[0]+centerPoint[0] , temp_point[1]+centerPoint[1]
    return temp_point

def rotatePolygon(polygon,origin,theta):
    """Rotates the given polygon which consists of corners represented as (x,y),
    around the ORIGIN, clock-wise, theta degrees"""
    rotatedPolygon = []
    for corner in polygon :
        rotatedPolygon.append(rotatePoint(origin,corner,theta))
    return rotatedPolygon

class Leg():
	def __init__(self,pivot,l,w,direction):
		self.p = pivot
		self.l = l*width/10
		self.w = w*height/10
		self.d = direction

		if(self.d == 0):#NORTH
			self.x = pivot[0]+(self.w/2)
			self.y = pivot[1]+(self.w/2)
			self.a = self.x-self.w
			self.b = self.y-self.l
		elif(self.d == 1):#EAST
			self.x = pivot[0]-(self.w/2)
			self.y = pivot[1]+(self.w/2)
			self.a = self.x+self.l
			self.b = self.y-self.w
		elif(self.d == 2):#SOUTH
			self.x = pivot[0]-(self.w/2)
			self.y = pivot[1]-(self.w/2)
			self.a = self.x+self.w
			self.b = self.y+self.l
		elif(self.d == 3):#WEST
			self.x = pivot[0]+(self.w/2)
			self.y = pivot[1]-(self.w/2)
			self.a = self.x-self.l
			self.b = self.y+self.w

		self.poly = [(self.x,self.y),(self.a,self.y),(self.a,self.b),(self.x,self.b)]

		self.l1 = None
		self.l2 = None
		self.l3 = None
		self.l4 = None

		self.draw()

	def draw(self):
		if(self.d == 0):#NORTH
			self.l1 = Line(Point(self.poly[0][0],self.poly[0][1]),Point(self.poly[3][0],self.poly[3][1]))
			self.l2 = Line(Point(self.poly[3][0],self.poly[3][1]),Point(self.poly[2][0],self.poly[2][1]))
			self.l3 = Line(Point(self.poly[2][0],self.poly[2][1]),Point(self.poly[1][0],self.poly[1][1]))
			self.l4 = Line(Point(self.poly[1][0],self.poly[1][1]),Point(self.poly[0][0],self.poly[0][1]))
		elif(self.d == 1):#EAST
			self.l1 = Line(Point(self.poly[0][0],self.poly[0][1]),Point(self.poly[1][0],self.poly[1][1]))
			self.l2 = Line(Point(self.poly[1][0],self.poly[1][1]),Point(self.poly[2][0],self.poly[2][1]))
			self.l3 = Line(Point(self.poly[2][0],self.poly[2][1]),Point(self.poly[3][0],self.poly[3][1]))
			self.l4 = Line(Point(self.poly[3][0],self.poly[3][1]),Point(self.poly[0][0],self.poly[0][1]))
		elif(self.d == 2):#SOUTH
			self.l1 = Line(Point(self.poly[0][0],self.poly[0][1]),Point(self.poly[3][0],self.poly[3][1]))
			self.l2 = Line(Point(self.poly[3][0],self.poly[3][1]),Point(self.poly[2][0],self.poly[2][1]))
			self.l3 = Line(Point(self.poly[2][0],self.poly[2][1]),Point(self.poly[1][0],self.poly[1][1]))
			self.l4 = Line(Point(self.poly[1][0],self.poly[1][1]),Point(self.poly[0][0],self.poly[0][1]))
		elif(self.d == 3):#WEST
			self.l1 = Line(Point(self.poly[0][0],self.poly[0][1]),Point(self.poly[1][0],self.poly[1][1]))
			self.l2 = Line(Point(self.poly[1][0],self.poly[1][1]),Point(self.poly[2][0],self.poly[2][1]))
			self.l3 = Line(Point(self.poly[2][0],self.poly[2][1]),Point(self.poly[3][0],self.poly[3][1]))
			self.l4 = Line(Point(self.poly[3][0],self.poly[3][1]),Point(self.poly[0][0],self.poly[0][1]))

		self.l1.setWidth(5)
		self.l2.setWidth(5)
		self.l3.setWidth(5)
		self.l4.setWidth(5)
		self.l1.setFill('red')
		self.l2.setFill('blue')
		self.l3.setFill('green')
		self.l4.setFill('yellow')
		self.l1.draw(win)
		self.l2.draw(win)
		self.l3.draw(win)
		self.l4.draw(win)

		#show pivot point
		p = Point(self.p[0],self.p[1])
		p.setFill('red')
		p.draw(win)

	def undraw(self):
		self.l1.undraw()
		self.l2.undraw()
		self.l3.undraw()
		self.l4.undraw()

	def rotate(self,angle):
		self.undraw()
		self.poly = rotatePolygon(self.poly,self.p,angle)
		self.draw()

def main():
	drawGrid()
	# print grid(6,6)
	drawChassis()
	RF = Leg(grid(6,3),2,0.5,NORTH)
	RM = Leg(grid(6,4.5),2,0.5,EAST)
	RB = Leg(grid(6,6),2,0.5,SOUTH)
	LF = Leg(grid(4,3),2,0.5,NORTH)
	LM = Leg(grid(4,4.5),2,0.5,WEST)
	LB = Leg(grid(4,6),2,0.5,SOUTH)

	RF.rotate(45)
	RB.rotate(-45)
	LF.rotate(-45)
	LB.rotate(45)

	# for i in range(5):
	# 	RF.rotate(i*2)
	# 	RM.rotate(i*2)
	# 	RB.rotate(i*2)
	# 	LF.rotate(i*2)
	# 	LM.rotate(i*2)
	# 	LB.rotate(i*2)

	win.getMouse()
	win.close()

main()