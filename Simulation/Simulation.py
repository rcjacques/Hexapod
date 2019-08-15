from graphics import *

width = 500
height = 500

NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3

win = GraphWin('Hexapod Simulation',width,height)

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

class Leg():
	def __init__(self,pivot,l,w,direction):
		self.pivot = pivot
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
		
		self.draw()

	def draw(self):
		if(self.d == 0):#NORTH
			l1 = Line(Point(self.x,self.y),Point(self.a,self.y))
			l2 = Line(Point(self.a,self.y),Point(self.a,self.b))
			l3 = Line(Point(self.a,self.b),Point(self.x,self.b))
			l4 = Line(Point(self.x,self.b),Point(self.x,self.y))
		elif(self.d == 1):#EAST
			l1 = Line(Point(self.x,self.y),Point(self.x,self.b))
			l2 = Line(Point(self.x,self.b),Point(self.a,self.b))
			l3 = Line(Point(self.a,self.b),Point(self.a,self.y))
			l4 = Line(Point(self.a,self.y),Point(self.x,self.y))
		elif(self.d == 2):#SOUTH
			l1 = Line(Point(self.x,self.y),Point(self.a,self.y))
			l2 = Line(Point(self.a,self.y),Point(self.a,self.b))
			l3 = Line(Point(self.a,self.b),Point(self.x,self.b))
			l4 = Line(Point(self.x,self.b),Point(self.x,self.y))
		elif(self.d == 3):#WEST
			l1 = Line(Point(self.x,self.y),Point(self.x,self.b))
			l2 = Line(Point(self.x,self.b),Point(self.a,self.b))
			l3 = Line(Point(self.a,self.b),Point(self.a,self.y))
			l4 = Line(Point(self.a,self.y),Point(self.x,self.y))

		l1.setWidth(5)
		l2.setWidth(5)
		l3.setWidth(5)
		l4.setWidth(5)
		l1.setFill('red')
		l2.setFill('blue')
		l3.setFill('green')
		l4.setFill('yellow')
		l1.draw(win)
		l2.draw(win)
		l3.draw(win)
		l4.draw(win)

		#show pivot point
		p = Point(self.pivot[0],self.pivot[1])
		p.setFill('red')
		p.draw(win)

def main():
	drawGrid()
	print grid(6,6)
	drawChassis()
	RF = Leg(grid(6,3),2,0.5,NORTH)
	RM = Leg(grid(6,4.5),2,0.5,EAST)
	RB = Leg(grid(6,6),2,0.5,SOUTH)
	LF = Leg(grid(4,3),2,0.5,NORTH)
	LM = Leg(grid(4,4.5),2,0.5,WEST)
	LB = Leg(grid(4,6),2,0.5,SOUTH)
	win.getMouse()
	win.close()

main()
